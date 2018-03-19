#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct RandomListNode{
    int label;
    RandomListNode *next,*random;
    RandomListNode(int x):label(x),next(NULL),random(NULL){}
};
RandomListNode *copyRandomList(RandomListNode *head);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

RandomListNode *copyRandomList(RandomListNode *head) {

    if(!head)
        return NULL;

    map<RandomListNode*,int> mymap;
    vector<RandomListNode*> vec;
    RandomListNode* p=head;
    int count=0;
    while(p){
        mymap[p]=count;
        RandomListNode* h=new RandomListNode(p->label);
        vec.push_back(h);

        count++;
        p=p->next;
    }

    p=head;
    int index=0;
    while(p){
        if(p->random==NULL)
            vec[index]->random=NULL;
        else{
            int t=mymap[p->random];
            vec[index]->random=vec[t];
        }
        index++;
        p=p->next;
    }
    for(int i=0;i<vec.size()-1;i++)
        vec[i]->next=vec[i+1];

    return vec[0];


}