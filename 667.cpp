#include <iostream>
#include <vector>
using namespace std;

vector<int> constructArray(int n, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


vector<int> constructArray(int n, int k) {
    vector<int> res;
    int i=1;int j=n;
    //res.push_back(1);
    while(i<=j){
        if(k>1){
            if(k%2==1){
                res.push_back(i);
                i++;
                k--;

            }else{
                res.push_back(j);
                j--;

                k--;

            }

        }else{
            res.push_back(i);
            i++;
        }
    }
    return res;

}