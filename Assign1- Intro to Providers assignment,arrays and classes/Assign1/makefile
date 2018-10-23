#
# PROGRAM:    assign1
# PROGRAMMER: Kevin Kang
# LOGON ID:   z1837081
# DATE DUE:   Thursday, 9/14/2017 by 11:59 pm
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rule to compile source code file to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1
