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




char buf[2024];
int j =0;
for(;j<sizeof(buf);j++)
{
	if(j%2 == 0)
		buf[j]= 'a';
	else 
		buf[j]= 's';
}
fd = open("t6/0", O_RDWR);
printf("%d",fd);
res = write(fd,buf,2024);
//res = read(fd, buf,8192);
//res = lseek(fd,10,SEEK_SET) ;
//int i=0;
printf("\n");
//res = res * 8;
int i = 0;
//for(;i<res;i++)
//	printf("%c",buf[i]);
//printf("\n");


printf("%d",res);

printf("\n");

return 0 ;




}







