#include <iostream>
#include<vector>
#include <map>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures);

int main() {
    vector<int> temp;
    temp.push_back(73);
    temp.push_back(74);
    temp.push_back(75);
    temp.push_back(71);
    temp.push_back(69);
    temp.push_back(72);
    temp.push_back(76);
    temp.push_back(73);
    vector<int> res=dailyTemperatures(temp);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
vector<int> dailyTemperatures(vector<int>& temperatures) {

    vector<vector<int>> not_find;
    map<int,int> my_map;
    int len=temperatures.size();
    vector<int> res;
    if(len==0)
        return res;
    for(int i=0;i<len;i++)
        res.push_back(0);
    for(int i=0;i<len;i++){
        int t=temperatures[i];
        while(!not_find.empty()&&t>not_find[0][0]){
            int ind=not_find[0][1];
            res[ind]=i-ind;
            not_find.erase(not_find.begin());
        }
        vector<int> v;
        v.push_back(t);
        v.push_back(i);
        not_find.insert(not_find.begin(),v);
    }
    return res;

}