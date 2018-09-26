#include "token.h"
using std::string;
using std::ostream;

void Token::freeUnion()
{
    switch(tok){
        case STR: svar.std::string::~string(); break;
        case SD: sdvar.~Sales_data(); break;
    }
}

Token& Token::operator=(int i)
{
    freeUnion();
    tok = INT;
    ivar = i;
    return *this;
}

Token& Token::operator=(char c)
{
    freeUnion();
    tok = CHAR;
    cvar = c;
    return *this;
}

Token& Token::operator=(double d)
{
    freeUnion();
    tok = DBL;
    dvar = d;
    return *this;
}

Token& Token::operator=(const string& s)
{
    if (tok == STR)
        svar = s;
    else
        new(&svar) string(s);
    tok = STR;
    return *this;
}

Token& Token::operator=(const Sales_data& sd)
{
    if (tok == SD)
        sdvar = sd;
    else
        new(&sdvar) Sales_data(sd);
    tok = SD;
    return *this;
}

void Token::copyUnion(const Token& t)
{
    switch(t.tok){
        case INT: ivar = t.ivar; break;
        case CHAR: cvar = t.cvar; break;
        case DBL: dvar = t.dvar; break;
        case STR: new(&svar) string(t.svar); break;
        case SD: new(&sdvar) Sales_data(t.sdvar); break;
    }
}

void Token::moveUnion(Token&& t)
{
    switch(t.tok){
        case INT: ivar = std::move(t.ivar); break;
        case CHAR: cvar = std::move(t.cvar); break;
        case DBL: dvar = std::move(t.dvar); break;
        case STR: new(&svar) string(std::move(t.svar)); break;
        case SD: new(&sdvar) Sales_data(std::move(t.sdvar)); break;
    }
}

Token& Token::operator=(const Token& t)
{
    if (tok == STR && t.tok != STR) svar.~string();
    if (tok == SD && t.tok != SD) sdvar.~Sales_data();
    if (tok == STR && t.tok == STR)
        svar = t.svar;
    else if (tok == SD && t.tok == SD)
        sdvar = t.sdvar;
    else
        copyUnion(t);
    tok = t.tok;
    return *this;
}

Token& Token::operator=(Token&& t) noexcept // Hints: noexcept在函数的声明、实现都要加入
{
    if (this != &t)     // Hints: 这里对象没有实现比较，应该用地址比较
    {
        freeUnion();
        moveUnion(std::move(t));
        tok = t.tok;
    }

    return *this;
}

ostream& operator<<(ostream& os, const Token& t)
{
    switch(t.tok)
    {
        case Token::INT: os << t.ivar; break;
        case Token::CHAR: os << t.cvar; break;
        case Token::DBL: os << t.dvar; break;
        case Token::STR: os << t.svar; break;
        case Token::SD: os << t.sdvar; break;
    }
    return os;
}