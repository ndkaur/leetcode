/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */
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

// @lc code=start
// k closest so we minum needed so we will make max heap

class Solution { // time->nlogk  space->O(k)
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n= points.size();
        
        priority_queue<vector<int>> pq;
        for(auto& p:points){
            int x = p[0];
            int y= p[1];
            pq.push({x*x+y*y , x, y});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans(k);
        for(int i=0; i<k; i++){
            vector<int> t= pq.top();
            pq.pop();
            ans[i] = {t[1],t[2]};
        }
        return ans;
    }
};

class Solution { // nlogn
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n= points.size();
        auto elu = [](auto& p){ return p[0]*p[0]+p[1]*p[1];  };
        sort(points.begin() , points.end(),  [&](auto& a, auto& b) { return elu(a) < elu(b);});
        points.resize(k);
        return points;
    }
};

class Solution { // nlogn
public:
    struct comp{
        bool operator()(vector<int> a, vector<int> b){
            return pow(a[0], 2) + pow(a[1], 2) > pow(b[0], 2) + pow(b[1], 2);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n= points.size();
        sort(points.begin(), points.end(),comp());
        vector<vector<int>> ans;
        int i=1;
        while(i<=k){
            ans.push_back(points[n-i]);
            i++;
        }
        return ans;
    }
};



class Solution { // nlogn
public:
    static bool comp(vector<int> a,vector<int> b){
        long d1,d2;
        d1=a[0]*a[0]+a[1]*a[1];
        d2=b[0]*b[0]+b[1]*b[1];
        
        return d1<d2;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k){        
        sort(a.begin(),a.end(),comp);
        vector<vector<int>> ans(a.begin(),a.begin()+k);
        
        return ans;
    }
};


// @lc code=end


int main(){

    return 0;
}