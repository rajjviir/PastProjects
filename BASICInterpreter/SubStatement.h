#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class SubStatement: public Statement
{
private:
	std::string m_variableName;
    std::string m_variableAdd;
	int m_value;
	std::map<std::string, int>* tempLetAddress;
    bool variable = false;
public:
	SubStatement(std::string variableName, int value);
	SubStatement(std::string variableName, std::string variableAdd);
	~SubStatement(){};
	virtual void execute(ProgramState * state, std::ostream &outf);
};


#endif
