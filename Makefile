CFLAGS = -Wall

all: heap.h heap.o p_queue.h p_queue.o main.c
	gcc $(CFLAGS) heap.o p_queue.o main.c -o priorityqueue

clean:
	rm *.o *~ priorityqueue
