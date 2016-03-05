CXX=g++
CFLAGS=-Wall -c

runner: obj/runner.o obj/bettingcompany.o obj/player.o obj/customrandom.o
	$(CXX) obj/runner.o obj/bettingcompany.o obj/player.o obj/customrandom.o -o runner

obj/bettingcompany.o: src/bettingcompany.cpp include/bettingcompany.h
	$(CXX) $(CFLAGS) src/bettingcompany.cpp  -Iinclude -o obj/bettingcompany.o

obj/player.o: src/player.cpp include/player.h
	$(CXX) $(CFLAGS) src/player.cpp  -Iinclude -o obj/player.o

obj/customrandom.o: src/customrandom.cpp include/customrandom.h
	$(CXX) $(CFLAGS) src/customrandom.cpp  -Iinclude -o obj/customrandom.o


obj/runner.o: src/runner.cpp
	$(CXX) $(CFLAGS) src/runner.cpp -Iinclude -o obj/runner.o



.PHONY: clean

clean:
	rm -f obj/*.o *~ core include/*~
