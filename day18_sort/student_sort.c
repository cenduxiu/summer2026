#include <stdio.h>
#include <string.h>
typedef struct{
char name[20];
int age;
float score;
}Student;
void sort_by_score(Student arr[],int n) {
for (int i = 0;i < n - 1;i++) {
for (int j = 0;j < n - 1 - i;j++) {
if (arr[j].score > arr[j + 1].score) {
Student temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}
void sort_by_name(Student arr[],int n) {
for (int i = 0;i < n - 1;i++) {
for (int j = 0;j < n - 1 - i;j++) {
if (strcmp(arr[j].name,arr[j + 1].name) > 0) {
Student temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}
void print_students(Student arr[],int n) {
for (int i = 0;i < n;i++) {
printf("%-8s %2d岁 %.1f分\n",arr[i].name,arr[i].age,arr[i].score);
}
}
int main() {
Student students[5]  = {
{"张三",19,88.5},
{"李四",20,76.0},
{"王五",18,93.5},
{"赵六",21,82.0},
{"陈七",19,68.5}
};
int n = 5;
printf("原始数据: \n");
print_students(students,n);

Student by_score[5];
memcpy(by_score,students,sizeof(students));
sort_by_score(by_score,n);
printf("\n按成绩升序: \n");
print_students(by_score,n);

Student by_name[5];
memcpy(by_name,students,sizeof(students));
sort_by_name(by_name,n);
printf("\n按姓名升序: \n");
print_students(by_name,n);
return 0;
}
