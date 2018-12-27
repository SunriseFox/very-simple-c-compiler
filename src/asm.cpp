#include "tree.h"

#include <map>
#include <string>
#include <vector>

using namespace std;

static map<Symbol*, string> varDeclare;
static int tempVarCount = 0;

static int labelCount = 0;

extern TreeNode* root;

static std::ofstream of;

enum {A, B, C, D, SI, DI, R8, R9, R10, R11, R12, R13, R14, R15};

static bool regUsed[14] = {false};

string get2RegName(int i) {
    switch (i) {
    case 0: return "%al";
    case 1: return "%bl";
    case 2: return "%cl";
    case 3: return "%dl";
    case 4: return "%sil";
    case 5: return "%dil";
    case 6: return "%r8b";
    case 7: return "%r9b";
    case 8: return "%r10b";
    case 9: return "%r11b";
    case 10: return "%r12b";
    case 11: return "%r13b";
    case 12: return "%r14b";
    case 13: return "%r15b";
    }
    return "unknown4reg";
}

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

string getTmpReg(int size) {
    for (int i = 0; i < 14; i++) {
        if (!regUsed[i])
            return size == 2 ? get2RegName(i) : (size == 4 ? get4RegName(i) : get8RegName(i));
    }
    cerr << "no enough regs" << endl;
    throw 0;
}

int getRegNum(const string& reg) {

    if (reg.size() > 0 && reg.at(0) != '%')
        return -1;

    string tmp;
    if (reg.find("ax") != string::npos || reg.find("al") != string::npos) return 0;
    if (reg.find("bx") != string::npos || reg.find("bl") != string::npos) return 1;
    if (reg.find("cx") != string::npos || reg.find("cl") != string::npos) return 2;
    if (reg.find("dx") != string::npos || reg.find("dl") != string::npos) return 3;

    if (reg.find("si") != string::npos) return 4;
    if (reg.find("di") != string::npos) return 5;

    if (reg.find("8") != string::npos) return 6;
    if (reg.find("9") != string::npos) return 7;
    if (reg.find("10") != string::npos) return 8;
    if (reg.find("11") != string::npos) return 9;
    if (reg.find("12") != string::npos) return 10;
    if (reg.find("13") != string::npos) return 11;
    if (reg.find("14") != string::npos) return 12;
    if (reg.find("15") != string::npos) return 13;

    cerr << "unknown reg" << endl;
    throw 0;
}

void protectRegByName(const string& reg) {
    int num = getRegNum(reg);
    if (num < 0) return;

    regUsed[num] = true;
}

void releaseRegByName(const string& reg) {
    int num = getRegNum(reg);
    if (num < 0) return;

    regUsed[num] = false;
}

string getSymbolMemory(Symbol* sym) {
    if (varDeclare[sym].size() == 0) {
        cerr << "++++++++ trying getting empty symbol " << sym << endl;
        throw 0;
    }
    return varDeclare[sym] + string("(%rip)");
}

