// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{
	
}


void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	//use map address to find value to print
	//print value and then iterate to next line
	std::map<std::string, int>* tempPrintAddress = state->getMapAddress();
	int tempPrintValue = (*tempPrintAddress)[m_variableName];
	outf << tempPrintValue << std::endl;
	int* tempCounter = state->programCounter();
	(*tempCounter)++;

}