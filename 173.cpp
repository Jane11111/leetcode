#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
class BSTIterator {
    TreeNode* i;
    BSTIterator(TreeNode *root) {
        i=root;
    }

    bool hasNext() {

        if(i==NULL)
         return false;
        else
         return true;
    }

    int next() {
        if(!i->left){
            int res=i->val;
            i=i->right;
            return res;
        }
        TreeNode* cur=i->left;
        TreeNode* pre=i;
        while(cur->left){
            cur=cur->left;
            pre=pre->left;
        }
        pre->left=cur->right;
        return cur->val;


    }
};