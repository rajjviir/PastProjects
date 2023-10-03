// LetStatement.cpp:
#include "MultStatement.h"

MultStatement::MultStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}

MultStatement::MultStatement(std::string variableName, std::string variableAdd)
    :m_variableName(variableName), m_variableAdd(variableAdd), variable(true)
{}


void MultStatement::execute(ProgramState * state, std::ostream &outf)
{
    //same as divide and add functions, with check for existing number
	std::map<std::string, int>* tempLetAddress = state->getMapAddress();
    if ((*tempLetAddress).find(m_variableName) == (*tempLetAddress).end()){
        (*tempLetAddress)[m_variableName] = 0;
    }
    if (variable){
        (*tempLetAddress)[m_variableName] *= (*tempLetAddress)[m_variableAdd];
    }
    else{
	    (*tempLetAddress)[m_variableName] *= m_value;
    }
	int* tempCounter = state->programCounter();
	(*tempCounter)++;
}

