#include<iostream>
#include<vector>
using namespace std;
//Bst construction ,max,min,find,height,size
class Node
{
    public:
    int data=0;
    Node *left=NULL;
    Node *right=NULL;


    Node(int data)
    {
        this->data=data;
    }
};
Node *create(vector<int> &arr,int si,int ei)
{
    if(si>ei) return NULL;
    // if(si==ei)
    // {
    //     Node node=new Node(arr[si]);
    //     return node;
    // }

    int mid=(si+ei)/2;  //same as divided by 2
    Node *node= new Node(arr[mid]);
    node->left=create(arr,si,mid-1);
    node->right=create(arr,mid+1,ei);
    return node;


}

 void display(Node *node)
    {
        if(node==NULL)
        return;

       string s; 
        s.append(node->left!=NULL?to_string(node->left->data):".");
        s.append("->"+to_string(node->data)+"<-");
        s.append(node->right!=NULL?to_string(node->right->data):".");
        cout<<s<<"\n";

        display(node->left);
        display(node->right);


    }

bool find(Node *node,int data)
{   if(node==NULL)
return false;
    if(node->data==data)
    return true;
   
    bool l=find(node->left,data);
    bool r=find(node->right,data);
    return l||r;
}
 //in bst maximum is always  on right tree
int findmax(Node*node)
{
 
Node*curr=node;
while(curr->right!=NULL)
curr=curr->right;
return curr->data;

}
int findmin(Node *node)
{
    Node*curr=node;
while(curr->left!=NULL)
curr=curr->left;
return curr->data;
}

int height(Node* node)
{
    return(node==NULL) ?0 : max(height(node->left),height(node->right))+1;

}
int size(Node* node)
{
    return(node==NULL) ?0 : size(node->left),size(node->right)+1;

}


bool find(Node *node,int data,int level,string ans)
{   if(node==NULL)
return false;
    if(node->data==data)
    {   cout <<ans<<" "<<data;
        cout<<endl<<"Height of data in tree :"<<level<<endl;
        return true;
    }
    else if(node->data>data)
    return find(node->left,data,level+1,ans+to_string(node->data)+" ");
     else if(node->data<data)
   return find(node->right,data,level+1,ans+to_string(node->data)+" ");
}

 int LCA(Node* node,int d1,int d2)
 {
     if(node==NULL)
     return -1;

     if(node->data<d1)
     return LCA(node->right,d1,d2);
     else if(node->data>d2)
     return LCA(node->left,d1,d2);
     else 
     return node->data;

 }

static Node* previ=NULL;
static Node* succ=NULL;
static  Node* pred=NULL;
 void predSucc(Node* curr,int data)
 {
     if(curr==NULL)
     return;
     predSucc(curr->left,data);
    if(curr->data==data,data)
    pred=previ;
    if(previ!=NULL && previ->data==data)
    succ=curr;

    previ=curr;
    predSucc(curr->right,data);
 }


 void addNode_03(Node **node,int data)
 {
     if((*node)==NULL)
     {
         (*node)=new Node(data);
         return;
     }
     if((*node)->data==data)
     {
         (*node)->freq++;
         return;
     }
     else if(data<(*node)->data)
       addNode_03(node.left,data);    
       else 
       addNode_03(node.right,data);
 }
void solve()
{
    vector<int> arr={10,20,30,40,50,60,70,80};
    Node *root=create(arr,0,arr.size()-1);
    display(root);
    cout<<(boolalpha)<<find(root,80,1,"")<<"\n";
    cout<<"Max:"<<findmax(root)<<"\n";
    cout<<"Min:"<<findmin(root);
    predSucc(root,20);
    cout<<"\nPredeccor succesor"<<endl<<(pred!=NULL?pred->data:-1)<<"->" << 20<<"<-"<<(succ!=NULL?succ->data:-1);
}
int main(int arga,char** argb)
{
solve();
}
