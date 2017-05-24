#include <iostream>

#include <algorithm>

long long int MAX = 1000000000000;

int SQRT_MAX = 1000000;

int *numbers = new int[SQRT_MAX];

int *primes = new int[SQRT_MAX];

long long int *fill_primes = new long long int[SQRT_MAX];

int count_primes = 0;

int count_fill_primes = 0;

long long int temp = 0;

void func() {

numbers[0] = numbers[1] = 0;

for(int i = 2; i <= SQRT_MAX; i++) {

numbers[i] = i;

}

for(int i = 2; i <= SQRT_MAX; i++) {

if(numbers[i] != 0) {

primes[count_primes] = numbers[i];

temp = long long int(numbers[i])*long long int(numbers[i]);

count_primes++;

do {

fill_primes[count_fill_primes] = temp;

count_fill_primes++;

temp *= long long int (numbers[i]);

} while (temp <= MAX);

for(int j = 2; i*j <= SQRT_MAX; j++) {

numbers[i*j] = 0;

}

}

}

}

int getCount(long long int n) {

int L = 0, R = 80069;

while (L < R){

int m = (L + R + 1) / 2;

if (fill_primes[m] <= n)

L = m;

else

R = m - 1;

}

return fill_primes[L] <= n ? L + 1 : 0;

}

int main() {

func();

fill_primes[count_fill_primes]=0;

std::sort(fill_primes, fill_primes+count_fill_primes);

int number_of_tests;

std::cin >> number_of_tests;

long long int low, high;

for(int i = 0; i < number_of_tests; i++) {

std::cin >> low >> high;

std::cout << getCount(high) - getCount(low-1) << std::endl;

}

system("pause");

return 0;

}
