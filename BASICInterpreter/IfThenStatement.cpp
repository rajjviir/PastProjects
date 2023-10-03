// LetStatement.cpp:
#include "IfThenStatement.h"

IfThenStatement::IfThenStatement(int value, std::string variableName, std::string typeOperator, int lineNum)
: m_value(value), m_variableName(variableName), m_typeOperator(typeOperator), m_lineNum(lineNum)
{}

void IfThenStatement::execute(ProgramState * state, std::ostream &outf)
{
	//create pointer to map and program line
	std::map<std::string, int>* tempLetAddress = state->getMapAddress();
	int temp = (*tempLetAddress)[m_variableName];
	int* tempCounter = state->programCounter();
	bool equationPassed = false;
	bool goodJump = true;

	//use good jump to see if jump is valid
	if (m_lineNum > state->getNumLines()){
		goodJump = false;
	}

	//if else branch to determine what operator is being used
	if(m_typeOperator == "<"){
		if (temp < m_value){
			equationPassed = true;
			(*tempCounter) = m_lineNum;
		}
	}
	else if(m_typeOperator == ">"){
		if (temp > m_value){
			equationPassed = true;
			(*tempCounter) = m_lineNum;
		}
	}
	else if(m_typeOperator == "<="){
		if(temp <= m_value){
			equationPassed = true;
			(*tempCounter) = m_lineNum;
		}
	}
	else if(m_typeOperator == ">="){
		if(temp >= m_value){
			equationPassed = true;
			(*tempCounter) = m_lineNum;
		}
	}
	else if(m_typeOperator == "="){
		if((temp == m_value)){
			equationPassed = true;
			(*tempCounter) = m_lineNum;
		}
	}
	else if(m_typeOperator == "<>"){
		if(temp != m_value){
			equationPassed = true;
			(*tempCounter) = m_lineNum;
		}
	}

	//use if else branch to move to next line or terminate 
	//with illegal jump based on whether equation and jump
	//is valid
	if (!goodJump && !equationPassed){
		(*tempCounter)++;
	}

	if (goodJump == false && equationPassed == true){
		outf << "Illegal jump instruction" << std::endl;
		state->setEnd(true);
	}

	if (goodJump && !equationPassed){
		(*tempCounter)++;
	}
}

