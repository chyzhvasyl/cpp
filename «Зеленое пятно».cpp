#include <iostream>

#include <cmath>

#include <vector>

#include <algorithm>

using namespace std;

const double EPS = 1E-9;

struct pt {

double x, y;

bool operator< (const pt & p) const {

return x < p.x - EPS || abs(x - p.x) < EPS && y < p.y - EPS;

}

};

vector<pt> fig;

struct line {

double a, b, c;

line() {}

line(pt p, pt q) {

a = p.y - q.y;

b = q.x - p.x;

c = -a * p.x - b * p.y;

norm();

}

void norm() {

double z = sqrt(a*a + b*b);

if (abs(z) > EPS)

a /= z, b /= z, c /= z;

}

double dist(pt p) const {

return a * p.x + b * p.y + c;

}

};

#define det(a,b,c,d) (a*d-b*c)

double sq(const vector<pt> & fig)

{

double res = 0;

for (unsigned i = 0; i<fig.size(); i++)

{

pt

p1 = i ? fig[i - 1] : fig.back(),

p2 = fig[i];

res += (p1.x - p2.x) * (p1.y + p2.y);

}

return fabs(res) / 2;

}

bool cmp(pt a, pt b) {

return a.x < b.x || a.x == b.x && a.y < b.y;

}

bool cw(pt a, pt b, pt c) {

return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) < 0;

}

bool ccw(pt a, pt b, pt c) {

return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) > 0;

}

void convex_hull(vector<pt> & fig) {

if (fig.size() == 1) return;

sort(fig.begin(), fig.end(), &cmp);

pt p1 = fig[0], p2 = fig.back();

vector<pt> up, down;

up.push_back(p1);

down.push_back(p1);

for (size_t i = 1; i<fig.size(); ++i) {

if (i == fig.size() - 1 || cw(p1, fig[i], p2)) {

while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], fig[i]))

up.pop_back();

up.push_back(fig[i]);

}

if (i == fig.size() - 1 || ccw(p1, fig[i], p2)) {

while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], fig[i]))

down.pop_back();

down.push_back(fig[i]);

}

}

fig.clear();

for (size_t i = 0; i<up.size(); ++i)

fig.push_back(up[i]);

for (size_t i = down.size() - 2; i>0; --i)

fig.push_back(down[i]);

}

inline bool betw(double l, double r, double x) {

return min(l, r) <= x + EPS && x <= max(l, r) + EPS;

}

inline bool intersect_1d(double a, double b, double c, double d) {

if (a > b) swap(a, b);

if (c > d) swap(c, d);

return max(a, c) <= min(b, d) + EPS;

}

bool isInArray(double x, double y){

for (int i = 0; i < fig.size(); ++i){

if ((fabs(fig[i].x - x)<0.00000001) && (fabs(fig[i].y - y)<0.00000001))

/*if (fig[i].x == x && fig[i].y == y)*/

return false;

}

return true;

}

bool intersect(pt a, pt b, pt c, pt d) {

pt left, right;

if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))

return false;

line m(a, b);

line n(c, d);

double zn = det(m.a, m.b, n.a, n.b);

if (abs(zn) < EPS) {

if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)

return false;

if (b < a) swap(a, b);

if (d < c) swap(c, d);

left = max(a, c);

right = min(b, d);

return true;

}

else {

left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;

left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;

if (betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y)

&& betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y)) {

if (isInArray(left.x, left.y)){

fig.push_back(left);

}

}

return betw(a.x, b.x, left.x)

&& betw(a.y, b.y, left.y)

&& betw(c.x, d.x, left.x)

&& betw(c.y, d.y, left.y);

}

}

void isPointOnDelta(double x, double y, double x1, double y1, double x2, double y2, double x3, double y3){

double a1 = (x1 - x)*(y2 - y1) - (x2 - x1)*(y1 - y);

double a2 = (x2 - x)*(y3 - y2) - (x3 - x2)*(y2 - y);

double a3 = (x3 - x)*(y1 - y3) - (x1 - x3)*(y3 - y);

if ((a1 >= 0.0 && a2 >= 0.0 && a3 >= 0.0) || (a1 <= 0.0 && a2 <= 0.0 && a3 <= 0.0)){

if (isInArray(x, y)){

pt point;

point.x = x;

point.y = y;

fig.push_back(point);

}

}

}

void main() {

vector<pt> triangle1;

vector<pt> triangle2;

for (int i = 0; i < 3; ++i) {

pt point;

cin >> point.x;

cin >> point.y;

triangle1.push_back(point);

}

for (int i = 0; i < 3; ++i) {

pt point;

cin >> point.x;

cin >> point.y;

triangle2.push_back(point);;

}

intersect(triangle1[0], triangle1[1], triangle2[0], triangle2[1]);

intersect(triangle1[1], triangle1[2], triangle2[0], triangle2[1]);

intersect(triangle1[2], triangle1[0], triangle2[0], triangle2[1]);

intersect(triangle1[0], triangle1[1], triangle2[1], triangle2[2]);

intersect(triangle1[1], triangle1[2], triangle2[1], triangle2[2]);

intersect(triangle1[2], triangle1[0], triangle2[1], triangle2[2]);

intersect(triangle1[0], triangle1[1], triangle2[2], triangle2[0]);

intersect(triangle1[1], triangle1[2], triangle2[2], triangle2[0]);

intersect(triangle1[2], triangle1[0], triangle2[2], triangle2[0]);

isPointOnDelta(triangle1[0].x, triangle1[0].y, triangle2[0].x, triangle2[0].y, triangle2[1].x, triangle2[1].y, triangle2[2].x, triangle2[2].y);

isPointOnDelta(triangle1[2].x, triangle1[2].y, triangle2[0].x, triangle2[0].y, triangle2[1].x, triangle2[1].y, triangle2[2].x, triangle2[2].y);

isPointOnDelta(triangle1[1].x, triangle1[1].y, triangle2[0].x, triangle2[0].y, triangle2[1].x, triangle2[1].y, triangle2[2].x, triangle2[2].y);

isPointOnDelta(triangle2[0].x, triangle2[0].y, triangle1[0].x, triangle1[0].y, triangle1[1].x, triangle1[1].y, triangle1[2].x, triangle1[2].y);

isPointOnDelta(triangle2[1].x, triangle2[1].y, triangle1[0].x, triangle1[0].y, triangle1[1].x, triangle1[1].y, triangle1[2].x, triangle1[2].y);

isPointOnDelta(triangle2[2].x, triangle2[2].y, triangle1[0].x, triangle1[0].y, triangle1[1].x, triangle1[1].y, triangle1[2].x, triangle1[2].y);

if (fig.size() != 0) {

convex_hull(fig);

}

printf("%d %.2f\n", fig.size(), sq(fig));

system("pause");

}
