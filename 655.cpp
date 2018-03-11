#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<string>> printTree(TreeNode* root);
int GetHeight(TreeNode *root);
string IntToStr(int n);
vector<vector<string>> res;
void Rec(TreeNode* root,int s,int e,int level);
int main() {
    TreeNode *p1=new TreeNode(1);
    TreeNode *p2=new TreeNode(2);
   // TreeNode *p3=new TreeNode(3);
  //  TreeNode *p4=new TreeNode(4);
    p1->left=p2;
  //  p1->right=p3;
  //  p2->right=p4;
    vector<vector<string>> res=printTree(p1);
    cout<<res.size()<<endl;

}
int GetHeight(TreeNode *root){
    if(!root)
        return 0;
    int n1=GetHeight(root->left);
    int n2=GetHeight(root->right);
    return max(n1,n2)+1;
}
string IntToStr(int n){
    ostringstream os;
    os<<n;
    return os.str();
}
void Rec(TreeNode* root,int s,int e,int level){
    if(s>e||!root)
        return ;
    int m=(s+e)/2;
    res[level][m]=IntToStr(root->val);
    Rec(root->left,s,m-1,level+1);
    Rec(root->right,m+1,e,level+1);
}
vector<vector<string>> printTree(TreeNode* root) {
    int h=GetHeight(root);
    int w=pow(2,h)-1;
   // vector<vector<string>> res;
    for(int i=0;i<h;i++){
        vector<string> r;
        for(int j=0;j<w;j++)
            r.push_back("");
        res.push_back(r);
    }

    Rec(root,0,w-1,0);


    return res;

}