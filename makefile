all : prog2

prog2: prog2.c
	gcc -g prog2.c -o prog2tree

clean:
	rm -f prog2tree


