# compiler
CC = g++
# compiler flags
CFLAGS = -std=c++11 -Wall
 
# .cpp files
SOURCES = main.cpp
# .h files
DEPS = helpers/dataStructures/FiniteStateMachine.h modules/engine/Engine.h

# combines both sources and deps into one variable
FILES = $(SOURCES) $(DEPS)
 
# the linker flags for the compiler
LINKER_FLAGS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread
 
# gets the object file names by simply replacing .cpp with .o
OBJS = $(FILES:.cpp=.o)
 
# the output file
LINUX_BIN = run.out
 
#Compile(output into error.txt if there is an error), link, then run
linux:
	$(CC) $(CFLAGS) -c $(FILES)
	$(CC) $(CFLAGS) $(OBJS) -o $(LINUX_BIN) $(LINKER_FLAGS)