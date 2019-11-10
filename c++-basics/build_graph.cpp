#include <iostream>

using namespace std;
const int MAX_N = 100;
const int MAX_M = 10010;
const int INF = 0x3f3f3f3f;

struct edge
{
  int s, d, w;
  edge* next;
}mem[MAX_M];

int size = -1;

