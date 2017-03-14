all : sort

quick_sort : sort.cpp
	g++ -g -o $@ $^

clean :
	rm -rf sort *.~