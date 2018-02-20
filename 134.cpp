#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {


    int len=gas.size();

    int start=0;
    int cur=0;

    int gas_count=0;

    while(true){
        while(gas_count+gas[cur]>=cost[cur]){
            if((start+len-1)%len==cur)
                return start;
            gas_count+=(gas[cur]-cost[cur]);
            cur=(cur+1)%len;
        }

        while(start<len&&gas_count+gas[cur]<cost[cur]){
            if(start<cur) {
                gas_count = gas_count + cost[start] - gas[start];
                start+=1;
            }else{
                start++;
                cur++;
            }
        }
        if(start==len)
            return -1;

    }

}