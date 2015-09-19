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
SOURCES = main.cpp 

# everything inside include/
_DEPH = Debug.h Engine.h FiniteStateMachine.h Mob.h
# grabbing the complimentary .cpp files for the headers
_DEPSRC = $(FILES:.h=.cpp)
# combining into one variable
DEPS = $(DEPH) $(DEPSRC) 

# include/ filenames with directory
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# all files
FILES = $(SOURCES) $(DEPS)

# .o filenames with directory
OBJS = $(FILES:.cpp=.o)

# the linker flags for the compiler
LINKER_FLAGS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread

# the output file
LINUX_BIN = run.out

#Compile(output into error.txt if there is an error), link, then run
linux:
	$(CC) $(CFLAGS) -c $(FILES) 2>$(DDIR)/errors.txt
	$(CC) $(CFLAGS) $(OBJS) -o $(BDIR)/$(LINUX_BIN) $(LINKER_FLAGS)