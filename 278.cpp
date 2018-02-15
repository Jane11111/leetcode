#include <iostream>
using namespace std;

bool isBadVersion(int version);
int firstBadVersion(int n);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool isBadVersion(int version){
return true;
}
int firstBadVersion(int n) {
    double low=1;
    double high=n;
    double mid=int((low+high)/2);
    bool f=isBadVersion(mid);
    bool f_pre=false;
    if(mid!=1)
        f_pre=isBadVersion(mid-1);
    while(!(f&&!f_pre)){
        if(f)
            high=mid-1;
        else
            low=mid+1;

        mid=int((low+high)/2);
        f=isBadVersion(mid);

        if(mid==1)
            f_pre=false;
        else
            f_pre=isBadVersion(mid-1);
    }
    return mid;

}