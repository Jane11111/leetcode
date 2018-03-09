#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode* constructMaximumBinaryTree(vector<int>& nums);
TreeNode* RecConstruct(vector<int>& nums,int s,int e);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
TreeNode* RecConstruct(vector<int>& nums,int s,int e){
    if(s>e)
        return NULL;
    else if(s==e)
        return new TreeNode(nums[s]);

    int max=INT_MIN;
    int index=0;
    for(int i=s;i<=e;i++){
        if(nums[i]>max){
            max=nums[i];
            index=i;
        }
    }

    TreeNode *root=new TreeNode(nums[index]);
    TreeNode *left=RecConstruct(nums,s,index-1);
    TreeNode *right=RecConstruct(nums,index+1,e);
    root->left=left;
    root->right=right;
    return root;

}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

    TreeNode *root=RecConstruct(nums,0,nums.size()-1);
    return root;
}