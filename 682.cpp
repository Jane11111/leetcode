#include <iostream>
#include <vector>
#include<sstream>
using namespace std;

int calPoints(vector<string>& ops);
int toInteger(string s);
int main() {
    vector<string> ops;
    ops.push_back("5");
    ops.push_back("2");
    ops.push_back("C");
    ops.push_back("D");
    ops.push_back("+");
    int res=calPoints(ops);
    cout<<res<<endl;
}


int calPoints(vector<string>& ops) {
    vector<int> record;
    int len=ops.size();
    int sum=0;
    for(int i=0;i<len;i++){
        string s=ops[i];
        int score;
        if(s=="C"){
            int r=record[0];
            record.erase(record.begin());
            sum-=r;

        }else if(s=="D"){
            int r=record[0];
            score=r*2;
            sum+=score;
            record.insert(record.begin(),score);

        }else if(s=="+"){
            int r1=record[0];
            int r2=record[1];
            score=r1+r2;
            sum+=score;
            record.insert(record.begin(),score);


        }else{
            score=toInteger(s);
            sum+=score;
            record.insert(record.begin(),score);

        }

    }
    return sum;


}

int toInteger(string s){
    istringstream is(s);
    int num;
    is>>num;
    return num;
}