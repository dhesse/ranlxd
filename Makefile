CXX=g++
CXXFLAGS=-I. -g -msse2 -DSSE

test.o: test/test.cc
	$(CXX) $(CXXFLAGS) -c -o test.o test/test.cc

ranlxd.o: ranlxd.cc
	$(CXX) $(CXXFLAGS) -c -o ranlxd.o ranlxd.cc

testrlxd: test.o ranlxd.o
	$(CXX) -o testrlxd test.o ranlxd.o

.PHONY: clean check

clean:
	rm -f *.o
check: testrlxd
	./testrlxd
