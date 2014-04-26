#include "if_statement.h"
#include "gpl_assert.h"

If_Statement::If_Statement(Expression* expr, Statement_block* stmt_block) : Statement()
{
    if(expr != NULL || stmt_block != NULL)
      {
        assert(expr->get_gType() == INT); //assert it is of type int or its an error
        if(expr->get_gType() == INT)
          {
            m_expression = expr;
            m_stmtblock = stmt_block;
          }
        else{
                //error if not type int
        }
      }
    else{ //else the expression is null or the stmt_block is null
        
    }
}
void If_Statement::execute()
{
    if(m_expression->evalint())
        m_stmtblock->execute();
}