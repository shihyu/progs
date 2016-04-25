#ifndef ASTNODE_H
#define ASTNODE_H

#include <vector>

#include "mytype.h"
#include "token.h"

//using std::vector;


class ASTNode
{
  public:
    ASTNode(ASTType asttype);
    //ASTNode(const ASTNode* l, const ASTNode* op, const ASTNode* r);
    ASTNode(const Token &token):token_(token)
    {
    }
    bool add_child(ASTNode* l) // for - (NEG), ex: -52
    {
      children_.push_back(l);
      return true;
    }
    bool add_child(ASTNode* l, ASTNode* r)
    {
      children_.push_back(l);
      children_.push_back(r);
      return true;
    }
    ASTType type() const
    {
      return token_.type_;
    }
    const char* type_str() const
    {
      const char *type_str[]={"INVALID", "ROOT", "SEP", "NEG", "ASSIGN", "EQUAL", "NAME", "ADD", "MIN", "MUL", "DIV", "GREAT", "LESS", "NUMBER", "STRING", "IF", "WHILE", "EOL"};

      if (INVALID <= type() && type() < LAST)
      {
        return type_str[type()];
      }
      else
      {
        return "unknown";
      }
    }

    // for tool tree to print AST
    void print_tree();
    void print();
  private:
    std::vector<ASTNode*> children_;
    Token token_;
    
};

#endif
