# compiler
CC = g++
# compiler flags
CFLAGS = -std=c++11 -Wall

# the different directories
IDIR = ./include
ODIR = ./obj
DDIR = ./doc
BDIR = ./bin

# .cpp files
SOURCES = main.cpp 

# header filenames without directories
_DEPS = Debug.h Engine.h FiniteStateMachine.h Mob.h worldgen.h

# filenames without directories
_FILES = $(SOURCES) $(_DEPS)

# object filenames without directories
_OBJS = $(_FILES:.cpp=.o)

# header filenames with directories
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# filenames with directories
FILES = $(SOURCES) $(DEPS)

# object filenames with directories
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

# the linker flags for the compiler
LINKER_FLAGS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread

# the output file
LINUX_BIN = run.out

#Compile(output into error.txt if there is an error), link, then run
linux:
	$(CC) $(CFLAGS) -c $(FILES) 2>$(DDIR)/errors.txt
	$(CC) $(CFLAGS) $(OBJS) -o $(BDIR)/$(LINUX_BIN) $(LINKER_FLAGS)