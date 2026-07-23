#include <stdio.h>
#include <string.h>
typedef struct {
char name[20];
int age;
float score;
}Student;
void input_students(Student *students,int n) {
printf("请输入3个学生的姓名,年龄,成绩");
for (int i = 0;i < n;i++) {
printf("请输入第%d个学生的姓名: ",i + 1);
scanf("%s",students[i].name);
printf("请输入第%d个学生的年龄: ",i + 1);
scanf("%d",&students[i].age);
printf("请输入第%d个学生的成绩: ",i + 1);
scanf("%f",&students[i].score);
}
}
void print_students(Student *students,int n) {
for (int i = 0;i < n;i++) {
printf("第%d个学生的姓名: %s\n",i + 1,students[i].name);
printf("第%d个学生的年龄: %d\n",i + 1,students[i].age);
printf("第%d个学生的成绩: %.1f\n",i + 1,students[i].score);
}
}
float average_score(Student *students,int n) {
int sum = 0;
for (int i = 0;i < n;i++) {
sum += students[i].score;
}
return sum / n;
}
int main() {
Student class[3];
int n = 3;
input_students(class,n);
printf("\n---学生信息---\n");
print_students(class,n);
float avg = average_score(class,n);
printf("平均成绩: %.1f\n",avg);
return 0;
}
