#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
int widthOfBinaryTree(TreeNode* root);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int widthOfBinaryTree(TreeNode* root) {

    vector<TreeNode*> Q;
    int max=0;
    if(root) {
        root->val=1;
        Q.push_back(root);
    }
    map<int,int> starts;
    starts[1]=1;

    while(!Q.empty()){

        TreeNode*p=Q[0];
        Q.erase(Q.begin());
        int level=int(log(p->val)/log(2))+1;
        if(starts.count(level)==0){
            starts[level]=p->val;
        }
        int start=starts[level];

        if(p->val-start+1>max)
            max=p->val-start+1;

        if(p->left){
            p->left->val=p->val *2;
            Q.push_back(p->left);
        }

        if(p->right){
            p->right->val=p->val *2+1;
            Q.push_back(p->right);
        }

    }
    return max;

}