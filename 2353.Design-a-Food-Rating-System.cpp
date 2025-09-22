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
            if(rate[itr.second] == itr.first) // rating is same that means no new rating has been added 
                return itr.second;
            else
                mp[cuisine].pop();
        }
        // we want to keep all ratings but when two ratings same need lexico smaller string so use comparator
    }
};


class FoodRatings {
public:
    // food-> {cuisne , rating}
    map<string, pair<string,int>> food_to_cusine_rating;
    // what cusine? -> max rating? -> same rating ?-> smallest letter food 
    map<string, map<int, set<string>>> cusine_to_rating_food;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            food_to_cusine_rating[foods[i]]={cuisines[i], ratings[i]};
            cusine_to_rating_food[cuisines[i]][ratings[i]].insert(foods[i]);
        }    
    }
    
    void changeRating(string food, int newRating) {
        auto food_info = food_to_cusine_rating.find(food);
        string cusine = food_info->second.first;
        int old_rating = food_info->second.second;
        // change in rating map
        food_info->second.second = newRating;

        // change in highest rating map
        cusine_to_rating_food[cusine][old_rating].erase(food);
        // same cusine can have same rating for different foods 
        // we need to remove the food for the old rating 
        // and if at that old rating there is no food left int he set , remove the old rating 
        // and add the new rating 
        if(cusine_to_rating_food[cusine][old_rating].empty()){
            // no food in the set, remove that rating for space managemt
            cusine_to_rating_food[cusine].erase(old_rating);
        }
        // add new rating 
        cusine_to_rating_food[cusine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        // cusine -> map(rating in ascending order) -> set(food in lexio smaller order)
        // rating in highest order -> food in smallest 
        return *cusine_to_rating_food[cuisine].rbegin()->second.begin();
    }
};

int main(){

    return 0;
}