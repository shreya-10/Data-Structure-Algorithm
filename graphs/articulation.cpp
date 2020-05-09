#include<iostream>
#include<vector>
#include<queue>
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
int n=12;
vector<int> low(n,-1);
vector<int> dis(n,-1);
vector<bool> Appoints(n,false);
int times=0;
int callsforroot=0;
void dfs_AP(int src,int par)
{

    low[src]=dis[src]=time++;
    for(edge* e:graph[src])
    {
        if(dis[e->v]==-1)//unvisited
        {
            if(src==orsrc)
             callsforroot++;

            dfs_AP(e->v,src);

            if(dis[src]<=low[e->v])
            Appoints[src]=true;

            if(dis[src]<low[e->v])
            cout<<"AP EDGE"<<src<<"to"<<e->v<<endl;

            low[src]=min(low[src],low[e->v]);

        }
        else if(dis[e->v]!=par)
       //visited but not parent
        {
            low[src]=min(low[src],dis[e->v]);

        }
.0l988    }
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
    {int n=7;
        for(int i=0;i<n;i++)
     {
         graphs.push_back(vector<edge*>());
     }
         
        addEdge(0,1,40);
        addEdge(1,2,10);
        addEdge(2,3,10);
        addEdge(3,4,2);
        addEdge(4,5,3);
        addEdge(5,3,10);
        addEdge(3,6,3);
        addEdge(6,7,8);
        addEdge(7,8,10);
        addEdge(8,9,10);
        addEdge(9,10,10);
        addEdge(10,11,10);
        addEdge(11,7,10);
        addEdge(1,8,10);
        addEdge(6,1,10);
        addEdge(6,0,10);
        

        display();
        

    }



int main(int args,char** argb)
{
construction();
}