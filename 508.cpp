#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> findFrequentTreeSum(TreeNode* root);
int RecSum(TreeNode* root,map<int,int>& freq);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
int RecSum(TreeNode* root,map<int,int>& freq){
    if(!root)return 0;
    int n1=RecSum(root->left,freq);
    int n2=RecSum(root->right,freq);
    int s=n1+n2+root->val;
    freq[s]++;
    return s;
}
vector<int> findFrequentTreeSum(TreeNode* root) {

    map<int,int> freq;
    RecSum(root,freq);

    vector<int> res;
    int max=INT_MIN;
    map<int,int> ::iterator ite=freq.begin();
    while(ite!=freq.end()){
        if(ite->second>max)
            max=ite->second;
        ite++;
    }
    ite=freq.begin();
    while(ite!=freq.end()){
        if(ite->second==max)
            res.push_back(ite->first);
        ite++;
    }
    return res;
}