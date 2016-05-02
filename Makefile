########################################
##
## Makefile
## LINUX compilation 
##
##############################################





#FLAGS
C++FLAG = -g -std=c++0x -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.

#Default run ARGS
ARGS = Graph1.txt AdjacencyQueries1.txt


#Rule for .cpp files
# .SUFFIXES : .cpp.o 

.cpp.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@




#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#PROGRAMS
ALL_OBJ0 = CreateGraphAndTest.o
PROGRAM_0 = CreateGraphAndTest
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

ALL_OBJ1 = FindPaths.o
PROGRAM_1 = FindPaths
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)

testGraph: 	
		./$(PROGRAM_0) ${ARGS}

findPath: 	
		./$(PROGRAM_1) ${ARGS}


#Clean obj files

clean:
	(rm -f *.o; rm -f CreateGraphAndTest; rm -f FindPaths)



(:
