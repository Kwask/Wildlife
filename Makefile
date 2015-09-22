# compiler
CC = g++
# compiler flags
CFLAGS = -std=c++11 -Wall

# the different directories
IDIR = ./include
ODIR = ./obj
DDIR = ./doc
BDIR = ./bin

# top level files
SRC = main.cpp 

# all .h files without directory
_DEPH = Debug.h Engine.h State.h EngineStates.h FiniteStateMachine.h EngineStateMachine.h Mob.h GLFWFuncs.h Coord.h
# all .cpp files without directory
_DEPSRC = $(_DEPH:.h=.cpp)

# all .h files with directory
DEPH = $(patsubst %,$(IDIR)/%,$(_DEPH))
# all .cpp files with directory
DEPSRC = $(patsubst %,$(IDIR)/%,$(_DEPSRC))

# all source files without directory and all header files with directory
_FILES = $(SRC) $(_DEPSRC) $(DEPH)
# all files with directory
FILES = $(SRC) $(DEPSRC) $(DEPH)

# .o filenames with directory
OBJS = $(_FILES:.cpp=.o)

# the linker flags for the compiler
LINKER_FLAGS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread

# the output file
LINUX_BIN = wildlife.out

.PHONY: clean

#Compile(output into error.txt if there is an error), link, then run
linux:
	$(CC) $(CFLAGS) -c $(FILES) 2>$(DDIR)/errors.txt
	$(CC) $(CFLAGS) $(OBJS) -o $(BDIR)/$(LINUX_BIN) $(LINKER_FLAGS)

clean:
	$(RM) -r *.o *~ *.gch *.out