#include <stdio.h>

int main()
{
int n, i, j, key;
int shifts = 0;

printf("Enter number of students: ");  
scanf("%d", &n);  

int marks[n];  

printf("Enter student marks:\n");  
for(i = 0; i < n; i++)  
{  
    scanf("%d", &marks[i]);  
}  

printf("\nArray after every pass:\n");  

for(i = 1; i < n; i++)  
{  
    key = marks[i];  
    j = i - 1;  

    while(j >= 0 && marks[j] > key)  
    {  
        marks[j + 1] = marks[j];  
        shifts++;  
        j--;  
    }  

    marks[j + 1] = key;  

    printf("Pass %d: ", i);  

    for(int k = 0; k < n; k++)  
    {  
        printf("%d ", marks[k]);  
    }  

    printf("\n");  
}  

printf("\nFinal sorted list: ");  

for(i = 0; i < n; i++)  
{  
    printf("%d ", marks[i]);  
}  

printf("\nTotal number of element shifts = %d\n", shifts);  

return 0;

}