#
# PROGRAM:    assign2
# PROGRAMMER: Byron Hogan
# LOGON ID:   Z1825194
# DATE DUE:   9-26-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign2: assign2.o provider.o providerDB.o
	g++ $(CCFLAGS) -o assign2 assign2.o provider.o providerDB.o

# Rules to compile source code file to object code
assign2.o: assign2.cpp providerDB.h
	g++ $(CCFLAGS) -c assign2.cpp

provider.o: provider.cpp provider.h
	g++ $(CCFLAGS) -c provider.cpp

providerDB.o: providerDB.cpp providerDB.h
	g++ $(CCFLAGS) -c providerDB.cpp

# Header file dependency
providerDB.h: provider.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2
