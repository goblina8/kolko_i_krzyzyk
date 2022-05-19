CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

__start__: sfml
	./sfml

projekt3: sfml.cpp 
	g++ -Wall -pedantic -std=c++0x -o sfml sfml.cpp -lpthread
	
sfml.o: sfml.cpp
	g++ -c ${CXXFLAGS} -o sfml.o

clean:
	rm -f *.o sfml.cpp
