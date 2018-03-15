#include <iostream>
#include <vector>
using namespace std;

bool isBipartite(vector<vector<int>>& graph);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool isBipartite(vector<vector<int>>& graph) {
    int len=graph.size();
    if(len==0)
        return true;

    //-3 未visited过 -1一个value -2另一个value
    vector<int> visited(len,-3);

    for(int i=0;i<len;i++){
        if(visited[i]==-3){
            vector<int> Q;
            Q.push_back(i);
            visited[i]=-1;//给他一个初始value -1
            while(!Q.empty()){


                int cur=Q[0];
                Q.erase(Q.begin());
                int label=visited[cur];
                if(label==-1)
                    label=-2;
                else
                    label=-1;
                vector<int> neighbors=graph[cur];
                for(int j=0;j<neighbors.size();j++){
                    int v=neighbors[j];
                    if(visited[v]==-3){//未visited过
                        visited[v]=label;
                        Q.push_back(v);
                    }else{
                        if(visited[v]!=label)
                            return false;
                    }
                }
            }
        }


    }
    return true;

}