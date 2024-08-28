build:
	gcc -I include -c src/io_util.c -o build/io_util.o
	gcc -I include -c src/main.c -o build/main.o
	gcc -o main build/*.o
