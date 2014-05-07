#include "variable.h"
#include "expression.h"
#include "gpl_assert.h"
#include "error.h"
#include "symbol_table.h"

Symbol_table* TheTable = Symbol_table::instance();

Variable::Variable(Symbol *target) //default add symbol to table int double strin
{
    m_MemberName = ""; //when would this have a member name?
    if(target != NULL){
        m_Expression = NULL;
        m_Symbol = target;
        m_Type = m_Symbol->getType();
        if(m_Symbol->getType() == ANIMATION_BLOCK)
        {
            m_AnimatiomBlock = m_Symbol->getanimationValue();
        }
    }
    else {
        //WTF goes here?
    }
}
Variable::Variable(std::string value, Expression *e) //array
{
    m_AnimatiomBlock = NULL;
    m_MemberName = "";
    m_Symbol = NULL;
    if(e->get_gType()== INT){
        m_sValue = value;
        Symbol *tmp_Symbol = TheTable->lookup(value + "[0]");
        if(tmp_Symbol == NULL){
            // if we can't find name [0], then this variable needs to reference
            // a dummy symbol
            m_Symbol = new Symbol(INT, value, 0);
            m_Expression = new Expression(0, INT);
            Error::error(Error::VARIABLE_NOT_AN_ARRAY, value);
        }
        else{
            m_Expression = e;
            m_Type = tmp_Symbol->getType();
        }
    }
    else if(e->get_gType() == DOUBLE){
        ostringstream ss;
        ss << e->evaldouble();
        m_sValue = value;
        Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, value, "A double expression");
        m_Symbol = new Symbol(INT, value, 0);
        m_Expression = new Expression(0, INT);
        m_Type = INT;

    }
    else if (e->get_gType() == STRING){
        Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, value, "A string expression");
        m_sValue = value;
        m_Symbol = new Symbol(INT, value, 0);
        m_Expression = new Expression(0, INT);
        m_Type = INT;
    }
}
Variable::Variable(Symbol *sym, std::string memberID) //EX J.x
{

    m_iValue = 0;
    m_dValue = 0;
    m_sValue = "EMPTY";
    if(sym != NULL){
        m_Symbol = sym;
        m_MemberName = memberID;
        m_Expression = NULL;
        m_AnimatiomBlock = NULL;

        // get type of the "m_MemberName" field of the game object

        Game_object *game_object = m_Symbol->getgameobjectValue();
        assert(game_object);
        Status result = game_object->get_member_variable_type(m_MemberName, m_Type);
        assert(result == OK);
        // m_Type = m_Symbol->getType();
    }
    else {
        //WTF goes here?
    }
}
Variable::Variable(Expression *e, std::string ID, std::string memberID)//EX J[10].x
{
    m_MemberName = memberID;
    m_AnimatiomBlock = NULL;
    m_Symbol = NULL;
    if(e->get_gType()== INT){
        m_sValue = ID;
        Symbol *tmp_Symbol = TheTable->lookup(ID + "[0]");
        if(tmp_Symbol == NULL){
            // if we can't find name [0], then this variable needs to reference
            // a dummy symbol
            m_Symbol = new Symbol(INT, ID, 0);
            m_Expression = new Expression(0, INT);
            Error::error(Error::VARIABLE_NOT_AN_ARRAY, ID);
        }
        else{
            m_Expression = e;
            // m_Type = tmp_Symbol->getType();

            Game_object *game_object = tmp_Symbol->getgameobjectValue();
            assert(game_object);
            Status result = game_object->get_member_variable_type(m_MemberName, m_Type);
            assert(result == OK);
        }
    }
    else if(e->get_gType() == DOUBLE){
        ostringstream ss;
        ss << e->evaldouble();
        m_sValue = ID;
        Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, ID, "A double expression");
        m_Symbol = new Symbol(INT, ID, 0);
        m_Expression = new Expression(0, INT);
        m_Type = INT;

    }
    else if (e->get_gType() == STRING){
        Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, ID, "A string expression");
        m_sValue = ID;
        m_Symbol = new Symbol(INT, ID, 0);
        m_Expression = new Expression(0, INT);
        m_Type = INT;
    }
}

