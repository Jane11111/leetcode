#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
class Solution {
public:
    int StrToInt(string str){
        int n;
        istringstream is(str);
        is>>n;
        return n;
    }
    NestedInteger deserialize(string s) {

        vector<NestedInteger> stack;

        string str;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='['){
                NestedInteger nests;
                stack.insert(stack.begin(),nests);

            }else if(c==']'){
                NestedInteger nests;
                if(str!=""){
                    nests.setInteger(StrToInt(str));
                    stack[0].add(nests);
                    str="";

                }

                if(stack.size()>1){
                    stack[1].add(stack[0]);
                    stack.erase(stack.begin());
                }
            }else if(c==','){
                NestedInteger nests;
                if(str!=""){
                    nests.setInteger(StrToInt(str));
                    stack[0].add(nests);
                    str="";

                }
                // stack[0].add(nests);
            }else{
                str.push_back(c);
            }
        }

        if(str!=""){
            stack.insert(stack.begin(),NestedInteger(StrToInt(str)));
        }
        return stack[0];



    }
};