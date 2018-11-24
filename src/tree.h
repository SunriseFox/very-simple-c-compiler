#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "symbol.h"

using namespace std;

class TreeNode {

public /* types */:

    enum NodeType {
        NODE_NONE,
        NODE_STATMENT,
        NODE_DECLARATION,
        NODE_EXPRESSION,
        NODE_OPERATOR
    };

    static int _nodeID;

public:

    int nodeID;
    int lineno;
    NodeType nodeType;
    TreeNode* child;
    TreeNode* sibling;
    Symbol* symbol;

    void addChild(TreeNode* node);
    void addSibling(TreeNode* node);

protected:
    TreeNode(int lineno, NodeType type);

};

class StatementNode : public TreeNode {

public /* types */:

    enum StatementType {
        ST_NONE,
        ST_EMPTY,
        ST_SCOPE,
        ST_DO_WHILE,
        ST_WHILE,
        ST_FOR,
        ST_IF,
        ST_IF_ELSE,
        ST_BREAK,
        ST_CONTINUE,
        ST_GOTO
    };

public:
    StatementType type;
    StatementNode (int lineno, StatementType type, std::initializer_list<TreeNode*> children = std::initializer_list<TreeNode*>());
};

class DeclarationNode : public TreeNode {

public:

    DeclarationNode (int lineno, Symbol *symbol);

};

class ExprNode : public TreeNode {

public:

    ExprNode (int lineno, Symbol* symbol);
    ExprNode (int lineno, Symbol::ValueType type, string value, bool isConstant = false);

};

class OperatorNode: public TreeNode {

public /* types */:

    enum OperatorType {

        OP_INC,
        OP_DEC,

        OP_NOT,
        OP_BREV,

        OP_LMOVE,
        OP_RMOVE,

        OP_MUL,
        OP_DIV,
        OP_MOD,

        OP_ADD,
        OP_SUB,

        OP_BAND,
        OP_BXOR,
        OP_BOR,

        OP_LESS,
        OP_LESSEQ,
        OP_MORE,
        OP_MOREEQ,
        OP_EQ,
        OP_NE,

        OP_LAND,
        OP_LOR,

        OP_MULAS,
        OP_DIVAS,
        OP_MODAS,
        OP_ADDAS,
        OP_SUBAS,
        OP_BANDAS,
        OP_BXORAS,
        OP_BORAS,
        OP_ASSIGN
    };

public /* statics */:

    static string getTypeStr(OperatorType type);

public:

    OperatorNode(int lineno, OperatorType type, std::initializer_list<TreeNode*> children);

    OperatorType type;

};

#endif // TREE_H
