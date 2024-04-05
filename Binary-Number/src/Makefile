CC=gcc
CFLAGS=-c
LDFLAGS=
SOURCES=errors/errors.c commands/commands.c arguments/arguments.c binary/binary.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=bodh

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lm -o $@

.c.o:
	$(CC) $(CFLAGS) $< -lm -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
