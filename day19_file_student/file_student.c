#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
#define FILENAME "students.txt"

typedef struct{
char name[20];
int age;
float score;
}Student;
void save_to_file(Student arr[],int n,const char *filename) {
FILE *fp = fopen(filename,"w");
if (fp == NULL) {
printf("无法打开文件%s进行写入! \n",filename);
return;
}
fprintf(fp,"%d\n",n);
for (int i = 0;i < n;i++) {
fprintf(fp,"%s %d %.1f\n",arr[i].name,arr[i].age,arr[i].score);
}
fclose(fp);
}
int load_from_file(Student arr[],int max_n,const char *filename) {
FILE *fp = fopen(filename,"r");
if (fp == NULL) {
printf("无法打开文件%s进行读取! \n",filename);
return 1;
}
int n;
fscanf(fp,"%d",&n);
if(n > max_n) {
printf("文件中的学生数(%d)超过最大限制(%d),只读前%d个\n",n,max_n,max_n);
n = max_n;
}
for (int i = 0;i < n;i++) {
fscanf(fp,"%s %d %f",arr[i].name,&arr[i].age,&arr[i].score);
}
fclose(fp);
return n;
}
void print_students(Student arr[],int n) {
for (int i = 0;i < n;i++) {
printf("%-8s %2d岁 %.1f分\n",arr[i].name,arr[i].age,arr[i].score);
}
}
int main() {
Student students[MAX_STUDENTS];
int n;
printf("请输入学生人数: ");
scanf("%d",&n);
for (int i = 0;i < n;i++) {
printf("请输入第%d个学生的姓名,年龄,成绩: ",i + 1);
scanf("%s %d %f",students[i].name,&students[i].age,&students[i].score);
}
save_to_file(students,n,FILENAME);
printf("已保存到%s\n\n",FILENAME);
memset(students,0,sizeof(students));
int count = load_from_file(students,MAX_STUDENTS,FILENAME);
printf("从文件读取了%d个学生: \n",count);
print_students(students,count);
return 0;
}
