#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

// ������׽��� ü
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> idx;
    vector<int> num;
    string temp;
    
    // �� ���� �ϳ��� �޾ƿ���
    for (int i = 0; i < numbers.size(); i++) {
        idx.push_back(numbers[i]);
    }
    sort(idx.begin(), idx.end());

    // ���� �� �ִ� ��� ���
    do {
        temp = "";
        for (int i = 0; i < idx.size(); i++) {
            temp.push_back(idx[i]);
            num.push_back(stoi(temp));
        }
    } while (next_permutation(idx.begin(), idx.end()));

    // �ߺ� ����
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    for (int i = 0; i < num.size(); i++) {
        if (isPrime(num[i])) answer++;
    }

    return answer;
}