#include <iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1;
        vector<int> l2;
        getLeaves(root1,l1);
        getLeaves(root2,l2);
        bool res=l1.size()==l2.size();
        int i=0;
        while(res&&i<l1.size()){
            res=l1[i]==l2[i];
            i++;
        }
        return res;
    }
    void getLeaves(TreeNode* root,vector<int>& l){
        if(root==NULL)
            return ;
        if(root->left==NULL&&root->right==NULL){
            l.push_back(root->val);
            return ;
        }
        getLeaves(root->left,l);
        getLeaves(root->right,l);
        return ;

    }
};

int main() {
    TreeNode* r1=new TreeNode(1);
    TreeNode* r2=new TreeNode(2);
    Solution s=Solution();
    bool res=s.leafSimilar(r1,r2);
    if(res)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}