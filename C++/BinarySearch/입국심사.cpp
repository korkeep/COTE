#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left, mid, right, people;
    
    // left: ������ �ּ� �ð�, right: ������ �ִ� �ð�
    left = 1;
    right = *max_element(times.begin(), times.end()) * (long long)n;
    
    while (left <= right) {
        people = 0;
        mid = (left + right) / 2;
        
        // people: mid �ð����� �ɻ��� �� �ִ� ��� ��� ��
        for (int i = 0; i < times.size(); i++) {
            people += mid / times[i];
        }

        // people�� n�� �̻��� ������ ��� right idx ���� & answer ����
        if (n <= people) {
            answer = mid;
            right = mid - 1;
        }

        // people�� n���� �۴ٸ� ���� �������� �����Ƿ� left idx ����
        else {
            left = mid + 1;
        }
    }

    return answer;
}