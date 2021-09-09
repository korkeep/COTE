#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    queue<int> q;
    int day;

    for (int i = 0; i < progresses.size(); i++) { 
        day = (100 - progresses[i]) / speeds[i]; 
        if (progresses[i] + day * speeds[i] != 100) day++;
        days.push_back(day);
    }

    q.push(days[0]);
    for (int i = 1; i < days.size(); i++) {
        if (days[i] <= q.front()) {
            q.push(days[i]);
        }
        else {
            answer.push_back(q.size());
            while (!q.empty()) q.pop();
            q.push(days[i]);
        }
    }
    if (!q.empty()) answer.push_back(q.size());

    return answer;
}