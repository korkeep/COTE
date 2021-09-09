// 백준 1021 회전하는 큐
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
	deque<int> deck;
	int cnt = 0;
	int N, M, num, idx, i, j;
	cin >> N >> M;

	for (i = 1; i <= N; i++) {
		deck.push_back(i);
	}

	for (i = 0; i < M; i++) {
		cin >> num;

		// Index 찾아주기
		for (j = idx = 0; j < deck.size(); j++) {
			if (deck[j] == num) {
				idx = j;
				break;
			}
		}
		
		// 2번 연산이 이로운 경우
		if (idx < deck.size() - idx) {
			while (true) {
				if (deck.front() == num) {
					deck.pop_front();
					break;
				}
				cnt++;
				deck.push_back(deck.front());
				deck.pop_front();
			}
		}
		
		// 3번 연산이 이로운 경우
		else {
			while (true) {
				if (deck.front() == num) {
					deck.pop_front();
					break;
				}
				cnt++;
				deck.push_front(deck.back());
				deck.pop_back();
			}
		}
	}
	cout << cnt << endl;

	return 0;
}