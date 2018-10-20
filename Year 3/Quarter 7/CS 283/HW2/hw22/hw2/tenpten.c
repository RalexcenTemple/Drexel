#include "csapp.h"
int main(int argc, char **argv)
{

	int n, temp, duptemp;
	rio_t rio;
	char buf[MAXLINE];
	if (argc == 2)
	{
		temp = open(argv[1], O_RDONLY);
		duptemp = dup2(temp, STDIN_FILENO);
	}

	Rio_readinitb(&rio, STDIN_FILENO);
	while((n = Rio_readineb(&rio, buf, MAXLINE)) != 0)
		Rio_writen(STDOUT_FILENO, buf, n);

	exit(0);

}