string getNextLabel() {
    return string(".L") + to_string(labelCount++);
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

void generateCode(TreeNode* node);
string handleExprNode(TreeNode* node);

void handleCodeBlock(TreeNode* node) {
    if (node->nodeType == TreeNode::NODE_STATMENT
            && static_cast<StatementNode*>(node)->type == StatementNode::ST_SCOPE) {
        node = node->child;
    }
    while (node) {
        generateCode(node);
        node = node -> sibling;
    }
}

void handleFuncCall(TreeNode* node) {
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
        if (op[0] == '$') {;
            of << "\tmovl\t" << op << ", " << get4RegName(argNums[i]) << "\n";
        } else if (children[i]->symbol->type == Symbol::VALUE_STRING) {
            of << "\tleaq\t" << op << ", "  << get8RegName(argNums[i]) << "\n";
        } else {
            of << "\tmovq\t" << op << ", "  << get8RegName(argNums[i]) << "\n";
        }
    }
    string funcName = static_cast<DeclarationNode*>(node)->symbol->value;
    cerr << "-- funccall" << funcName << endl;
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

        auto opType = static_cast<OperatorNode*>(node)->type;

        string op = handleExprNode(child[0]);

        if (opType == OperatorNode::OP_TADDR) {
            string reg = getTmpReg(8);
            of << "\tleaq\t" << op << ", " << reg << "\n";
            return reg;
        } else if (opType == OperatorNode::OP_DEC) {
            of << "\tdecl\t" << op << "\n";
            return op;
        } else if (opType == OperatorNode::OP_INC) {
            of << "\tincl\t" << op << "\n";
            return op;
        }

        string reg;

        if (getRegNum(op) == -1) { // 不是寄存器
            reg = getTmpReg(4);
            of << "\tmovl\t" << op << ", " << reg << "\n";
        } else {
            reg = op;
        }

        if (opType == OperatorNode::OP_NOT) {
            of << "\ttestl\t" << reg << ", " << reg << "\n";
            of << "\tsete\t" << get2RegName(getRegNum(reg)) << "\n";
            of << "\tmovzbl\t"<< get2RegName(getRegNum(reg)) << ", " << reg << "\n";
            return reg;
        }

        protectRegByName(reg);

        op = handleExprNode(child[1]);
        releaseRegByName(reg);

        string target;

        if(opType == OperatorNode::OP_LAND) {
            string Lfail = getNextLabel();
            string Lend = getNextLabel();
            of << "\ttest\t" << reg << ", " << reg << "\n";
            of << "\tje\t" << Lfail << "\n";
            of << "\tmovl\t" << op << ", " << reg << "\n";
            of << "\ttest\t" << reg << ", " << reg << "\n";
            of << "\tje\t" << Lfail << "\n";
            of << "\tmovl\t$1, " << reg << "\n";
            of << "\tjmp\t" << Lend << "\n";
            of << Lfail << ":\n";
            of << "\tmovl\t$0, " << reg << "\n";
            of << Lend << ":\n";
            return reg;
        } else if (opType == OperatorNode::OP_LOR) {
            string L2 = getNextLabel();
            string L3 = getNextLabel();
            string Lend = getNextLabel();
            of << "\ttest\t" << reg << ", " << reg << "\n";
            of << "\tjne\t" << L2 << "\n";
            of << "\tmovl\t" << op << ", " << reg << "\n";
            of << "\ttest\t" << reg << ", " << reg << "\n";
            of << "\tje\t" << L3 << "\n";
            of << L2 << ":\n";
            of << "\tmovl\t$1, " << reg << "\n";
            of << "\tjmp\t" << Lend << "\n";
            of << L3 << ":\n";
            of << "\tmovl\t$0, " << reg << "\n";
            of << Lend << ":\n";
            return reg;
        }
        switch (opType) {
        case OperatorNode::OP_ADD:
            of << "\taddl\t" << op << ", " << reg << "\n";
            return reg;
        case OperatorNode::OP_SUB:
            of << "\tsubl\t" << op << ", " << reg << "\n";
            return reg;
        case OperatorNode::OP_ASSIGN:
            of << "\tmovl\t" << reg << ", " << op << "\n";
            return reg;
        case OperatorNode::OP_MULAS:
            of << "\timull\t" << op << ", " << reg << "\n";
            of << "\tmovl\t" << reg << ", " << op << "\n";
            return "";
        case OperatorNode::OP_MORE:
        case OperatorNode::OP_MOREEQ:
        case OperatorNode::OP_LESS:
        case OperatorNode::OP_LESSEQ:
            target = getTmpReg(2);
            string what;
            switch (opType) {
            case OperatorNode::OP_MORE:
                what = "le"; break;
            case OperatorNode::OP_MOREEQ:
                what = "l"; break;
            case OperatorNode::OP_LESS:
                what = "ge"; break;
            case OperatorNode::OP_LESSEQ:
                what = "g"; break;
            default: break;
            }
            of << "\tcmpl\t" << op << ", " << reg << "\n";
            of << "\tset" << what << "\t" << target << "\n";
            reg = getTmpReg(4);
            of << "\tmovzbl\t" << target << ", " << reg << "\n";
            return reg;
        }
        cerr << "++++ operator not handled" << endl;
        return getSymbolMemory(ownSymbol);
    }

    if (node->nodeType == TreeNode::NODE_FUNCCALL) {
        handleFuncCall(node);
        return "%eax";
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

    handleCodeBlock(children);

    while (true) {
        if (children->sibling != nullptr)
            children = children->sibling;
        else break;
    }

    if (children->nodeType == TreeNode::NODE_STATMENT
            && static_cast<StatementNode*>(children)->type == StatementNode::ST_RET) {

    } else {
        if (ownSymbol->value == "main") {
            of << "\tmovl $0, %eax\n";
        }
        of << "\tleave\n";
        of << "\tret\n";
    }
    of << "\t.size\t"<< ownSymbol->value <<", .-"<< ownSymbol->value <<"\n";
}

