CXX=g++ -std=c++11
CFLAGS=-Wall -c

runner: obj/runner.o obj/bettingcompany.o obj/player.o obj/customrandom.o obj/playerbet.o obj/legalentity.o
	$(CXX) obj/runner.o obj/bettingcompany.o obj/player.o obj/customrandom.o obj/playerbet.o obj/legalentity.o -o runner


obj/legalentity.o: src/legalentity.cpp include/legalentity.h
	$(CXX) $(CFLAGS) src/legalentity.cpp  -Iinclude -o obj/legalentity.o


obj/bettingcompany.o: src/bettingcompany.cpp include/bettingcompany.h obj/legalentity.o
	$(CXX) $(CFLAGS) src/bettingcompany.cpp   -Iinclude -o obj/bettingcompany.o

obj/player.o: src/player.cpp include/player.h obj/legalentity.o
	$(CXX) $(CFLAGS) src/player.cpp   -Iinclude -o obj/player.o

obj/playerbet.o: src/playerbet.cpp include/playerbet.h obj/legalentity.o
	$(CXX) $(CFLAGS) src/playerbet.cpp  -Iinclude -o obj/playerbet.o

obj/customrandom.o: src/customrandom.cpp include/customrandom.h
	$(CXX) $(CFLAGS) src/customrandom.cpp  -Iinclude -o obj/customrandom.o


obj/runner.o: src/runner.cpp
	$(CXX) $(CFLAGS) src/runner.cpp -Iinclude -o obj/runner.o



.PHONY: clean

clean:
	rm -f obj/*.o *~ core include/*~
