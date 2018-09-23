#include <iostream>
using namespace std;


int main() {

    int N;
    cin>>N;
    while(N>0){
        N--;
        int M;
        int sum=0;
        int num;
        cin>>M;
        for(int i=0;i<M;i++){
            cin>>num;
            sum+=num;
        }
        cout<<sum<<endl;
        if(N)
            cout<<endl;
    }
    return 0;
}