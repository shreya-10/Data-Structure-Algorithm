#include<iostream>
#include<queue>
#include<string>
using namespace std;
class edge
{
    public: //by default private
    int v;
    int w;
     edge(int v,int w)
        {
            this->v=v;
            this->w=w;
        }
};
vector<vector<edge*>> graphs;
int n=7;


class Dpair
{
    public:
    int vtx;
    int cost;
    string path;

    Dpair(int vtx,int cost,string path)
    {
        this->vtx=vtx;
        this->cost=cost;
        this->path=path;
    }

    bool operator>(const Dpair& other)const
    {
        return this->cost>other.cost;
    }
};

void dijkstra(int src)
{
    priority_queue<Dpair,vector<Dpair>,greater<Dpair>> pq;
    Dpair root(src,0,to_string(src));
    vector<bool> vis(n,false);
    pq.push(root);

    while(pq.size()!=0)
    {
        Dpair rem=pq.top();
        pq.pop();
       
        
        if(vis[rem.vtx]==true)
        continue;

         vis[rem.vtx]=true;
        cout<<rem.vtx<<" @ "<<rem.cost<<" via "<<rem.path<<endl;

        for(edge* e:graphs[rem.vtx])
        {
            if(vis[e->v]==false)
            {
                Dpair newp(e->v,rem.cost+e->w,rem.path+to_string(e->v));
                pq.push(newp);
            }
        }

    }

}

void display()
    {
        for(int i=0;i<graphs.size();i++)
        {
            cout<<i<<"->";
            for(edge*  e:graphs[i])
            {
               cout<<"("<<e->v<<","<<e->w<<")";
            }
             cout<<endl;
        }

    }



    void addEdge(int u,int v,int w)
    {
        if(u<0 || v<0 || u>=graphs.size() || v>=graphs.size())
        return;

        graphs[u].push_back(new edge(v,w));
        graphs[v].push_back(new edge(u,w));
    }
     void construction()
    {
        for(int i=0;i<n;i++)
     {
         graphs.push_back(vector<edge*>());
     }
         
        addEdge(0,3,40);
        addEdge(0,1,10);
        addEdge(1,2,10);
        addEdge(2,3,10);
        addEdge(3,4,2);
        addEdge(4,5,3);
        addEdge(5,6,3);
        addEdge(4,6,8);
        

        display();
        

    }



int main(int args,char** argb)
{
construction();
dijkstra(0);
}