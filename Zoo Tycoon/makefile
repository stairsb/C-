CC = g++
exe_file = project
$(exe_file): zoo.o animal.o tiger.o sealion.o bear.o driver.o
	$(CC) zoo.o animal.o tiger.o sealion.o bear.o driver.o -o $(exe_file)
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
animal.o: animal.cpp
	$(CC) -c animal.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
sealion.o: sealion.cpp
	$(CC) -c sealion.cpp
bear.o: bear.cpp
	$(CC) -c bear.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)