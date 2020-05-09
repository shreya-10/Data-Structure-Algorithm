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
int N=7;
vector<vector<edge>> graphs;


void bfs_basic(int src)
{
    queue<pair<int,string>> que;
    vector<bool> vis(N);
    que.push({src,to_string(src)});
     int cycle=0;
     int dest=6;
    
    while(que.size()!=0)
    {
        pair<int,string> rvtx=que.front(); que.pop();

        if(vis[rvtx.first]) 
        {
            cycle++;
            cout<<"Cycle "<<cycle<<"@"<<rvtx.second<<endl;
            continue;
         }
         if(rvtx.first==dest)
         {
             cout<<"Destiation :"<<"@"<<rvtx.second;
         }
        vis[rvtx.first]=true; 
        for(edge e:graphs[rvtx.first])
        {
        if(!vis[e.v])
        que.push({e.v,rvtx.second+to_string(e.v)});
        }
    }

}


//DESTINATION THROUGH DELIMINATOR
void bfs_deliminator(int src)
{
    queue<pair<int,string>> que;
    vector<bool> vis(N);
    que.push({src,to_string(src)});
    que.push({-1,""});
     int cycle=0;
    int dest=6;
    int level=0;
    while(que.size()!=1)
    {
        pair<int,string> rvtx=que.front(); que.pop();
   if(rvtx.first==-1)
        {
            level++;
           
        que.push({-1,""});
        continue;
        }
    
        if(vis[rvtx.first]) 
        {
            cycle++;
            cout<<"Cycle "<<cycle<<"@"<<rvtx.second<<endl;
            continue;
         }
         if(rvtx.first==dest)
         {
                cout<<"dest found at:"<<level<<"@"<<rvtx.second<<endl;
        }
        vis[rvtx.first]=true; 
        for(edge e:graphs[rvtx.first])
        {
        if(!vis[e.v])
        que.push({e.v,rvtx.second+to_string(e.v)});
        }
    }
      

}
void bfs_dest(int src)
{
    queue<pair<int,pair<string,int>>> que;
    vector<bool> vis(N);
    que.push({src,{to_string(src),0}});
     int cycle=0;
     int dest=6;
    
    while(que.size()!=0)
    {
        pair<int,pair<string,int>> rvtx=que.front(); que.pop();

        if(vis[rvtx.first]) 
        {
            cycle++;
            cout<<"Cycle "<<cycle<<"@"<<rvtx.second.first<<endl;
            continue;
         }
         if(rvtx.first==dest)
         {
             cout<<"Destiation :"<<"@"<<rvtx.second.first<<"@ level:"<<rvtx.second.second;
         }
        vis[rvtx.first]=true; 
        for(edge e:graphs[rvtx.first])
        {
        if(!vis[e.v])
        que.push({e.v,{rvtx.second.first+to_string(e.v),rvtx.second.second+1}});
        }
    }

}
//cycle doesnt matters
void bfs_best(int src)
{
     queue<int> que;
    vector<bool> vis(N);
    que.push(src);
    vis[src]=true;
     int cycle=0;
     int dest=6;
     int level=0;
     while(que.size()!=0)
     {
         int size=que.size();
         while(size-- >0)
         {
             int rvtx=que.front();que.pop();
             if(rvtx==dest)
             cout<<"dest at:"<<level;
             for(edge e:graphs[rvtx])
             {
                 if(!vis[e.v])
                 {
                     que.push(e.v);
                     vis[e.v]=true;  //prevent duplicate to enter in queue.
                                    //but will not detect cycle.
                 }
             }
         }
         level++;
     }
    
}

 void bfs_best_2(int src)
{
     queue<int> que;
    vector<bool> vis(N);
    que.push(src);

     int cycle=0;
     int dest=6;
     int level=0;
     while(que.size()!=0)
     {
         int size=que.size();
         while(size-- >0)
         {
             int rvtx=que.front();que.pop();
            if(vis[rvtx])
            {
              cycle++;
              cout<<"cycle "<<cycle<<"@"<<rvtx ;  
            }
             if(rvtx==dest)
             cout<<"dest at:"<<level;
             vis[rvtx]=true;
             for(edge e:graphs[rvtx])
             {
                 if(!vis[e.v])
                 {
                     que.push(e.v);
                       
                 }
             }
         }
         level++;
     }
    
}

bool isBipartite(int src,vector<int>& vis)
{
   queue<pair<int,int>> que;
   que.push({src,0});

   while(que.size()!=0)
   {
       int size=que.size();
       while(size-- >0)
       {
           pair<int,int> rvtx=que.front();que.pop();
            if(vis[rvtx.first]!=-1)
            {
                if(vis[rvtx.first]!=rvtx.second)
                return false;
            }
           vis[rvtx.first]=rvtx.second;
           for(edge e:graphs[rvtx.first])
           {
            if(vis[e.v]==-1)
            {
                que.push({e.v,(rvtx.second+1)%2});


            }
           }
       }

   }
   return true;
}
void bipartite()
{
    vector<int> vis(N,-1); // -1 : unvisited, 0 : red, 1 : green
    for(int i=0;i<N;i++)
    {
        if(vis[i]==-1)
       cout << (boolalpha) << isBipartite(i, vis) << endl;
    }

}
    void addEdge(int u,int v,int w)
    {
     
     if(u<0 || v<0 || u>=graphs.size() || v>=graphs.size())
     return;
            graphs[u].push_back(edge(v,w));
            graphs[v].push_back(edge(u,w));
       
    }
    void display()
    {
        for(int i=0;i<graphs.size();i++)
        {
            cout<<i<<"->";
            for(edge e:graphs[i])
            {
                cout<<"("<<e.v<<","<<e.w<<")";
            }
            cout<<endl;
        }
       
    }


     void construction()
    {
        for(int i=0;i<N;i++)
     {
         graphs.push_back(vector<edge>());
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
   //bfs(0);
  //bfs_deliminator(0);
//   bfs_dest(0);
  //bfs_best(0);
  bfs_best_2(0);
}