#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<arpa/inet.h>
using namespace std;
int main()
{
    char buffer[1025],fname[50];
    int welcome,new_soc,fd,n;
    struct sockaddr_in addr;
    welcome=socket(PF_INET,SOCK_STREAM,0);
    addr.sin_family=AF_INET;
    addr.sin_port=htons(7891);
    addr.sin_addr.s_addr=inet_addr("127.0.01");
    
    bind(welcome,(struct sockaddr*)&addr,sizeof(addr));
    cout<<"Server is online\n";
    listen(welcome,5);
    new_soc=accept(welcome,NULL,NULL);
    recv(new_soc,fname,sizeof(fname),0);
    fd=open(fname,O_RDONLY);
    if(fd<0)
        send(new_soc,"\nFile not found\n",15,0);
    else
        {
            while((n=read(fd,buffer,sizeof(buffer)))>0)
                send(new_soc,buffer,n,0);
            cout<<"Request sent\n";
        }
    close(fd);
    return 0;
}

