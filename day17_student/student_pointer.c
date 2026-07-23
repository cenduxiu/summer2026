#include <stdio.h>
#include <string.h>
typedef struct {
char name[20];
int id;
float score;
}Student;
int main() {
Student stu = {"李四",2024001,92.5};
Student *p = &stu;
p->score = 96.0;
strcpy(p->name,"王五");
printf("姓名: %s\n",p->name);
printf("学号: %d\n",p->id);
printf("成绩: %.1f\n",p->score);
return 0;
}
