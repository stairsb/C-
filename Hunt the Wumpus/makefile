CC = g++
exe_file = prog3
$(exe_file): driver.o event.o wumpus.o bat.o pit.o gold.o room.o play.o
	$(CC) driver.o event.o wumpus.o bat.o pit.o gold.o room.o play.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
event.o: event.cpp
	$(CC) -c event.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
bat.o: bat.cpp
	$(CC) -c bat.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
room.o: room.cpp
	$(CC) -c room.cpp
play.o: play.cpp
	$(CC) -c play.cpp
clean:
	rm -f *.out *.o $(exe_file)