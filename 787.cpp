#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

    map<int,int> dis;
    map<int,int> tmp;
    dis[src]=0;

    while(K>=0){

        tmp=dis;
        for(int i=0;i<flights.size();i++){
            int s=flights[i][0];
            int e=flights[i][1];
            int p=flights[i][2];

            if(tmp.find(s)!=tmp.end()){
                if(dis.find(e)==dis.end())//更新dis
                    dis[e]=tmp[s]+p;
                else {
                    dis[e] = min(dis[e], tmp[s] + p);
                }
            }


        }


        K--;
    }
    if(dis.find(dst)==dis.end())
        return -1;
    return dis[dst];
}