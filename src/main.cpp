#include "common.h"
#include <fstream>

extern TreeNode * root;
extern FILE* yyin;

void showTree(TreeNode* root) {

    if (root == nullptr) return;

    auto children = root -> child;
    while (children) {
        showTree(children);
        children = children -> sibling;
    }
    Symbol* ownSymbol = nullptr;

    cout << "(Line " << root -> lineno << ") " << root->nodeID << ": ";
    switch (root->nodeType) {
    case TreeNode::NODE_NONE:
        cout << "[Unknown] ";
        break;
    case TreeNode::NODE_STATMENT:
        cout << "[Statement ";
        switch (static_cast<StatementNode*>(root)->type) {
        case StatementNode::ST_NONE:
            cout << "Unknown";
            break;
        case StatementNode::ST_EMPTY:
            cout << "Empty";
            break;
        case StatementNode::ST_SCOPE:
            cout << "Scope";
            break;
        case StatementNode::ST_RET:
            cout << "Return";
            break;
        case StatementNode::ST_DO_WHILE:
            cout << "Do-While";
            break;
        case StatementNode::ST_WHILE:
            cout << "While";
            break;
        case StatementNode::ST_FOR:
            cout << "For";
            break;
        case StatementNode::ST_FUNCTION:
            cout << "Function<";
            cout << static_cast<FuncStatementNode*>(root)->symbol->value << ">";
            break;
        case StatementNode::ST_IF:
            cout << "If";
            break;
        case StatementNode::ST_IF_ELSE:
            cout << "If-Else";
            break;
        case StatementNode::ST_BREAK:
            cout << "Break";
            break;
        case StatementNode::ST_CONTINUE:
            cout << "Continue";
            break;
        case StatementNode::ST_GOTO:
            cout << "Goto";
            break;
        }
        cout << "]";
        break;

    case TreeNode::NODE_FUNCCALL:
        cout << "[FuncCall<";
        ownSymbol = static_cast<DeclarationNode*>(root)->symbol;
        cout << Symbol::getSymbolName(ownSymbol);
        cout << "> " <<static_cast<DeclarationNode*>(root)->symbol->value << "] ";

        break;
    case TreeNode::NODE_DECLARATION:
        cout << "[Declaration<";
        // fall through
        [[clang::fallthrough]];
    case TreeNode::NODE_EXPRESSION:
        if(root->nodeType == TreeNode::NODE_EXPRESSION)
            cout << "[Expression<";

        ownSymbol = static_cast<DeclarationNode*>(root)->symbol;

        cout << Symbol::getSymbolName(ownSymbol);

        cout << "> " <<static_cast<DeclarationNode*>(root)->symbol->value << "] ";
        break;
    case TreeNode::NODE_OPERATOR:
        ownSymbol = root->symbol = new OpNode(root->child->symbol->type, "");
        cout << "[Operator ";
        cout << OperatorNode::getTypeStr(static_cast<OperatorNode*>(root)->type);
        cout << " <";
        cout << Symbol::getSymbolName(ownSymbol);
        cout << ">]";
        switch (static_cast<OperatorNode*>(root)->type) {
        case OperatorNode::OP_ASSIGN:
        case OperatorNode::OP_ADDAS:
        case OperatorNode::OP_SUBAS:
        case OperatorNode::OP_MULAS:
        case OperatorNode::OP_DIVAS:
        case OperatorNode::OP_BORAS:
        case OperatorNode::OP_BANDAS:
        case OperatorNode::OP_BXORAS:
        case OperatorNode::OP_LSHFTAS:
        case OperatorNode::OP_RSHFTAS:
            if (static_cast<ExprNode*>(root->child)->symbol->symbolType != Symbol::SYMBOL_VARIABLE)
                cout << "[error] could only assign to lvalue";
            break;
        default: break;
        }
        break;
    }
    children = root -> child;
    if(children) {
        cout << endl << "\tChildren: ";
    }
    while (children) {
        cout << children->nodeID << " ";
        children = children -> sibling;
    }
    cout << endl;
    children = root -> child;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        FILE* fin = fopen(argv[1], "r");
        if (fin != nullptr) {
            yyin = fin;
        } else {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    } else {
#if YYDEBUG != 0
        extern int yydebug;
        yydebug = 1;
#endif
    }

    scope = new Scope();

    yyparse();

    TreeNode* temp = root;

    while (temp) {
        showTree(temp);
        temp = temp -> sibling;
    }

    extern void generateASM();
    generateASM();

    return 0;
}
