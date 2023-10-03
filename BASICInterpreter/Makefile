# all:.dirstamp Interpreter

# Interpreter: Interpreter.cpp Statement.o LetStatement.o PrintStatement.o ProgramState.o AddStatement.o DivStatement.o EndStatement.o GoSubStatement.o GoToStatement.o IfThenStatement.o MultStatement.o PrintAllStatement.o ReturnStatement.o SubStatement.o
#     g++ -Wall -std=c++11 -g -c Interpreter.cpp -o Interpreter.o

# AddStatement.o: AddStatement.h AddStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c AddStatement.cpp -o AddStatement.o

# DivStatement.o: DivStatement.h DivStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c DivStatement.cpp -o DivStatement.o

# EndStatement.o: EndStatement.h EndStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c EndStatement.cpp -o EndStatement.o

# GoSubStatement.o: GoSubStatement.h GoSubStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c GoSubStatement.cpp -o GoSubStatement.o

# GoToStatement.o: GoToStatement.h GoToStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c GoToStatement.cpp -o GoToStatement.o

# IfThenStatement.o: IfThenStatement.h IfThenStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c IfThenStatement.cpp -o IfThenStatement.o

# LetStatement.o: LetStatement.h LetStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c LetStatement.cpp -o LetStatement.o

# MultStatement.o: MultStatement.h MultStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c MultStatement.cpp -o MultStatement.o

# PrintAllStatement.o: PrintAllStatement.h PrintAllStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c PrintAllStatement.cpp -o PrintAllStatement.o

# PrintStatement.o: PrintStatement.h PrintStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c PrintStatement.cpp -o PrintStatement.o

# ProgramState.o: ProgramState.h ProgramState.cpp Statement.h
# 	g++ -Wall -std=c++11 -g -c ProgramState.cpp -o ProgramState.o

# ReturnStatement.o: ReturnStatement.h ReturnStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c ReturnStatement.cpp -o ReturnStatement.o

# SubStatement.o: SubStatement.h SubStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c SubStatement.cpp -o SubStatement.o


# .PHONY: clean
# clean:
# 	rm -rf *.o

# .dirstamp:
# 	rm -rf *.o


# # List of object files
# OBJS = Interpreter.o Statement.o LetStatement.o PrintStatement.o ProgramState.o AddStatement.o DivStatement.o EndStatement.o GoSubStatement.o GoToStatement.o IfThenStatement.o MultStatement.o PrintAllStatement.o ReturnStatement.o SubStatement.o

# # Main target
# all: Interpreter

# Interpreter: $(OBJS)
# 	g++ -Wall -std=c++11 -g $(OBJS) -o Interpreter

# # Object file dependencies
# Statement.o: Statement.h Statement.cpp
# 	g++ -Wall -std=c++11 -g -c Statement.cpp -o Statement.o

# LetStatement.o: LetStatement.h LetStatement.cpp ProgramState.h Statement.h
# 	g++ -Wall -std=c++11 -g -c LetStatement.cpp -o LetStatement.o

# # Add other object file rules similarly

# # Clean rule
# .PHONY: clean
# clean:
# 	rm -rf *.o Interpreter

# .dirstamp:
# 	rm -rf *.o



CXX = g++
CPPFLAGS = -g -Wall -Ilib

all: interpreter
OBJS = LetStatement.o EndStatement.o PrintStatement.o ProgramState.o PrintAllStatement.o AddStatement.o MultStatement.o SubStatement.o DivStatement.o GoSubStatement.o GoToStatement.o ReturnStatement.o IfThenStatement.o

all: interpreter

# Link object files to create the executable
interpreter: Interpreter.cpp $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@

ProgramState.o: ProgramState.cpp ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

LetStatement.o: LetStatement.cpp LetStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

EndStatement.o: EndStatement.cpp EndStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

PrintStatement.o: PrintStatement.cpp PrintStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

PrintAllStatement.o: PrintAllStatement.cpp PrintAllStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

SubStatement.o: SubStatement.cpp SubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

AddStatement.o: AddStatement.cpp AddStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
DivStatement.o: DivStatement.cpp DivStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

MultStatement.o: MultStatement.cpp MultStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

ReturnStatement.o: ReturnStatement.cpp ReturnStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

GoSubStatement.o: GoSubStatement.cpp GoSubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

GoToStatement.o: GoToStatement.cpp GoToStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

IfThenStatement.o: IfThenStatement.cpp IfThenStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@


# Clean up object files and the executable
.PHONY: clean
clean:
	rm -rf *.o

