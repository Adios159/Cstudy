CC = gcc
CFLAGS = -Wall -g

TARGET = topologicalsort

OBJS = main.o graph.o linked_list.o TopologicalSort.o common.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c TopologicalSort.h
	$(CC) $(CFLAGS) -c main.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c

linked_list.o: linked_list.c linked_list.h graph.h
	$(CC) $(CFLAGS) -c linked_list.c

TopologicalSort.o: TopologicalSort.c TopologicalSort.h
	$(CC) $(CFLAGS) -c TopologicalSort.c

common.o: common.c common.h
	$(CC) $(CFLAGS) -c common.c

clean:
	rm -f $(TARGET) $(OBJS)
