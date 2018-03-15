#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix);
bool isValid(pair<int,int> p,int m,int n);
bool canGo(pair<int,int> p,int cur,vector<vector<int>>& matrix);
int main() {
    vector<vector<int>> matrix;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    vector<int> row4;
    vector<int> row5;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(2);
    row1.push_back(3);
    row1.push_back(5);
    row2.push_back(3);
    row2.push_back(2);
    row2.push_back(3);
    row2.push_back(4);
    row2.push_back(4);
    row3.push_back(2);
    row3.push_back(4);
    row3.push_back(5);
    row3.push_back(3);
    row3.push_back(1);
    row4.push_back(6);
    row4.push_back(7);
    row4.push_back(1);
    row4.push_back(4);
    row4.push_back(5);
    row5.push_back(5);
    row5.push_back(1);
    row5.push_back(1);
    row5.push_back(2);
    row5.push_back(4);
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    matrix.push_back(row5);
    vector<pair<int,int>> res=pacificAtlantic(matrix);
    cout<<res.size()<<endl;

}
bool isValid(pair<int,int> p,int m,int n){
    int x=p.first;
    int y=p.second;
    return x>=0&&x<m&&y>=0&&y<n;
}
bool canGo(pair<int,int> p,int cur,vector<vector<int>>& matrix){
    int x=p.first;
    int y=p.second;
    return matrix[x][y]>=cur;
}
vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {

    vector<pair<int,int>> res;

    int m=matrix.size();
    if(m==0)
        return res;
    int n=matrix[0].size();
    if(n==0)
        return res;


    vector<pair<int,int>> PQ;
    map<pair<int,int>,bool> Pmap;

    for(int i=0;i<n;i++){
        pair<int,int> p=pair<int,int>(0,i);
        PQ.push_back(p);
        Pmap[p]=true;
    }
    for(int i=0;i<m;i++){
        pair<int,int> p=pair<int,int>(i,0);
        PQ.push_back(p);
        Pmap[p]=true;
    }


    while(!PQ.empty()){
        pair<int,int> cur=PQ[0];
        PQ.erase(PQ.begin());

        int x=cur.first;
        int y=cur.second;
        int h=matrix[x][y];

        pair<int,int> up(x-1,y);
        pair<int,int> down(x+1,y);
        pair<int,int> left(x,y-1);
        pair<int,int> right(x,y+1);

        if(!Pmap.count(up)&&isValid(up,m,n)&&canGo(up,h,matrix)){
            Pmap[up]=true;
            PQ.push_back(up);
        }
        if(!Pmap.count(down)&&isValid(down,m,n)&&canGo(down,h,matrix)){
            Pmap[down]=true;
            PQ.push_back(down);
        }
        if(!Pmap.count(left)&&isValid(left,m,n)&&canGo(left,h,matrix)){
            Pmap[left]=true;
            PQ.push_back(left);
        }
        if(!Pmap.count(right)&&isValid(right,m,n)&&canGo(right,h,matrix)){
            Pmap[right]=true;
            PQ.push_back(right);
        }


    }


    vector<pair<int,int>> AQ;
    map<pair<int,int>,bool> Amap;

    for(int i=0;i<n;i++){
        pair<int,int> p=pair<int,int>(m-1,i);
        AQ.push_back(p);
        Amap[p]=true;
    }
    for(int i=0;i<m;i++){
        pair<int,int> p=pair<int,int>(i,n-1);
        AQ.push_back(p);
        Amap[p]=true;
    }


    while(!AQ.empty()){
        pair<int,int> cur=AQ[0];
        AQ.erase(AQ.begin());

        int x=cur.first;
        int y=cur.second;
        int h=matrix[x][y];

        pair<int,int> up(x-1,y);
        pair<int,int> down(x+1,y);
        pair<int,int> left(x,y-1);
        pair<int,int> right(x,y+1);

        if(!Amap.count(up)&&isValid(up,m,n)&&canGo(up,h,matrix)){
            Amap[up]=true;
           AQ.push_back(up);
        }
        if(!Amap.count(down)&&isValid(down,m,n)&&canGo(down,h,matrix)){
            Amap[down]=true;
            AQ.push_back(down);
        }
        if(!Amap.count(left)&&isValid(left,m,n)&&canGo(left,h,matrix)){
            Amap[left]=true;
            AQ.push_back(left);
        }
        if(!Amap.count(right)&&isValid(right,m,n)&&canGo(right,h,matrix)){
            Amap[right]=true;
            AQ.push_back(right);
        }


    }

    map<pair<int,int>,bool>::iterator ite=Pmap.begin();
    while(ite!=Pmap.end()){
        if(Amap.count(ite->first))
            res.push_back(ite->first);
        ite++;
    }

    return res;




}