CC = g++
exe_file = prog5
$(exe_file): linklist.o node.o driver.o
	$(CC) linklist.o node.o driver.o -o $(exe_file)
linkedlist.o: linkedlist.cpp
	$(CC) -c linkedlist.cpp
node.o: node.cpp
	$(CC) -c node.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)