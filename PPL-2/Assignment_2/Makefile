
eight_queens: main.o Board.o Queen.o
	g++ main.o Board.o Queen.o -o eight_queens

main.o: main.cpp Board.h Queen.h
	g++ -c main.cpp

Board.o: Board.cpp Board.h Queen.h
	g++ -c Board.cpp

Queen.o: Queen.cpp Queen.h
	g++ -c Queen.cpp

clean:
	rm -f *.o eight_queens
