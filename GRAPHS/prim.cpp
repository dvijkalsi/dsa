#include<iostream>
#include<limits>
using namespace std;
class graph
{
    int n;
    int **ar;
    public:
    graph(int n)
    {
        this->n=n;
        cout<<"\nEnter graph matrix,-1 for empty\n";
        ar=new int*[n+1];//not using 0th row, column
        for(int i=1;i<=n;i++)
        {
            *(ar+i)=new int[n+1];
            for(int j=1;j<=n;j++)
            {
                int t;
                cin>>t;
                if(t==-1) ar[i][j]=INT16_MAX;
                else  ar[i][j]=t;
            }

        }
    }

    void prim()
    {
        //ds used
        int near[n+1];
        int i;
        for(i=1;i<=n;i++)
        near[i]=INT16_MAX;
        
        int t[2][n-1];//stores the minimum cost spanning tree

        //finding minimum cost edge in upper triangular part of graph matrix ar
        int j,k,u,v,min=INT16_MAX;
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                if(ar[i][j]<min)
                {
                    min=ar[i][j];
                    u=i;
                    v=j;

                }
            }
        }

        //storing minimum cost edge in t
        t[0][0]=u;
        t[1][0]=v;

        //making near of these vertices 0
        near[u]=near[v]=0;

        //updating rest of near[] according to the nearness to the initial two selected vertices
        for(i=1;i<=n;i++)
        {
            if(near[i]!=0)
            {
                if(ar[i][u]<ar[i][v])
                {
                    near[i]=u;
                }
                else
                {
                    near[i]=v;
                }
            }
        }
        //initial work is over, now repeating steps

        for(i=1;i<n-1;i++)//loop for remaining edges to be filled in t[]
        {
            //finding the next minimum cost edge using near[]
            min=INT16_MAX;
            for(j=1;j<=n;j++)
            {
                if(near[j]!=0 && ar[j][near[j]]<min)
                {
                    min=ar[j][near[j]];
                    k=j;
                }
            }

            //putting the next minimum edge in t[]
            t[0][i]=k;
            t[1][i]=near[k];
            near[k]=0;//making new added vertice 0 in near[]

            //updating rest of near[] according to nearness with newly added vertice
            for(j=1;j<=n;j++)
            {
                if(near[j]!=0 && ar[j][k]<ar[j][near[j]])
                near[j]=k;
            } 
        }

        //printing spanning tree
        cout<<"\nspanning tree:-\n";
        for(i=0;i<=1;i++)
        {
            for(j=0;j<n-1;j++)
            {
                cout<<t[i][j]<<" ";
            } 
            cout<<endl;
        }
    }
};

int main()
{
    graph g(7);
    g.prim();
    return 0;
}
// -1 25 -1 -1 -1 5 -1
// 25 -1 12 -1 -1 -1 10
// -1 12 -1 8 -1 -1 -1
// -1 -1 8 -1 16 -1 14
// -1 -1 -1 16 -1 20 18
// 5 -1 -1 -1 20 -1 -1
// -1 10 -1 14 18 -1 -1