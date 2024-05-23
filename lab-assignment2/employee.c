/*C Program to read and print the n employee details using structure and dynamic
 * memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/
typedef struct employee {
  int empId;
  char name[100];
  char designation[100];
  char dept[10];

} employee_t;
/* Read the employee details using scanf*/
void readData(int n, employee_t *s) {
  for (int i = 0; i < n; i++) {
    printf("Enter Employee %d's ID: \n", i + 1);
    scanf("%d", &(s + i)->empId);
    printf("Enter Employee %d's name: \n", i + 1);
    scanf("%s", (s + i)->name);
    printf("Enter Employee %d's designation: \n", i + 1);
    scanf("%s", (s + i)->designation);
    printf("Enter Employee %d's department: \n", i + 1);
    scanf("%s", (s + i)->dept);
    printf("\n");
  }
  return;
}
/* Function to print the employee details*/
void display(int n, employee_t *s) {
  for (int i = 0; i < n; i++) {
    printf("The details of Employee %d: \n", i + 1);
    printf("empId: %d\n", (s + i)->empId);
    printf("Name: %s\n", (s + i)->name);
    printf("Designation: %s\n", (s + i)->designation);
    printf("Dept: %s\n", (s + i)->dept);
  }
  return;
}

/*----------Main Program--------*/
int main() {
  int n;
  printf("Enter the number of employees: ");
  scanf("%d", &n);
  employee_t *arr = (employee_t *)malloc(n * sizeof(employee_t));
  readData(n, arr);
  display(n, arr);
  free(arr);
  return 0;
}