CXX = g++-10

CXXFLAGS = -Wall -O

all:main main2

clean:
	rm -rf *.o *~ main main2


# 暗黙の生成規則
OBJS1 = main.o sub.o

main:$(OBJS1)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS1)

OBJS2 = main2.o

main2:$(OBJS2)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS2)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

# オブジェクトの依存関係
main.o:main.cpp sub.h
sub.o:sub.cpp
main2.o: main2.cpp

