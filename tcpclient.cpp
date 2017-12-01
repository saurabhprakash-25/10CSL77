#include<iostream>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
using namespace std;
int main()
{
    char buffer[1025],fname[50];
    int soc,n;
    struct sockaddr_in addr;
    soc=socket(PF_INET,SOCK_STREAM,0);    
    addr.sin_family=AF_INET;
    addr.sin_port=htons(7891);
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    while(connect(soc,(struct sockaddr*)&addr,sizeof(addr)));
    cout<<"Connected to server\n";
    cout<<"Enter file name : ";
    cin>>fname;
    send(soc,fname,sizeof(fname),0);
    while ((n = recv(soc, buffer, sizeof(buffer), 0)) > 0)
        cout<<buffer;
    return 0;
}
