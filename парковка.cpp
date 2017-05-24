#include <iostream>

#include <vector>

#include <queue>

using std::cout;

using std::cin;

int main() {

int count_places, count_cars, temp;

scanf("%d %d", &count_places, &count_cars);

std::vector<int> price;

for (int i = 0; i < count_places; i++) {

cin >> temp;

price.push_back(temp);

}

std::vector<int> weight;

for (int i = 0; i < count_cars; i++) {

cin >> temp;

weight.push_back(temp);

}

std::queue<int> order;

for (int i = 0; i < 2 * count_cars; i++) {

cin >> temp;

order.push(temp);

}

std::vector<int> places(count_places, -1);

std::queue<int> waitings_cars;

int free_places = count_places;

int money = 0;

while (!order.empty()) {

int current_car;

if (!waitings_cars.empty() && free_places > 0) {

current_car = waitings_cars.front();

waitings_cars.pop();

int i;

for (i = 0; i < count_places; i++) {

if (places[i] == -1) {

money += price[i] * weight[current_car - 1];

places[i] = current_car;

free_places--;

break;

}

}

} else {

current_car = order.front();

order.pop();

if (current_car < 0) {

current_car *= -1;

for (int i = 0; i < count_places; i++) {

if (places[i] == current_car) {

places[i] = -1;

free_places++;

}

}

} else {

int k;

for (k = 0; k < count_places; k++) {

if (places[k] == -1) {

money += price[k] * weight[current_car - 1];

places[k] = current_car;

free_places--;

break;

}

}

if (k == count_places) waitings_cars.push(current_car); }

}

}

cout << money << std::endl;

return 0;

}
