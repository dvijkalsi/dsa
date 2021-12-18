#include<iostream>
#include<limits>
using namespace std;
class graph
{
    int vertices;
    int edges;
    int **ar;
    int *set;
    public:
    graph(int v,int e)
    {
        edges=e;
        vertices=v;
        ar=new int*[3];
        for(int i=0;i<3;i++)
        {
            ar[i]=new int[edges];
        }
        cout<<"\nEnter edges\n";
        for(int i=0;i<edges;i++)
        {
            cin>>ar[0][i]>>ar[1][i]>>ar[2][i];
        }
        set=new int[vertices+1];
        for(int i=0;i<=vertices;i++)
        set[i]=-1;
    }
    void Union(int u,int v)
    {
        if(set[u]<set[v])
        {
            set[u]+=set[v];
            set[v]=u;
        }
        else
        {
            set[v]=set[u]+set[v];
            set[u]=v;
        }
    }
    int parent(int u)
    {
        int x=u,v=0;
        while(set[x]>0)
        {
            x=set[x];
        }
        while(u!=x)
        {
            v=set[u];
            set[u]=x;
            u=v;
        }
        return x;
    }
    void kruskal()
    {
        int i,j,k,min,u,v;

        int inc[edges];
        for(i=0;i<edges;i++)
        inc[i]=0;

        int t[2][vertices-1];
        i=0;
        //loop for edges to be stored in spanning tree
        while(i<vertices-1)
        {
            //finding minimum cost edge
            min=INT16_MAX;
            for(j=0;j<edges;j++)
            {
                if(inc[j]==0 && ar[2][j]<min)
                {
                    min=ar[2][j];
                    k=j;
                    u=ar[0][j];
                    v=ar[1][j];
                }
            }
            
            if(parent(u)!=parent(v))
            {
                t[0][i]=u;
                t[1][i]=v;
                Union(parent(u),parent(v)); 
                i++;
            }
            inc[k]=1;
        }

        //printing spanning tree
        cout<<"\nspanning tree:-\n";
        for(i=0;i<=1;i++)
        {
            for(j=0;j<vertices-1;j++)
            {
                cout<<t[i][j]<<" ";
            } 
            cout<<endl;
        }
    }
};

int main()
{
    graph g(7,9);
    g.kruskal();
    return 0;
}
