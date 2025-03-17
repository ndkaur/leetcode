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
        bool isPossible(long long& given_time, vector<int>& ranks, int cars){
            int n = ranks.size();
            long long total_cars_repaired= 0;
            // l , h , mid is time ranges 
            // time = rank * no of cars^2
            // so we need to find how many no of cars can be repaired with mid time 
            // and if the repaired cars is equal or greater to the cars then true
            // no of cars^2 = time/rank
            // no of cars = sqrt(time/rank)
            for(int rank:ranks){
                total_cars_repaired += sqrt(given_time/rank);
                if(total_cars_repaired>=cars){
                    return true;
                }
            }
            return false;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            int n = ranks.size();
            long long l = 1;
            long long h = (long long)*min_element(ranks.begin(), ranks.end())*cars*cars;
            long long ans = -1;
            while(l<=h){
                long long mid = l+(h-l)/2;
                if(isPossible(mid,ranks, cars)){
                    ans = mid;
                    h = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            return ans;
        }
    };

int main(){

    return 0;
}