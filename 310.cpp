#include <iostream>
#include<vector>
using namespace std;
struct Node{
    int label;
    Node * next;
    Node * pi;
    int h;
    bool is_leaf;
    Node(int x,Node* p=NULL,int d=0,bool f=false): label(x),next(p),h(d),is_leaf(false),pi(NULL){}
};
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) ;
void Insert(Node* head,int label);

int main() {
    int n=6;
    vector<pair<int,int>>edges;
    pair<int,int>e1;
    e1.first=3;
    e1.second=0;
    pair<int,int> e2;
    e2.first=1;
    e2.second=3;
    pair<int,int>e3;
    e3.first=2;
    e3.second=3;
    pair<int,int> e4;
    e4.first=4;
    e4.second=3;
    pair<int,int>e5;
    e5.first=5;
    e5.second=4;
    edges.push_back(e1);
    edges.push_back(e2);
    edges.push_back(e3);
    edges.push_back(e4);
    edges.push_back(e5);
    vector<int> res=findMinHeightTrees(n,edges);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}
void Insert(Node* head,int label){
    Node * new_node=new Node(label);
    new_node->next=head->next;
    head->next=new_node;
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    //变成邻接链表表示
    vector<Node*> G;
    for(int i=0;i<n;i++){
        G.push_back(new Node(i));
    }
    for(int i=0;i<edges.size();i++){
        pair<int,int > e=edges[i];
        Insert(G[e.first],e.second);
        Insert(G[e.second],e.first);
    }

    int visited[n];
    for(int i=0;i<n;i++)
        visited[i]=-1;
    vector<int> min_height;
    for(int i=0;i<n;i++)
        min_height.push_back(-1);
    //for(int i=0;i<n;i++){
        //BFS
        Node* s=G[0];
        vector<Node* > Q;
        Q.push_back(s);
        G[s->label]->h=0;//更新高度
        visited[s->label]=s->label;//标记为遍历过
        if(s->next==NULL&&s->h>min_height[s->label]) {//为叶子结点，更新min_height
            min_height[s->label] = G[s->label]->h;
            G[s->label]->is_leaf=true;
        }
        while(!Q.empty()){
            Node * u=G[Q[0]->label];
            Node * v=u->next;
            Q.erase(Q.begin());
            bool is_leaf=true;//判断u是不是叶子
            while(v!=NULL){//遍历u的邻居
                if(visited[v->label]!=s->label){//没有遍历过
                    is_leaf=false;
                    G[v->label]->pi=u;
                    Q.push_back(v);
                    G[v->label]->h=G[u->label]->h+1;//更新高度
                    visited[v->label]=s->label;//标记为便利过
                }
                v=v->next;
            }
            if(is_leaf)
                G[u->label]->is_leaf=true;
            if(is_leaf&&u->h>min_height[s->label]) {
                min_height[s->label] = u->h;
            }

        }
    //}

    vector<int> path_contain_root;
    int max=-1;
    for(int i=0;i<n;i++){
        if(G[i]->is_leaf&&G[i]->h>max)
            max=G[i]->h;
    }
    for(int i=0;i<n;i++){
        if(G[i]->is_leaf&&G[i]->h==max){
            Node * p=G[i];
            while(p!=NULL&&p!=G[0]){
                path_contain_root.push_back(p->label);
                p=G[p->pi->label];
            }
        }
    }

    for(int i=0;i<path_contain_root.size();i++){//只需要遍历这条路径上的结点
        int label=path_contain_root[i];
        if(label==0)
            continue;
        Node* s=G[label];
        if(visited[s->label]==s->label)
            continue;
        vector<Node* > Q;
        Q.push_back(s);
        G[s->label]->h=0;//更新高度
        visited[s->label]=s->label;//标记为遍历过
        if(s->next==NULL&&s->h>min_height[s->label]) {//为叶子结点，更新min_height
            min_height[s->label] = G[s->label]->h;
            G[s->label]->is_leaf=true;
        }
        while(!Q.empty()){
            Node * u=G[Q[0]->label];
            Node * v=u->next;
            Q.erase(Q.begin());
            bool is_leaf=true;//判断u是不是叶子
            while(v!=NULL){//遍历u的邻居
                if(visited[v->label]!=s->label){//没有遍历过
                    is_leaf=false;
                    Q.push_back(v);
                    G[v->label]->h=G[u->label]->h+1;//更新高度
                    visited[v->label]=s->label;//标记为便利过
                }
                v=v->next;
            }
            if(is_leaf&&u->h>min_height[s->label])
                G[u->label]->is_leaf=true;
            min_height[s->label]=u->h;

        }
    }

    int min=-1;
    for(int i=0;i<n;i++)
        if(min_height[i]!=-1&&(min_height[i]<min||min==-1))
            min=min_height[i];

    vector<int> res;
    for(int i=0;i<n;i++)
        if(min_height[i]==min)
            res.push_back(i);

    return res;



}