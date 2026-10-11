main:
	gcc -o main -Wall -g main.c

clean:
	rm -rf main

run: main
	clear && ./main