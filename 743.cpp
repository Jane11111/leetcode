#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};
int networkDelayTime(vector<vector<int>>& times, int N, int K);
int main() {
    vector<vector<int>> times;
    vector<int> t1;
    vector<int> t2;
    vector<int> t3;
    t1.push_back(2);
    t1.push_back(1);
    t1.push_back(1);
    t2.push_back(2);
    t2.push_back(3);
    t2.push_back(1);
    t3.push_back(3);
    t3.push_back(4);
    t3.push_back(1);
    times.push_back(t1);
    times.push_back(t2);
    times.push_back(t3);
    int N=4;
    int K=2;
    int res=networkDelayTime(times,N,K);
    cout<<res<<endl;
}
int networkDelayTime(vector<vector<int>>& times, int N, int K) {

    vector<int> dis(N,INT_MAX);
    dis[K-1]=0;

    while(N>1){

        for(int i=0;i<times.size();i++){
            int s=times[i][0];
            int e=times[i][1];
            int v=times[i][2];
            if(dis[s-1]==INT_MAX)
                continue;

            dis[e-1]=min(dis[e-1],dis[s-1]+v);
        }


        N--;
    }
    int res=INT_MIN;
    for(int i=0;i<dis.size();i++)
        res=max(res,dis[i]);
    if(res==INT_MAX)
        return -1;
    return res;

}