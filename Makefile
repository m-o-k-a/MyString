CC     = gcc
CFLAGS = -std=c99 -W -Wall -Werror -pedantic -Wfatal-errors 
CFLAGS += -D_XOPEN_SOURCE=700 # we use strdup() and strndup() 
LIBS   = # -lm

EXEC= mystring
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
MODULES = $(basename $(SOURCES))
OBJECTS = $(addsuffix .o , $(MODULES))

$(EXEC): $(OBJECTS)
	@echo === LINKING $@ ===
	$(CC) $^ $(LIBS) -o $@

%.o : %.c
	@echo === COMPILING $@ ===
	$(CC) $< $(CFLAGS) -c

depend: $(SOURCES) $(HEADERS)
	@echo === COMPUTING $@ === 
	$(CC) -MM $(SOURCES) | tee $@

clean ::
	@echo === CLEANING ===
	rm -f *.o depend

-include depend
