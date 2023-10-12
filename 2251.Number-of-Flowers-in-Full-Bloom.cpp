#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution0 {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        map<int,int> mp{{0,0}};
        for(auto &flower:flowers){
            mp[flower[0]]++;
            mp[flower[1]+1]--;
        }
        int sum =0;
        for(auto &itr:mp){
            sum += itr.second;
            // this increase the curr count of the bloomed flowers a person can see 
            itr.second=sum;
        }

        vector<int> ans;
        for(int i=0; i<people.size(); i++){
            auto itr = mp.upper_bound(people[i]);
            ans.push_back(prev(itr)->second);
        }
        return ans;
    }
};


// logic of start time upper bound : - val>target
//  we want first index where the person is able to see the bloomed flower when it comes that means index greater than its value 

// end time lower bound:-  val>=target
//  we want to find the index till which the either the flower dies or will dies afterwards but is still bloomed so lower bound 

class Solution { // time -> O((N+M) log N)
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
        for(auto flower:flowers){
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(), start.end()); // O(nlogn)
        sort(end.begin(), end.end());

        vector<int> ans;
        for(int p:people){
            // lb , ub -> O(MlogN)
            int started = upper_bound(start.begin(), start.end(), p)- start.begin(); 
            int ended = lower_bound(end.begin(), end.end(), p) - end.begin();
            ans.push_back(started- ended);
        }
        return ans;
    }
};


int main(){

    return 0;
}