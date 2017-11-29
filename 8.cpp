#include<iostream>
using namespace std;
struct node
{
    int from[20];
    int dist[20];
 }route[20];
 int main()
 {
    int n,dm[20][20];
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the distance matrx\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dm[i][j];
            route[i].dist[j]=dm[i][j];
            route[i].from[j]=j;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(route[i].dist[j]>route[i].dist[k]+route[k].dist[j])
                {
                    route[i].dist[j]=route[i].dist[k]+route[k].dist[j];
                    route[i].from[j]=k;
                }
            }
        }
     }
     
     for(int i=0;i<n;i++)
     {
        cout<<"Router info for node "<<i+1<<endl;
        cout<<"Destination\tNext Hop\tDist\n";
        for(int j=0;j<n;j++)
        {
            cout<<j+1<<"\t\t"<<route[i].from[j]+1<<"\t\t"<<route[i].dist[j]<<endl;
        }
     }
    return 0;
 }
