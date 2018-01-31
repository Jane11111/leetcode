#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Node{
    int label;
    Node * next;
    int f;
    Node():label(0),next(NULL),f(0){};
    Node(int l,Node *p=NULL): label(l),next(p),f(0){}
};
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) ;
void DFS(Node * u,map<int,Node*>& G,map<int,bool>& visited);
int time=0;
int main() {
    int numCourses=2;
    vector<pair<int,int>> prerequisities;
    prerequisities.push_back(pair<int,int>(0,1));
    //prerequisities.push_back(pair<int,int>(1,0));
    bool res=canFinish(numCourses,prerequisities);
    if(res)
        cout<<"can "<<endl;
    else
        cout<<"can not"<<endl;
    return 0;
}

void DFS(Node * u,map<int,Node*>& G,map<int,bool> &visited){
    visited[u->label]=true;
    Node * v=u->next;//遍历u的邻居
    while(v!=NULL){
        if(!visited[v->label]){
            DFS(G[v->label],G,visited);
        }
        v=v->next;
    }
    time++;
    u->f=time;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    map<int,Node*> G;//变为邻接链表

    map<int,bool> visited;//初始化visited数组
    for(int i=0;i<prerequisites.size();i++){
        pair<int,int> e=prerequisites[i];
        visited[e.first]=false;
        visited[e.second]=false;
        if(G.count(e.first)==0)
            G[e.first]=new Node(e.first);
        if(G.count(e.second)==0)
            G[e.second]=new Node(e.second);
        Node *new_node=new Node(e.second,G[e.first]->next);
        G[e.first]->next=new_node;
    }



    map<int,Node *> ::iterator ite;
    for(ite=G.begin();ite!=G.end();ite++){//DFS
        if(!visited[ite->first])
            DFS(G[ite->first],G,visited);

    }

    for(int i=0;i<prerequisites.size();i++){
        pair<int,int> e=prerequisites[i];
        if(G[e.first]->f<G[e.second]->f)
            return false;
    }
    return true;



}