void handleWhile(StatementNode* node) {
    string LCondition = getNextLabel();

    of << "\tjmp\t" << LCondition << "\n";

    string LBlock = getNextLabel();

    of << LBlock << ":\n";

    handleCodeBlock(node->child->sibling);

    of << LCondition << ":\n";
    string reg = handleExprNode(node->child);
    of << "\ttestl\t" << reg << ", " << reg << "\n";
    of << "\tje\t" << LBlock << "\n";
}

void handleFor(StatementNode* node) {
    TreeNode* st1 = node->child;
    TreeNode* st2 = st1->sibling;
    TreeNode* st3 = st2->sibling;
    TreeNode* st4 = st3->sibling;

    handleExprNode(st1);
    string LFor = getNextLabel();
    string LCondition = getNextLabel();
    of << "\tjmp\t" << LCondition << "\n";

    of << LFor << ":\n";
    handleCodeBlock(st4);
    handleExprNode(st3);

    of << LCondition << ":\n";
    string reg = handleExprNode(st2);
    of << "\ttestl\t" << reg << ", " << reg << "\n";
    of << "\tje\t" << LFor << "\n";
}


void handleIf(StatementNode* node) {
    string LElse = getNextLabel();
    string LEnd = getNextLabel();
    string op = handleExprNode(node->child);

    string reg;

    if (getRegNum(op) == -1) { // 不是寄存器
        reg = getTmpReg(4);
        of << "\tmovl\t" << op << ", " << reg << "\n";
    } else {
        reg = op;
    }

    of << "\ttestl\t" << reg << ", " << reg << "\n";
    of << "\tje\t" << LElse << "\n";
    generateCode(node->child->sibling);
    of << "\tjmp\t" << LEnd << "\n";

    of << LElse << ":\n";
    generateCode(node->child->sibling ? node->child->sibling->sibling : nullptr);
    of << LEnd << ":\n";
}

void generateCode(TreeNode* node) {
    if (node == nullptr) return;

    Symbol* ownSymbol = nullptr;
    string reg;

    if (node->nodeType == TreeNode::NODE_STATMENT) {
        StatementNode* stnode = static_cast<StatementNode*>(node);
        if (stnode->type == StatementNode::ST_IF_ELSE
                || stnode->type == StatementNode::ST_IF) {
            handleIf(stnode);
        } else if (stnode->type == StatementNode::ST_WHILE) {
            handleWhile(stnode);
        } else if (stnode->type == StatementNode::ST_FOR) {
            handleFor(stnode);
        }  else if (stnode->type == StatementNode::ST_FUNCTION) {
            handleFunctionNode(node);
        } else if (stnode->type == StatementNode::ST_RET) {
            reg = handleExprNode(stnode->child);
            of << "\tmovl\t" << reg << ", %eax\n";
            of << "\tleave\n";
            of << "\tret\n";
        } else if (static_cast<StatementNode*>(node)->type == StatementNode::ST_SCOPE) {
            handleCodeBlock(node);
        }
    }

    else if (node->nodeType == TreeNode::NODE_DECLARATION) {
        ownSymbol = static_cast<DeclarationNode*>(node)->symbol;
        if (!node->child) return;
        switch (ownSymbol->type) {
        case Symbol::VALUE_INT:
        case Symbol::VALUE_CHAR:
            reg = handleExprNode(node->child);
            of << "\tmovl\t" << reg << ", " << getSymbolMemory(ownSymbol) << "\n";
            return;
        case Symbol::VALUE_STRING:
            varDeclare[static_cast<DeclarationNode*>(node)->symbol] = varDeclare[node->child->symbol];
            return;
        default:
            cerr << "could not handle type" << endl;
            return;
        }
    }

    else if (node->nodeType == TreeNode::NODE_FUNCCALL) {
        handleFuncCall(node);
    }

    else if (node->nodeType == TreeNode::NODE_OPERATOR
             || node->nodeType == TreeNode::NODE_EXPRESSION) {
        handleExprNode(node);
    }

    else {
        cerr << "+++++ ignoring node !" << endl;
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
        } else if (i.second.substr(0, 4) == ".str") {
            constStr.push_back(i);
        }
        cerr << i.first->value << " " << i.second << endl;
    }

    if(constStr.size() != 0) {
        of << "\t.section\t.rodata\n";
    }

    for (const auto& i : constStr) {
        of << i.second << ":\n";
        of << "\t.string\t\"" << i.first->value << "\"\n";
    }

    putLine(".text");

    handleCodeBlock(root);

    of << "\t.ident\t\"Vampire very-simple-c-compiler\"\n";
    of << "\t.section\t.note.GNU-stack,\"\",@progbits\n";
}
