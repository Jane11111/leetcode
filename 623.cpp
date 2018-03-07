#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
TreeNode* addOneRow(TreeNode* root, int v, int d);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


TreeNode* addOneRow(TreeNode* root, int v, int d){


    if(d==1){
        TreeNode *head=new TreeNode(v);
        head->left=root;
        return head;
    }
    d--;
    vector<int> record;
    record.push_back(1);
    int index=0;
    vector<TreeNode*> Q;
    Q.push_back(root);
    while(!Q.empty()){
        TreeNode * p=Q[0];
        Q.erase(Q.begin());
        if(record[index]==d){
            TreeNode *p1=new TreeNode(v);
            TreeNode *p2=new TreeNode(v);
            p1->left=p->left;
            p2->right=p->right;
            p->left=p1;
            p->right=p2;

        }else{
            if(p->left){
                Q.push_back(p->left);
                record.push_back(record[index]+1);
            }
            if(p->right){
                Q.push_back(p->right);
                record.push_back(record[index]+1);
            }
        }
        index++;
    }
    return root;
}