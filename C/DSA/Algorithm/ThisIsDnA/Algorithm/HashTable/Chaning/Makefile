CC = gcc
CFLAGS = -Wall -g

TARGET = Chaining

OBJS = main.o Chaining.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c Chaining.h
	$(CC) $(CFLAGS) -c main.c

Chaining.o: Chaining.c Chaining.h
	$(CC) $(CFLAGS) -c Chaining.c

clean:
	rm -f $(TARGET) $(OBJS)
