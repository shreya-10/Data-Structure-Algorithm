#include<iostream>
#include<queue>
using namespace std;


void demo_1()
{
     priority_queue<int> pq;
     
     pq.push(5);
     pq.push(1);
     pq.push(8);
     pq.push(85);
     pq.push(11);

     while(pq.size()!=0)
     {
         int top=pq.top();
         pq.pop();
         cout<<top<<"  ";
     }
     
}
void demo_2()
{
     priority_queue<int,vector<int>,greater<int>> pq;//lowest nmbr is popped first
     
     pq.push(5);
     pq.push(1);
     pq.push(8);
     pq.push(85);
     pq.push(11);

     while(pq.size()!=0)
     {
         int top=pq.top();
         pq.pop();
         cout<<top<<"  ";
     }
     
}
class event 
{
    public:
    int s;
    int e;
    event(int s,int e)
    {
        this->s=s;
        this->e=e;
    }
    bool operator<(const event& other )const
    {
        return this->s< other.s;
    }
    
     bool operator>(const event& other )const
    {
        return this->s> other.s;
    }

};
void demo_3()
{
    priority_queue<event,vector<event>,greater<event>> pq;

    event e1(10,6);
    event e2(11,5);
    event e3(9,12);
    event e4(2,8);
    pq.push(e1);
    pq.push(e2);
    pq.push(e3);
    pq.push(e4);


while(pq.size()!=0)

     {
         event top=pq.top();
         pq.pop();
         cout<<top.s<<"  "<<top.e<<endl;
     }
}

int main(int arg,char** argb)
{
 demo_3();
}