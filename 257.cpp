#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<string> binaryTreePaths(TreeNode* root);
int main() {
    TreeNode*p1=new TreeNode(1);
    TreeNode*p2=new TreeNode(2);
    TreeNode*p3=new TreeNode(3);
    TreeNode*p4=new TreeNode(5);
    p1->left=p2;
    p1->right=p3;
    p2->right=p4;
    vector<string> res=binaryTreePaths(p1);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    vector<string> real_res;
    if(root==NULL)
        return res;
    vector<TreeNode*>Q;
    Q.push_back(root);
    ostringstream os;
    os<<root->val;
    res.push_back(os.str());
    while(!Q.empty()){
        TreeNode*p=Q[0];
        Q.erase(Q.begin());
        string str=res[0];
        res.erase(res.begin());
        if(p->left==NULL&&p->right==NULL)
            real_res.push_back(str);
        if(p->left!=NULL){
            ostringstream os;
            os<<p->left->val;

            string s1=str+"->"+os.str();
            res.push_back(s1);
            Q.push_back(p->left);
        }
        if(p->right!=NULL){
            ostringstream os;
            os<<p->right->val;
            string s2=str+"->"+os.str();
            res.push_back(s2);
            Q.push_back(p->right);
        }

    }
    return real_res;

}