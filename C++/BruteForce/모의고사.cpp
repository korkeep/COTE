#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int supo1[5] = { 1, 2, 3, 4, 5 };
int supo2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int supo3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
int cnt[3];

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int max_cnt = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (supo1[i % 5] == answers[i]) cnt[0]++;
        if (supo2[i % 8] == answers[i]) cnt[1]++;
        if (supo3[i % 10] == answers[i]) cnt[2]++;
    }
    max_cnt = max(cnt[0], max(cnt[1], cnt[2]));

    for (int i = 0; i < 3; i++) {
        if (max_cnt == cnt[i]) answer.push_back(i + 1);
    }

    return answer;
}