/*Represent any real world graph using adjacency list /adjacency matrix find minimum spanning
tree using Kruskal’s algorithm.*/

#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int s,d,w;
};
class edgelist
{
    edge data[30];
    int n;
public:
    friend class graph;
    edgelist(){n=0;}
    void sort1();
    void print();
};
void edgelist::sort1()
{
    int i,j;
    edge temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(data[j].w>data[j+1].w)
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}
class graph
{
    int am[30][30];
    int n;
public:
    graph(){n=0;}
    void readgraph();
    void printgraph();
    void kruskal(edgelist &spanlist);
};
void graph::readgraph()
{
    int i,j;
    cout<<"\nEnter no of vertices :";
    cin>>n;
        cout<<"\nEnter no of weights:";

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>am[i][j];
        }
    }
}
void graph::printgraph()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        cout<<"\n";
        for(j=0;j<n;j++)
        {
            cout<<" "<<am[i][j];
        }
    }
}
void edgelist::print()
{
    int i;
    int cost = 0;
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<data[i].s<<" "<<data[i].d<<" "<<data[i].w;
        cost = cost+data[i].w;
    }
    cout<<"\nCost of the spanning tree =\n"<<cost;
}
int find(int parent[],int v)
{
    return(parent[v]);
}
void union1(int parent[],int c1,int c2,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(parent[i]==c2)
            parent[i]=c1;
    }
}
void graph::kruskal(edgelist &spanlist)
{
    int parent[30],i,j,cno1,cno2;
    edgelist elist;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++)
        {
            if(am[i][j]!=0)
            {
                elist.data[elist.n].s=i;
                elist.data[elist.n].d=j;
                elist.data[elist.n].w=am[i][j];
                elist.n++;
            }
        }
    }
    elist.sort1();
    for(i=0;i<n;i++)
        parent[i]=i;
    for(i=0;i<elist.n;i++)
    {
        cno1 = find(parent,elist.data[i].s);
        cno2 = find(parent,elist.data[i].d);
        if(cno1!=cno2)
        {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n=spanlist.n+1;
            union1(parent,cno1,cno2,n);
        }
    }
}

int main()
{
    edgelist spanlist;
    graph g1;
    g1.readgraph();
    g1.printgraph();
    g1.kruskal(spanlist);
    spanlist.print();
    return 0;

}
