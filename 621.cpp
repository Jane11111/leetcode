#include <iostream>
#include<queue>

using namespace std;

int leastInterval(vector<char>& tasks, int n);

int main()
{
    priority_queue<int> pq;
    pq.push(30);
    pq.push(100);
    pq.push(25);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}
int leastInterval(vector<char>& tasks, int n) {

    int freqs[26];
    for(int i=0;i<26;i++)
        freqs[i]=0;
    for(int i=0;i<tasks.size();i++){
        freqs[i]++;
    }

    priority_queue<int> Q;
    for(int i=0;i<26;i++){
        if(freqs[i])
            Q.push(freqs[i]);
    }


    int cycle=n+1;
    int res=0;
    while(!Q.empty()){
        int time=0;
        vector<int> tmp;
        for(int i=0;i<cycle;i++){
            if(!Q.empty()){
                tmp.push_back(Q.top()--);
                Q.pop();
                time++;
            }
        }

        for(int i=0;i<tmp.size();i++){
            if(tmp[i]){
                Q.push(tmp[i]);
            }
        }
        if(Q.empty())
            res+=time;
        else
            res+=cycle;


    }
    return res;

}
