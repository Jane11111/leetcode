#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<TreeNode*>generateTrees(int n);
vector<TreeNode*> Next(vector<TreeNode*>&pre_tree,int num);
TreeNode* Copy(TreeNode* head);
int main() {
    int n=3;
    vector<TreeNode*> res=generateTrees(n);
    cout<<res.size()<<endl;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> tree;
    for(int i=0;i<=n;i++){
        tree=Next(tree,i);
    }
    return tree;
}

vector<TreeNode*> Next(vector<TreeNode*>&pre_tree,int num){
    vector<TreeNode*> new_tree;
    if(num==1){
        new_tree.push_back(new TreeNode(num));
        return new_tree;
    }
    int len=pre_tree.size();
    for(int i=0;i<len;i++){
        TreeNode* head=pre_tree[i];
        TreeNode* cur=pre_tree[i];
        TreeNode* p=new TreeNode(num);
        p->left=cur;
        TreeNode* new_tree_head=Copy(p);
        new_tree.push_back(new_tree_head);
        while(cur){
            TreeNode* p=new TreeNode(num);
            p->left=cur->right;
            cur->right=p;
            TreeNode* new_tree_head=Copy(head);
            new_tree.push_back(new_tree_head);
            cur->right=p->left;
            cur=cur->right;
        }

    }

    return new_tree;
}

TreeNode* Copy(TreeNode* head){
    if(head==NULL)
        return NULL;
    TreeNode* new_head=new TreeNode(head->val);
    vector<TreeNode*> Q;
    vector<TreeNode*>new_Q;
    Q.push_back(head);
    new_Q.push_back(new_head);
    while(!Q.empty()){
        TreeNode* p=Q[0];
        Q.erase(Q.begin());
        TreeNode* new_p=new_Q[0];
        new_Q.erase(new_Q.begin());

        if(p->left!=NULL){
            TreeNode* new_left=new TreeNode(p->left->val);
            new_p->left=new_left;
            Q.push_back(p->left);
            new_Q.push_back(new_p->left);
        }
        if(p->right!=NULL){
            TreeNode* new_right=new TreeNode(p->right->val);
            new_p->right=new_right;
            Q.push_back(p->right);
            new_Q.push_back(new_p->right);
        }

    }
    return new_head;
}