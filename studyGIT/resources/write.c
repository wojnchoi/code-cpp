#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	int fd1;
	char buf[128];
	fd1 = open(argv[1],  O_WRONLY | O_CREAT);
	if(fd1 == -1)
	{
		perror("File cannot be opened");
		return EXIT_FAILURE;
	}

	scanf("%127s", buf);

	write(fd1,buf,strlen(buf));
	close(fd1);

	return 0;
}
