CXX = g++-10

CXXFLAGS = -Wall -O

all:main

clean:
	rm -rf *.o *~ main


# 暗黙の生成規則
OBJS1 = main.o sub.o

main:$(OBJS1) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS1)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

# オブジェクトの依存関係
main.o:main.cpp sub.h
sub.o:sub.cpp
