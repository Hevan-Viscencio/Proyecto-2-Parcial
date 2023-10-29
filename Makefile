bin/spacerace : src/spacerace.cpp include/*
	c++ src/spacerace.cpp -o bin/spacerace -I include -lcurses

run : bin/spacerace
	./bin/spacerace