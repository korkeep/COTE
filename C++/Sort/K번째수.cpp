#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    int idx, i, j, k;

    for (idx = 0; idx < commands.size(); idx++) {
        i = commands[idx][0] - 1;
        j = commands[idx][1] - 1;
        k = commands[idx][2] - 1;
        
        for (; i <= j; i++)
            temp.push_back(array[i]);

        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);

        temp.clear();
    }

    return answer;
}