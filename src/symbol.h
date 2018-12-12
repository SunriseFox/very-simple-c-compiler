#ifndef SYMBOL_H
#define SYMBOL_H

#include "pch.h"

using namespace std;

class ExprNode;

class Symbol {

public /* types */:

    enum ValueType {
        VALUE_NONE,
        VALUE_VOID,
        VALUE_INT,
        VALUE_DOUBLE,
        VALUE_STRING,
        VALUE_CHAR,
        VALUE_ERROR
    };

    enum SymbolType {
        SYMBOL_CONSTANT,
        SYMBOL_VARIABLE,
        SYMBOL_CALLABLE,
        SYMBOL_OPNODE,
    };

    static string getSymbolName(Symbol* s);

public:

    ValueType type;
    string value;
    SymbolType symbolType;

    protected:

        Symbol(ValueType type, string value, SymbolType symbolType);

};

class Constant : public Symbol {

public:

    Constant(ValueType type, string value);

};

class Variable : public Symbol {

public:

    Variable(ValueType type, string value);

};

class Callable : public Symbol {

public:

    Callable(ValueType type, string value);

};

class OpNode : public Symbol {

public:

    OpNode(ValueType type, string value);

};

#endif // + SYMBOL_H
