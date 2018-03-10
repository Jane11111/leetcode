#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int pathSum(TreeNode* root, int sum);
void Rec(TreeNode* root,int cur_sum,int sum);
int count;
int main() {
    TreeNode *p1=new TreeNode(1);
    TreeNode *p2=new TreeNode(2);
    TreeNode *p3=new TreeNode(3);
    TreeNode *p4=new TreeNode(4);
    TreeNode *p5=new TreeNode(5);
    p1->right=p2;
    p2->right=p3;
    p3->right=p4;
    p4->right=p5;
    int res=pathSum(p1,3);
    cout<<res<<endl;
    return 0;
}
void Rec(TreeNode* root,int cur_sum,int sum){
    if(!root)
        return ;
    if(cur_sum+root->val==sum){
        count++;
    }
    if(root->left){
        Rec(root->left,cur_sum+root->val,sum);

    }
    if(root->right){
        Rec(root->right,cur_sum+root->val,sum);
    }
}
int pathSum(TreeNode* root, int sum) {
    count=0;
    vector<TreeNode*> Q;
    if(root)
        Q.push_back(root);
    while(!Q.empty()){
        TreeNode* p=Q[0];
        Q.erase(Q.begin());
        Rec(p,0,sum);
        if(p->left)
            Q.push_back(p->left);
        if(p->right)
            Q.push_back(p->right);
    }
    return count;

}
