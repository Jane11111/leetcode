#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val=NULL;
    vector<Node*> children;
    Node(){}
    Node(int _val,vector<Node*> _children){
        val=_val;
        children=_children;
    }
};
vector<vector<int>> levelOrder(Node* root);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> res;
    if(root==NULL)
        return res;
    vector<Node*> Q;
    vector<int> levels;
    Q.push_back(root);
    levels.push_back(0);
    while(!Q.empty()){
        int l=levels.at(0);
        levels.erase(levels.begin());
        Node* cur=Q.at(0);
        Q.erase(Q.begin());
        if(res.size()==l)
            res.push_back(vector<int> ());
        res[l].push_back(cur->val);
        for(Node* c:cur->children){
            Q.push_back(c);
            levels.push_back(l+1);
        }


    }
    return res;

}