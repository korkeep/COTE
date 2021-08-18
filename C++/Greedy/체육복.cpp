#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> value(n, 0);

    for (int i = 0; i < lost.size(); i++)
        value[lost[i] - 1]--;

    for (int i = 0; i < reserve.size(); i++)
        value[reserve[i] - 1]++;
    
    for (int i = 0; i < value.size(); i++) {
        if (value[i] == -1) {
            if (i != 0 && value[i - 1] == 1) {
                value[i - 1]--;
                value[i]++;
            }
            if (i != value.size() - 1 && value[i + 1] == 1) {
                value[i + 1]--;
                value[i]++;
            }
        }
    }

    for (int i = 0; i < value.size(); i++) {
        if (value[i] != -1) answer++;
    }

    return answer;
}