void Variable::update_symbol() //for an array
{
    if(m_Expression != NULL)
      {
        stringstream ss;
        ss << m_Expression->evalint();
        m_Symbol = TheTable->lookup(m_sValue + '[' + ss.str() + ']');
        if(m_Symbol== NULL)
          {
            stringstream ss2;
            ss2 << m_Expression->evalint();
            Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_sValue, ss2.str());
            m_Symbol = TheTable->lookup(m_sValue + "[0]");
          }
      }
}

int Variable::getiValue()
{
    update_symbol();
    {
        if(m_MemberName != "")
        {
            Game_object *tmp = m_Symbol->getgameobjectValue();
            int val;
            tmp->get_member_variable(m_MemberName, val);
            return val;
        }
        else
          {
            if(m_Symbol->getType() == INT)
                return m_Symbol->getintValue();
            else if(m_Symbol->getType() == DOUBLE) //error
                return -1;
            else //you are a string error
                
                return -1;
          }
    }
    return 0;
}
double Variable::getdValue()
{
    update_symbol();
    {
        if(m_MemberName != "")
        {
            Game_object *tmp = m_Symbol->getgameobjectValue();
            assert(m_Symbol->getgameobjectValue());
            double val;
            tmp->get_member_variable(m_MemberName, val);
          cout << val << endl;
          cout << m_MemberName << endl;
            return val;
        }
        else
        {
            if(m_Symbol->getType() == INT)
                return m_Symbol->getintValue();
            else if(m_Symbol->getType() == DOUBLE)
                return m_Symbol->getdoubleValue();
            else //you are a string //error
                return -1;
        }
    }
    return 0;
}
std::string Variable::getsValue()
{
    update_symbol();
    if(m_Symbol){
        if(m_MemberName != "")
        {
            Game_object *tmp = m_Symbol->getgameobjectValue();
            string val;
            tmp->get_member_variable(m_MemberName, val);
            return val;
        }
        else
        {
            if(m_Symbol->getType() == INT)
            {
                stringstream s;
                s << m_Symbol->getintValue();
                return s.str();
            }
            else if(m_Symbol->getType() == DOUBLE)
            {
                stringstream s;
                s<< m_Symbol->getdoubleValue();
                return s.str();
            }
            else //you are a string
                return m_Symbol->getstringValue();
        }
    }
    return "";
}
Gpl_type Variable::gettype()
{
    return m_Type;
}
Animation_block* Variable::getAnimate()
{
    update_symbol();
    return m_Symbol->getanimationValue();
}
void Variable::set(int value)
{
    update_symbol();
    {
        if(m_MemberName != "")
        {
            Game_object *tmp = m_Symbol->getgameobjectValue();
            tmp->set_member_variable(m_MemberName,value);
        }
        else
        {
            if(m_Symbol->getType() == INT)
                m_Symbol->set(value);
            else if(m_Symbol->getType() == DOUBLE){} //error
                //
                else {}//you are a string error
                //
        }
    }
}
void Variable::set(double value)
{
    update_symbol();
    {
        if(m_MemberName != "")
        {
            Game_object *tmp = m_Symbol->getgameobjectValue();
            tmp->set_member_variable(m_MemberName, value);
        }
        else
        {
            if(m_Symbol->getType() == INT)
                m_Symbol->set(value);
            else if(m_Symbol->getType() == DOUBLE) //error
                m_Symbol->set(value);
            else{}
        }
    }
}
void Variable::set(std::string value)
{
    update_symbol();
    {
        if(m_MemberName != "")
        {
            Game_object *tmp = m_Symbol->getgameobjectValue();
            tmp->set_member_variable(m_MemberName, value);
        }
        m_Symbol->set(value);
    }
}
void Variable::set(Game_object *value)
{
    update_symbol();
    assert(value);
    m_Symbol->set(value);
}
void Variable::set(Animation_block *value)
{
    update_symbol(); //This is to pass the test 4 EX circles[index].animation_block = move;
    m_Symbol->getgameobjectValue()->set_member_variable("animation_block", value);
}
Symbol* Variable::get_symbol()
{
    update_symbol(); //this is the one we needed to do to pass the tests in the 20's for p8
    return m_Symbol;
}
Expression* Variable::get_expression()
{
    if(m_Expression == NULL)
        return NULL;
    return m_Expression;
}
std::string Variable::getVariableName()
{
    update_symbol();
    return m_Symbol->getID();
}
