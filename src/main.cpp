#include "common.h"

TreeNode * root;
extern FILE* yyin;

void showTree(TreeNode* root) {
  if (root == nullptr) return;
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
      case StatementNode::ST_DO_WHILE:
          cout << "Do-While";
          break;
      case StatementNode::ST_WHILE:
          cout << "While";
          break;
      case StatementNode::ST_FOR:
          cout << "For";
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
  case TreeNode::NODE_DECLARATION:
      cout << "[Declaration<";
      // fall through
      [[clang::fallthrough]];
  case TreeNode::NODE_EXPRESSION:
      if(root->nodeType == TreeNode::NODE_EXPRESSION) cout << "[Expression<";
      switch (static_cast<DeclarationNode*>(root)->symbol->type) {
      case Symbol::VALUE_CHAR:
          cout << "char";
          break;
      case Symbol::VALUE_DOUBLE:
          cout << "double";
          break;
      case Symbol::VALUE_INT:
          cout << "int";
          break;
      case Symbol::VALUE_NONE:
          cout << "unknown";
          break;
      case Symbol::VALUE_STRING:
          cout << "string";
          break;
      case Symbol::VALUE_VOID:
          cout << "void";
          break;
      }
      cout << "> " <<static_cast<DeclarationNode*>(root)->symbol->value << "] ";
      break;
  case TreeNode::NODE_OPERATOR:
      cout << "[Operator ";
      cout << OperatorNode::getTypeStr(static_cast<OperatorNode*>(root)->type);
      cout << "]";
      break;

  }
  auto children = root -> child;
  if(children) {
    cout << endl << "\tChildren: ";
  }
  while (children) {
    cout << children->nodeID << " ";
    children = children -> sibling;
  }
  cout << endl;
  children = root -> child;
  while (children) {
    showTree(children);
    children = children -> sibling;
  }
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
  }

  yyparse();
  while (root) {
    showTree(root);
    root = root -> sibling;
  }
  return 0;
}
