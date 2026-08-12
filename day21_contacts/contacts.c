#include <stdio.h>
#include <string.h>

#define MAX 100
#define FILENAME "family.txt"

typedef struct {
char name[20];
char phone[20];
char email[30];
char group[10];
} Contact;

void load_contacts(Contact arr[],int *count) {
FILE *fp = fopen(FILENAME,"r");
if (fp == NULL) {
*count = 0;
return;
}
*count = 0;
while (fscanf(fp,"%s %s %s %s",
arr[*count].name,
arr[*count].phone,
arr[*count].email,
arr[*count].group) == 4) {
(*count)++;
if (*count >= MAX) break;
}
fclose(fp);
}

void save_contacts(Contact arr[],int count) {
FILE *fp = fopen(FILENAME,"w");
if (fp == NULL) {
printf("无法保存文件\n");
return;
}
for (int i = 0;i < count;i++) {
fprintf(fp,"%s %s %s %s\n",arr[i].name,arr[i].phone,arr[i].email,arr[i].group);
}
fclose(fp);
}

void add_contact(Contact arr[],int *count) {
if (*count >= MAX) {
printf("通讯录已满，无法添加!\n");
return;
}
printf("请输入姓名: ");
scanf("%s",arr[*count].name);
printf("请输入电话: ");
scanf("%s",arr[*count].phone);
printf("请输入邮箱: ");
scanf("%s",arr[*count].email);
printf("请输入分组(家人/朋友/同事/其他): ");
scanf("%s",arr[*count].group);

(*count)++;
printf("添加成功!\n");
}

void delete_contact(Contact arr[],int *count) {
char name[20];
printf("请输入要删除的联系人姓名:");
scanf("%s",name);

int found = 0;
for (int i = 0;i < *count;i++) {
if (strcmp(arr[i].name,name) == 0) {
for (int j = i;j < *count - 1;j++) {
arr[j] = arr[j + 1];
}
(*count)--;
found = 1;
printf("删除成功!\n");
break;
}
}
if (!found) {
printf("未找到联系人: %s\n",name);
}
}

void search_contact(Contact arr[],int count) {
char name[20];
printf("请输入要查找的姓名: ");
scanf("%s",name);
int found = 0;
for (int i = 0;i < count;i++) {
if (strcmp(arr[i].name,name) == 0) {
printf("姓名:%s 电话:%s 邮箱:%s 分组:%s\n",
arr[i].name,arr[i].phone,arr[i].email,arr[i].group);
found = 1;  
}
}
if (!found) {
printf("未找到联系人: %s\n",name);
}
}

void modify_contact(Contact arr[],int count) {
char name[20];
printf("请输入要修改的联系人姓名:");
scanf("%s",name);
for (int i = 0;i < count;i++) {
if (strcmp(arr[i].name,name) == 0) {
printf("找到联系人,请输入新信息:\n");
printf("姓名：");
scanf("%s",arr[i].name);
printf("电话: ");
scanf("%s",arr[i].phone);
printf("邮箱: ");
scanf("%s",arr[i].email);
printf("分组: ");
scanf("%s",arr[i].group);
printf("修改成功!\n");
return;
}
}

printf("未找到联系人: %s\n",name);
}

void list_all(Contact arr[],int count) {
if (count == 0) {
printf("通讯录为空!\n");
return;
}
printf("\n共有%d个联系人: \n",count);
for (int i = 0;i < count;i++) {
printf("%-10s %-15s %-20s %-10s\n",
arr[i].name,arr[i].phone,arr[i].email,arr[i].group);
}
}

void list_by_group(Contact arr[],int count) {
char group[10];
printf("请输入分组名(家人/朋友/同事/其他):");
scanf("%s",group);
int found = 0;
for (int i = 0;i < count;i++) {
if (strcmp(arr[i].group,group) == 0) {
printf("%-10s %-15s %-20s\n",
arr[i].name,arr[i].phone,arr[i].email);
found = 1;
}
}
if(!found) {
printf("分组%s中没有联系人\n",group);
}
}

void show_menu() {
printf("1:添加联系人\n");
printf("2:删除联系人(按姓名)\n");
printf("3:修改联系人(按姓名)\n");
printf("4:查找联系人(按姓名)\n");
printf("5:显示所有联系人\n");
printf("6:按分组显示联系人\n");
printf("0:退出并保存\n");
}

int main() {
int count = 0;
Contact familys[MAX];
load_contacts(familys,&count);
printf("已经加载%d个联系人\n\n",count);

int choice;
do {
show_menu();
printf("请输入数字实现对应功能: ");
scanf("%d",&choice);

switch(choice) {
case 1:add_contact(familys,&count);break;
case 2:delete_contact(familys,&count);break;
case 3:modify_contact(familys,count);break;
case 4:search_contact(familys,count);break;
case 5:list_all(familys,count);break;
case 6:list_by_group(familys,count);break;
case 0:
save_contacts(familys,count);
printf("数据已经保存,再见!\n");
break;
default:printf("无效选择，请重新输入!\n");
}
} while (choice != 0);
return 0;
}


