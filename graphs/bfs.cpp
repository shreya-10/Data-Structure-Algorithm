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
int n=8;
//only cycle
void bfs_basic(int src,int des,vector<bool>& vis)
 {
     queue<int> que2;
     int cycle=0;
     que2.push(src);
     while(que2.size()!=0)
     {
         int front=que2.front(); que2.pop();

         if(vis[front])
         {
             cycle++;
             cout<<"cycle:"<<cycle<<"@"<<front<<endl;
             continue;
         }
         vis[front]=true;
         
         for(edge* e:graphs[front])
         {  if(!vis[e->v])
             que2.push(e->v);
         }


     }
 }





 //only destination
void bfs_dest(int src)
{
    queue<int> que;
    que.push(src);
    vector<bool> vis(7,false);
     que.push(-1);
    int level=0;
    int dest=6;
    bool isDest=false;
    while(que.size()!=1)
    {
        int front=que.front(); que.pop();

         if(front==dest && !isDest)
        {
            cout<<"dest found at level:"<<level<<endl;
             isDest=true;
        }

       
        vis[front]=true;
        for(edge* nbre:graphs[front])
        if(vis[nbre->v]==false)
        {
               que.push(nbre->v);
        }
        if(que.front()==-1)
        {
          level++;
          que.pop();
          que.push(-1);
        
        }
        

    }

   
}
 //both cycle and destination.
void bfs(int src)
{
    queue<int> que;
    que.push(src);
    vector<bool> vis(7,false);
     que.push(-1);
    int cycle=0,level=0;
    int dest=6;
    bool isDest=false;
    while(que.size()!=1)
    {
        int front=que.front(); que.pop();


       if(front==-1)
        {
          level++;
          que.push(-1);
         continue;
        }
        if(vis[front]==true)
        {   cycle=cycle+1;
            cout<<"cycle:"<<cycle<<"@"<<front<<endl;
            continue;
        }
         if(front==dest && !isDest)
        {
            cout<<"dest found at level:"<<level<<endl;
             isDest=true;
        }

       
        vis[front]=true;
        for(edge* nbre:graphs[front])
        if(vis[nbre->v]==false)
        {
               que.push(nbre->v);
        }
          
     
       


    }

   
}

void bfs_02(int src,int dest)
{
    queue<int> que;
    que.push(src);
    int cycle =0,level=0;
    int size;
    bool isDest=false;
    vector<bool> vis(n,false);
    while(que.size()!=0)
    {
        size=que.size();
        while(size-->0)
        {
            int front =que.front();
            que.pop();
            
            if(vis[front])
            {   
                
                cout<<"cycle"<<++cycle<<"@"<<front<<endl;
                continue;
            }
            if(front==dest && !isDest)
            {
                cout<<"destination found at level:"<<level<<endl;
                isDest=true;
            }
            vis[front]=true;
            for(edge* e:graphs[front])
            {
                if(vis[e->v]==false)
                que.push(e->v);
            }    
           
        }
        ++level;
        
    }
}
 

 

 void hamitonianPath(int orgsrc,int movsrc,vector<bool>& vis,string ans,int noEdge)
{
        if( noEdge==graphs.size()-1)
        {
            bool flag=false;
            //check cycle
            for(edge* e:graphs[movsrc])
            if(e->v==orgsrc)
            {
              cout<<"cycle:"<<ans<<movsrc<<endl;
              flag=true;
            }
            if(!flag)
            {
                cout<<"path:"<<ans<<movsrc<<endl;
            }
            return;
        }

        vis[movsrc]=true;
        for(edge* e:graphs[movsrc])
        {
            int v=e->v;
            if(!vis[v])
            hamitonianPath(orgsrc,v,vis,ans+to_string(movsrc)+"->",noEdge+1);

        }
        vis[movsrc]=false;
}

//Bipartite==============================================================================
class Bipart
{
    public:
    int src=0;
    int set=0;
    Bipart(int src,int set)
    {
        this->src=src;
        this->set=set;
    }
    Bipart()
    {

    }
};
bool Bipartite(int src,vector<int>& vis)
 {
    
     queue<Bipart*> que2;
     bool flag=true;
   
    //Bipart* root(src,0);
     que2.push(new Bipart(src,0));
     
     
     while(que2.size()!=0)
     {
         Bipart* front=que2.front(); que2.pop();

         //check conflict              
         if(vis[front->src]!=-1 )
         {
             if(vis[front->src]!=front->set)
             {
             flag=false;
             continue;
            
             }
             //
        }
    
         vis[front->src]=front->set;
         
         for(edge* e:graphs[front->src])
         {  if(vis[e->v]==-1)
        // Bipart* npair(e->v,((front->set)+1)%2);
             que2.push(new Bipart(e->v,((front->set)+1)%2) );
         }
       

     }
     return flag;
 }
bool bipartDriver()
{
    vector<int> vis(n,-1);
    bool res;
 
    for(int i=0;i<graphs.size();i++)
    {
        if(vis[i]==-1)
       res=Bipartite(i,vis);
       if(res==false)
       return false;

    }
    return true;
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
    {int n=8;
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
        
       addEdge(2,7,0);
        display();
        

    }



int main(int args,char** argb)
{
construction();
vector<bool> vis(7,false);
//bfs(0);
//bfs_02(0,6,vis);
//hamitonianPath(0,0,vis,"",0);
//ector<int> vis(7,-1);
// for(int i=0;i<vis.size();i++)
// {
//     if(vis[i]!=-1)
//     {
//         cout<<(boolalpha)<<Bipartite(i,vis)<<endl;
//     }
// }
//cout<<(boolalpha)<<bipartDriver();
//bfs_dest(0);
//bfs(0);
//bfs_02(0,6);
bfs_basic(0,n,vis);

}