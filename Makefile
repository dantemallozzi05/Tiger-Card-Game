CXX = g++
OPTIONS = -std=c++11 -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Card.cpp Deck.cpp Hand.cpp
	$(CXX) $(OPTIONS) main.cpp Card.cpp Deck.cpp Hand.cpp -o $(PROGRAM)

clean:
	rm -f $(PROGRAM)
