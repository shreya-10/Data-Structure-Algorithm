#include <iostream>
#include <vector>

using namespace std;

//342. Power of Four
bool isPowerOfFour(int n) {
        int count=0;
        if(n>0 && ((n & (n-1))==0))  //check if power of 2
        {
            while(n!=1)
            {
                count++;  //count all zeroes before 1;
                n>>=1;
            }
        
        if((count & 1)==0) //check if count is even.
            return true;
        }
        return false;
        
    }
//231. Power of Two LEETCODE

    bool isPowerOfTwo(int n) {
        return (n>0 && !(n & (n-1)));  // n & (n-1)==0
        
    }

//Letcode 260.
vector<int> singleNumberIII(vector<int>& nums) 
{
    int xorNum=0;
        for(int el:nums)
        xorNum^=el;
    int lastSetBit=xorNum & (~xorNum+1);
    int a=0,b=0;
    for(int el:nums)
    {
        if((el^lastSetBit)==0)
        a^=el;
        else
        {
            b^=el;
        }
        
    }
    return{a,b};
}

int OddfromPairs(vector<int>& pairs) //even number of pairs
{
    int odd=0;
    for(int el:pairs)
    {
        odd^=el;

    }
    return odd;
}

//leetcode 137
int singleNumberII(vector<int> &arr,int k)
{
    ///space O(32) time (32n)
    vector<int> bitArray(32,0);
    int OddNum=0;
    for(int el:arr)
    {
        for(int i=0;i<32;i++)
        {
            int mask=(1<<i);

            if((mask & el)!=0)
            bitArray[i]++;

        }
    }
    for(int i=0;i<32;i++)
    {
        if((bitArray[i]%k)!=0)
        {
           int mask=(1<<i);
        OddNum|=mask;
        }

    }
    return OddNum;


}
//O(1) space  O(32N) time
int singleNumberII_Mod(vector<int> &arr,int k)
{
    int singleNum=0;
    for(int i=0;i<32;i++)
    {
        int count =0;
        int mask=(1<<i);
        for(int el:arr)
        {
            if((mask & el)!=0)
            count++;
        }
        if((count%k)!=0)
        {
            singleNum|=mask;
        }
    }
    return singleNum;
}

int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i=0;i<nums.size();i++){
            twos = twos | (ones & nums[i]);
            ones = (ones ^ nums[i]);
            
            int mask = ~(ones & twos);
            ones &= mask;
            twos &= mask;
        }
        return ones;
        
    }
int NoofSetBitsOpti(int num) //Loop rusnumber of set bit times
{
    int count=0;
    while(num!=0)
    {
        num=(num&(num-1));
        count++;   
        }
        return count;
}
int noOfSetBits(int num)  // loop runs until num becomes zero
{
     int count=0;
    int totBits=32;
    while(num!=0 && totBits!=0)
    {
   
    if((num & 1)!=0)
        count++;
    
    num=num>>1;
    totBits--;
    }
    return count;
}
int setBit(int num, int k) // on -> on and off -> on
{
    int mask=(1<<k);
    return (num | mask);
}

int UnsetBit(int num, int k) // on -> off and off -> off
{
    int mask=(~(1<<k));
    return (num & mask);
}

void oddEve(int num)
{
    if((num & 1)==0)
    cout<<num <<" even";
    else
    cout<<num<<" odd";
}

int main()
{

    //int res=setBit(8,2);
    //cout<<res<<endl;
   // cout<<UnsetBit(res,2);
    //oddEve(6);
    //cout<<noOfSetBits(5);
   // cout<<NoofSetBitsOpti(16);
    //vector<int> pairs={1,1,4,2,6,2,4};
    //cout<<OddfromPairs(pairs);
    vector<int> pairs={1,1,4,2,6,2,4,1,2,4};
    //cout<<singleNumberII(pairs,3);
    cout<<singleNumberII_Mod(pairs,3);
}