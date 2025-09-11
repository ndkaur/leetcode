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
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // find which person knows what all languages and store it in a set
        int users = languages.size();
        vector<set<int>> knows(users+1);
        for(int i=0; i<users; i++){
            for(int l:languages[i]){
                // 0 basex indexing 
                // person i+1 knows l language
                knows[i+1].insert(l);
            }
        }

        set<int> needToTeach;
        // now we need to find that among friend who all we need to teach 
        for(auto& f:friendships){
            int u = f[0];
            int v = f[1];
            // check for any language intersection among both friends 
            // check if all the languages known to u any of them is also known to v
            bool flag = false;
            for(int lang:knows[u]){
                if(knows[v].find(lang)!=knows[v].end()){ // intersections found
                    flag = true;
                    break;
                }
            }
            // if the flag is still false then it has no common languge so we need to thech both the people
            if(!flag){
                needToTeach.insert(u);
                needToTeach.insert(v);
            }
        }

        if(needToTeach.size()==0)
            return 0;
        // now we know what all people we need to teech 
        // so we can chack one by one each language and see what min no of people nedd to be taught 
        int ans = users;
        for(int l=1; l<=n; l++){
            int cnt =0;
            for(int people:needToTeach){
                // for that person check if it knows that particular lang
                if(knows[people].find(l)==knows[people].end()){
                    // doenot know that lang
                    cnt++; // teach that person
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};

int main(){

    return 0;
}