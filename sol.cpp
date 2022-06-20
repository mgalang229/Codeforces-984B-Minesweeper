#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long

const int M = 101;
char a[M][M];
int n, m;
int x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int y[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%s", &a[i]);
	bool ok = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != '*') {
				int cnt = 0;
				for (int id = 0; id < 8; id++) {
					int R = (i + x[id]);
					int C = (j + y[id]);
					if (R >= 0 && R < n && C >= 0 && C < m)
						if (a[R][C] == '*') cnt++;
				}
				//printf("%d\n", cnt);
				if (a[i][j] == '.' && cnt > 0) ok = false;
				if (a[i][j] != '.' && cnt != (a[i][j] - '0')) ok = false;
			}
	printf(ok ? "YES\n" : "NO\n");
	
	return 0;
}
