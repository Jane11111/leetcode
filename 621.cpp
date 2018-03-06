#include <iostream>
#include<queue>

using namespace std;

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
