#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> pathSum(TreeNode* root, int sum) ;
void Rec(TreeNode* root, int sum,vector<int>& paths) ;
vector<vector<int>> res;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
void Rec(TreeNode* root, int sum,vector<int>& paths){

    if(!root)
        return ;

    if(!root->left&&!root->right&&root->val==sum)
        res.push_back(paths);
    else{
        if(root->left){
            paths.push_back(root->left->val);
            root->left->val+=root->val;
            Rec(root->left,sum,paths);
            paths.erase(paths.begin()+paths.size()-1);
        }
        if(root->right){
            paths.push_back(root->right->val);
            root->right->val+=root->val;
            Rec(root->right,sum,paths);
            paths.erase(paths.begin()+paths.size()-1);
        }
    }

}
vector<vector<int>> pathSum(TreeNode* root, int sum) {

    vector<int> paths;
    if(root){
        paths.push_back(root->val);
        Rec(root,sum,paths);
    }
    return res;
}