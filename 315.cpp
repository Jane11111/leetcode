#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int index;
    int val;
    Node(int x,int v):index(x),val(v){}
};
vector<int> countSmaller(vector<int>& nums);
void Sort(vector<Node*>& nodes,int s,int e);
void Merge(vector<Node*>& nodes,int s1,int e1,int s2,int e2);
vector<int>res;
int main() {
    vector<int>nums;
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(3);
    nums.push_back(1);
    vector<int> res=countSmaller(nums);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}


vector<int> countSmaller(vector<int>& nums) {
    int len=nums.size();
    for(int i=0;i<len;i++)
        res.push_back(0);
    vector<Node*> nodes;
    for(int i=0;i<len;i++){
        nodes.push_back(new Node(i,nums[i]));
    }
    Sort(nodes,0,len-1);
    return res;


}
void Sort(vector<Node*>& nodes,int s,int e){
    if(s>=e)
        return;
    int mid=(s+e)/2;
    Sort(nodes,s,mid);
    Sort(nodes,mid+1,e);
    Merge(nodes,s,mid,mid+1,e);
}
void Merge(vector<Node*>& nodes,int s1,int e1,int s2,int e2){
    vector<Node*> L;
    vector<Node*> R;
    for(int i=s1;i<=e1;i++)
        L.push_back(nodes[i]);
    L.push_back(new Node(-1,INT_MAX));
    for(int i=s2;i<=e2;i++)
        R.push_back(nodes[i]);
    R.push_back(new Node(-1,INT_MAX));
    int i=0;
    int j=0;
    int count=0;
    int sum=0;
    while (i!=e1-s1+1||j!=e2-s2+1){
        Node* l=L[i];
        Node* r=R[j];
        if(r->val<l->val){
            sum++;
            //if(l->index!=-1)
            //    res[l->index]=res[l->index]+sum;
            nodes[s1+count]=r;
            j++;

        }else{
            nodes[s1+count]=l;
            if(l->index!=-1)
                res[l->index]=res[l->index]+sum;
            i++;
        }
        count++;
    }

}
