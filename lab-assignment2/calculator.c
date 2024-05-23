//Dylan Mesa
//mesa.d@northeastern.edu
#include<stdio.h>
int main()
{
    int a,b,c, choice;
    
    printf("Enter your choice\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d",&choice);
    
    printf("Enter a and b values ");
    scanf("%d %d", &a, &b);
    
    switch (choice){
        case 1:
            c = a + b;
            printf("Additon\nSum=%d\n",c);
            break;
        case 2:
            c = a - b;
            printf("Subtraction\nDifference=%d\n",c);
            break;
        case 3:
            c = a * b;
            printf("Multiplication\nProduct=%d\n",c);
            break;
        case 4:
            if(b == 0){
                printf("Divide by zero error.\n");
                break;
            }
            c = a / b;
            printf("Division\nQuotient=%d\n",c);
            c = a % b;
            if(c != 0){
            printf("Remainder=%d",c);
            }
            break;
        default:
            printf("Invalid option\n");
            break;

    }
           
    return 0;
}
