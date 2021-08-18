#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left, mid, right, people;
    
    // left: 가능한 최소 시간, right: 가능한 최대 시간
    left = 1;
    right = *max_element(times.begin(), times.end()) * (long long)n;
    
    while (left <= right) {
        people = 0;
        mid = (left + right) / 2;
        
        // people: mid 시간동안 심사할 수 있는 모든 사람 수
        for (int i = 0; i < times.size(); i++) {
            people += mid / times[i];
        }

        // people이 n명 이상을 충족한 경우 right idx 변경 & answer 갱신
        if (n <= people) {
            answer = mid;
            right = mid - 1;
        }

        // people이 n명보다 작다면 조건 만족하지 않으므로 left idx 변경
        else {
            left = mid + 1;
        }
    }

    return answer;
}