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