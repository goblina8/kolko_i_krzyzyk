CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

__start__: projekt3
	./projekt3

projekt3: obj obj/main.o obj/functions.o obj/pole.o obj/plansza.o 
	g++ -Wall -pedantic -std=c++0x -o projekt3 obj/main.o obj/functions.o obj/pole.o obj/plansza.o -lpthread
	
obj:
	mkdir obj
	
obj/main.o: src/main.cpp inc/functions.hh inc/plansza.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/functions.o: src/functions.cpp inc/functions.hh inc/plansza.hh
	g++ -c ${CXXFLAGS} -o obj/functions.o src/functions.cpp

obj/pole.o: src/pole.cpp inc/pole.hh 
	g++ -c ${CXXFLAGS} -o obj/pole.o src/pole.cpp

obj/plansza.o: src/plansza.cpp inc/plansza.hh inc/pole.hh 
	g++ -c ${CXXFLAGS} -o obj/plansza.o src/plansza.cpp

clean:
	rm -f obj/*.o projekt3