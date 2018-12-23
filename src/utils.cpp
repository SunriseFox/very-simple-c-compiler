#include "common.h"

// need : global scope strings
// map. scope name -> symbol list

// declaration in each function
// enter function table, commit function table

// map， token name -> token name

// 生成 asm: 保护自己和所有兄弟用的寄存器

// 每个节点都应该有一个类型

int lineno  = 1;

TreeNode *root;

Scope *scope;

Callable *currFunc = nullptr;
int currFuncCount = 0;

map<Callable*, list<Symbol*>> funcTable;
