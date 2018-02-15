#include <iostream>
#include <vector>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s);
int main() {
    vector<int> g;
    vector<int> s;
    g.push_back(10);
    g.push_back(9);
    g.push_back(8);
    g.push_back(7);
    s.push_back(5);
    s.push_back(6);
    s.push_back(7);
    s.push_back(8);
    int res=findContentChildren(g,s);
    cout<<res<<endl;
}

int findContentChildren(vector<int>& g, vector<int>& s) {
    int len1=g.size();
    int len2=s.size();
    for(int i=0;i<len1;i++){
        int num=g[i];
        for(int j=i-1;j>=0;j--){
            if(num<g[j])
                swap(g[j],g[j+1]);
            else
                break;
        }
    }

    for(int i=0;i<len2;i++){
        int num=s[i];
        for(int j=i-1;j>=0;j--){
            if(num<s[j])
                swap(s[j],s[j+1]);
            else
                break;
        }
    }


    int i=0;
    int j=0;
    int count=0;

    while(i<len1&&j<len2){
        if(g[i]<=s[j]){
            i++;
            j++;
            count++;

        }else{
            j++;
        }
    }



    return count;

}