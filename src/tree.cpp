#include "tree.h"

int TreeNode::_nodeID = 1;

TreeNode::TreeNode(int lineno, NodeType type)
    : lineno(lineno), nodeType(type)
{
    nodeID = TreeNode::_nodeID++;
    child = nullptr;
    sibling = nullptr;
}

void TreeNode::addChild(TreeNode *node)
{
    if (child == nullptr) {
        child = node;
        return;
    }
    if (child->sibling == nullptr) {
        child->sibling = node;
        return;
    }
    auto cur = child->sibling;
    while (cur->sibling != nullptr) {
        cur = cur->sibling;
    }
    cur->sibling = node;
}

void TreeNode::addSibling(TreeNode *node)
{
    if (sibling == nullptr) {
        sibling = node;
        return;
    }
    auto cur = sibling;
    while (cur->sibling != nullptr) {
        cur = cur->sibling;
    }
    cur->sibling = node;
}


StatementNode::StatementNode(int lineno, StatementType type, std::initializer_list<TreeNode *> children)
    : TreeNode(lineno, NODE_STATMENT), type(type)
{
    for( auto elem : children )
        this->addChild(elem);
}

FuncStatementNode::FuncStatementNode(int lineno, Callable *symbol, std::initializer_list<TreeNode*> children) : StatementNode (lineno, ST_FUNCTION, children)
{
    this->symbol = symbol;
}


DeclarationNode::DeclarationNode(int lineno, Symbol *symbol)
    : TreeNode(lineno, NODE_DECLARATION)
{
    this->symbol = symbol;
}

ExprNode::ExprNode(int lineno, Symbol *symbol)
    : TreeNode(lineno, NODE_EXPRESSION)
{
    this->symbol = symbol;
}

ExprNode::ExprNode(int lineno, Symbol::ValueType type, string value, bool isConstant)
    : TreeNode(lineno, NODE_EXPRESSION)
{
    if (isConstant)
        this->symbol = new Constant(type, value);
    else
        this->symbol = new Variable(type, value);
}

string OperatorNode::getTypeStr(OperatorNode::OperatorType type)
{
    switch (type) {

    case OP_INC: return "++";
    case OP_DEC: return "--";

    case OP_NOT: return "!";
    case OP_BREV: return "~";

    case OP_LSHFT: return "<<";
    case OP_RSHFT: return ">>";

    case OP_MUL: return "*";
    case OP_DIV: return "/";
    case OP_MOD: return "%";

    case OP_ADD: return "+";
    case OP_SUB: return "-";
    case OP_UADD: return "+";
    case OP_USUB: return "-";

    case OP_BAND: return "&";
    case OP_BXOR: return "^";
    case OP_BOR: return "|";

    case OP_LESS: return "<";
    case OP_LESSEQ: return "<=";
    case OP_MORE: return ">";
    case OP_MOREEQ: return ">=";
    case OP_EQ: return "==";
    case OP_NE: return "!=";

    case OP_LAND: return "&&";
    case OP_LOR: return "||";

    case OP_LSHFTAS: return "<<=";
    case OP_RSHFTAS: return ">>=";
    case OP_MULAS: return "*=";
    case OP_DIVAS: return "/=";
    case OP_MODAS: return "%=";
    case OP_ADDAS: return "+=";
    case OP_SUBAS: return "-=";
    case OP_BANDAS: return "&=";
    case OP_BXORAS: return "^=";
    case OP_BORAS: return "|=";
    case OP_ASSIGN: return "=";
    }
    return "unknown";
}

OperatorNode::OperatorNode(int lineno, OperatorNode::OperatorType type, std::initializer_list<TreeNode *> children)
    : ExprNode (lineno, nullptr), type(type)
{
    nodeType = NODE_OPERATOR;
    for( auto elem : children )
        this->addChild(elem);
}

EmptyNode::EmptyNode(int lineno) : TreeNode (lineno, NODE_NONE)
{

}
