#include <iostream>
#include <vector>

using namespace std;

class Node{
public :
    int val;
    vector<Node*> children;
    Node(){}
    Node(int _val,vector<Node*> _children){
        val=_val;
        children=_children;
    }
};

class Solution{
public:
    int maxDepth(Node* root){
        if (root==NULL)
            return 0;
        int deep=1;
        vector<Node*> children=root->children;
        int max_length=0;
        for (int i=0;i<children.size();i++){
            Node* v=children[i];
            max_length=max(max_length,maxDepth(v));

        }
        return deep+max_length;

    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

