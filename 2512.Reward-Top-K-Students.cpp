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
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){ // If score is equal we sort on the basis of the id, lower ID first
            return a[1]<b[1];
        }
        // score not equal decending order
        return a[0]>=b[0]; // Descending order of scores
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        // Using set for fast access
        unordered_set<string> p(positive_feedback.begin(),positive_feedback.end());
        unordered_set<string> n(negative_feedback.begin(),negative_feedback.end());
        vector<vector<int>>s;
        for(int i=0;i<report.size();i++){
            string w=report[i]+" ";
            string tmp="";
            int score=0;
            // Seperating into words and checking 
            for(auto j:w){
                if(j!=' ')
                    tmp+=j;
                else{
                    if(p.find(tmp)!=p.end())
                        score+=3;
                    if(n.find(tmp)!=n.end())
                        score-=1;
                    tmp="";    
                }
            }
            s.push_back({score,student_id[i]});
            
        }
        sort(s.begin(),s.end(),comp);
        vector<int> ans;
        for(int i=0;i<k;i++) // First 'k' Id's
            ans.push_back(s[i][1]);
        return ans;
    }
};

// positive_feedback = ["smart","brilliant","studious"],
// negative_feedback = ["not"], 
// report = ["this student is studious","the student is smart"], 
// student_id = [1,2], k = 2
// Output: [1,2]

int main(){

    return 0;
}