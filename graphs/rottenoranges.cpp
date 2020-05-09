//use bfs
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int bfs_rotten(vector<vector<int>>& box )
{
    queue<pair<int,int>> que;

    for(int i=0;i<box.size();i++)
    {
        for(int j=0;j<box[0].size();j++)
        {
            if(box[i][j]==2)
            {
                que.push({i,j});
            }
        }
    }

    while(que.size()!=0)
    {
        pair<int,int> rem=que.front();
        que.pop();

        if(box[rem.first][rem.second+1]==1  && rem.second+1<box[0].size())
        {que.push({rem.first,rem.second+1});

        }
         if(box[rem.first][rem.second-1]==1  && rem.second-1>=0)
        {que.push({rem.first,rem.second-1});

        }
         if(box[rem.first+1][rem.second]==1  && rem.first+1<box.size())
        {que.push({rem.first+1,rem.second});

        }
         if(box[rem.first-1][rem.second]==1  && rem.first-1>=0)
        {que.push({rem.first-1,rem.second});

        }



    }

   
    for(int i=0;i<box.size();i++)
    {
        for(int j=0;j<box[0].size();j++)
        {
            if(box[i][j]==1)
            {
                return -1;
            }
        }
    }
    return 1;


}

int main(int args,char** argb)
{

    vector<vector<int>> box{
                            {2,1,0,2,1},
                            {1,0,1,2,1},
                            {1,0,0,2,1}

    };
    cout<<bfs_rotten(box);
}