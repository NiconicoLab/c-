CXX = g++-11
CXXFLAGS = -Wall -O
LDFLAGS = -I /usr/local/include -L /usr/local/lib -lboost_system -lboost_thread-mt

all: main main2

.PHONY: clean
clean:
	rm -rf main main2 *.o *~

OBJS1 = main.o

main:$(OBJS1) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJS1)

OBJS2 = main2.o

main2:$(OBJS2) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJS2)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCLUDE) -c -o $@ $<

main.o: main.cpp
main2.o: main2.cpp
