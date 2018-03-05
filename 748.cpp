#include <iostream>
#include<vector>
#include<map>
using namespace std;
string shortestCompletingWord(string licensePlate, vector<string>& words);
int isLetter(char c);
bool isValid(map<char,int> mymap,string word);
int main()
{
    string str="1s3 PSt";
    vector<string> words;
    words.push_back("step");
    words.push_back("steps");
    words.push_back("stripe");
    words.push_back("stepple");

    string res=shortestCompletingWord(str,words);
    cout<<res<<endl;
    return 0;
}

int isLetter(char c){
    if(c>='a'&&c<='z')
        return c-'a';

    if(c>='A'&&c<='Z')
        return c-'A';

    return -1;
}
bool isValid(map<char,int> mymap,string word){




    for(int i=0;i<word.size();i++){
            char c='a'+isLetter(word[i]);
        if(mymap.count(c)==0)
             continue;
        if(mymap[c]==1){
            mymap.erase(c);
            continue;
        }
        mymap[c]--;

    }


    return mymap.size()==0;
}


string shortestCompletingWord(string licensePlate, vector<string>& words) {

    map<char,int> mymap;
    for(int i=0;i<licensePlate.size();i++){
            char c=licensePlate[i];
        int n=isLetter(c);
        if(n<0)
            continue;

        mymap['a'+n]++;

    }

    for(int i=0;i<words.size();i++){
            string word=words[i];
        if(isValid(mymap,word))
            return word;
    }
    return "";

}
