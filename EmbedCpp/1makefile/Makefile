CXX=g++
CXXFLAGS = -Wall -std=c++17

TARGET = display_app

$(TARGET): main.o display.o
	$(CXX) $(CXXFLAGS) main.o display.o -o $(TARGET)

main.o: main.cpp display.h
	$(CXX) $(CXXFLAGS) -c main.cpp

display.o: display.cpp display.h
	$(CXX) $(CXXFLAGS) -c display.cpp

clean:
	rm -f *.o $(TARGET)
