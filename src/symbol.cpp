#include "symbol.h"

Symbol::Symbol(Symbol::ValueType type, std::string value, SymbolType symbolType)
    : type(type), value(value), symbolType(symbolType)
{

}


Constant::Constant(Symbol::ValueType type, string value)
    : Symbol (type, value, SYMBOL_CONSTANT)
{

}

Variable::Variable(Symbol::ValueType type, string value)
    : Symbol (type, value, SYMBOL_VARIABLE)
{

}

Callable::Callable(Symbol::ValueType type, string value)
    : Symbol (type, value, SYMBOL_CALLABLE)
{

}
