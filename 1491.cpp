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
    double average(vector<int>& salary) {
        int n=salary.size();
        
        sort(salary.begin(),salary.end());
        double avg=0;
        double sum=0;
        double count=0;
        for(int i=1;i<n-1;i++){
            sum=sum+salary[i];
            count++;
        }
        avg=sum/count;
        return avg;
    }
};


int main(){
    Solution sol;
    vector<int> salary={48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000};
    double avg=sol.average(salary);
    cout<<avg;
    return 0;
}