#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFER_SIZE 100
int main()
{
    int src, dst;
	int read_cnt;
    char buf[BUFFER_SIZE];

    src=open("src.dat", O_RDONLY);
	dst=open("dst.dat", O_CREAT|O_WRONLY|O_TRUNC);
    if(src==-1||dst==-1)
	{
		puts("file open error");
		return -1;
	}
    while((read_cnt=read(src, buf, BUFFER_SIZE))!=0)
		write(dst, buf, read_cnt);
    	close(src);
	close(dst);
    return 0;
}