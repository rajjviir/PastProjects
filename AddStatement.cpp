// LetStatement.cpp:
#include "AddStatement.h"

AddStatement::AddStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}

AddStatement::AddStatement(std::string variableName, std::string variableAdd)
    :m_variableName(variableName), m_variableAdd(variableAdd), variable(true)
{}


void AddStatement::execute(ProgramState * state, std::ostream &outf)
{
    //create ppinter to map address
    
	std::map<std::string, int>* tempLetAddress = state->getMapAddress();

    //check if variable being added exists, if it doesnt set to 0
    if ((*tempLetAddress).find(m_variableName) == (*tempLetAddress).end()){
        (*tempLetAddress)[m_variableName] = 0;
    }

    //if variable, then add
    if (variable){
        (*tempLetAddress)[m_variableName] += (*tempLetAddress)[m_variableAdd];
    }
    else{
	    (*tempLetAddress)[m_variableName] += m_value;
    }
    //iterate to next line in program
	int* tempCounter = state->programCounter();
	(*tempCounter)++;
}

