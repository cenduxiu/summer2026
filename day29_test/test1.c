#include <stdio.h>
#include <string.h>

#define FILENAME "result.txt"

typedef struct{
char name[20];
int ID;
float score;
}Student;

void sort(Student arr[],int n) {
for (int i = 0;i < n - 1;i++) {
for (int j = 0;j < n - 1 - i;j++) {
if (arr[j].score < arr[j + 1].score) {
Student temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}

int main() {
int N;
printf("请输入学生人数:");
scanf("%d",&N);

Student students[100];
for (int i = 0;i < N;i++) {
printf("请输入第%d个学生的名字,学号,分数(用空格隔开):",i + 1);
scanf("%s %d %f",students[i].name,&students[i].ID,&students[i].score);
}

sort(students,N);

FILE *fp = fopen(FILENAME,"w");
for (int i = 0;i < N;i++) {
fprintf(fp,"%s %d %f\n",students[i].name,students[i].ID,students[i].score);
}
fclose(fp);

memset(students,0,sizeof(students));

FILE *fp1 = fopen(FILENAME,"r");
int count = 0;
while (fscanf(fp1,"%s %d %f",students[count].name,&students[count].ID,&students[count].score) == 3) {
printf("%s %d %f\n",students[count].name,students[count].ID,students[count].score);
count++;
}
fclose(fp1);

return 0;
}
