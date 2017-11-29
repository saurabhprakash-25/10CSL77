#include<iostream>
using namespace std;
#define MAX 10;
int front=-1,rear=-1,q[10];
void delq()
{
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;
}
void insq(int i)
{
    if(front==rear)
        front=rear=0;
    else
        rear=(rear+1)%MAX;
    q[rear]=i;
}
int main()
{
    int t=0,q=1,i=1,j=1,cap,opr,n;
    cout<<"Enter bucket capacity : ";
    cin>>cap;
    
    cout<<"Enter output rate : ";
    cin>>opr;
    
    cout<<"Enter the number of times the output is to be shown: ";
    cin>>n;
    
    for(int a=0;a<n;a++ )
    {
        t=(++t)%opr;
        if(t==0)
        {
            delq();
            cout<<"t = "<<t<<" "<<j<<" delivered\n";
            j++;
        }
        else
        {
            if((q-j)>cap)
            {
                cout<<"t = "<<t<<" "<<i<<" discarded\n";
                i++;
            }
            else
            {
                cout<<"t = "<<t<<" "<<i<<" queued\n";
                insq(i);
                i++;
                q++;
            }
        }
    }   
    return 0;
}
