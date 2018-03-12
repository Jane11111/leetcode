#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestConsecutive(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}



int longestConsecutive(vector<int>& nums) {

    map<int,bool> mymap;
    for(int i=0;i<nums.size();i++)
        mymap[nums[i]]=true;
    int res=0;
    for(int i=0;i<nums.size();i++){
        int num=nums[i];
        if(mymap[num]){
            int count=1;
            int left=num-1;
            int right=num+1;
            mymap[num]=false;
            while(mymap.count(left)){
                mymap[left]=false;
                count++;
                left--;
            }
            while(mymap.count(right)){
                mymap[right]=false;
                count++;
                right++;
            }
            if(count>res)
                res=count;

        }

    }
    return res;
}