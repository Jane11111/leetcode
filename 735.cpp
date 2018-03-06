#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids);

int main()
{
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-2);
    vector<int> res=asteroidCollision(nums);
    cout<<res.size()<<endl;
}


vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int>Q;
    for(int i=0;i<asteroids.size();i++){
        int num=asteroids[i];
        if(num>0)
            Q.push_back(num);
        else{
           if(Q.empty()){
                Q.push_back(num);
                continue;
            }
            for(int j=Q.size()-1;j>=0;j--){
                if(Q[j]<0){
                    Q.push_back(num);
                    break;
                }else{
                    if(Q[j]>abs(num))
                        break;
                    else if(Q[j]==abs(num)){
                        Q.erase(Q.begin()+j);
                        break;
                    }else{
                        Q.erase(Q.begin()+j);
                    }
                }
            }
        }
    }
    return Q;

}
