#include <iostream>

#include <set>

using std::cin;

using std::set;

void main() {

int n;

set<int> s;

set<int>::iterator iter;

bool search=false;

int result;

scanf("%d", &n);

for (int i = 0; i < n; ++i) {

char symbol;

int number;

cin >> symbol;

scanf("%d", &result);

if(symbol == '+') {

if(search) {

s.insert((result+number) % 1000000000);

search = false;

}

else

s.insert(result);

}

else if(symbol == '?') {

search = true;

iter = s.lower_bound(result);

if(iter == s.end()) {

printf("-1\n");

number = -1;

} else {

number = *iter;

printf("%d\n", number);

}

}

}
