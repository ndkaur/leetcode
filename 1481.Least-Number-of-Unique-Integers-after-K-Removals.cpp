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


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();  
        map<int,int> mp;
        for(int a:arr){
            mp[a]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto itr:mp){
            pq.push({itr.second,itr.first});
        }
        while(k>0){
            auto freq = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            if(k>=freq)
                k=k-freq;
            else{ // freq is greater 
                k = 0;
                pq.push({freq-k, node});
            }
        }
        return pq.size();
    }
};

int main(){

    return 0;
}