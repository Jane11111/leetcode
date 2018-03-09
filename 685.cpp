#include <iostream>
#include <vector>
using namespace std;

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges);
int main() {
    vector<vector<int>> edges;
    vector<int> e1;
    vector<int> e2;
    vector<int> e3;
    vector<int> e4;
    vector<int> e5;
    e1.push_back(1);
    e1.push_back(2);
    e2.push_back(2);
    e2.push_back(3);
    e3.push_back(3);
    e3.push_back(4);
    e4.push_back(4);
    e4.push_back(1);
    e5.push_back(1);
    e5.push_back(5);
    edges.push_back(e1);
    edges.push_back(e2);
    edges.push_back(e3);
    edges.push_back(e4);
    edges.push_back(e5);
    vector<int> res=findRedundantDirectedConnection(edges);
    cout<<res[0]<<endl;
    cout<<res[1]<<endl;
    return 0;
}


vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

    int N=edges.size();
    vector<int> degrees(N+1,0);
    vector<int> in(N+1,0);
    for(int i=0;i<N;i++){
        degrees[edges[i][0]]++;
        degrees[edges[i][1]]++;
        in[edges[i][1]]++;
    }

    bool has_root=false;
    vector<int>Q;
    for(int i=1;i<=N;i++){
        if(degrees[i]==1)
            Q.push_back(i);
        if(in[i]==0)
            has_root=true;
    }

    while(!Q.empty()){
        int v=Q[0];
        Q.erase(Q.begin());
        int u;
        for(int i=0;i<edges.size();i++){
            vector<int>edge=edges[i];
            if(edge[0]==v){
                edges.erase(edges.begin()+i);
                u=edge[1];break;
            }
            if(edge[1]==v){
                edges.erase(edges.begin()+i);
                u=edge[0];
                break;
            }
        }
        degrees[u]--;
        if(degrees[u]==1)
            Q.push_back(u);
    }

    vector<int> res;

    for(int i=edges.size()-1;i>=0;i--){
        vector<int> edge=edges[i];
        if(has_root){
            if(in[edge[1]]!=0&&in[edge[1]]!=1){
                res=edge;
                break;
            }
        }else{
            if(in[edge[1]]==1){
                res=edge;
                break;
            }
        }
    }
    return res;


}