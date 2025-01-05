
class TaskManager {
    map<int,set<int>> ptasks;
    unordered_map<int, pair<int,int>> tasks;
public:
    TaskManager(vector<vector<int>>& T) {
        ptasks = {}, tasks = {};
        for(auto& task : T) {
            int u = task[0], t = task[1], p = task[2];
            add(u,t,p);
        }
    }

    void add(int userId, int taskId, int priority) {
        ptasks[priority].insert(taskId);
        tasks[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority) {
        ptasks[tasks[taskId].second].erase(taskId);
        if(ptasks[tasks[taskId].second].size() == 0) {
            ptasks.erase(tasks[taskId].second);
        }
        tasks[taskId].second = newPriority;
        ptasks[newPriority].insert(taskId);
    }

    void rmv(int taskId) {
        ptasks[tasks[taskId].second].erase(taskId);
        if(ptasks[tasks[taskId].second].size() == 0) {
            ptasks.erase(tasks[taskId].second);
        }
        tasks.erase(taskId);
    }

    int execTop() {
        if(ptasks.empty()) return -1;
        int task = *prev(end(prev(end(ptasks))->second));
        int userId = tasks[task].first;
        rmv(task);
        return userId;
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