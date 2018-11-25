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
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATHLEN_MAX 5000

//static const char *hello_str = "Hello World!\n";
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
		stbuf->st_size = 8192;//sizeof(hello_str);
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


	
int j = 0;
int i =0;

for(i=1;i<strlen(path) ;i++)
{
	int ia = (int)path[i] - '0'; 
	
	int i3 = 1;
	

		i3 = i3 * 10;
	j = (j *i3) + ia;
}
//j = j -1;


int y=10;
int sz1=10;

FILE *fp = fopen("/home/osboxes/Desktop/d5", "r");
if(fp == NULL)
	y = -10;
else
{

    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    sz1=ftell(fp);
    fseek(fp,prev,SEEK_SET); 
    char data[sz1];
    int blks[8];
    if(j<1024 && j>-1)
    {	
	y = 9;
	fscanf(fp, "%s", data);
	fclose(fp); 
	int z =0;
	y = 0;
	for(z = 0;z<8;z++ )
	{
		char nu[4];
		int v = 0;
		for (v = 0; v < 4 ; v++)
		{
			nu[v] = data[(j*40)+ 4 + (z*4) + v];//  inodes,inode numb,  num of blks read ,char to be read
		}
		//y++;
		int j11 = 0;
		for(i=1;i<sizeof(nu) ;i++)
		{
			int ia = (int)nu[i] - '0'; 
	
			int i3 = 1;
			int i2 =0;
			for(;i2< i-1 ;i2++)
				i3 = i3 * 10;
			j11 = (j11 *i3) + ia;
		}
		//if(z == 1)
		//	y = j11;
			//j11 = j11 - 1;
		blks[z] = j11;
		//y = j11;
			
	}
	int tb = 0;
	int v = 0;
	//y = 0;
	for (v = 0; v < 8 ; v++)
	{
		if(blks[v] > 0)
		{
			tb++;
			//y = blks[v];	
		}
	}
	//y = tb;
	if(tb > 0)
	{
		//y = 0;	
		char myData[tb*1024];
		v = 0;
		y = 22;
		for (v = 0; v < tb ; v++)
		{
				blks[v] = blks[v]-1;
				int jj =0;
				for(i=(40960 + ((blks[v])*1024) );i<(40960 + ((blks[v])*1024)+1024);i++)
				{
					myData[(v*1024) + jj] = data[i];
					jj++;
					//rv = data[i] - '0';
				}
					
			
			
		}
			
		memcpy(buf, myData, y*1024);
			y = tb;
			y = sizeof(myData);
	}
    }
} 
		


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
	//int i2 =0;
	//for(;i2< i-1 ;i2++)
		i3 = i3 * 10;
	j = (j *i3) + ia;
}
//j = j -1;

  		int n =0;
		int i3 = j;
		/*if(i3/1000 > 0)
			n =4;
		else if(i3/100 > 0)
			n =3;
		else if(i3/10 > 0)
			n =2;
		else 
			n =1;
		//int i;
		char numberArray[n]; */
		
int y=0;
int sz1=10;
//char inode[4];
FILE *fp = fopen("/home/osboxes/Desktop/d5", "r");
int nz = 0;
if(fp == NULL)
	j = -10;

