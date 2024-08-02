//mesa.d@northeastern.edu
//Dylan Mesa

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]){
    char ch;
    int count = 1;
    int index = 0;
    int size = 0;
    if(n == 0){
        return 0;
    }
    for(int i = 0; i < n; i++){
        ch = arr[i];
        if(i < (n - 1) && arr[i] == arr[i + 1]){
            count++;
        } else {
            if(count != 1){
                res[index] = ch;
                res[index + 1] = count;
                index += 2;
                size += 2;
                int temp = count;
                while(temp / 10 > 0){
                    size++;
                    temp /= 10;
                }
            } else {
                res[index] = ch;
                index++;
                size += 1;
            }
            count = 1;
        }
    }
    return size;
}
 
int main()
{
    char a[]="aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);
    return 0;
}
