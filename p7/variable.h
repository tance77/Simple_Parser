#ifndef variable_h
#define variable_h

#include <string>
#include "gpl_type.h"
#include "symbol.h"


class Expression;
class Symbol;
class Variable
{
public:
    ~Variable();
    Variable();
    Variable(Symbol *s); //VARIABLE
    Variable(std::string value, Expression *e); //EXPRESSION
                                                //  Variable(std::string GameObject_Name, std::string MemberName); //GAME OBJECT
                                                //  Variable(std::string name, Animation_block *animate); //ANIMATION BLOCK
    Variable(Symbol *s, std::string); //Symbol with variable EX j.x
    Variable(Expression * e, std::string id, std::string memberID); //Expression Member Variable EX j[10].x expr
    Gpl_type gettype();
    void evaluate();
    int getiValue();
    double getdValue();
    std::string getsValue();
    Animation_block* getAnimate();
    void set(int);
    void set(double);
    void set(std::string);
    void set(Game_object*);
private:
    int m_iValue;
    double m_dValue;
    std::string m_sValue;
    Gpl_type m_Type;
    Symbol *m_Symbol;
    Variable *m_Variable;
    Expression *m_Expression;
    Animation_block *m_AnimatiomBlock;
    std::string m_MemberName;
};
#endif
