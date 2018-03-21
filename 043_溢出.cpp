#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1, string num2);
int main() {
    string num1="18";
    string num2="12";
    string res=multiply(num1,num2);
    cout<<res<<endl;
    return 0;
}


string multiply(string num1, string num2) {

    int res=0;
    int i=num1.size()-1;


    int base=1;
    while(i>=0){
        int local_res=0;
        int local_base=1;
        int n1=num1[i]-'0';
        int carry=0;

        for(int j=num2.size()-1;j>=0;j--){
            int n2=num2[j]-'0';
            int r=n1*n2+carry;
            carry=r/10;
            local_res+=local_base*(r%10);
            local_base*=10;

        }
        if(carry)
            local_res+=(carry*local_base);

        res+=(local_res*base);
        i--;
        base*=10;
    }

    string sres;
    while(res){
        char c='0'+(res%10);
        res/=10;
        sres.insert(sres.begin(),c);
    }
    if(sres.empty())
        sres="0";
    return sres;

}