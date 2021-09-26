// Baekjoon 12865

#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> WV[101]; // 제품의 무게, 제품의 가치
int result[101][100001]; // i번째 아이템, 누적된 무게

int main() {
	
    int N, K, i, j;
	cin >> N >> K;	//제품의 개수, 버틸수 있는 무게

	for (i = 1; i <= N; i++) {
		cin >> WV[i].first >> WV[i].second;	//제품의 무게, 제품의 가치
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= K; j++) {
			result[i][j] = result[i - 1][j];
			if (WV[i].first <= j) {
				result[i][j] = max(result[i][j], result[i - 1][j - WV[i].first] + WV[i].second);
			}
		}
	}

	cout << result[N][K] << '\n';
	return 0;
}