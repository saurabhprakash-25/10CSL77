#include<iostream>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
using namespace std;
int main()
{
    char buffer[1025],fname[50];   
    int req,res,n,file;
    mkfifo("req.fifo",0777);
    mkfifo("res.fifo",0777);
    req=open("req.fifo",O_RDONLY);
    res=open("res.fifo",O_WRONLY);
    read(req,fname,sizeof(fname));
    cout<<"Request received for "<<fname<<endl;
    file=open(fname,O_RDONLY);
    if(file<0)
    {
        cout<<"File doesn't exist\n";
    }
    else
    {
        while((n=read(file,buffer,sizeof(buffer)))>0)
            write(res,buffer,n);
    }     
    close(req);
    close(res);
    unlink("req.fifo");
    unlink("res.fifo");
    return 0;
}
