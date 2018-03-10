#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void connect(TreeLinkNode *root) {

    vector<TreeLinkNode *> Q;
    vector<int> levels;
    levels.push_back(1);
    int i=0;
    if(root)
        Q.push_back(root);
    while(!Q.empty()){
        TreeLinkNode *p=Q[0];
        Q.erase(Q.begin());
        int num=levels[i];
        i++;
        if(!Q.empty()&&num==levels[i])
            p->next=Q[0];

        if(p->left){
            Q.push_back(p->left);
            levels.push_back(num+1);
        }
        if(p->right){
            Q.push_back(p->right);
            levels.push_back(num+1);
        }

    }

}