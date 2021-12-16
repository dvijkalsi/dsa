#include<iostream>
using namespace std;
class Queue;
class node
{
    
    int data;
    node *next;
    public:
    node()
    {
        data=0;
        next=NULL;
    }
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    friend class Queue;
    friend class Stack;
};
class Queue
{
    
    node *start;
    public:
    Queue()
    {
        start=NULL;
    }
    void enque(int);
    int deque();
    void display();
    void search_list(int);
    int isempty()
    {
        if(!start)
        return 1;
        else 
        return 0;
    }
};
void Queue::enque(int x)
{
    node *newNode=new node(x);
    if(!start)
    {
        start=newNode;
        return;
    }
    else
    {
        node *t=start;
        while(t->next)
        {
            t=t->next;
        }
        t->next=newNode;
    }
}
int Queue::deque()
{
    int x=start->data;
    node *t=start;
    start=start->next;
    free(t);
    return x;
}
void Queue::display()
{
    cout<<"\nList:";
    node* t=start;
    while (t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}
void Queue::search_list(int key)
{
    node* temp=start;
    while (temp && key>=temp->data)
    {
        if(temp->data==key)
        {
            cout<<"\nKey "<<key<<" found";
            return;
        }
        temp=temp->next;
    }
    cout<<"\nKey "<<key<<" not found";
}
class Stack
{
    int data;
    node *start;
    public:
    Stack()
    {
        start=NULL;
    }
    void push(int);
    int pop();
    void display();
    void search_list(int);
    int isempty()
    {
        if(!start)
        return 1;
        else 
        return 0;
    }
    
};

void Stack::push(int x)
{
    node *newNode=new node(x);
    if(!start)
    {
        start=newNode;
        return;
    }
    else
    {
        newNode->next=start;
        start=newNode;
    }
}
int Stack::pop()
{
    int x=start->data;
    node *t=start;
    start=start->next;
    free(t);
    return x;
}
void Stack::display()
{
    cout<<"\nList:";
    node* t=start;
    while (t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}
void Stack::search_list(int key)
{
    node* temp=start;
    while (temp && key>=temp->data)
    {
        if(temp->data==key)
        {
            cout<<"\nKey "<<key<<" found";
            return;
        }
        temp=temp->next;
    }
    cout<<"\nKey "<<key<<" not found";
}



class graph
{
    int n;
    int **ar;
    public:
    graph(int n)
    {
        this->n=n;
        cout<<"\nEnter graph matrix\n";
        ar=new int*[n+1];
        for(int i=1;i<n+1;i++)
        {
            *(ar+i)=new int[n+1];
            for(int j=1;j<n+1;j++)
            {
                cin>>ar[i][j];
            }

        }
    }
    void bfs(int i)
    {
        int *visited=new int[n+1];
        for(int i=0;i<n+1;i++)
        visited[i]=0;
        int u;
        cout<<"\nbfs:"<<i<<" ";
        visited[i]=1;
        Queue q;
        q.enque(i);
        while(!q.isempty())
        {
            u=q.deque();
            for(int v=1;v<n+1;v++)
            {
                if(ar[u][v]==1 && visited[v]==0)
                {
                    cout<<v<<" ";
                    visited[v]=1;
                    q.enque(v);
                }
            }
        }
    }
    void dfs(int i)
    {
        int *visited=new int[n+1];
        for(int i=0;i<n+1;i++)
        visited[i]=0;
        int u;
        cout<<"\ndfs:"<<i<<" ";
        visited[i]=1;
        Stack s;
        s.push(i);
        while (!s.isempty())
        {
            u=s.pop();
            for(int v=1;v<n+1;v++)
            {
                if(ar[u][v]==1 && visited[v]==0)
                {
                    cout<<v<<" ";
                    visited[v]=1;
                    s.push(v);
                }
            }
        }
        
    }
};

int main()
{
    graph g(7);
    g.bfs(4);
    g.dfs(4);

    return 0;
}
