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

// O((candidate+k) log(candidate+k))
// O(candidate)

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1, pq2;
        int i=0; 
        int j=n-1;
        long long  sum = 0;
        int cnt =0;
        while(cnt<k){
            while(i<=j && pq1.size() < candidates){
                pq1.push({costs[i], i});
                i++;
            }
            while(j>=i && pq2.size() < candidates){
                pq2.push({costs[j], j});
                j--;
            }
            int top1 = pq1.size() > 0 ? pq1.top().first : INT_MAX;
            int top2 = pq2.size() > 0 ? pq2.top().first : INT_MAX;
            if(top1 <= top2){
                sum += top1;
                pq1.pop();
            }
            else{
                sum += top2;
                pq2.pop();
            }
            cnt++;    
        }
        return sum;
    }
};

// no need to store idx 
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int i=0; 
        int j=n-1;
        long long  sum = 0;
        int cnt =0;
        while(cnt<k){
            while(i<=j && pq1.size() < candidates){
                pq1.push(costs[i]);
                i++;
            }
            while(j>=i && pq2.size() < candidates){
                pq2.push(costs[j]);
                j--;
            }
            int top1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int top2 = pq2.size() > 0 ? pq2.top() : INT_MAX;
            if(top1 <= top2){
                sum += top1;
                pq1.pop();
            }
            else{
                sum += top2;
                pq2.pop();
            }
            cnt++;    
        }
        return sum;
    }
};


int main(){

    return 0;
}