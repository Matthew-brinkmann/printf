#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main (void)
{
    int fd[2]; 
    char buf1[1024] = "hello %%\b  world frank \n"; 
    char buf2[1024]; 
  
    // assume foobar.txt is already created 
    fd[0] = open("foobar.txt", O_RDWR);         
    fd[1] = open("foobar.txt", O_RDWR); 
      
    write(fd[0], buf1, 1024);         
    write(1, buf2, read(fd[1], buf2, 1024)); 
  
    close(fd[0]); 
    close(fd[1]); 
  
    return 0; 
} 
