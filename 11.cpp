#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
long int isPrime(long int n)
{
    for(long int i=2;i<n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
long int gcd(long int a,long int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long int encrypt(char ch,long int n,long int e)
{
    long int temp=ch;
    for(long int i=1;i<e;i++)
    {
       temp=(temp*ch)%n;
    }
    return temp;
}
char decrypt(long int ch,long int n,long int d)
{
    long int temp=ch;
    for(long int i=1;i<d;i++)
    {
        ch=(temp*ch)%n;
    }
    return ch;
}
int main()
{
    long int p,q,n,e,d,cipher[50],phi,len;
    char text[50];
    cout<<"Enter text to be encrypted : ";
    cin>>text;
    len=strlen(text);
    do{
        p=rand()%100;
      }while(!isPrime(p));
    do{
        q=rand()%100;
      }while(!isPrime(q)); 
    n=p*q;
    cout <<"n = p * q = "<<p<<" * "<<q<<" = "<<n<<endl;
    phi=(p-1)*(q-1);
    do{
       e=rand()%phi;
      }while(gcd(phi,e)!=1);
    do{
        d=rand()%phi;
      }while(((d*e)%phi)!=1);
    cout<<"Public Key (n,e) = ("<<n<<" , "<<e<<" )"<<endl;
    cout<<"Private Key (n,d) = ("<<n<<" , "<<d<<" )"<<endl;
    for(int i=0;i<len;i++)
    {
        cipher[i]=encrypt(text[i],n,e);
    }
    cout<<"Encrypted text : ";
    for(int i=0;i<len;i++)
    {
        cout<<cipher[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<len;i++)
    {
        text[i]=decrypt(cipher[i],n,d);
    }
    cout<<"\nDecrypted text : ";
    for(int i=0;i<len;i++)
    {
        cout<<text[i]<<" ";
    }
    cout<<endl; 
    return 0;
}
