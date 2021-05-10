#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Array
{
    char arr[8];
    int brr[7];
}Array;
const Array A = { "IVXLCDM",1,5,10,50,100,500,1000 };
int romanToInt(char* s, int n)
{
    static int sum = 0;
    int i = 0;
    int j = 0;
    for (j; j < n; ++j)
        for (i; i < 7; ++i)
        {
            if (s[j] = A.arr[i])
            {
                sum += A.brr[i];
                break;
            }
        }
    return sum;

}
int main(int argc, char* argv[])
{
    char a[10];
    scanf("%s", a);
    int sum = romanToInt(a, sizeof(a) / sizeof(a[0]));
    printf("%d", sum);
}
