#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int candy(vector<int>& ratings) {

    int len=ratings.size();
    if(len==0)
        return 0;
    vector<int> candies(len,1);
    for(int i=1;i<len;i++){
        if(ratings[i]>ratings[i-1])
            candies[i]=candies[i-1]+1;

        int j=i;
        while(j>0&&ratings[j]<ratings[j-1]&&candies[j]==candies[j-1]){
            candies[j-1]++;
            j--;
        }
    }

    int res=0;
    for(int i=0;i<len;i++)
        res+=candies[i];
    return res;

}