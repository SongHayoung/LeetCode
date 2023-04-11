
struct Task {
    string desc;
    vector<string> tags;
    int dueDate;
    int id;
};
class TodoList {
    int idGen = 0;
    unordered_map<int, unordered_map<string,unordered_set<int>>> tagRef;
    unordered_map<int, unordered_map<int, Task>> taskRef;
    int incr(int userId) {
        return ++idGen;
    }
    vector<string> sortByDueDate(vector<Task>& A) {
        sort(begin(A), end(A), [](auto a, auto b) {return a.dueDate < b.dueDate;});
        vector<string> res;
        for(auto t : A) res.push_back(t.desc);
        return res;
    }
public:
    TodoList() {}

    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        int id = incr(userId);
        Task task{taskDescription, tags, dueDate, id};
        taskRef[userId][id] = task;
        for(auto t : tags) tagRef[userId][t].insert(id);
        return id;
    }

    vector<string> getAllTasks(int userId) {
        vector<Task> A;
        for(auto [id, t] : taskRef[userId]) A.push_back(t);
        return sortByDueDate(A);
    }

    vector<string> getTasksForTag(int userId, string tag) {
        vector<Task> A;
        for(auto id : tagRef[userId][tag]) A.push_back(taskRef[userId][id]);
        return sortByDueDate(A);
    }

    void completeTask(int userId, int taskId) {
        if(!taskRef.count(userId)) return;
        if(!taskRef[userId].count(taskId)) return;
        Task t = taskRef[userId][taskId];
        taskRef[userId].erase(taskId);
        if(taskRef[userId].empty()) taskRef.erase(userId);
        for(auto& tag : t.tags) {
            tagRef[userId][tag].erase(t.id);
            if(tagRef[userId][tag].empty()) tagRef[userId].erase(tag);
            if(tagRef[userId].empty()) tagRef.erase(userId);
        }
    }
};

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */
