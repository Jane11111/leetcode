#include <iostream>
#include<vector>
using namespace std;

struct Node{
    int val;
    int extra;
    Node* next;
    Node():val(0),extra(0),next(NULL){}
    Node(int x,int y=0,Node* p=NULL):val(x),extra(y),next(p){}
};

vector<int> findRedundantConnection(vector<vector<int>>& edges);
void DFS(Node* s,Node* v,vector<Node*>G,vector<int>& Circle,bool* arr);
void PrintRes(vector<int> res){
    for (int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}
int main() {

    vector<vector<int>> edges;
    vector<int> e1;
    e1.push_back(1);
    e1.push_back(2);
    vector<int> e2;
    e2.push_back(2);
    e2.push_back(3);
    vector<int> e3;
    e3.push_back(3);
    e3.push_back(4);
    vector<int> e4;
    e4.push_back(1);
    e4.push_back(4);
    vector<int> e5;
    e5.push_back(1);
    e5.push_back(5);
    edges.push_back(e1);
    edges.push_back(e2);
    edges.push_back(e3);
    edges.push_back(e4);
    edges.push_back(e5);

    vector<int> res=findRedundantConnection(edges);
    PrintRes(res);



}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    vector<Node*> G;
    int len=edges.size();
    //变为邻接链表表示
    for(int i=0;i<len;i++){
        vector<int> e=edges[i];
        if(e[1]>=G.size()){
            for(int j=G.size();j<=e[1];j++){
                Node* v =new Node(j);
                G.push_back(v);

            }
        }
        Node* v1=G[e[0]];
         Node* p1=new Node(e[1],i,v1->next);

        v1->next=p1;

        Node*v2=G[e[1]];
        Node* p2=new Node(e[0],i,v2->next);
        v2->next=p2;
    }

    vector<int> edge_number;//纪录每个结点的边的数目
    for(int i=0;i<G.size();i++)
        edge_number.push_back(0);

    for(int i=0;i<edges.size();i++){
        vector<int> e=edges[i];

        edge_number[e[0]]++;
        edge_number[e[1]]++;
    }

    vector<int> non_circle;//纪录不属于circle的结点
    for(int i=0;i<G.size();i++)
        if(edge_number[i]==1)
            non_circle.push_back(i);

    while(!non_circle.empty()){//从边数位1的结点开始，循环删去那些不再环上的结点，即设为1
        int v=non_circle[0];
        non_circle.erase(non_circle.begin());

        Node* p=G[v]->next;//v的邻居
        while(p!=NULL){
            if(edge_number[p->val]>1){
                edge_number[p->val]--;
                if(edge_number[p->val]==1)
                    non_circle.push_back(p->val);
            }
            p=p->next;
        }
    }
    vector<int> e;

    for(int i=edges.size()-1;i>=0;i--){
        e=edges[i];
        if(edge_number[e[0]]!=1&&edge_number[e[1]]!=1)
            return e;
    }

    return e;


}

void DFS(Node* s,Node* v,vector<Node*> G,vector<int>& Circle,bool* visited){
    Node* p=G[v->val];
    visited[v->val]=true;
    while(p!=NULL){
        Node * u=p->next;
        if(u->val==s->val){
            s->val=-1;
            return ;

        }
        if(!visited[u->val]) {
            Circle.push_back(u->val);
            DFS(s, u, G, Circle, visited);
            if(s->val!=-1)
                Circle.pop_back();
            else
                break;
        }
        p=p->next;
    }

}


