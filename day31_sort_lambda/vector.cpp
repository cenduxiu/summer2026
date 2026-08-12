#include <iostream>
#include <vector>
using namespace std;

int main() {
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

cout << "大小:" << v.size() << endl;
cout << "第一个:" << v[0] << endl;
cout << "最后一个:" << v.back() << endl;

for (int i = 0;i < v.size();i++) 
cout << v[i] << " ";
cout << endl;

for (int x : v)
cout << x << " ";
cout << endl;

v.pop_back();
cout << "删除后大小:" << v.size() << endl;
return 0;
}
