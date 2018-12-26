#include "tree.h"

#include <map>
#include <string>
#include <vector>

using namespace std;

static map<Symbol*, string> varDeclare;
static int tempVarCount = 0;

extern TreeNode* root;

static std::ofstream of;

enum {A, B, C, D, SI, DI, R8, R9, R10, R11, R12, R13, R14, R15};

static bool regUsed[14] = {false};

string get4RegName(int i) {
    switch (i) {
    case 0: return "%eax";
    case 1: return "%ebx";
    case 2: return "%ecx";
    case 3: return "%edx";
    case 4: return "%esi";
    case 5: return "%edi";
    case 6: return "%r8d";
    case 7: return "%r9d";
    case 8: return "%r10d";
    case 9: return "%r11d";
    case 10: return "%r12d";
    case 11: return "%r13d";
    case 12: return "%r14d";
    case 13: return "%r15d";
    }
    return "unknown4reg";
}

string get8RegName(int i) {
    switch (i) {
    case 0: return "%rax";
    case 1: return "%rbx";
    case 2: return "%rcx";
    case 3: return "%rdx";
    case 4: return "%rsi";
    case 5: return "%rdi";
    case 6: return "%r8";
    case 7: return "%r9";
    case 8: return "%r10";
    case 9: return "%r11";
    case 10: return "%r12";
    case 11: return "%r13";
    case 12: return "%r14";
    case 13: return "%r15";
    }
    return "unknown8reg";
}

string getTmp4Reg() {
    for (int i = 0; i < 14; i++) {
        if (!regUsed[i])
            return get4RegName(i);
    }
    cerr << "no enough regs" << endl;
    throw 0;
}

string getTmp8Reg() {
    for (int i = 0; i < 14; i++) {
        if (!regUsed[i])
            return get8RegName(i);
    }
    cerr << "no enough regs" << endl;
    throw 0;
}

string getUnused4Reg() {
    for (int i = 0; i < 14; i++) {
        if (!regUsed[i]) {
            regUsed[i] = 1;
            return get4RegName(i);
        }
    }
    cerr << "no enough regs" << endl;
    throw 0;
}

string getUnused8Reg() {
    for (int i = 0; i < 14; i++) {
        if (!regUsed[i]) {
            regUsed[i] = 1;
            return get8RegName(i);
        }
    }
    cerr << "no enough regs" << endl;
    throw 0;
}

string getSymbolMemory(Symbol* sym) {
    if (varDeclare[sym].size() == 0) {
        cerr << "trying getting empty symbol " << sym << endl;
        throw 0;
    }
    return varDeclare[sym] + string("(%rip)");
}

void storeVar(TreeNode* node) {
    if (node == nullptr) return;

    Symbol* ownSymbol = nullptr;

    if (node->nodeType == TreeNode::NODE_DECLARATION) {
        ownSymbol = static_cast<DeclarationNode*>(node)->symbol;
        cerr << "get dec " << ownSymbol << " " << ownSymbol->value << endl;
        varDeclare[ownSymbol] = string("temp") + to_string(tempVarCount++);
    } else if (node->nodeType == TreeNode::NODE_EXPRESSION) {
        ownSymbol = static_cast<ExprNode*>(node)->symbol;
        cerr << "get exp " << ownSymbol << " " << ownSymbol->value << endl;
        if (ownSymbol->symbolType == Symbol::SYMBOL_CONSTANT
                && ownSymbol->type == Symbol::VALUE_STRING) {
            varDeclare[ownSymbol] = string(".str") + to_string(tempVarCount++);
        }
    }

    auto children = node -> child;
    while (children) {
        storeVar(children);
        children = children -> sibling;
    }
}

void putLine(const string& text) {
    of << "\t" << text << "\n";
}

int symbolSize(Symbol* const & sym) {
    switch (sym->type) {
    case Symbol::VALUE_INT:
        return 4;
    case Symbol::VALUE_CHAR:
        return 1;
    case Symbol::VALUE_NONE:
        return 0;
    case Symbol::VALUE_VOID:
        return 0;
    case Symbol::VALUE_ERROR:
        return 0;
    case Symbol::VALUE_DOUBLE:
        return 8;
    case Symbol::VALUE_STRING:
        return 0;
    }
    return 0;
}

string handleExprNode(TreeNode* node) {
    Symbol* ownSymbol = static_cast<ExprNode*>(node)->symbol;
    cerr << "symbol is: " << ownSymbol << ", " << ownSymbol->value << endl;

    if (node->nodeType == TreeNode::NODE_EXPRESSION) {
        cerr << "exprnode" << endl;
        if (ownSymbol->symbolType == Symbol::SYMBOL_CONSTANT) {
            if (ownSymbol->type == Symbol::VALUE_INT) {
                return string("$") + ownSymbol->value;
            }
            if (ownSymbol->type == Symbol::VALUE_CHAR) {
                return string("$") + to_string(ownSymbol->value[0]);
            }
        }
        return getSymbolMemory(ownSymbol);
    }

    if (node->nodeType == TreeNode::NODE_OPERATOR) {
        TreeNode* child[3];
        child[0] = node->child;
        child[1] = child[0] ? child[0]->sibling : nullptr;
        child[2] = child[1] ? child[1]->sibling : nullptr;

        string reg = getTmp4Reg();

        string op = handleExprNode(child[0]);

        auto opType = static_cast<OperatorNode*>(node)->type;

        if (opType == OperatorNode::OP_TADDR) {
            reg = getTmp8Reg();
            of << "\tleaq\t" << op << ", " << reg << "\n";
            return reg;
        }

        if (op != reg) {
            of << "\tmovl\t" << op << ", " << reg << "\n";
        }

        switch (opType) {
        case OperatorNode::OP_ADD:
            op = handleExprNode(child[1]);
            of << "\taddl\t" << op << ", " << reg << "\n";
            return reg;
        }

        return getSymbolMemory(ownSymbol);
    }

    return "";
}

