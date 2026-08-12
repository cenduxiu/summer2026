#include <iostream>
#include <string>
using namespace std;
#define FILENAME "result.txt"

typedef struct Student {
char name[20];
int ID;
float score;
} Student;

void sort(Student arr[],int n) {
for (int i = 0;i < n - 1;i++) {
int swapped = 0;
for (int j = 0;j < n - 1 - i;j++) {
if (arr[j].score < arr[j + 1].score) {
Student temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
swapped = 1;
}
}
if (swapped == 0) return;
}
}

int main() {
int n;
Student students[20];
cout << "请输入学生人数:";
cin >> n;
for (int i = 0;i < n;i++) {
cout << "请依次输入第i + 1个学生的名字,学号,成绩:" << endl;
cin >> students[i].name >> students[i].ID >> students[i].score;
}

sort(students,n);

FILE *fp = fopen(FILENAME,"w");
for (int j = 0;j < n;j++) {
fprintf(fp,"%s %d %f\n",students[j].name,students[j].ID,students[j].score);
}
fclose(fp);

FILE *fp1 = fopen(FILENAME,"w");
int count = 0;
while (fscanf(fp,"%s %d %f",students[count].name,&students[count].ID,&students[count].score) == 3) {
count++;
}
fclose(fp1);

for (int k = 0;k < n;k++) {
cout << "名字:" << students[k].name << "学号:" << students[k].ID << "成绩:" << students[k].score << endl;
}

return 0;
}
