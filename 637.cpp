#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
vector<double> averageOfLevels(TreeNode* root);
int main() {
    TreeNode *p1=new TreeNode(3);
    TreeNode *p2=new TreeNode(9);
    TreeNode *p3=new TreeNode(20);
    TreeNode *p4=new TreeNode(15);
    TreeNode *p5=new TreeNode(7);
    p1->left=p2;
    p1->right=p3;
    p3->left=p4;
    p3->right=p5;
    vector<double> res=averageOfLevels(p1);
    cout<<res.size()<<endl;
}

vector<double> averageOfLevels(TreeNode* root) {
    vector<int> level_count;
    vector<double> level_sum;
    vector<TreeNode*> Q;
    level_count.push_back(1);
    level_sum.push_back(root->val);
    root->val=0;
    Q.push_back(root);
    while(!Q.empty()){
        TreeNode *p=Q[0];
        Q.erase(Q.begin());
        int cur_level=p->val;
        if((p->left||p->right)&&cur_level+1==level_count.size()){
            level_count.push_back(0);
            level_sum.push_back(0);
        }
        if(p->left){
            level_count[cur_level+1]++;
            level_sum[cur_level+1]+=p->left->val;
            p->left->val=cur_level+1;
            Q.push_back(p->left);

        }
        if(p->right){
            level_count[cur_level+1]++;
            level_sum[cur_level+1]+=p->right->val;
            p->right->val=cur_level+1;
            Q.push_back(p->right);
        }
    }
    for(int i=0;i<level_sum.size();i++){
        level_sum[i]=(level_sum[i]/level_count[i]);
    }
    return level_sum;

}