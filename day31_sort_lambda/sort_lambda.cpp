#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
vector<int> v = {5,2,8,1,3};

sort(v.begin(),v.end());
cout << "升序:";
for (int x : v)
cout << x << " ";
cout << endl;

sort(v.begin(),v.end(),[](int a,int b) {
return a > b;
});
cout << "降序:";
for (int x : v)
cout << x << " ";
cout << endl;

return 0;
}
