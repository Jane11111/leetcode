#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<string> topKFrequent(vector<string>& words, int k);
void MergeSort(vector<pair<string,int>>& freqvec,int s,int e);
void Merge(vector<pair<string,int>>& freqvec,int s,int m,int e);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void MergeSort(vector<pair<string,int>>& freqvec,int s,int e){
    if(s>=e)
        return;
    int m=(s+e)/2;
    MergeSort(freqvec,s,m);
    MergeSort(freqvec,m+1,e);
    Merge(freqvec,s,m,e);
}
void Merge(vector<pair<string,int>>& freqvec,int s,int m,int e){
    vector<pair<string,int>> left;
    vector<pair<string,int>> right;
    for(int i=s;i<=m;i++)
        left.push_back(freqvec[i]);
    left.push_back(pair<string,int>("",INT_MIN));

    for(int i=m+1;i<=e;i++)
        right.push_back(freqvec[i]);
    right.push_back(pair<string,int>("",INT_MIN));

    int i=0;int j=0;
    for(int index=s;index<=e;index++){
        if(left[i].second>right[j].second||(left[i].second==right[j].second&&left[i].first<right[j].first)){
            freqvec[index]=left[i];
            i++;
        }else{
            freqvec[index]=right[j];
            j++;
        }
    }
}

vector<string> topKFrequent(vector<string>& words, int k) {

    map<string,int> freqmap;
    for(string word:words)
        freqmap[word]++;

    vector<pair<string,int>> freqvec;
    map<string,int>::iterator ite=freqmap.begin();
    while(ite!=freqmap.end()){
        freqvec.push_back(pair<string,int>(ite->first,ite->second));
        ite++;
    }
    MergeSort(freqvec,0,freqvec.size()-1);

    vector<string> res;
    for(int i=0;i<words.size()&&i<k;i++)
        res.push_back(freqvec[i].first);
    return res;

}