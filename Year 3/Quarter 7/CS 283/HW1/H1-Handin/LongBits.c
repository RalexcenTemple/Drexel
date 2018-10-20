//Reed Ceniviva
//CS 283 thur 630-930
//H1

//prototype printf() to use without including stdio.h
int printf(const char * format, ...);


int main(){

	//declare two long int variables
	long int i, j;

	// find the distance between the locations
	int bits = (long int)&j - (long int)&i;

	//adjust bits accordingly
	bits = (bits*4);

	//format answer and print answer (bits)
	printf("\n");
	printf("%d", bits);
	printf("\n");

}
