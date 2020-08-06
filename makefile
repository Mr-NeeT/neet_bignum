CC = gcc
SRCDIR := src
BINDIR := bin
IDIR := inc
CFLAGS := -I$(IDIR)

ODIR := obj
LDIR := lib

LIBS := -lm

_DEPS := list.h bigint.h
DEPS := $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ := main.o list.o bigint.o
OBJ := $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	@$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS) $(LIBS)

run: main
	@$(BINDIR)/main

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 