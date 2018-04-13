all: A3

A3: main.c P11.c P12.c P21.c P22.c P23.c
		 gcc -o A3 main.c P11.c P12.c P21.c P22.c P23.c

clean:
	rm -f *.o
	rm A3
