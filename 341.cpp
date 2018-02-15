#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> partitionLabels(string S);
int main() {

}

class NestedIterator {
public:
    vector<int> res;
    int index;


    void RecFind(vector<int>& res,NestedInteger nest){

        if(nest.isInteger())
            res.push_back(nest.getInteger());
        else{
            vector<NestedInteger> my_list=nest.getList();
            for(int i=0;i<my_list.size();i++)
                RecFind(res,my_list[i]);
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=0;i<nestedList.size();i++)
            RecFind(res,nestedList[i]);
        index=0;

    }

    int next() {
        int r=res[index];
        index++;
        return r;
    }

    bool hasNext() {
        if(index>=res.size())
            return false;
        return true;

    }
};