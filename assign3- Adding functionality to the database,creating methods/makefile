#
# PROGRAM:    assign3
# PROGRAMMER: Byron Hogan
# LOGON ID:   Z1825194
# DATE DUE:   9-26-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign3: assign3.o provider.o providerDB.o
	g++ $(CCFLAGS) -o assign3 assign3.o provider.o providerDB.o

# Rules to compile source code file to object code
assign3.o: assign3.cpp providerDB.h
	g++ $(CCFLAGS) -c assign3.cpp

provider.o: provider.cpp provider.h
	g++ $(CCFLAGS) -c provider.cpp

providerDB.o: providerDB.cpp providerDB.h
	g++ $(CCFLAGS) -c providerDB.cpp

# Header file dependency
providerDB.h: provider.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign3
