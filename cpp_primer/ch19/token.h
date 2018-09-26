#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>
#include "Sales_data.h"

class Token{
public:
    Token() : tok(INT), ivar(0) {}
    Token(const Token& t) : tok(t.tok) { copyUnion(t); }
    Token(Token&& t) noexcept : tok(std::move(t.tok)) { moveUnion(std::move(t)); }
    Token &operator=(const Token&);
    Token &operator=(Token &&) noexcept;
    ~Token() { freeUnion(); }

    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);        // Hints: 基础类型不用常量引用
    Token &operator=(const std::string&);
    Token &operator=(const Sales_data&);

private:
    enum {INT, CHAR, DBL, STR, SD} tok;
    union{
        char cvar;
        int ivar;
        double dvar;
        std::string svar;
        Sales_data sdvar;
    };
    void copyUnion(const Token&);
    void moveUnion(Token &&);
    void freeUnion();
};

#endif