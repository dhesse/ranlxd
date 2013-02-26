CXX=g++

test.o: test/test.cc
	$(CXX) -I. -c -o test.o test/test.cc