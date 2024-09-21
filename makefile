clean:
	rm build/*.o

compile:
	gcc -I include -c src/constants.c	-o build/constants.o
	gcc -g -I include -c src/buffer_util.c -o build/buffer_util.o
	gcc -I include -c src/io_util.c 	-o build/io_util.o
	gcc -g -I include -c src/main.c 		-o build/main.o
	gcc -g -o main build/*.o

run:
	./main
