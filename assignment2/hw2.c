// name: Dylan Mesa
// email: mesa.d@northeastern.edu

#include <stdbool.h> // standard boolean library: bool, true, false
#include <stdio.h>   // stardard input/output library

#define MAXSIZE 100

bool isEmpty(int *s, int t) { return t == -1; }

bool isFull(int *s, int t) { return t == MAXSIZE - 1; }

void push(int v, int *s, int *tp) {
  if (isFull(s, *tp)) {
    printf("Cannot push %d; stack is full.\n", v);
  } else {
    (*tp)++;
    s[*tp] = v;
    printf("Pushed %d. New top at %d.\n", v, *tp);
  }
  return;
}

int pop(int *s, int *tp) {
  if (isEmpty(s, *tp)) {
    printf("Cannot pop; stack is empty.\n");
  } else {
    (*tp)--;
    if(*tp>=0){
      printf("Popped %d. New top at %d.\n", s[*tp + 1], *tp);
    }
    else{
      printf("Popped %d. Stack is empty.\n", s[*tp + 1]);
    }
    return s[*tp + 1];
  }
  return -1;
}

int main() {

  int stack1[MAXSIZE]; // array in which stack will live
  int top1 = -1;       // top valid location in stack, -1 == empty
  int stack2[MAXSIZE]; // array in which stack will live
  int top2 = -1;       // top valid location in stack, -1 == empty

  printf("pushing: 1, 2, 3, 4, 5 onto first stack\n");
  printf("pushing: 100, 200, 300, 400, 500 onto second stack\n\n");
  push(1, stack1, &top1);
  push(2, stack1, &top1);
  push(3, stack1, &top1);
  push(4, stack1, &top1);
  push(5, stack1, &top1);
  push(100, stack2, &top2);
  push(200, stack2, &top2);
  push(300, stack2, &top2);
  push(400, stack2, &top2);
  push(500, stack2, &top2);

  printf("popping alternating stacks:\n");
  printf("1> %d\n", pop(stack1, &top1));
  printf("2> %d\n", pop(stack2, &top2));
  printf("1> %d\n", pop(stack1, &top1));
  printf("2> %d\n", pop(stack2, &top2));
  printf("1> %d\n", pop(stack1, &top1));
  printf("2> %d\n", pop(stack2, &top2));
  printf("1> %d\n", pop(stack1, &top1));
  printf("2> %d\n", pop(stack2, &top2));
  printf("1> %d\n", pop(stack1, &top1));
  printf("2> %d\n", pop(stack2, &top2));
  printf("1> %d\n", pop(stack1, &top1));
  printf("2> %d\n", pop(stack2, &top2));
  return 0;
}
