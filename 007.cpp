#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int reverse(int x);

int main() {
    int x=1534236469;
    int y=1563847412;
    int r=reverse(y);
    cout<<r<<endl;

}

int reverse(int x) {

    int max=2147483647;

    vector<int> rev_str;
    bool is_positive=true;
    if(x<0) {
        is_positive = false;
        x=-x;
    }


    while(x>0){
        rev_str.push_back(x%10);
        x/=10;
    }

    int count=1;
    long long num=0;
    int index=rev_str.size()-1;
    if(index>9)
        return 0;
    else if(index==9){
        for(int i=0;i<=index;i++){
            //max=2147483647
            double temp2=pow(10,9-i);
            if(rev_str[i]>(int(max/temp2)%10))
                return 0;
            else if(rev_str[i]<(int(max/temp2)%10))
                break;
        }

    }


    for(;index>=0;index--){
        int t=rev_str[index];
        num+=t*count;
        count*=10;
    }
    if (!is_positive )
        num=-num;
    return int(num);




}