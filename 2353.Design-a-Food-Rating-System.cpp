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

class myComparator{
public:
    bool operator() (pair<int,string>& p1, pair<int,string>& p2){
        if(p1.first==p2.first) // both the ratings same 
            return p1.second > p2.second; // return true if second string is greater than first string and if true than no swapping 
        return p1.first < p2.first;
    }
};


 // map<string, pq> // {cusine, {rating,food } }
//  priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>>
class FoodRatings {
public:
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>,myComparator>> mp;  
    // we want lexicographcaly smaller 
    unordered_map<string,int> rate; // food, it
    unordered_map<string,string> cuis; // food, cuisine

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            mp[cuisines[i]].push({ratings[i], foods[i]});
            rate[foods[i]] = ratings[i];
            cuis[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        // changes the rating of the food
        rate[food] = newRating;
        // now change the rating in the map mp also 
        // but map is of cuisine , {rating, food}
        // ans cuisine can be found using map of cuis
        string cusine = cuis[food];
        mp[cusine].push({newRating, food});

    }
    
    string highestRated(string cuisine) {
        string ans;
        while(1){
            auto itr = mp[cuisine].top(); // {rating, food}
            // if rate changed new rating given 
            // rate map -> {food, rating}
            if(rate[itr.second] == itr.first) // rating is same no change
                return itr.second;
            else
                mp[cuisine].pop();
        }
        // we want to keep all ratings but when two ratings same need lexico smaller string so use comparator
    }
};

int main(){

    return 0;
}