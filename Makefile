FILES=four.5b four.txt gettysburg.5b gettysburg.txt Makefile smile.5b smile.gif filter.c test.sh 45zero 45zero.5b 760r 760r.5b

5bit: 5bits.c++
	g++ -o 5bits 5bits.c++

good: 5bit.c++
	g++ -o 5bits 5bits.good.c++

filter: filter.c++
	g++ -o filter filter.c++

