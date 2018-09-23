#include <iostream>
#include <vector>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
TreeNode* increasingBST(TreeNode* root);
void DFS(TreeNode* root,vector<int>& nodes);

int main() {

    TreeNode* p1=new TreeNode(1);
    TreeNode* p2=new TreeNode(2);
    TreeNode* p3=new TreeNode(3);
    TreeNode* p4=new TreeNode(4);
    TreeNode* p5=new TreeNode(5);
    TreeNode* p6=new TreeNode(6);
    TreeNode* p7=new TreeNode(7);
    TreeNode* p8=new TreeNode(8);
    TreeNode* p9=new TreeNode(9);
    p2->left=p1;
    p3->left=p2;
    p3->right=p4;
    p5->left=p3;
    p5->right=p6;
    p6->right=p8;
    p8->right=p9;
    p8->left=p7;

    TreeNode* test=increasingBST(p5);

    return 0;
}

TreeNode* increasingBST(TreeNode* root){
    if(root==NULL)
        return NULL;
    TreeNode* l=increasingBST(root->left);
    TreeNode* r=increasingBST(root->right);
    root->left=NULL;
    root->right=r;
    if(l==NULL)
        return root;
    TreeNode* head=l;
    TreeNode* p=head;
    while(p->right)
        p=p->right;
    p->right=root;
    return head;

}

