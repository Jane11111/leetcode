#include <iostream>
#include <vector>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K){

    if(src==dst)
        return 0;
    if(K==0){
        for(int i=0;i<flights.size();i++){
            int s=flights[i][0];
            int e=flights[i][1];
            int p=flights[i][2];
            if(s==src&&e==dst)
                return p;
        }
        return -1;
    }

    int res=INT_MAX;
    for(int i=0;i<flights.size();i++){
        int s=flights[i][0];
        int e=flights[i][1];
        int p=flights[i][2];


        if(s==src){
            int r=findCheapestPrice(n,flights,e,dst,K-1);
            if(r==-1)
                continue;
            res=min(res,r+p);
        }
    }
    if(res==INT_MAX)
        return -1;
    else
        return res;



}