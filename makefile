CXX = g++ -std=c++0x
CXXFLAGS = -c -Wall -pedantic-errors -g

OBJS = main.o game.o lobby.o player.o room1.o room2.o room3.o room4.o room5.o space.o inputValidation.o
SRCS = main.cpp game.cpp lobby.cpp player.cpp room1.cpp room2.cpp room3.cpp room4.cpp room5.cpp space.cpp inputValidation.cpp


blinddate: $(OBJS) 
	$(CXX) $(LDFLAGS) $(OBJS) -o blinddate
	
$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) $(@:.o=.cpp)

memcheck: blinddate
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -v ./blinddate

clean:
	rm -rf *o blinddate
