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

class TaskManager {
public:
    priority_queue<pair<int,int>> pq; // max_heap -> priority->task
    unordered_map<int,int> taskToPriority; // task->prioirty
    // we want to return user that has max priorirty-> task-> user? 
    unordered_map<int,int> taskToUser; // task -> user
    TaskManager(vector<vector<int>>& tasks) {
        for(auto task:tasks){
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        taskToPriority[taskId] = priority;
        taskToUser[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        pq.push({newPriority, taskId});
        taskToPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        taskToPriority[taskId] = -1;
    }
    
    int execTop() {
        while(pq.size()){
            auto itr = pq.top();
            pq.pop();
            int prio = itr.first;
            int task = itr.second;
            // if the priority os the task is same in the pq and in the map that means no new rating was added 
            if(prio == taskToPriority[task]){
                taskToPriority[task] = -1;
                return taskToUser[task];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */ 


int main(){

    return 0;
}