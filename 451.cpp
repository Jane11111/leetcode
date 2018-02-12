#include <iostream>
#include <vector>
#include <map>
using namespace std;

string frequencySort(string s);
void Insert(vector<char>& v_c,vector<int>& v_f,char c,int f);
int main() {
    string s="Aabb";
    string res=frequencySort(s);
    cout<<res<<endl;
}

void Insert(vector<char>& v_c,vector<int>& v_f,char c,int f){
    v_c.push_back(c);
    v_f.push_back(f);
    int len=v_c.size();
    for(int i=len-2;i>=0;i--){
        if(v_f[i]<f) {
            swap(v_f[i], v_f[i + 1]);
            swap(v_c[i],v_c[i+1]);
        }
    }

}
string frequencySort(string s) {
    int len=s.size();
    map<char,int> freq;
    for(int i=0;i<len;i++){
        char c=s[i];
        freq[c]+=1;
    }
    vector<char> sort_char;
    vector<int> sort_freq;
    map<char,int> ::iterator ite=freq.begin();
    while(ite!=freq.end()){
        Insert(sort_char,sort_freq,ite->first,ite->second);
        ite++;
    }

    string str;
    for(int i=0;i<sort_char.size();i++){
        char c=sort_char[i];
        int f=sort_freq[i];
        while(f!=0){
            str.push_back(c);
            f--;
        }
    }
    return str;

}