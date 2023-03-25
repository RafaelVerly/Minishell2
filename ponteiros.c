#include <stdio.h>

int main()
{
    int num;
    int *p_num;
    int **pont_num;

    num = 15;
    p_num = &num;
    pont_num = &p_num;
    printf("pont_num: %i\n", **pont_num);
}