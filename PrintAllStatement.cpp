// PrintStatement.cpp:
#include "PrintAllStatement.h"

PrintAllStatement::PrintAllStatement()
{}


void PrintAllStatement::execute(ProgramState * state, std::ostream &outf)
{
	std::map<std::string, int>* tempPrintAddress = state->getMapAddress();
	
	//use map iterator to print all values stored in map with first and second
  	for (std::map<std::string,int>::iterator it=(*tempPrintAddress).begin(); it!=(*tempPrintAddress).end(); it++){
		outf << it->first << " " << it->second << std::endl;
	}

	int* tempCounter = state->programCounter();
	(*tempCounter)++;
}
