//#include <cstdio>
#include <ctime>
//#include <cstring>
#include <cstdlib>
//#include <algorithm>
#include <iostream>
#include <fstream>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i);
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int MOD = 7+1e9;
//产生 [L,R] 内随机数
int maker(int L,int R) {
  return L + rand() % (R - L + 1);
}
ofstream fout("data.out");
int main() {
	unsigned int tm = (unsigned)time(NULL);
  srand(tm);
  //srand(time(0));
	_rep(i, 0, 100) {
		fout << maker(1, 10000) << ' ' << maker(1, 100) << " " << maker(1, 100) << endl;
	}
  return 0;
}
