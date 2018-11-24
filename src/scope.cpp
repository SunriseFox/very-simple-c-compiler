#include "scope.h"

ScopeNode::ScopeNode(int lineno, const string &name, Symbol *symbol) : lineno(lineno), name(name), symbol(symbol)
{

}

Scope::Scope()
{
    this->pushScope();
}

Symbol *Scope::findSymbol(const string &name)
{
    for (const auto& l: scopeStack) {
        for (const auto& n: l) {
            if(n.name == name)
                return n.symbol;
        }
    }
    return nullptr;
}

bool Scope::insertSymbol(const string &name, int lineno, Symbol *symbol)
{
    auto& current = scopeStack.front();
    for (const auto& n: current) {
        if(n.name == name)
            return false;
    }
    current.push_back(ScopeNode(lineno, name, symbol));
    return true;
}

void Scope::pushScope()
{
    scopeStack.push_front(ScopeList());
}

void Scope::popScope()
{
    scopeStack.pop_front();
}
