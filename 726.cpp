#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;
string countOfAtoms(string formula);
bool isUpper(char c);
bool isLower(char c);
int CharToInt(char c);
string IntToStr(int i);
map<string,int> my_map;
void RecFind(string formula,double base);
int main() {
    string formula="(((U42Se42Fe10Mc31Rh49Pu49Sb49)49V39Tm50Zr44Og6)33((W2Ga48Tm14Eu46Mt12)23(RuRnMn11)7(Yb15Lu34Ra19CuTb2)47(Md38BhCu48Db15Hf12Ir40)7CdNi21(Db40Zr24Tc27SrBk46Es41DsI37Np9Lu16)46(Zn49Ho19RhClF9Tb30SiCuYb16)15)37(Cr48(Ni31)25(La8Ti17Rn6Ce35)36(Sg42Ts32Ca)37Tl6Nb47Rh32NdGa18Cm10Pt49(Ar37RuSb30Cm32Rf28B39Re7F36In19Zn50)46)38(Rh19Md23No22PoTl35Pd35Hg)41)50";
    string res=countOfAtoms(formula);
    cout<<res<<endl;

}

string countOfAtoms(string formula) {

    string res="";
    int len=formula.size();
    RecFind(formula,1);
    map<string,int>::iterator ite=my_map.begin();
    while(ite!=my_map.end()){
        res+=ite->first;
        ostringstream oss;
        oss<<ite->second;
        string num=oss.str();
        if(num!="1")
            res+=num;
        ite++;
    }
    return res;
}


void RecFind(string formula,double base){

    int len=formula.size();
    for(int i=0;i<len;i++){
        string next="";
        if(formula[i]=='('){
            vector<char> my_vector;
            my_vector.push_back(formula[i]);
            i=i+1;
            while(!my_vector.empty()){
                if(formula[i]=='(')
                    my_vector.push_back('(');
                else if(formula[i]==')')
                    my_vector.pop_back();
                if(my_vector.empty())
                    break;

                next.push_back(formula[i]);
                i++;
            }
            if(i+1<len&&formula[i+1]!='('&&!isUpper(formula[i+1])){//是数字
                string snum="";
                while(i+1<len&&formula[i+1]!='('&&!isUpper(formula[i+1])) {
                    snum.push_back(formula[i+1]);
                    i++;
                }
                int  num=1;
                if(snum!=""){
                    num=atoi(snum.c_str());
                }
                double tmp=base*num;
                RecFind(next, tmp);
//                i--;

            }else{//不是数字
                RecFind(next,base);
            }
            continue;
        }
        if(isUpper(formula[i])){
            string item;
            item.push_back(formula[i]);
            while((i+1)<len&&isLower(formula[i+1])){
                i++;
                item+=formula[i];

            }
            string snum="";
            while(i+1<len&&formula[i+1]!='('&&!isUpper(formula[i+1])) {//是数字
                snum.push_back(formula[i+1]);
                i++;
            }
            if(my_map.count(item)==0){
                my_map[item]=0;
            }
            int num=1;
            if(snum!=""){
                num=atoi(snum.c_str());
            }
            my_map[item]+=(num*base);
        }
    }

}


int CharToInt(char c){
    switch (c){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
    }
}
bool isUpper(char c){
    switch (c){
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'M':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            return true;
        default:
            return false;
    }
}
bool isLower(char c){
    switch (c){
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return true;
        default:
            return false;
    }
}