else
{
    
    nz = size/1024;
    if(size % 1024 > 0)
		nz++;
    nz = nz * 1024;
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
     sz1=ftell(fp);
    fseek(fp,prev,SEEK_SET); 
    sz1 = sz1 -1 ;
    char newData[sz1+nz+1];
    char data[sz1];
    fscanf(fp, "%s", data);
    char nd[nz];
    int lc = 0;

    for(;lc<nz;lc++)
	nd[lc] = '0';

    lc=0;
    for(;lc<size;lc++)
	nd[lc] = buf[lc];


    lc =0;
    for(;lc<sz1;lc++)
	newData[lc] = data[lc];


    lc = sz1;
    int jk =0;
    for(;lc<sz1+nz;lc++,jk++)
	
	newData[lc] = nd[jk];

    int nb = nz/1024;
    int blks[nb];
    //current blocks
    int cb = sz1/1024;
    cb = cb-40;
    lc =0;
    for(;lc<nb;lc++)
	blks[lc] = ++cb;
    
    
    lc =0;
    for(;lc<36;lc++)
    {
	//clear prv blocks
	newData[(j*40)+ 4  + lc] = '0';
        
    } 
    lc = 0;
    for(;lc<nb;lc++)
    {
	//insert new block numbs
	//newData[(j*40)+ 4 + (z*4) + lc] = '0';
 		 n =0;
		 i3 = blks[lc];
		if(i3/1000 > 0)
			n =4;
		else if(i3/100 > 0)
			n =3;
		else if(i3/10 > 0)
			n =2;
		else 
			n =1;
		//int i;
		char inode1[4];
		char numberArray1[n]; 
	 	sprintf(numberArray1,"%ld", blks[lc]);

		if(n == 1)
		{
			inode1[0]= '0';
			inode1[1]= '0';
			inode1[2]= '0';
			inode1[3]= numberArray1[0];
		}
		else if(n == 2)
		{
			inode1[0] = '0';
			inode1[1] = '0';
			inode1[2] = numberArray1[0];
			inode1[3] = numberArray1[1];
		}
		else if(n == 3)
		{
			inode1[0]= '0';
			inode1[1]= numberArray1[0];
			inode1[2]= numberArray1[1];
			inode1[3]= numberArray1[2];
		}	
		else if(n == 4)
		{
			inode1[0]= numberArray1[0];
			inode1[1]= numberArray1[1];
			inode1[2]= numberArray1[2];
			inode1[3]= numberArray1[3];
		}
		
        newData[(j*40)+ 4 + (lc*4) + 0] = inode1[0];
	newData[(j*40)+ 4 + (lc*4) + 1] = inode1[1];
        newData[(j*40)+ 4 + (lc*4) + 2] = inode1[2];
	newData[(j*40)+ 4 + (lc*4) + 3] = inode1[3];
    } 
    fclose(fp);

   
    newData[sz1+nz]= '\0';

    fp = fopen("/home/osboxes/Desktop/d5", "w");
    fputs(newData,fp);
    
    fclose(fp);

	
}

y = sz1+nz;
return y;
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

void makeInodes()
{
FILE *fp;
fp = fopen("/home/osboxes/Desktop/d5", "rb+");
if(fp == NULL) //if file does not exist, create it
{
    fp = fopen("/home/osboxes/Desktop/d5", "wb");
   
}

char inodes[40961];
int i = 0;
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
     int sz1=ftell(fp);
    fseek(fp,prev,SEEK_SET); 
    sz1 = sz1 -1 ;

		
if(sz1<40960)
{
for(i=0;i<1024;i++ )
	{
		int j1 = 0;
		int i3 = i ;
		//int number = i;
		
		int n =0;
		if(i3/1000 > 0)
			n =4;
		else if(i3/100 > 0)
			n =3;
		else if(i3/10 > 0)
			n =2;
		else 
			n =1;
		//int i;
		char numberArray[n]; 
		
	        sprintf(numberArray,"%ld", i);
		if(n == 1)
		{
			inodes[i*40]= '0';
			inodes[(i*40)+1]= '0';
			inodes[(i*40)+2]= '0';
			inodes[(i*40)+3]= numberArray[0];
		}
		else if(n == 2)
		{
			inodes[i*40]= '0';
			inodes[(i*40)+1]= '0';
			inodes[(i*40)+2]= numberArray[0];
			inodes[(i*40)+3]= numberArray[1];
		}
		else if(n == 3)
		{
			inodes[i*40]= '0';
			inodes[(i*40)+1]= numberArray[0];
			inodes[(i*40)+2]= numberArray[1];
			inodes[(i*40)+3]= numberArray[2];
		}	
		else if(n == 4)
		{
			inodes[(i*40)]= numberArray[0];
			inodes[(i*40)+1]= numberArray[1];
			inodes[(i*40)+2]= numberArray[2];
			inodes[(i*40)+3]= numberArray[3];
		}
		
	
		for(j1 = 0 ; j1<36 ; j1++)	
			inodes[(i*40)+4+j1]= '0';
			
	}
fclose(fp);
fp = fopen("/home/osboxes/Desktop/d5", "wb");
fprintf(fp, "%s", "");
fclose(fp);
inodes[40960] = '\0';
fp = fopen("/home/osboxes/Desktop/d5", "wb");
fprintf(fp, "%s", inodes);
}
fclose(fp);
//}

}
int main(int argc, char *argv[])
{
	makeInodes();
	return fuse_main(argc, argv, &hello_oper, NULL);
}
