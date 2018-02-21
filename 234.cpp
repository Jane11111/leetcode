#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
bool isPalindrome(ListNode* head);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool isPalindrome(ListNode* head) {
    vector<int> nums;
    while(head!=NULL){
        nums.push_back(head->val);
        head=head->next;
    }

    int s=0;
    int e=nums.size()-1;
    while(s<e){
        if(nums[s]!=nums[e])
            return false;
        s++;
        e--;
    }
    return true;

}