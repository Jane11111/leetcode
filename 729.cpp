#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MyCalendar {
public:

    vector<pair<int,int>> books;
    MyCalendar() {

    }

    bool book(int start, int end) {
        int i=0;
        for(;i<books.size()&&start>books[i].first;i++);

        if(i>0&&start<books[i-1].second||i<books.size()&&end>books[i].first)
            return false;
        books.insert(books.begin()+i,pair<int,int>(start,end));
        return true;

    }
};