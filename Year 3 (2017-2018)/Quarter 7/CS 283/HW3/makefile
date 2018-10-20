#after first doing the program I realize the make file could have handled
# getting just the text files
defualt: frp

frp.o: frp.c
	gcc -c frp.c -o frp.o

frp: frp.o
	gcc frp.o -o frp

clean:
	-rm -f frp.o
	-rm -f frp
