#ifndef TOKEN_H
#define TOKEN_H

#include <string>

#include "mytype.h"

class Token
{
  public:
    Token(const std::string str);
    Token(){type_ = INVALID;}
    bool valid() const
    {
      if (type_ == INVALID)
        return false;
      else
        return true;
    }
    std::string str_;
    ASTType type_;
  private:
};

extern Token invalid_token;
#endif