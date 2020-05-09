#include<iostream>
#include<vector>
#include<climits>
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
 //vector<vector<edge*>> graphs(7,vector<edge*>());
vector<vector<edge*>> graphs;


bool hasPath(int src,int dest,vector<bool>& vis,string ans)
{
    if(src==dest)
    {
        cout<<ans<<dest;
    return true;
    }
    vis[src]=true;
    
    bool res=false;
    for(edge* e:graphs[src])
    {
        int v=e->v;
        if(!vis[v])
        {
           res=res || hasPath(v,dest,vis,ans+to_string(src)+"->");
        }

    }
    return res;

}

void allPath(int src,int dest,vector<bool>& vis,string ans)
{
        if(src==dest)
        {
            cout<<ans<<dest<<endl;
            return;
        }

        vis[src]=true;
        for(edge* e:graphs[src])
        {
            int v=e->v;
            if(!vis[v])
            allPath(v,dest,vis,ans+to_string(src)+"->");

        }
        vis[src]=false;
}

void preOrderPath(int src,vector<bool>& vis,string ans)

{
        cout<<src<<"->"<<ans<<src<<endl;
        vis[src]=true;
        for(edge* e:graphs[src])
        {
            int v=e->v;
            if(!vis[v])
            preOrderPath(v,vis,ans+to_string(src));

        }
        vis[src]=false;


}


void postOrderPath(int src,vector<bool>& vis,string ans)

{
        
        vis[src]=true;
        for(edge* e:graphs[src])
        {
            int v=e->v;
            if(!vis[v])
            postOrderPath(v,vis,ans+to_string(src));

        }
        vis[src]=false;
        cout<<src<<"->"<<ans<<src<<endl;


}

 int minwt=1e8; 
 string minans="";
void lightest_path(int src,int dest,int wt,vector<bool>& vis,string ans)
{
      
    if(src==dest)
        {
           if(wt<minwt)
           {
               minwt=wt;
               minans=ans+to_string(dest);
              
           }
           return;
        }

      
        vis[src]=true;
        for(edge* e:graphs[src])
        {
            int v=e->v;
            int w=e->w;
            if(!vis[v])
            lightest_path(v,dest,wt+w,vis,ans+to_string(src)+"->");

        }
        vis[src]=false;
}
      
  
//===================================================================================================================================================

 int maxwt=-1; 
 string maxans="";
void heavitest_path(int src,int dest,int wt,vector<bool>& vis,string ans)
{
      
    if(src==dest)
        {
           if(wt>maxwt)
           {
               maxwt=wt;
               maxans=ans+to_string(dest);
              
           }
           return;
        }

      
        vis[src]=true;
        for(edge* e:graphs[src])
        {
            int v=e->v;
            int w=e->w;
            if(!vis[v])
            heavitest_path(v,dest,wt+w,vis,ans+to_string(src)+"->");

        }
        vis[src]=false;
}
   





int swsf = 1e8;
string spsf = "";

int lwsf = -1;
string lpsf = "";

void allSolutions(int src, int desti, vector<bool> &vis, int wsf, string psf)
{
    if (src == desti)
    {
        if (wsf < swsf)
        {
            swsf = wsf;
            spsf = psf;
        }

        if (wsf > lwsf)
        {
            lwsf = wsf;
            lpsf = psf;
        }
    }

    vis[src] = true;
    for (edge *e : graphs[src])
    {
        if (!vis[e->v])
            allSolutions(e->v, desti, vis, wsf + e->w, psf + to_string(src) + "->");
    }
    vis[src] = false;
}

int ceilval=INT_MAX;
int floorval=INT_MIN;
string ceilans="";
string floorans="";
void ceilFloor(int src,int dest,int wt,vector<bool>& vis,string ans,int factor)
{
        if(src==dest)
        {
            ans=ans+to_string(dest);
            cout<<ans<<"@"<<wt<<endl;
            if(wt>floorval && wt<factor)
            {
            floorval=wt;
            floorans=ans;
            }
            if(wt<ceilval && wt>factor)
            {
            ceilval=wt;
            ceilans=ans;
            }

            return;
        }

        vis[src]=true;
        for(edge* e:graphs[src])
        {
            int v=e->v;
            if(!vis[v])
            ceilFloor(v,dest,wt+e->w,vis,ans+to_string(src)+"->",factor);

        }
        vis[src]=false;
}
  
void dfs(int src, vector<bool> &vis)
{
    vis[src] = true;
    for (edge *e : graphs[src])
        if (!vis[e->v])
            dfs(e->v, vis);
}

void getConnectedComponents()
{
    vector<bool> vis(7, false);
    int compo = 0;
    for (int i = 0; i < 7; i++)
    {
        if (!vis[i])
        {
         
             compo++;
            dfs(i, vis);
        }
    }
    cout << compo << endl;
}

void removeEdge(int u,int v)
{
    int i=0,j=0;
    while(i<graphs[u].size())
    {
        edge* e=graphs[u][i];
        if(e->v==v)
        break;


        i++;
    }

     while(j<graphs[v].size())
    {
        edge* e=graphs[v][j];
        if(e->v==u)
        break;

        
        j++;
    }
    graphs[u].erase(graphs[v].begin()+i);
     graphs[v].erase(graphs[u].begin()+j);
}
void removevtx(int u)
{
    vector<edge*> vtxEdges=graphs[u];
    while(vtxEdges.size()!=0)
    {
        int lidx=vtxEdges.size()-1;
        edge* e=vtxEdges[lidx];
        removeEdge(u,e->v);
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
    {int n=7;
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
vector<bool> vis(7,false);
//hasPath(0,6,vis,"");
//allPath(0,6,vis,"");

// preOrderPath(0,vis,"");
//postOrderPath(0,vis,"");
// lightest_path(0,6,0,vis,"");
//  cout<<minans<<"@"<<minwt;

// heavitest_path(0,6,0,vis,"");
//  cout<<maxans<<"@"<<maxwt;
 //dfs(0,vis);
 ceilFloor(0,6,0,vis,"",49);
 cout<<"ceil"<<ceilans<<"@"<<ceilval<<endl;
cout<<"floor:"<<floorans<<"@"<<floorval<<endl;


}

