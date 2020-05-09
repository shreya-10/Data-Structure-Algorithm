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
int n=8;
vector<vector<edge*>> graphs;
vector<int> topostack;
vector<int> topological_sort(int src, vector<bool>& vis)
{
    vis[src]=true;
    for(edge* e:graphs[src])
    {
        if(!vis[e->v])
        topological_sort(e->v,vis);

    }
    topostack.push_back(src);
     
}
void kosaraju()
{ 
  for(int i=0;i<n;i++)
  {
      topological_sort(i, vector<bool> vis(n,false));

  }  
  

}


void kosadfs(int src, vector<bool> &vis)
{
    vis[src] = true;
    for (edge *e : graphs[src])
        if (!vis[e->v])
            kosadfs(e->v, vis);
} 
//USING BFS
void khansAlgo()
{
    vector<int> indegree(n,0);
  for(int i=0;i<graphs.size();i++)
     for(edge* e:graphs[i])
    {
        indegree[e->v]++;
    }

 queue<int> mque;
    vector<int> ans;
    for(int i=0;i<indegree.size();i++)
    if(indegree[i]==0)
      mque.push(i);
    
    
    while(mque.size()!=0)
    {
        int front=mque.front(); mque.pop();
        ans.push_back(front);
         
         for(edge* e:graphs[front])
         {    indegree[e->v]--;
              if(indegree[e->v]==0)
                 mque.push(e->v);
             
        }
    }
    if(ans.size()!=graphs.size())
    cout<<"Cycle detected";

    else
    {
    for(int i=0;i<ans.size();i++)
    cout<<ans[i];
    }
    


}


void topological_sort(int src, vector<bool>& vis,vector<int>& stack)
{
    vis[src]=true;
    for(edge* e:graphs[src])
    {
        if(!vis[e->v])
        topological_sort(e->v,vis,stack);

    }
    stack.push_back(src);
}

//USING DFS
int count=0;
bool cytopological_sort(int src, vector<bool>& vis,vector<bool>& cycleDetect,vector<int>& stack)
{
    vis[src]=true;
    cycleDetect[src]=true;
    bool res=false;
    for(edge* e:graphs[src])
    {
        if(!vis[e->v])
        res=res||cytopological_sort(e->v,vis,cycleDetect,stack);
        else if(cycleDetect[e->v])
         return true;
    }

    cycleDetect[src]=false;
    stack.push_back(src);
    return  res;
}

void topological_sort()
{
    vector<int> stack;
     vector<bool> cycle(n,false);
    vector<bool> vis(n,false);

    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        //topological_sort(i,vis,stack);
         cout<<(boolalpha)<<cytopological_sort(i,vis,cycle,stack)<<"@"<<i<<endl;
    }
    while(stack.size()!=0)
    {
        cout<<stack.back();
        stack.pop_back();
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
        // graphs[v].push_back(new edge(u,w)); //directional graph
    }
     void construction()
    {
        for(int i=0;i<n;i++)
     {
         graphs.push_back(vector<edge*>());
     }
    
         addEdge(0,1,0);
        addEdge(0,4,0);
        addEdge(1,2,0);
        addEdge(2,3,0);
        addEdge(5,3,0);
        addEdge(7,4,0);
        addEdge(7,6,0);
        addEdge(6,5,0);
        // addEdge(7,8,0); //cycle form
        // addEdge(8,9,0);
        // addEdge(9,7,0);
          // addEdge(5,7,0);
        

        display();
        

    }



int main(int args,char** argb)
{
construction();
 vector<bool> vis(n,false);

topological_sort();
//khansAlgo();
cout<<endl<<count;


}