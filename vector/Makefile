CXX = g++-11
CXXFLAGS = -Wall -O -std=c++11

all: main main2

.PHONY: clean
clean:
	rm -rf main main2 *.o *~

OBJS1 = main.o 

main:$(OBJS1) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS1)

OBJS2 = main2.o

main2:$(OBJS2)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS2)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

main.o: main.cpp
main2.o: main2.cpp
