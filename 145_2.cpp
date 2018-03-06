#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
vector<int> postorderTraversal(TreeNode* root);

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

vector<int> postorderTraversal(TreeNode* root){

    vector<TreeNode*> Q;
    if(root)
        Q.push_back(root);
    vector<int> res;
    while(!Q.empty()){
        TreeNode* p=Q[0];
        Q.erase(Q.begin());
        res.insert(res.begin(),p->val);
        if(p->left!=NULL)
            Q.insert(Q.begin(),p->left);
        if(p->right!=NULL)
            Q.insert(Q.begin(),p->right);
    }
    return res;
}
