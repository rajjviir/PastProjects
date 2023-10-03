// Interpreter.cpp
#include "Statement.h"
#include "LetStatement.h"
#include "PrintStatement.h"
#include "PrintAllStatement.h"
#include "EndStatement.h"
#include "GoToStatement.h"
#include "MultStatement.h"
#include "SubStatement.h"
#include "DivStatement.h"
#include "AddStatement.h"
#include "IfThenStatement.h"
#include "ReturnStatement.h"
#include "GoSubStatement.h"

#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter BASIC program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	std::string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
{
	//create variables to take in file input
	Statement * statement;	
	stringstream ss;
	string type;
	string var;
	int val;
	int lineNumber;

	ss << line;
	ss >> lineNumber;
	ss >> type;
	
	//create if else branches for variable type to create new statements
	//specific to type
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;
		statement = new LetStatement(var, val);
	}

	else if (type == "PRINT"){
		ss >> var;

		statement = new PrintStatement(var);
	}

	else if (type == "PRINTALL"){
		statement = new PrintAllStatement();
	}

	else if (type == "ADD"){
		int addition = 0;
		string var2;
		ss >> var;
		ss >> var2;
		//create new string stream to compare if variable or int
		//for all math statements
		std::istringstream iss(var2);
		if (iss >> addition){
			statement = new AddStatement(var, addition);
		}
		else{
			statement = new AddStatement(var, var2);
		}
	}

	else if (type == "SUB"){
		int subtract = 0;
		string var2;
		ss >> var; 
		ss >> var2;
		ss >> subtract;

		std::istringstream iss(var2);
		if (iss >> subtract){
			statement = new SubStatement(var, subtract);
		}
		else{
			statement = new SubStatement(var, var2);
		}
	}

	else if (type == "MULT"){
		int mult = 0;
		string var2;
		ss >> var;
		ss >> var2;
		std::istringstream iss(var2);
		if (iss >> mult){
			statement = new MultStatement(var, mult);
		}
		else{
			statement = new MultStatement(var, var2);
		}
	}

	else if (type == "DIV"){
		int div = 0;
		string var2;
		ss >> var;
		ss >> var2;
		std::istringstream iss(var2);
		if (iss >> div){
			statement = new DivStatement(var, div);
		}
		else{
			statement = new DivStatement(var, var2);
		}
	}

	else if (type == "GOTO"){
		ss >> val;
		
		statement = new GoToStatement(val);
	}

	else if (type == "IF"){
		ss >> var; 
		std::string c_typeOperator;
		ss >> c_typeOperator;
		int c_value;
		ss >> c_value;
		std::string then;
		ss >> then;
		int c_lineNum;
		ss >> c_lineNum;
		
		statement = new IfThenStatement(c_value, var, c_typeOperator, c_lineNum);
	}

	else if (type == "PRINTALL"){
		statement = new PrintAllStatement();
	}

	else if (type == "GOSUB"){
		int c_lineNum;
		ss >> c_lineNum;
		statement = new GoSubStatement(c_lineNum);
	}

	else if (type == "RETURN"){
		statement = new ReturnStatement();
	}

	else if (type == "END" || type == "."){
		statement = new EndStatement();
	}

	// Incomplete;  TODO:  Finish this function!
	return statement;
}


void interpretProgram(istream& inf, ostream& outf){
	//create vector of statement pointers
	vector<Statement *> program;
	parseProgram( inf, program );

	//create map pointer to point at program state functions
	ProgramState *tempState = new ProgramState(program.size());
	bool endExecution = false;
	int curr = 1;
	int vectorSize = program.size();
	
	//use while loop to iterate through vector of statements
	while (curr != vectorSize && !endExecution){
		curr = *((*tempState).programCounter());
		program[curr]->execute(tempState, outf);
		curr++;
		if (tempState->isEnd()){
			endExecution = true;
		}
	}
	//deallocate vector of statement pointers
	for(size_t i = 0; i < program.size(); i++){
		delete program[i];
	}
	delete tempState;
}
