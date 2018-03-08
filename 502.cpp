#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    priority_queue<int> pq;
    for(int i=0;i<Capital.size();i++){
        if(Capital[i]<=W) {
            pq.push(Profits[i]);
            Capital.erase(Capital.begin()+i);
            Profits.erase(Profits.begin()+i);
            i--;
        }

    }
    int res=0;
    while(k>0){
        if(pq.empty())
            break;
        W+=(pq.top());
        pq.pop();
        for(int i=0;i<Capital.size();i++){
            if(Capital[i]<=W) {
                pq.push(Profits[i]);
                Capital.erase(Capital.begin()+i);
                Profits.erase(Profits.begin()+i);
                i--;
            }
        }
        k--;



    }
    return W;
}