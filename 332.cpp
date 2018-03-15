#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct cmp{
    bool operator()(string a,string b){
            return a>b;
    }
};

vector<string> findItinerary(vector<pair<string, string>> tickets);
bool DFS(string start,vector<string>& list,map<string,vector<string>> mymap);
void Insert(vector<string>& list,string s);
int main() {
    vector<pair<string,string>> tickets;
    tickets.push_back(pair<string,string>("JFK","KUL"));
    tickets.push_back(pair<string,string>("JFK","NRT"));
    tickets.push_back(pair<string,string>("NRT","JFK"));
   // tickets.push_back(pair<string,string>("ATL","JFK"));
   // tickets.push_back(pair<string,string>("ATL","SFO"));

    vector<string> res=findItinerary(tickets);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
void Insert(vector<string>& list,string s){
    int i=list.size()-1;
    while(i>=0&&s<list[i])
        i--;
    list.insert(list.begin()+i+1,s);
}
bool DFS(string start,vector<string>& list,map<string,vector<string>> mymap){

    map<string,vector<string>>::iterator ite=mymap.begin();
    bool allempty=true;
    while(ite!=mymap.end()){
        if(!ite->second.empty()){
            allempty=false;
            break;
        }
        ite++;
    }
    if(allempty)//已经全都遍历玩
        return true;
    vector<string> neighbors=mymap[start];
    if(neighbors.empty())
        return false;

    int len=neighbors.size();
    for(int i=0;i<len;i++){
        string dest=mymap[start][i];
        mymap[start].erase(mymap[start].begin()+i);
        list.push_back(dest);
        bool f=DFS(dest,list,mymap);
        if(f)
            return f;
        list.erase(list.begin()+list.size()-1);
        mymap[start].insert(mymap[start].begin()+i,dest);
    }
    return false;


}
vector<string> findItinerary(vector<pair<string, string>> tickets) {

    map<string,vector<string>> mymap;


    for(int i=0;i<tickets.size();i++){
        pair<string,string> ticket=tickets[i];{
            if(mymap.find(ticket.first)==mymap.end()){
                vector<string> t;
                mymap[ticket.first]=t;
            }
            Insert(mymap[ticket.first],ticket.second);
        }
    }

    vector<string> list;
    list.push_back("JFK");
    DFS("JFK",list,mymap);
    return list;

}