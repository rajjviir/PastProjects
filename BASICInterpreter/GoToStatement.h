 #ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class GoToStatement: public Statement
{
private:
	int m_lineNum;
	int* tempCounter;
public:
	GoToStatement(int lineNum);
	~GoToStatement(){};

	virtual void execute(ProgramState * state, std::ostream &outf);
};


#endif
