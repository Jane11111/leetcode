#include <iostream>
#include <vector>
#include <map>
using namespace std;


struct Node{ 
    string label;
    Node * next;
    double val;
    Node* pi;
    Node():next(NULL),pi(NULL){}
    Node(string l,double v=1 ): label(l),next(NULL),pi(NULL),val(v){}
};
vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) ;


int main() {
    vector<pair<string,string>> equations;
    vector<double> val;
    vector<pair<string,string>>queries;



    equations.emplace_back(pair<string,string>("a","b"));
    equations.emplace_back(pair<string,string>("b","c"));

    val.emplace_back(2.0);
    val.emplace_back(3.0);

    queries.emplace_back(pair<string,string>("a","c"));
    queries.emplace_back(pair<string,string>("b","a"));
    queries.emplace_back(pair<string,string>("a","e"));
    queries.emplace_back(pair<string,string>("a","a"));
    queries.emplace_back(pair<string,string>("x","x"));

    vector<double> res=calcEquation(equations,val,queries);

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {

    //转为邻接链表表示
    map<string,Node*> G;
    for(int i=0;i<equations.size();i++){
        pair<string,string> e=equations[i];
        double val=values[i];

        if(G.count(e.first)==0){
            Node *new_node=new Node(e.first);
            G[e.first]=new_node;
        }
        if(G.count(e.second)==0){
            Node *new_node=new Node(e.second);
            G[e.second]=new_node;
        }

        Node * first=G[e.first];
        Node * first_neighbor=new Node(e.second,val);
        first_neighbor->next=first->next;
        first->next=first_neighbor;

        Node * second=G[e.second];
        double tmp=1/val;
        Node * second_neighbor=new Node(e.first,1.0/val);
        second_neighbor->next=second->next;
        second->next=second_neighbor;

    }

    vector<double> res;
    map<string,bool> visited;

    for(int i=0;i<queries.size();i++){
        pair<string,string> query=queries[i];
        if(G.count(query.first)==0||G.count(query.second)==0){
            res.push_back(-1.0);
            continue;
        }

        for(int i=0;i<equations.size();i++){//清理visited
            pair<string,string> e=equations[i];
            visited[e.first]=false;
            visited[e.second]=false;
        }
        map<string,Node*> ::iterator ite;//清理G，将其pi置为NULL
        for(ite=G.begin();ite!=G.end();ite++){
            ite->second->val=1;
            ite->second->pi=NULL;
        }


        vector<string> Q;
        Q.push_back(query.first);
        visited[query.first]=true;
        while(!Q.empty()){
            string u_key=Q[0];
            Q.erase(Q.begin());
            Node * u=G[u_key];
            Node * v=u->next;//遍历u的neighbor
            while(v!=NULL){
                if(visited[v->label]==false){
                    Q.push_back(v->label);
                    visited[v->label]=true;
                    G[v->label]->pi=G[u->label];//更新pi值
                    G[v->label]->val=v->val;
                }
                v=v->next;
            }
        }
        if(visited[query.second]==false)
            res.push_back(-1.0);
        else{
            double r=1.0;
            Node * p=G[query.second];
            while(p!=NULL){
                r*=p->val;
                p=p->pi;
            }
            res.push_back(r);
        }

    }
    return res;
}