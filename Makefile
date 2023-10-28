bin/ship : src/ship.cpp include/*
	c++ src/ship.cpp -o bin/ship -I include -lcurses

run : bin/ship
	./bin/ship