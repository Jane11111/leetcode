#include <iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* sortedArrayToBST(vector<int>& nums);
TreeNode* Construct(vector<int>& nums,int s,int e);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {

    TreeNode* root=Construct(nums,0,nums.size()-1);
    return root;
}

TreeNode* Construct(vector<int>& nums,int s,int e){
    TreeNode* root;
    if(s==e){
        root=new TreeNode(nums[s]);
        return root;
    }else if(s>e){
        return NULL;
    }

    int mid=(s+e)/2;
    root=new TreeNode(nums[mid]);
    TreeNode* left=Construct(nums,s,mid-1);
    TreeNode* right=Construct(nums,mid+1,e);
    root->left=left;
    root->right=right;
    return root;
}