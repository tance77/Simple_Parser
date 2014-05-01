#include "event_manager.h"
#include "gpl_assert.h"
#include "statement_block.h"
using namespace std;

/* static */ Event_manager *Event_manager::m_instance = 0;

/* static */ Event_manager * Event_manager::instance()
{
    if (!m_instance)
        m_instance = new Event_manager();
    return m_instance;
}

Event_manager::Event_manager()
{
}

Event_manager::~Event_manager()
{
}


void Event_manager::execute_handlers(Window::Keystroke keystroke)
{
    for(vector<Statement_block*>::iterator it = array_of_statement_blocks[keystroke].begin();
        it != array_of_statement_blocks[keystroke].end(); it++){
        (*it)->execute();
    }
    
        //array_of_statement_blocks[keystroke] is the vector adding the [i] is the index to the vector
        //    for(int i=0; i < array_of_statement_blocks[keystroke].size(); i++){
        //        array_of_statement_blocks[keystroke][i]->execute();
        //}
}
    //put the statements in the actual vector here?
void Event_manager::register_handlers(Window::Keystroke keystroke, Statement_block *stmt)
{
    assert(stmt);
    array_of_statement_blocks[keystroke].push_back(stmt);
}