CC = g++
exe_file = assignment1
$(exe_file): assignment1.o driver.o
	$(CC) assignment1.o driver.o -o $(exe_file)
assignment1.o: assignment1.cpp
	$(CC) -c assignment1.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)