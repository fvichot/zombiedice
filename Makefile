CC=`which g++`
LD=`which g++`
RM=`which rm` -f
MV=`which mv`

INCDIR = include
SRCDIR = src
OBJDIR = obj
BINDIR = bin
SRC    = $(wildcard $(SRCDIR)/*.cpp)
OBJ    = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRC:.cpp=.o))
TARGET = zombiedice
CFLAGS = -Wall -Wextra -pedantic -g -I$(INCDIR)
LFLAGS = $(shell sdl-config --libs) -lSDL_image -lGL -lGLU -lm

all : $(BINDIR)/$(TARGET)

objects : $(OBJ)

$(BINDIR)/$(TARGET) : $(OBJ)
	@echo -n "+ Linking" $@"..."
	@$(LD) $(LFLAGS) $^ -o $@
	@echo " done."

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@echo -n "- Compiling" $<"..."
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo " done."

exe :
	$(BINDIR)/$(TARGET)

clean :
	@$(RM) *~ $(BINDIR)/$(TARGET) $(INCDIR)/*~ $(SRCDIR)/*~ $(OBJDIR)/*.o


