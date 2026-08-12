#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
char data[MAX];
int top;
}Stack;

void init(Stack *s) {
s->top = -1;
}

bool isEmpty(Stack *s) {
return s->top == -1;
}

bool isFull(Stack *s) {
return s->top == MAX - 1;
}

void push(Stack *s,char value) {
if (isFull(s)) return;
s->data[++(s->top)] = value;
}

char pop(Stack *s) {
if (isEmpty(s)) return '\0';
return s->data[(s->top)--];
}

char peek(Stack *s) {
if (isEmpty(s)) return '\0';
return s->data[s->top];
}

bool isMatch(char left,char right) {
return (left == '('&&right == ')') ||
(left == '['&&right == ']') ||
(left == '{'&&right == '}');
}

bool isBalanced(char *expr) {
Stack s;
init(&s);

for (int i = 0;expr[i] != '\0';i++) {
char c = expr[i];
if (c == '('||c =='{'||c == '[') {
push(&s,c);
} else if (c == ')'||c == '}'||c == ']') {
if (isEmpty(&s)) {
return false;
}
char topChar = pop(&s);
if (!isMatch(topChar,c)) {
return false;
}
}
}
return isEmpty(&s);
}

int main() {
char testCases[] [20] = {
"()",
"([])",
"({[]})",
"([)]",
"((())",
"())",
"",
"(a + b)*[c - d]",
"{[()]}"
};
int n = sizeof(testCases) / sizeof(testCases[0]);
for (int i = 0;i <= n;i++) {
printf("%-12s -> %s\n",testCases[i],
isBalanced(testCases[i])?"匹配":"不匹配");
}
return 0;
}
