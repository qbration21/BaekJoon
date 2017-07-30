#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n; vector<int> arr;
int dp[10000][3];
int go(int pos, int state) {
	if (pos == n) return 0;
	int &ret = dp[pos][state];
	if (ret != -1) return ret;
	ret = 0;
	if(state < 2)
		ret = go(pos + 1, state + 1) + arr[pos];
	ret = max(ret, go(pos + 1, 0));
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	arr = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << '\n';
	return 0;
}