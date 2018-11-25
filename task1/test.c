#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <utime.h>
#include <errno.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{

	int fd = 0;
	int res=0;;




char buf[1024];
char buf2[1024];
int i =0;
for(i;i<1024;i++)
	buf2[i] = '7';

fd = open("t6/2", O_RDWR);
printf("%d",fd);
res = write(fd,buf2,1024);
//res = read(fd, buf, sizeof(buf));
//res = lseek(fd,10,SEEK_SET) ;
//int i=0;
printf("\n");

i = 0;
//for(;i<1024;i++)
//	printf("%c",buf[i]);
printf("\n");


printf("%d",res);

printf("\n");

return 0 ;




}
