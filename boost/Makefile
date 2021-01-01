CXX = g++-10
CXXFLAGS = -Wall -O
LDFLAGS = -I /usr/local/include -L /usr/local/lib -lboost_system -lboost_thread-mt

all: main

clean:
	rm -rf main *.o *~

OBJS1 = main.o 

main:$(OBJS1) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJS1)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCLUDE) -c -o $@ $<

main.o: main.cpp
