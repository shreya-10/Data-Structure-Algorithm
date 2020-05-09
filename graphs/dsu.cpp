#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n=7;
 vector<vector<pair<int,int>>> newgraph(7,vector<pair<int,int>>());
class edges{
    public:
    int u;
    int v;
    int wt;
    edges(int u,int v,int wt)
    {
        this->u=u;
         this->v=v;
          this->wt=wt;
    }

    bool operator>(const edges& other) const { // check
        return this->wt > other.wt;
    }
};

void merge(int p1,int p2,vector<int>& par,vector<int>& size)
{
    if(size[p1]<size[p2])
    {
        par[p1]=p2;
        size[p2]+=size[p1];
    }
    else
    {
        par[p2]=p1;
        size[p1]+=size[p2];
    }
}

int findpar(int vtx, vector<int> &par) //need parent
{
    if(par[vtx]==vtx)
    return vtx;

    par[vtx]=findpar(par[vtx], par);
    
    return par[vtx];

}

void display()
    {
        for(int i=0;i<newgraph.size();i++)
        {
            cout<<i<<"->";
            for( pair<int,int> e:newgraph[i])
            {
               cout<<"("<<e.first<<","<<e.second<<")";
            }
             cout<<endl;
        }

    }

int main(int arg,char** argb)
{
   
    vector<int> par(n);
    vector<int> size(n,1);
    for(int i=0;i<par.size();i++)
    {
        par[i]=i;
    }
    

    // vector<vector<int>> edges(6,vector<int>(2));
    // edges.push_back(0,1);
    // edges.push_back(1,2);
    // edges.push_back(0,3);
    // edges.push_back(3,2);
    // edges.push_back(4,5);
    // edges.push_back(4,6);
    edges e1(0,1,10);
    edges e2(0,3,40);
    edges e3(1,2,10);
  
    edges e4(3,4,5);
    edges e5(4,5,4);
    edges e6(5,6,3);
    edges e7(4,6,8);
    edges e8(2,3,10);
    int p1;
     int p2;

    priority_queue<edges, vector<edges>,greater<edges>> pq;
    pq.push(e1);
    pq.push(e2);
    pq.push(e3);++
    pq.push(e4);
    pq.push(e5);
    pq.push(e6);
    pq.push(e7);
    pq.push(e8);

    while(pq.size()!=0)
    {
        edges rem=pq.top();
        pq.pop();
        p1=findpar(rem.u, par);
        p2=findpar(rem.v, par);
         if(p1!=p2)
         {
              merge(p1,p2,par,size);
              newgraph[rem.u].push_back({rem.v,rem.wt});
              newgraph[rem.v].push_back({rem.u,rem.wt});
         }
         
    }
    display();
  
// for(int i=0;i<par.size();i++)
//     {
//         cout<<par[i]<<"  ";
//     }
//     cout<<endl;
//     for(int i=0;i<size.size();i++)
//     {
//         cout<<size[i]<<"  ";
//     }


    
}