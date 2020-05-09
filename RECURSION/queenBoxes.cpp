#include<iostream>
#include<vector>
using namespace std;
int queenCombi(int tq,int tboxes,int qpsf,int bsf,string ans)
{
    if(qpsf==tq)
    {
    cout<<ans<<endl;
    return 1;
    }
    int count=0;
    for(int i=bsf;i<tboxes;i++)
    count+=queenCombi(tq,tboxes,qpsf+1,i+1,ans+"B"+to_string(i)+"q"+to_string( qpsf)+" ");
    return count;
}

int queenPermu(int tq,int tboxes,int qpsf,vector<bool>& vis,string ans)
{
    if(qpsf==tq)
    {
    cout<<ans<<"   ";
    return 1;
    }
    int count=0;
    
    for(int i=0;i<tboxes;i++)
    {
        if(!vis[i])
        {
        vis[i]=true;
      count+=queenPermu(tq,tboxes,qpsf+1,vis, ans+"B"+to_string(i)+"q"+to_string( qpsf)+" ");
        vis[i]=false;
        }
    }
    return count;
}

int queenpermu_02(int tq,int tboxes,int idx,int qpsf,vector<bool>& vis,string ans)
{
    if(idx==tboxes || tq==qpsf )
       {
           if(tq==qpsf)
           {
           cout<<ans<<"    ";
           return 1;
           }
           return 0;
       }
int count=0;
       if(!vis[idx])
       {
           vis[idx]=true;
       count+=queenpermu_02(tq,tboxes,0,qpsf+1,vis,ans+"B"+to_string(idx)+"q"+to_string( qpsf)+" ");
       vis[idx]=false;
       }

       count+=queenpermu_02(tq,tboxes,idx+1,qpsf,vis,ans);
       return count;
}


int queenCombi2D(vector<vector<int>>& boxes,int tqueen,int idx,string ans)
{
    if(tqueen==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<boxes.size()*boxes[0].size();i++)
    {
        int r=i/boxes[0].size();
        int c=i%boxes[0].size();
        count+=queenCombi2D(boxes,tqueen-1,i+1,ans+"("+to_string(r)+","+to_string(c)+")");
    }
    return count;
}
int queenPermu2D(vector<vector<int>>& boxes,int tqueen,int idx,string ans,vector<bool> vis)
{
    if(tqueen==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<boxes.size()*boxes[0].size();i++)
    {
        int r=i/boxes[0].size();
        int c=i%boxes[0].size();
        if(!vis[i])
        {
        vis[i]=true;
        count+=queenPermu2D(boxes,tqueen-1,i+1,ans+"("+to_string(r)+","+to_string(c)+")",vis);
        vis[i]=false;
        }
    }

    return count;
}
int main(int args,char** argb)
{
    int n=3;
    int m=3;
    vector<bool> vis(n*m,0);
vector<vector<int>> boxes(n,vector<int>(m));
   // cout<<endl<<queenCombi(3,9,0,0,"");
    cout<<endl<<queenPermu(3,9,0,vis,"");
    //cout<<endl<<queenpermu_02(3,5,0,0,vis,"");
   //cout<<queenCombi2D(boxes,3,0,"");
   cout<<queenPermu2D(boxes,3,0,"",vis);
   

}