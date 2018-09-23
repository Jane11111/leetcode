#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic(vector<int>& A);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool isMonotonic(vector<int>& A) {
    if(A.size()<=1)
        return true;
    int i=1;
    while(i<A.size()&&A[i]==A[i-1])
        i++;
    if(i==A.size())
        return true;

    bool flag=A[i]>=A[i-1];
    i+=1;
    for(;i<A.size();i++){
        if(A[i]==A[i-1])
            continue;
        bool tmp=A[i]>=A[i-1];
        if(tmp!=flag)
            return false;
    }
    return true;
}