#include <iostream>
using namespace std;
int guess(int num);
int guessNumber(int n);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int guessNumber(int n) {
    int low=1;
    int high=n;
    int mid=(low+high)/2;
    int g=guess(mid);
    while(g!=0){
        if(g==1)
            low=mid+1;
        else
            high=mid-1;
        mid=(low+high)/2;
        g=guess(mid);
    }
    return mid;

}