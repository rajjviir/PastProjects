#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class AddStatement: public Statement
{
private:
	std::string m_variableName;
    std::string m_variableAdd;
	int m_value;
	std::map<std::string, int>* tempLetAddress;
    bool variable = false;
public:
	AddStatement(std::string variableName, int value);
	AddStatement(std::string variableName, std::string variableAdd);
	~AddStatement(){};

	virtual void execute(ProgramState * state, std::ostream &outf);
};


#endif
