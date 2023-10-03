// LetStatement.cpp:
#include "DivStatement.h"

DivStatement::DivStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value ), variable(false)
{}

DivStatement::DivStatement(std::string variableName, std::string variableAdd)
    :m_variableName(variableName), m_value(-1), variable(true), m_variableAdd(variableAdd)
{}


void DivStatement::execute(ProgramState * state, std::ostream &outf)
{
	std::map<std::string, int>* tempLetAddress = state->getMapAddress();

    //create exception for dividing by 0 and do same thing as
    //add function for variable vs int types
    if(variable){
        if ((*tempLetAddress)[m_variableAdd] == 0){
            outf << "Divide by 0 exception" << std::endl;
            state->setEnd(true);
        }
    }
    else{
        if (m_value == 0){
            outf << "Divide by 0 exception" << std::endl;
            state->setEnd(true);
        }
    }
    if ((*tempLetAddress).find(m_variableName) == (*tempLetAddress).end()){
        (*tempLetAddress)[m_variableName] = 0;
    }
    if (variable){
        (*tempLetAddress)[m_variableName] /= (*tempLetAddress)[m_variableAdd];
    }
    else{
	    (*tempLetAddress)[m_variableName] /= m_value;
    }
	int* tempCounter = state->programCounter();
	(*tempCounter)++;
}

