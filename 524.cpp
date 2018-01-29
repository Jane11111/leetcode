#include <iostream>
#include<vector>
using namespace std;
string findLongestWord(string s, vector<string>& d);
int main() {
    string s="qakcyffurpbkuepnzrpknxdstrpvertmlitjqimeulfbuldfbqjbhgewnwxygtimnsdtjluahoegmjhjgynldxpihcgzojwoddtlqvttedwdlxnzdwszkgnnnqilmweacummvsuwsepbpthzonpprhgspmqqvozxpuopaqkgvxaweorhbtokkxplfupctkblhudpwzpyevszvndpybhyzkephlcnnivaevvcukzsobgjwiinyqwntskndmuhdanwbzgcdvyhetvlnyeqsjjcvaznahfpsriruiqifczgjrkrifnlvrwaefzlwuyewxukdlsrracjixbufuilvnlesdbfopnycmkcjyloinuszqatpsohmvkdkdrapkcfluorgfymxnfrkilyopadxyregxwholrrgrbnbfiexqbticcmfoofbeububuzqkzqypzcxsvdpcpnvvukrlerjexcxbzpyamrtzxxernepsklpdvcxldyugjv";
    vector<string> d;
    d.push_back("qicsjagdufeyfalkotcdmtrq");
    d.push_back("cibcbxlghdntmvrmnyxhz");
    d.push_back("qa");
    d.push_back("b");
    string res=findLongestWord(s,d);
    cout<<res<<endl;
}

string findLongestWord(string s, vector<string>& d) {
    int s_len=s.length();
    int d_len=d.size();
    vector<string> res;
    //暴力求解，三层循环
    for(int i=0;i<s_len;i++){
        for(int j=0;j<d_len;j++){
            if(s[i]==d[j][0]){
                string tmp=d[j];
                if(s_len-i<tmp.size())
                    continue;
                int s_index=i;
                for(int t=0;t<tmp.size()&&s_index+t<s_len;){
                    if(s[s_index+t]!=tmp[t])
                        s_index++;
                    else {
                        if(t==tmp.size()-1)
                            res.push_back(tmp);
                        t++;
                    }

                }
            }
        }
    }

    string str="";
    for(int i=0;i<res.size();i++){
        if(res[i].size()>str.size()|| res[i].size()==str.size()&&res[i]<str)
            str=res[i];
    }
    return str;
}