#include <iostream>
#include <string>
#include <sstream>
#include<vector>
using namespace std;
string reorganizeString(string S);
int CharToInt(char c);
char IntToChar(int i);
vector<int> FindMax(int* arr,int len);
int main() {
    string S="aaba";
    string res=reorganizeString(S);
    cout<<res<<endl;
}

string reorganizeString(string S) {


    int max=26;
    int arr[max];
    for(int i=0;i<max;i++)
        arr[i]=0;

    int len=S.length();
    int largest=0;
    for(int i=0;i<len;i++){
        int t=CharToInt(S[i]);
        arr[t]+=1;
        if(arr[t]>largest)
            largest=arr[t];
    }

    if(len%2&&largest>(len/2+1) || (len%2==0)&&largest>len/2)
        return "";
    string res="";
    vector<int> nums;
    for(int i=0;i<len;i++){
        nums=FindMax(arr,max);
        char c1=IntToChar(nums[0]);
        char c2=IntToChar(nums[1]);
        arr[nums[0]]--;
        arr[nums[1]]--;
        res+=c1;
        i+=1;
        if(i!=len)
            res+=c2;


    }
    return res;

}

vector<int> FindMax(int* arr,int len){
    vector<int> res;

    int max_index=0;
    int max_num=-1;
    for(int i=0;i<len;i++){
        if(arr[i]>max_num){
            max_num=arr[i];
            max_index=i;
        }
    }
    res.push_back(max_index);

    int second_index=0;
    int second_num=-1;
    for(int i=0;i<len;i++){
        if(arr[i]>second_num&&i!=max_index){
            second_num=arr[i];
            second_index=i;
        }
    }
    res.push_back(second_index);
    return res;

}
char IntToChar(int i){
    switch (i){
        case  0:
            return 'a';
        case  1:
            return 'b';
        case  2:
            return 'c';
        case  3:
            return 'd';
        case  4:
            return 'e';
        case  5:
            return 'f';
        case  6:
            return 'g';
        case  7:
            return 'h';
        case  8:
            return 'i';
        case  9:
            return 'j';
        case  10:
            return 'k';
        case  11:
            return 'l';
        case  12:
            return 'm';
        case  13:
            return 'n';
        case  14:
            return 'o';
        case  15:
            return 'p';
        case  16:
            return 'q';
        case  17:
            return 'r';
        case  18:
            return 's';
        case  19:
            return 't';
        case  20:
            return 'u';
        case  21:
            return 'v';
        case  22:
            return 'w';
        case  23:
            return 'x';
        case  24:
            return 'y';
        case  25:
            return 'z';
    }
}

int CharToInt(char c){
    switch (c){
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        case 'i':
            return 8;
        case 'j':
            return 9;
        case 'k':
            return 10;
        case 'l':
            return 11;
        case 'm':
            return 12;
        case 'n':
            return 13;
        case 'o':
            return 14;
        case 'p':
            return 15;
        case 'q':
            return 16;
        case 'r':
            return 17;
        case 's':
            return 18;
        case 't':
            return 19;
        case 'u':
            return 20;
        case 'v':
            return 21;
        case 'w':
            return 22;
        case 'x':
            return 23;
        case 'y':
            return 24;
        case 'z':
            return 25;
    }
}