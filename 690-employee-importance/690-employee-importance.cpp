/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    unordered_map<int, Employee*> employeeIdMap;
    int res = INT_MIN;
    int getTotalImportance(Employee* employee) {
        int importance = employee->importance;
        for(auto& sub : employee->subordinates) {
            importance += getTotalImportance(employeeIdMap[sub]);
        }
        return importance;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(auto& e : employees)
            employeeIdMap[e->id] = e;
        return getTotalImportance(employeeIdMap[id]);
    }
};