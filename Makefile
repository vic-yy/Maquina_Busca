CC := g++

Busca: main.o Busca.o
	${CC}  main.o Busca.o -o Busca

main.o: main.cpp
	${CC} -c main.cpp

Busca.o: Busca.cpp
	${CC} -c Busca.cpp

clean:
	rm *.o Busca