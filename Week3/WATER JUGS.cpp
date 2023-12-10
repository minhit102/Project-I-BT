#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int printpath(map<pii, pii> mp, pii u, int k)
{
	if (u.first == 0 && u.second == 0) {
	    return k;
	}
	return printpath(mp, mp[u], k + 1);
}

int BFS(int a, int b, int target)
{
	map<pii, int> m;
	bool isSolvable = false;
	map<pii, pii> mp;

	queue<pii> q;

	q.push(make_pair(0, 0));
	while (!q.empty()) {

		auto u = q.front();
		q.pop();
		if (m[u] == 1)
			continue;

		if ((u.first > a || u.second > b || u.first < 0 || u.second < 0))
			continue;

		m[{ u.first, u.second }] = 1;

		if (u.first == target || u.second == target) {
			isSolvable = true;

			return printpath(mp, u, 0);
		}

		if (m[{ u.first, b }] != 1) {
			q.push({ u.first, b });
			mp[{ u.first, b }] = u;
		}

		if (m[{ a, u.second }] != 1) {
			q.push({ a, u.second });
			mp[{ a, u.second }] = u;
		}

		int d = b - u.second;
		if (u.first >= d) {
			int c = u.first - d;
			if (m[{ c, b }] != 1) {
				q.push({ c, b });
				mp[{ c, b }] = u;
			}
		}
		else {
			int c = u.first + u.second;
			if (m[{ 0, c }] != 1) {
				q.push({ 0, c });
				mp[{ 0, c }] = u;
			}
		}

		d = a - u.first;
		if (u.second >= d) {
			int c = u.second - d;
			if (m[{ a, c }] != 1) {
				q.push({ a, c });
				mp[{ a, c }] = u;
			}
		}
		else {
			int c = u.first + u.second;
			if (m[{ c, 0 }] != 1) {
				q.push({ c, 0 });
				mp[{ c, 0 }] = u;
			}
		}

		if (m[{ u.first, 0 }] != 1) {
			q.push({ u.first, 0 });
			mp[{ u.first, 0 }] = u;
		}

		if (m[{ 0, u.second }] != 1) {
			q.push({ 0, u.second });
			mp[{ 0, u.second }] = u;
		}
	}
	if (!isSolvable)
		return -1;
}

int main()
{
	int Jug1, Jug2, target ;
	cin >> Jug1 >> Jug2  >> target;
	cout << BFS(Jug1, Jug2, target);
	return 0;
}
