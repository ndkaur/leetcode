#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


class Solution0 { //n^2
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(prices[i]);
            for(int j=i+1; j<n; j++){
                if(prices[j] <= prices[i]){
                    ans[i]=(prices[i]-prices[j]);
                    break;
                }
            }
        }
        return ans;
    }
};



class Solution { 
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        
        stack<int> stk;
        // next smaller element we need -> monotonic increasing stack
        for(int i=0; i<n; i++){
            // decreasing will be condition 
            while(stk.size() && prices[stk.top()] >= prices[i]){
                ans[stk.top()] = prices[stk.top()] - prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> finalPrices(vector<int>& price) {
        int n=price.size();
        for(int i=0;i<n-1;i++){
            int j=i+1;
            if(price[i]>=price[j]){
                price[i]=price[i]-price[j];
            }
            else {
                while(j!=n){
                    if(price[i]>=price[j]){
                        price[i]=price[i]-price[j];
                        break;
                    }
                    else 
                        j++;
                }
            }
        }
        return price;
    }
};

int main(){
    Solution sol;
    vector<int> price={10,1,1,6};
    vector<int> ans=sol.finalPrices(price);
    print(ans);
    return 0;
}