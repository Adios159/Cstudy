CC = gcc
CFLAGS = -Wall -g

TARGET = graph

OBJS = main.o graph.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c graph.h
	$(CC) $(CFLAGS) -c main.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c

clean:
	rm -f $(TARGET) $(OBJS)
