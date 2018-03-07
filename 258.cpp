#include <iostream>
#include <vector>
using namespace std;

int addDigits(int num);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int addDigits(int num) {

    while(num>=10){
        int count=0;
        while(num>0){
            count+=num%10;
            num/=10;
        }
        num=count;

    }
    return num;

}