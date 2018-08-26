#include <stdio.h>
int cones (long long int num)
{
    long long int ones = 0;
    while (num!=0)
    {
        num = num & (num-1);
        ones++;
    }
return ones;}
int main() {
    printf("%d", cones (1000000000));
    return 0;
}