CXX = g++-10
CXXFLAGS = -Wall -O

all: main

clean:
	rm -rf main *.o *~

OBJS1 = main.o 

main:$(OBJS1) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS1)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

main.o: main.cpp
