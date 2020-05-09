#include<iostream>
#include<vector>

using namespace std;

int dir[][2]={
                {-1,0},//up
                {-1,1},//east
                {0,1},//right
                {1,1},//south
                {1,0},//down
                {1,-1},//west
                {0,-1},//left
                {-1,-1}};//north
vector<string> dirN={"U","E","R","S","D","W","L","N"};
int allDirection_02(vector<vector<bool>> &vis,int sr,int sc,int er,int ec,string ans)
{
    if(sr==er && sc==ec)
    {
        cout<<ans<< " ";
        return 1; 
    }
    int count=0;
    
    for(int i=0;i<8;i++)
    {

        int x=sr+dir[i][0];
        int y=sc+dir[i][1];
        if( x>=0 && y>=0 && x<=er && y<=ec && (!vis[x][y]))
        {
            vis[x][y]=true;
            count+=allDirection_02(vis,x,y,er,ec,ans+dirN[i]);  
            vis[x][y]=false;   
            
        }
    }
     
    
    return count;
}

int allDirection_multimove(vector<vector<bool>> &vis,int sr,int sc,int er,int ec,int rad,string ans)
{
    if(sr==er && sc==ec)
    {
        cout<<ans<< " ";
        return 1; 
    }
  int count=0;
   vis[sr][sc]=true;
    for(int i=0;i<8;i++)
    {
        for(int mag=1;mag<=rad;mag++)
        {
        int x=sr+mag*dir[i][0];
        int y=sc+mag*dir[i][1];
        if( x>=0 && y>=0 && x<=er && y<=ec && (!vis[x][y]))
        {
            count+=allDirection_multimove(vis,x,y,er,ec,rad,ans+dirN[i]+to_string(rad));     
            
        }
        }
    }
      vis[sr][sc]=false;
    
    return count;
}
int main(int args,char** argb)
{
    int er=2,ec=2;
    vector<vector<bool>> vis(er+1,vector<bool>(ec+1,0));
    string ans="";
    vis[0][0]=true;
     cout<<allDirection_02(vis,0,0,er,ec,ans);
    // int rad=2;
    // cout<<allDirection_multimove(vis,0,0,er,ec,rad,ans);
}