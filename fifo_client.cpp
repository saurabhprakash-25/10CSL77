#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<cstdlib>
#include<sys/types.h>
using namespace std;
int main()
{
    char buffer[1025],fname[50];
    int req,res,n;
    req=open("req.fifo",O_WRONLY);
    res=open("res.fifo",O_RDONLY);
    if(req<0||res<0)
    {
        cout<<"Start the server first\n";
        exit(-1);
    }
    cout<<"Enter the file name : ";
    cin>>fname;
    write(req,fname,sizeof(fname));
    cout<<"Response received\n";
    while((n=read(res,buffer,sizeof(buffer)))>0)
        write(1,buffer,n);
    close(req);
    close(res);
    return 0;
}

