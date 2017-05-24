#include <iostream>

using std::cin;

using std::cout;

long searchL(long* a, long left, long right, long key) {

long mid;

while (left < right) {

mid = (left + right) / 2;

if (key <= a[mid]) {

right = mid;

}

else {

left = mid + 1;

}

}

return left;

}

long searchR(long* a, long left, long right, long key) {

long mid;

while (left < right) {

mid = (left + right) / 2;

if (key >= a[mid]) {

left = mid + 1;

}

else {

right = mid;

}

}

return right;

}

void main() {

long N;

long M;

cin >> N;

long* animal = new long[N];

for (long i = 0; i < N; ++ i) {

cin >> animal[i];

}

cin >> M;

long* color = new long[M];

for (long i = 0; i < M; ++ i) {

cin >> color[i];

}

long left = 0;

long right = 0;

for (long i = 0; i < M; ++ i) {

long key = color[i];

long left = searchL(&animal[0], 0, N, key);

long right = searchR(&animal[0], 0, N, key);

cout << right - left << "\n";

}

delete [] animal;

delete [] color;

}
