#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> partitionLabels(string S);
int main() {
    string S="ababcbacadefegdehijhklij";
    vector<int> res=partitionLabels(S);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}

vector<int> partitionLabels(string S) {
    int len=S.size();
    map<char,int> my_map;
    for(int i=0;i<len;i++){
        char c=S[i];
        my_map[c]+=1;
    }


    vector<int> res;

    for(int i=0;i<len;){
        int count=0;
        map<char,bool> record_map;
        char c=S[i];
        count+=my_map[c];
        record_map[c]=true;
        int cur_count=1;
        i++;
        while(cur_count<count&&i<len){
            c=S[i];
            if(record_map.count(c)==0){
                record_map[c]=true;
                count+=my_map[c];
                cur_count++;
            }else{
                cur_count++;
            }
            i++;
        }
        res.push_back(count);
    }
    return res;
}