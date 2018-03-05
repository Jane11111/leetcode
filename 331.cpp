#include <iostream>
#include<vector>
using namespace std;
bool isValidSerialization(string preorder);
int findSubTree(vector<int> vals,int index);

int main()
{
    string preorder="1,#,#,1";
    bool res=isValidSerialization(preorder);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
int findSubTree(vector<int> vals,int index){

      if(index==vals.size())
        return -1;
      if(vals[index]==0)
        return index;
      int left=findSubTree(vals,index+1);
      if(left==-1)
        return -1;
      int right=findSubTree(vals,left+1);
      return right;

}

bool isValidSerialization(string preorder) {

    vector<int> vals;
    if(preorder.size()==0)
        return true;
    if(preorder[0]=='#')
        vals.push_back(0);
    else
        vals.push_back(1);



    for(int i=1;i<preorder.size();i++){
        if(preorder[i]=='£¬'||preorder[i]==','){
            if(preorder[i+1]=='#')
                vals.push_back(0);
            else
                vals.push_back(1);
        }
    }

    cout<<vals.size()<<endl;






    int res=findSubTree(vals,0);
    if(res!=vals.size()-1)
        return false;
    return true;


}
