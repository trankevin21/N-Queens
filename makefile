NQueen: NQ.o
	g++ NQ.o -o Nqueen

NQ.o: NQ.cpp NQ.h
	g++ -c NQ.cpp
clean:
	rm -f *.o
	rm Nqueen
run: Nqueen
	./Nqueen
