#include <iostream>
using namespace std;

int main() {
char name[20];
int age;
float height;

cout << "请输入名字：";
cin >> name;
cout << "请输入年龄: ";
cin >> age;
cout << "请输入身高：";
cin >> height;

cout << name << "今年" << age << "岁,身高" << height << "米" << endl;
return 0;
}
