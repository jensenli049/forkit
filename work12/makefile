all: forkit.o
	gcc -o fork forkit.o

stats.o: forkit.c forkit.h
	gcc -c -g forkit.c

run: all
	./fork

clean:
	rm *~
	rm *.o
