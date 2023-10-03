// LetStatement.cpp:
#include "LetStatement.h"

LetStatement::LetStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState * state, std::ostream &outf)
{
	std::map<std::string, int>* tempLetAddress = state->getMapAddress();

	//let the map value equal new value inputted
	(*tempLetAddress)[m_variableName] = m_value;
	// TODO
	//move to next line
	int* tempCounter = state->programCounter();
	(*tempCounter)++;
}

