#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

int myAtoi(string str);
int StrToInt(char str);
int main() {
    string s="1095502006p8";
    int t=myAtoi(s);
    cout<<t<<endl;
}
int myAtoi(string str) {
    if(str=="")
        return 0;

    vector<int> num;

    bool is_positive=true;
    while(str[0]==' '){//处理前面的空格
        if(str.size()==1)
            return 0;
        str=str.substr(1);
    }

    if(str[0]=='-') {//删除符号
        str=str.substr(1);
        is_positive = false;
    }else if(str[0]=='+')
        str=str.substr(1);

    //开始转化
    int is_conversion=false;
    int len=str.size();
    for(int i=0;i<len;i++ ){
        int n=StrToInt(str[i]);
        if (n==-1)
            break;
        is_conversion=true;
        num.push_back(n);
    }

    //处理未处理情况
    if (!is_conversion)
        return 0;

    //处理溢出情况
    int max=2147483647;
    if(num.size()>10){
        if(is_positive)
            return max;
        else
            return -max-1;
    }else if(num.size()==10){
        for(int i=0;i<num.size();i++){//0为最高位
            double tmp=pow(10,9-i);
            int left=int(max/tmp)%10;
            if(num[i]>left){
                if(is_positive)
                    return max;
                else
                    return -max-1;
            }
            else if(num[i]<left)
                break;
        }



    }

    int n=0;
    int count=1;
    for(int i=num.size()-1;i>=0;i--){
        n += count * num[i];
        count *= 10;
    }
    if (!is_positive)
        n=-n;
    return  n;

}

int StrToInt(char str){
    int n;
    switch (str){
        case '1':
            n=1;
            break;
        case '2':
            n=2;
            break;
        case '3':
            n=3;
            break;
        case '4':
            n=4;
            break;
        case '5':
            n=5;
            break;
        case '6':
            n=6;
            break;
        case '7':
            n=7;
            break;
        case '8':
            n=8;
            break;
        case '9':
            n=9;
            break;
        case '0':
            n=0;
            break;
        default:
            n=-1;
    }
    return n;
}
