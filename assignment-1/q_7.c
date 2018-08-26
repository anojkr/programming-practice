#include <stdio.h>
#include <string.h>

void palindrome(char str[])
{
	int l = 0;
	int h = strlen(str) - 1;

	while (h > l)
	{
		if (str[l++] != str[h--])
		{
			printf("\n%s is Not Palindrome\n", str);
			return;
		}
	}
	printf("\n%s is palindrome\n", str);
}

void main(){
	char p[100];
	printf("\nEnter string\n");
	scanf("%s", p);
	palindrome(p);

}