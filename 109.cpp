#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* sortedListToBST(ListNode* head);
TreeNode* Construct(vector<int>& nums,int s,int e);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

TreeNode* sortedListToBST(ListNode* head) {

    vector<int> nums;
    while(head!=NULL){
        nums.push_back(head->val);
        head=head->next;
    }
    TreeNode * root=Construct(nums,0,nums.size()-1);
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
