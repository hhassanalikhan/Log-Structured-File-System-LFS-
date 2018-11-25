/*
  FUSE: Filesystem in Userspace
  Copyright (C) 2001-2007  Miklos Szeredi <miklos@szeredi.hu>

  This program can be distributed under the terms of the GNU GPL.
  See the file COPYING.

  gcc -Wall hello.c `pkg-config fuse --cflags --libs` -o hello
*/
#define FUSE_CAP_BIG_WRITES (1 << 5)

#define FUSE_USE_VERSION 26

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef linux
/* For pread()/pwrite() */
#define _XOPEN_SOURCE 500
#endif
#include <math.h>

#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/stat.h>
#ifdef HAVE_SETXATTR
#include <sys/xattr.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATHLEN_MAX 5000

static const char *hello_str = "Hello World!\n";
static const char *hello_path = "/hello.txt";

static int hello_getattr(const char *path, struct stat *stbuf)
{
	int res = 0;

	memset(stbuf, 0, sizeof(struct stat));
	if (strcmp(path, "/") == 0) {
		stbuf->st_mode = S_IFDIR | 0755;
		stbuf->st_nlink = 2;
	} else  {
		stbuf->st_mode = S_IFREG | 0444;
		stbuf->st_nlink = 1;
		stbuf->st_size = 2000;//sizeof(hello_str);
	} 

	return res;
}

static int hello_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
			 off_t offset, struct fuse_file_info *fi)
{
	(void) offset;
	(void) fi;
	/*
	if (strcmp(path, "/") != 0)
		return -ENOENT;
	*/
	filler(buf, ".", NULL, 0);
	filler(buf, "..", NULL, 0);
	filler(buf, hello_path + 1, NULL, 0);
	

	return 0;
}

static int hello_open(const char *path, struct fuse_file_info *fi)
{
	if (strcmp(path, hello_path) != 0)
		{}//return -ENOENT;

	if ((fi->flags & 3) != O_RDONLY)
		{}//return -EACCES;

	return 0;
}

static int hello_read(const char *path, char *buf, size_t size, off_t offset,
		      struct fuse_file_info *fi)
{
	size_t len;
	(void) fi;
	int j = 10;
	if(strcmp(path, hello_path) != 0)
		j = 11;

	len = strlen(hello_str);
	if (offset < len) {
		if (offset + size > len)
			size = len - offset;
		//memcpy(buf, hello_str + offset, size);
	} else
		size = 0;

	
 j = 0;
int i =0;

for(i=1;i<strlen(path) ;i++)
{
	int ia = (int)path[i] - '0'; 
	
	int i3 = 1;
	int i2 =0;
	//for(;i2< i-1 ;i2++)
		i3 = i3 * 10;
	j = (j *i3) + ia;
}
j = j -1;


int y=0;
int sz1=10;
FILE *fp = fopen("/home/osboxes/Desktop/d4", "r");
if(fp == NULL)
	y = -10;
else
{
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
     sz1=ftell(fp);
    fseek(fp,prev,SEEK_SET); 
    char data[sz1];
    if((((j)*1024)+1024) > sz1)
		y = -3;
    else
	{
		char d[1024];
	   	fscanf(fp, "%s", data);
	   	int jj = 0;
		for(i=((j)*1024);i<(((j)*1024)+1024);i++)
		{
			d[jj] = data[i];
			jj++;
		}
		fclose(fp); 
		memcpy(buf, d, 1024);
		y=1024;
	}

}


//y = 1024;
return y;
}


static int hello_mknod(const char *path, mode_t mode, dev_t rdev)
{
    /*int res;

  On Linux this could just be 'mknod(path, mode, rdev)' but this
       is more portable 
path = full(path);

    if (S_ISREG(mode)) {
        res = open(path, O_CREAT | O_EXCL | O_WRONLY, mode);
        if (res >= 0)
            res = close(res);
    } else if (S_ISFIFO(mode))
        res = mkfifo(path, mode);
    else
        res = mknod(path, mode, rdev);
    if (res == -1)
        return -errno;*/

    return 0;
}


static int hello_utimens(const char *path, const struct timespec ts[2])
{
   

    return 0;
}


static int hello_write(const char *path, const char *buf, size_t size,
                     off_t offset, struct fuse_file_info *fi)
{

   	
 int j = 0;
int i =0;

for(i=1;i<strlen(path) ;i++)
{
	int ia = (int)path[i] - '0'; 
	
	int i3 = 1;
	int i2 =0;
	//for(;i2< i-1 ;i2++)
		i3 = i3 * 10;
	j = (j *i3) + ia;
}
j = j -1;


int y=0;
int sz1=10;
FILE *fp = fopen("/home/osboxes/Desktop/d4", "r");
if(fp == NULL)
	j = -10;

else
{
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
     sz1=ftell(fp);
    fseek(fp,prev,SEEK_SET); 
    sz1 = sz1 -1 ;
    char data[sz1];
    // fclose(fp); 

    int nx = sz1+1025;
    char ta[nx];
    if((((j)*1024)) > sz1)
		j = sz1;//not in squence
    else 
    	{
		int tj = j;
		
		char d[1024] ;//= "";
		fscanf(fp, "%s", data);
		fclose(fp);
		i = 0;
	   	for(;i<size;i++)
		{
			if(buf[i] != EOF)
			d[i] = buf[i];
		}
		fp = fopen("/home/osboxes/Desktop/d4", "w+");
		if(((tj)*1024) == sz1 )
		{
			
			
			int xx = 0;
			for(;xx < sz1; xx++)
				ta[xx] = data[xx];
			i =0;
			xx = sz1;
			for(;i<1024;i++)
			{
				ta[i+xx] = buf[i];
				
			}
			//ta[nx]= '\0';
			fprintf(fp, "%s", "");
			fclose(fp);
			fp = fopen("/home/osboxes/Desktop/d4", "w+");
			fprintf(fp, "%s", ta);
			fclose(fp);
			//int sj = strlen(ta);
			//while(sj > 0)
			// {y++, sj = sj-10;}
			j =  222;//created new
		}
		else
		{
			fscanf(fp, "%s", data);
			fclose(fp);
			
			int jj = 0;

			for(i=((tj)*1024);i<(((tj)*1024)+1024);i++)
			{
				data[i] = d[jj];
				jj++;
			}
			fp = fopen("/home/osboxes/Desktop/d4", "w+");
			fprintf(fp, "%s", "");
			fclose(fp);
			fp = fopen("/home/osboxes/Desktop/d4", "w+");
			fprintf(fp, "%s", data);
		
			j = 111;//update old;
			fclose(fp);
		}
		//fclose(fp);
	}
}
//while(sz1 > 0)
//{y++,sz1 = sz1-10;}
//y = sz1 % 2000;
return j;
}

static struct fuse_operations hello_oper = {
	.getattr	= hello_getattr,
	.readdir	= hello_readdir,
	.open		= hello_open,
	.read		= hello_read,
	.mknod		= hello_mknod,
	.utimens	= hello_utimens,
	.write		= hello_write,
};

int main(int argc, char *argv[])
{
	return fuse_main(argc, argv, &hello_oper, NULL);
}
