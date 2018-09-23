#include <iostream>
using namespace std;

int main(){
    int N;
    int a,b;
    cin>>N;
    while(N>0){
        N--;
        cin>>a>>b;
        int sum=a+b;
        cout<<sum<<endl;
    }
}