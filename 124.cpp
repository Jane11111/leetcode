#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
int maxPathSum(TreeNode* root);
int CalMax(TreeNode* root,int& max);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int maxPathSum(TreeNode* root) {
    int max=INT_MIN;
    CalMax(root,max);
    return max;

}
int CalMax(TreeNode* root,int & max){
    if(root==NULL)
        return INT_MIN;
    int left=CalMax(root->left,max);
    int right=CalMax(root->right,max);
    int sum=root->val;
    if(left>0)
        sum+=left;
    if(right>0)
        sum+=right;
    if(sum>max)
        max=sum;
    if(left<=0&&right<=0)
        return root->val;
    if(left>=right)
        return root->val+left;
    else
        return root->val+right;
}