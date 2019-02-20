build:gps
gps:gps.o
	gcc gps.o -o gps -lm
gps.o: gps.c
	gcc -c gps.c
clean:
	rm -f gps gps.o
