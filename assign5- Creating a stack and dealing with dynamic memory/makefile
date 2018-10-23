#
# PROGRAM:    assign5
# PROGRAMMER: Byron Hogan
# LOGON ID:   Z1825194
# DATE DUE:   10-19-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign5: assign5.o stack.o
	g++ $(CCFLAGS) -o assign5 assign5.o stack.o

# Rules to compile source code file to object code
assign5.o: assign5.cpp Stack.h
	g++ $(CCFLAGS) -c assign5.cpp

stack.o: stack.cpp Stack.h
	g++ $(CCFLAGS) -c stack.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign5
