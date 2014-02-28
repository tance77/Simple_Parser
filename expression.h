#ifndef expression_h
#define expression_H

#include <string>
#include "gpl_type.h"

class Variable;
class Expression
{
    public:
        Expression(Variable *variable){};
        Expression(Gpl_type gType, Expression *LHS, Expression *RHS);
        Expression(Operator_type oType, Expression *LHS, Expression *RHS);
        Gpl_type getType();
        void evaluate();
    protected:
        Expression *m_LHS;
        Expression *m_RHS;
    private:
        Variable *m_vVariable;
        Operator_type m_oType;
};
class iExpression : public Expression
{
    public:
       iExpression(Gpl_type gType, Expression *LHS, Expression *RHS); 
    private:

        int mValue;
        Gpl_type m_Type;
};
class dExpression : public Expression
{
    public:
       dExpression(Gpl_type gType, Expression *LHS, Expression *RHS); 
    private:

        double mValue;
        Gpl_type m_Type;
};
class sExpression : public Expression
{
    public:
       sExpression(Gpl_type gType, Expression *LHS, Expression *RHS); 
    private:

        std::string mValue;
        Gpl_type m_Type;
};
class uExpression : public Expression
{
    public:
        uExpression(Operator_type type, Expression *LHS, Expression *RHS);

    private:

        Operator_type m_oType;
};
class bExpression : public Expression
{
    public:
        bExpression(Operator_type oType, Expression *LHS, Expression *RHS);
    private:
        Operator_type m_oType;
};
class vExpression : public Expression
{
    public:
        vExpression();
    private:
};
#endif
