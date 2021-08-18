#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 2147483647;
void recursive(int N, int number, int cnt, int sum) {
	// 8보다 큰 경우
	if (cnt > 8) return;

	// answer에 도달
	if (sum == number)
		if (answer > cnt) answer = cnt;

	int i, NN;	// NN: 반복되는 숫자
	for (i = 1, NN = 0; i <= 8; i++) {
		NN = NN * 10 + N;
		recursive(N, number, cnt + i, sum + NN);
		recursive(N, number, cnt + i, sum - NN);
		recursive(N, number, cnt + i, sum / NN);
		recursive(N, number, cnt + i, sum * NN);
	}
}

int solution(int N, int number) {
	recursive(N, number, 0, 0);
	if (answer > 8) answer = -1;
	return answer;
}

int main() {
    int N, number;
    cin >> N >> number;
    cout << solution(N, number) << endl;
}