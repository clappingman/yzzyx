CC = g++

CFLAGS = -g -O3 -Wall
LDFLAGS = -g

OBJDIR = bin
SRCDIR = src
BINDIR = bin

OBJECTS = main.o
OBJECTS_W_DIR = $(OBJECTS:%=$(OBJDIR)/%)

all : yzzyx

$(OBJECTS) :
	$(CC) $(CFLAGS) -c -o $(OBJDIR)/$@ $(SRCDIR)/$*.c

yzzyx : $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(BINDIR)/$@ $(OBJECTS_W_DIR)

.PHONY : clean
clean :
	-rm $(OBJECTS_W_DIR) 
	-rm $(BINDIR)/yzzyx
