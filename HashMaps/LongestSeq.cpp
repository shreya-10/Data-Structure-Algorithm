#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


void longestSequence(vector<int>& arr)
{
    unordered_map<int,bool> map;
    for(int el:arr)
    {
        map[el]=true;
    }
    int size=-1;
    int number=-1;
    for(auto pair:map)
    {
        if(map.find(pair.first-1)!=map.end())
        map[pair.first]=false;

    }
     for(auto pair:map)
    {
        if(pair.second==true)
        {
            int num=pair.first+1;
            int smallsize=1;
            while(map.find(num)!=map.end())
            {
                num++;
                smallsize++;
            }

            if(smallsize>size)
            {
                size=smallsize;
                number=pair.first;
            }

        }

    }
    // for(int i=1;i<=size;i++)
    // cout<<number-i<<" ";
  
for(int i=0;i<size;i++)
cout<<number+i<<" ";
  cout<<"\nsize:"<<size;

}
int main(int args,char** argb)
{   vector<int> arr={0,1,2,6,7,100,98,97,96,95,101,94,99,93,92,102,103,12,3,4,5,10,8};
    longestSequence(arr);
}