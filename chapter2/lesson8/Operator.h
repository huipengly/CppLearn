
#ifndef __OPERATOR_H
#define __OPERATOR_H

class Operator
{
private:
    char mOp;
    int mP1;
    int mP2;

public:
    bool setOperator(char op);
    void setParameter(int p1, int p2);
    bool result(double& r);
};

#endif
