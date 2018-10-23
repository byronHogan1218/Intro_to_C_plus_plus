#
# PROGRAM:  assign1
# PROGRAMMER: Byron Hogan
# LOGON ID: z1825194
# DATE DUE: 9/14/2017
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11
FILE = assign1Test

# Rule to link object code files to create executable file
$(FILE): $(FILE).o
	g++ $(CCFLAGS) -o $(FILE) $(FILE).o

# Rule to compile source code to object code
$(FILE).o: $(FILE).cpp
	g++ $(CCFLAGS) -c $(FILE).cpp

#Psuedo-target to remove object code and executable files
clean:
	-rm *.o $(FILE)
