#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {

    int len=people.size();
    for (int i = 0; i < len; ++i) {//按照h从大到小，k从小到大排序
        pair<int,int> p=people[i];
        for(int j=i-1;j>=0;--j){
            pair q=people[j];
            if(q.first<p.first||q.first==p.first&&q.second>p.second)
                swap(people[j],people[j+1]);
        }

    }
    vector<pair<int,int>> res;
    for(int i=0;i<len;i++){
        pair<int,int> p=people[i];
        int pos=p.second;
        res.insert(res.begin()+pos,p);
    }

    return res;

}