void handleFunctionNode(TreeNode* node) {
    Symbol* ownSymbol = static_cast<TreeNode*>(node)->symbol;
    of << "\t.globl\t" << ownSymbol->value << "\n";
    of << "\t.type\t" << ownSymbol->value << ", @function\n";
    of << ownSymbol->value << ":\n";
    of << "\tpushq\t%rbp\n";
    of << "\tmovq\t%rsp, %rbp\n";

    auto children = node -> child;
    while (children) {
        void generateCode(TreeNode* node);
        generateCode(children);
        children = children -> sibling;
    }

    of << "\tleave\n";
    of << "\tret\n";
}

void generateCode(TreeNode* node) {
    if (node == nullptr) return;

    Symbol* ownSymbol = nullptr;

    if (node->nodeType == TreeNode::NODE_STATMENT) {
        auto ownType = static_cast<StatementNode*>(node)->type;
        if (ownType == StatementNode::ST_FUNCTION) {
            handleFunctionNode(node);
            return;
        }
    }

    string reg;

    if (node->nodeType == TreeNode::NODE_DECLARATION) {
        ownSymbol = static_cast<DeclarationNode*>(node)->symbol;
        if (!node->child) return;
        switch (ownSymbol->type) {
        case Symbol::VALUE_INT:
        case Symbol::VALUE_CHAR:
            reg = handleExprNode(node->child);
            of << "\tmovl\t" << reg << ", " << getSymbolMemory(ownSymbol) << "\n";
            return;
        case Symbol::VALUE_STRING:
            static_cast<DeclarationNode*>(node)->symbol = node->child->symbol;
            return;
        default:
            cerr << "could not handle type" << endl;
            return;
        }
    }

    if (node->nodeType == TreeNode::NODE_FUNCCALL) {
        vector<ExprNode*> children;
        ExprNode* child = static_cast<ExprNode*>(node->child);
        while (child) {
            children.push_back(child);
            child = static_cast<ExprNode*>(child->sibling);
        }
        string op;
        int argNums[]{5, 4, 3, 2, 6, 7};
        bool originalRegState[14];
        for (int i = 0; i < 14; i++) {
            originalRegState[i] = regUsed[i];
        }
        for (size_t i = 0; i < children.size(); i++) {
            if (i >= 6) {
                cerr << "ignoring " << i << "th args" << endl;
                continue;
            }
            op = handleExprNode(children[i]);
            if (regUsed[argNums[i]]) {
                of << "\tpushq\t" << op << ", " << get8RegName(argNums[i]) << "\n";
            }
            regUsed[argNums[i]] = true;
            // 让 OP 有自己的类型
            if (op[0] == '$') {;
                of << "\tmovl\t" << op << ", " << get4RegName(argNums[i]) << "\n";
            } else if (children[i]->symbol->type == Symbol::VALUE_STRING) {
                of << "\tleaq\t" << op << ", "  << get8RegName(argNums[i]) << "\n";
            } else {
                of << "\tmovq\t" << op << ", "  << get8RegName(argNums[i]) << "\n";
            }
        }
        string funcName = static_cast<DeclarationNode*>(node)->symbol->value;
        if (funcName == "scanf")
            funcName = "__isoc99_scanf@PLT";
        else if (funcName == "printf")
            funcName = "printf@PLT";
        of << "\tcall\t" << funcName << "\n";
        for (int i = 0; i < 14; i++) {
            regUsed[i] = originalRegState[i];
            if (regUsed[i]) {
                of << "\tpop\t" << op << get8RegName(argNums[i]) << "\n";
            }
        }
    }
}

void generateASM() {
    of.open("out.S");

    of << "\t.file\t\"" << "temp.c" << "\"\n";

    putLine(".text");

    TreeNode* temp = root;

    while (temp) {
        storeVar(temp);
        temp = temp -> sibling;
    }

    vector<pair<Symbol*, string>> constStr;

    for (const auto& i : varDeclare) {
        if (i.first->type != Symbol::VALUE_STRING) {
            int size = symbolSize(i.first);
            of << "\t.comm\t" << i.second << "," << size << "," << size << "\n";
        } else {
            constStr.push_back(i);
        }
        cerr << i.first->value << " " << i.second << endl;
    }

    if(constStr.size() != 0) {
        of << "\t.section\t.rodata\n";
    }

    for (const auto& i : constStr) {
        of << "" << i.second << ":\n";
        of << "\t.string\t\"" << i.first->value << "\"\n";
    }

    putLine(".text");

    temp = root;

    while (temp) {
        generateCode(temp);
        temp = temp -> sibling;
    }

}
