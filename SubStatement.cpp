// LetStatement.cpp:
#include "SubStatement.h"

SubStatement::SubStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}

SubStatement::SubStatement(std::string variableName, std::string variableAdd)
    :m_variableName(variableName), m_variableAdd(variableAdd), variable(true)
{}


void SubStatement::execute(ProgramState * state, std::ostream &outf)
{
    //same as add statement, just subtract
	std::map<std::string, int>* tempLetAddress = state->getMapAddress();
    if ((*tempLetAddress).find(m_variableName) == (*tempLetAddress).end()){
        (*tempLetAddress)[m_variableName] = 0;
    }
    if (variable){
        (*tempLetAddress)[m_variableName] -= (*tempLetAddress)[m_variableAdd];
    }
    else{
	    (*tempLetAddress)[m_variableName] -= m_value;
    }
	int* tempCounter = state->programCounter();
	(*tempCounter)++;
}

