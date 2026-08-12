#include <iostream>
#include <string>
using namespace std;

int main() {
string s1,s2;
cout << "请输入两个单词:";
cin >> s1 >> s2;
if (s1 == s2) {
cout << "相同" << endl;
} else if (s1 < s2) {
cout << "s1在s2前面" << endl;
} else {
cout << "s2在s1前面" << endl;
}

cout << "s1的长度:" << s1.length() << endl;
cout << "拼接:" << s1 + s2 << endl;

return 0;
}
