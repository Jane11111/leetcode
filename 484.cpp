#include <iostream>
#include <map>
#include <vector>
using namespace std;
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);
void GenMap(vector<int>& A,vector<int>& B,map<int,int>& map);
int main() {
    vector<int> A;
    vector<int>B;
    vector<int>C;
    vector<int>D;
    A.push_back(1);
    A.push_back(2);
    B.push_back(-2);
    B.push_back(-1);
    C.push_back(-1);
    C.push_back(2);
    D.push_back(0);
    D.push_back(2);
    int res=fourSumCount(A,B,C,D);
    cout<<res<<endl;
}
void GenMap(vector<int>& A,vector<int>& B,map<int,int>& map){
    int len1=A.size();
    int len2=B.size();
    for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++) {
            if (map.count(A[i] + B[j]) == 0)
                map[A[i] + B[j]] = 0;
            map[A[i] + B[j]]++;
        }
}
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){

    map<int,int>map1;
    map<int ,int>map2;
    GenMap(A,B,map1);
    GenMap(C,D,map2);
    map<int,int> ::iterator ite1;
    map<int,int>::iterator ite2;
    int count=0;
    for(ite1=map1.begin();ite1!=map1.end();ite1++){
        ite2=map2.find(-ite1->first);
        if(ite2!=map2.end())
            count+=(ite1->second*ite2->second);
    }
    return count;
}