SOURCES = minor5.c

start:	minor5.c
	gcc -std=c99 -Wall -o minor5 $(SOURCES) -lpthread

run: minor5
	./minor5

clean:
	rm -rf minor5