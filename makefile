main:./src/dameo.cpp ./src/move.cpp ./src/main.cpp ./src/verif.cpp ./src/game.cpp ./src/ia.cpp ./src/pile.cpp ./src/minmax.cpp ./lib/pile.h ./lib/pion.h ./lib/plateau.h
	g++ --std=c++11 ./src/dameo.cpp ./src/move.cpp ./src/main.cpp ./src/verif.cpp ./src/game.cpp ./src/pile.cpp ./src/ia.cpp ./src/minmax.cpp -o main

