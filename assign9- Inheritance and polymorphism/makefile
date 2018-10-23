#
# PROGRAM:    assign9
# PROGRAMMER: Byron Hogan
# LOGON ID:   Z1825194
# DATE DUE:   12-05-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign9: assign9.o Circle.o Shape.o Cylinder.o Cone.o
	g++ $(CCFLAGS) -o assign9 assign9.o Circle.o Shape.o Cylinder.o Cone.o

# Rules to compile source code file to object code
assign9.o: assign9.cpp Shape.h Circle.h Cylinder.h Cone.h
	g++ $(CCFLAGS) -c assign9.cpp

Cone.o: Cone.cpp Cone.h Circle.h Shape.h
	g++ $(CCFLAGS) -c Cone.cpp

Cylinder.o: Cylinder.cpp Cylinder.h Circle.h Shape.h
	g++ $(CCFLAGS) -c Cylinder.cpp

Circle.o: Circle.cpp Circle.h Shape.h
	g++ $(CCFLAGS) -c Circle.cpp

Shape.o: Shape.cpp Shape.h
	g++ $(CCFLAGS) -c Shape.cpp		

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign9
