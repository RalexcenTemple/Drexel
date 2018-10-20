all: client StartServe
    
client: client.o
	gcc -o client client.c -g -lpthread
StartServe: StartServe.o
	gcc -o StartServe StartServe.c -g -lpthread
clean:
	rm StartServe client client.o StartServe.o 
#reed ceniviva