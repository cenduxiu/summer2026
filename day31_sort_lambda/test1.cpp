#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FILENAME "result.txt"
using namespace std;

typedef struct Student {
string name;
int ID;
float score;
} Student;

int main() {
int n;
cout << "请输入学生人数:";
cin >> n;

vector<Student> students;
for (int i = 0;i < n;i++) {
Student s;
cout << "请输入第" << i + 1 << "个学生的名字,学号,成绩:";
cin >> s.name >> s.ID >> s.score;
students.push_back(s);
}

sort(students.begin(),students.end(),[](Student& a,Student& b) {
return a.score > b.score;
});

FILE *fp = fopen(FILENAME,"w");
for (int i = 0;i < students.size();i++) {
fprintf(fp,"%s %d %f",students[i].name.c_str(),students[i].ID,students[i].score);
}
fclose(fp);

cout << "降序后:";
FILE *fp1 = fopen(FILENAME,"r");
char buf_name[20];
int buf_ID;
float buf_score;
while (fscanf(fp,"%s %d %f",buf_name,&buf_ID,&buf_score) == 3) {
cout << buf_name << buf_ID << buf_score;
}
fclose(fp1);

return 0;
}
