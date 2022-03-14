
bin: main.c
	gcc main.c -o bin -lpthread

.PHONY: run clean

run:
	./bin

clean:
	rm bin
