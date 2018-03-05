#include <iostream>
#include<vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool canPlaceFlowers(vector<int>& flowerbed, int n) {

    int len=flowerbed.size();
    for(int i=0;i<len;i++){
        int num=flowerbed[i];
        if(num==0){
            if(i-1<0||i-1>=0&&flowerbed[i-1]==0){
                if(i+1==len||i+1<len&&flowerbed[i+1]==0){
                    n--;
                    flowerbed[i]=1;
                }
            }
        }
    }
    return n<=0;

}