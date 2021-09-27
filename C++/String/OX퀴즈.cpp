// Baekjoon: 8958

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n, i, j, cnt, temp;
	cin >> n;

	string str = "";
	vector<int> list;

	for (i = 0; i < n; i++) {
		cin >> str;
		temp = cnt = 0;
		for (j = 0; j < str.length(); j++) {
			if (str.at(j) == 'O') temp++;
			else temp = 0;
			cnt += temp;
		}
		list.push_back(cnt);
	}

	for (i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}
	return 0;
}