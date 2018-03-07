#include <iostream>
#include <vector>
using namespace std;

string removeKdigits(string num, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


string removeKdigits(string num, int k) {
    int count=k;

    vector<char> Q;
    for(int i=0;i<num.size();i++){
         char c=num[i];
        while(count>0&&!Q.empty()&&c<Q[0]){
            Q.erase(Q.begin());
            count--;
        }
        if(c=='0'){
            if(!Q.empty()){
                Q.insert(Q.begin(),c);//这个时候肯定count已经用完了
            }
        }else{
            Q.insert(Q.begin(),c);
        }
    }
    string res="";
    if(!Q.empty()){
        for(int i=count;i<Q.size();i++)
            res.insert(res.begin(),Q[i]);
    }
    if(res=="")
        res="0";
    return res;

}