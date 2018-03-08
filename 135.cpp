#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int candy(vector<int>& ratings){

    int res=0;
    int len=ratings.size();
    int pre=0;
    for(int i=0;i<len;){

        int summit;
        while(i==0||i<len&&ratings[i]>ratings[i-1]){
            pre++;
            res+=pre;
            i++;
        }

        if(i<len&&ratings[i]==ratings[i-1]) {//已经落到最低
            pre=1;
            res+=pre;
            i++;
            continue;
        }


        summit=pre;
        pre=1;
        while(i<len&&ratings[i]<ratings[i-1]){

            pre++;
            res+=pre;
            i++;
            if(pre==summit){
                res++;
                summit++;
            }
        }

        pre=1;

    }
    return res;

}