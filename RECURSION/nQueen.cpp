#include<iostream>
#include<vector>
using namespace std;


bool isSafetoPlaceQueen(vector<vector<bool>>& boxes,int x,int y)
{
    vector<vector<int>> dir={ {0,-1},{-1,-1},{-1,0},{-1,1}};
    for(int d=0;d<dir.size();d++)
    {
        for(int rad=1;rad<max(boxes.size(),boxes[0].size());rad++)
        {
            int checkr=x+rad*dir[d][0];
            int checkc=y+rad*dir[d][1];

            if(checkr>=0 && checkc>=0 && checkr<boxes.size() && checkc<boxes[0].size())
            {
                if(boxes[checkr][checkc])
                return false;
            }
            else break;
        }
    }
    return true;
}
int NQueen(vector<vector<bool>>& boxes,int tnq,int idx,string ans)
{
    int n=boxes.size();
    int m=boxes[0].size();
    if(tnq==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<n*m;i++)
    {
        int x=i/m;
        int y=i%m;
        if(isSafetoPlaceQueen(boxes,x,y))
        {
            boxes[x][y]=true;
            count+= NQueen(boxes,tnq-1,i+1,ans+"("+to_string(x)+","+to_string(y)+")");
            boxes[x][y]=false;
        }
    }
return count;
}
int rows=4;
int cols=4;
vector<int> rowA(rows);
vector<int> colA(cols);
vector<int> diagA(rows+cols-1);
vector<int> adiagA(rows+cols-1);
int NQueen_02(int n,int m,int tnq,int idx,string ans)
{

    if(tnq==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<n*m;i++)
    {
        int x=i/m;
        int y=i%m;
        if(!rowA[x] && !colA[y] && !diagA[x-y+m-1] && !adiagA[x+y])
        {
            rowA[x]=true; 
            colA[y]=true; 
            diagA[x-y+m-1]=true;
            adiagA[x+y]=true;
            count+= NQueen_02(n,m,tnq-1,i+1,ans+"("+to_string(x)+","+to_string(y)+")");
            rowA[x]=false; 
            colA[y]=false; 
            diagA[x-y+m-1]=false;
            adiagA[x+y]=false;
           
        }
    }
return count;
}

int rowbit=0;
int colbit=0;
int diagbit=0;
int adiagbit=0;
int NQueen_02_bits(int n,int m,int tnq,int idx,string ans)
{

    if(tnq==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<n*m;i++)
    {
        int x=i/m;
        int y=i%m;
        if((rowbit & (1<<x))==0 && (colbit & (1<<y))==0 && (diagbit & (1<<(x-y+m-1)))==0 && (adiagbit & (1<<(x+y)))==0)
        {
           rowbit|=(1<<x);
           colbit|=(1<<y);
           diagbit|=(1<<(x-y+m-1));
           adiagbit|=(1<<(x+y));
            count+= NQueen_02_bits(n,m,tnq-1,i+1,ans+"("+to_string(x)+","+to_string(y)+")");
            rowbit&=(~(1<<x));
           colbit&=(~(1<<y));
           diagbit&=(~(1<<(x-y+m-1)));
           adiagbit&=(~(1<<(x+y)));
           
        }
    }
return count;
}

int NQueen_03_bits(int n,int m,int tnq,int houserow,string ans)///houses and rooms
{

    if(tnq==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<m;i++)//loop for rooms
    {
        int x=houserow;
        int y=i;
        if((rowbit & (1<<x))==0 && (colbit & (1<<y))==0 && (diagbit & (1<<(x-y+m-1)))==0 && (adiagbit & (1<<(x+y)))==0)
        {
           rowbit|=(1<<x);
           colbit|=(1<<y);
           diagbit|=(1<<(x-y+m-1));
           adiagbit|=(1<<(x+y));
            count+= NQueen_02_bits(n,m,tnq-1,houserow+1,ans+"("+to_string(x)+","+to_string(y)+")");
            rowbit&=(~(1<<x));
           colbit&=(~(1<<y));
           diagbit&=(~(1<<(x-y+m-1)));
           adiagbit&=(~(1<<(x+y)));
           
        }
    }
return count;
}

int Nqueen_03_sub(int n, int m, int tnq, int idx, string ans)
{ //qpsf : queen place so far, tnq: total no of queen
    if (idx == n * m || tnq == 0)
    {
        if (tnq == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    int x = idx / m;
    int y = idx % m;

    if (!(rowbit & (1 << x)) && !(colbit & (1 << y)) && !(diagbit & (1 << (x - y + m - 1))) && !(adiagbit & (1 << (x + y))))
    {
        rowbit ^= (1 << x);
        colbit ^= (1 << y);
        diagbit ^= (1 << (x - y + m - 1));
        adiagbit ^= (1 << (x + y));

        count += Nqueen_03_sub(n, m, tnq - 1, idx + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");

        rowbit ^= (1 << x);
        colbit ^= (1 << y);
        diagbit ^= (1 << (x - y + m - 1));
        adiagbit ^= (1 << (x + y));
    }
    count += Nqueen_03_sub(n, m, tnq, idx + 1, ans);

    return count;
}

bool isSafetoPlaceQueen_permu(vector<vector<bool>>& boxes,int x,int y)
{
    vector<vector<int>> dir_={{0,-1},{-1,-1},{-1,0},{-1,1},{1,0},{1,1},{0,1},{1,-1}};
    for(int d=0;d<8;d++)
    {
        for(int rad=1;rad<max(boxes.size(),boxes[0].size());rad++)
        {
            int checkr=x+rad*dir_[d][0];
            int checkc=y+rad*dir_[d][1];

            if(checkr>=0 && checkc>=0 && checkr<boxes.size() && checkc<boxes[0].size())
            {
                if(boxes[checkr][checkc])
                return false;
            }
            else break;
           
        }
    }
    return true;
}
int NQueen_permu(vector<vector<bool>>& boxes,int tnq,string ans)
{
    int n=boxes.size();
    int m=boxes[0].size();
    if(tnq==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<n*m;i++)
    {
        int x=i/m;
        int y=i%m;
        if((boxes[x][y]==false) && isSafetoPlaceQueen_permu(boxes,x,y))
        {

            boxes[x][y]=true;
            count+= NQueen_permu(boxes,tnq-1,ans+"("+to_string(x)+","+to_string(y)+")");
            boxes[x][y]=false;
        }
    }
    return count;
}

int main()
{
    vector<vector<bool>> boxes(4,vector<bool>(4,false));
    // cout<<NQueen(boxes,4,0,"");
    //cout<<NQueen_02(rows,cols,4,0,"");
    //cout<<NQueen_02_bits(rows,cols,4,0,"");
     ///cout<<NQueen_permu(boxes,4,"");
      cout<<NQueen_03_bits(rows,cols,4,0,"");

}