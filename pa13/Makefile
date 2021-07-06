pa13: OrderedSet.o pa13.o
		$(CXX) $(CXXFLAGS) OrderedSet.o pa13.o -o pa13

OrderedSet.o: OrderedSet.cpp OrderedSet.h 
		$(CXX) $(CXXFLAGS) -c OrderedSet.cpp

pa13.o: pa13.cpp OrderedSet.h
		$(CXX) $(CXXFLAGS) -c pa13.cpp

clean:
		rm -f pa13 OrderedSet.o pa13.o
