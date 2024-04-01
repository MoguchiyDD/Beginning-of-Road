CC=gcc
CFLAGS=-c  # -Wall
LDFLAGS=
SOURCES=commands/commands.c binary/binary.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=bodh

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -lm -o $@

.c.o:
	$(CC) $(CFLAGS) $< -lm -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
