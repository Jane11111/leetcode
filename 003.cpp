#include <iostream>
#include <cstring>

using namespace std;

int lengthOfLongestSubstring(string s);

int main() {
   string str="pwwkew";
   int longest=lengthOfLongestSubstring(str);
   cout<<longest<<endl;
}
int lengthOfLongestSubstring(string s) {
    int len=s.size();
    int arr[len];
    for (int i=0;i<len;i++){
        arr[i]=-1;
        for(int j=i-1;j>=0;j--){
            if(s[i]==s[j]){
                arr[i]=j;
                break;
            }
        }
    }

    int largest=-1;
    int longest=0;
    for(int i=0;i<len;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
        int t;
        if (largest==-1){
            t=i+1;
        }else{
            t=i-largest;
        }
        if(longest<t)
            longest=t;
    }
    return longest;
}
