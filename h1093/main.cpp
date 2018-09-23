#include <iostream>
using namespace std;


int main() {
    int N;
    cin>>N;
    while(N>0){
        N--;
        int M;
        cin>>M;
        int sum=0;
        int num;
        for (int i=0;i<M;i++){
            cin>>num;
            sum+=num;
        }
        cout<<sum<<endl;
    }
    return 0;
}