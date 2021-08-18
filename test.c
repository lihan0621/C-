#include<stdio.h>
#include<assert.h>
#include<ctype.h>
void PasswordTranslation(char* p, char* q)
{
	while (*p != '\0')
	{
		if (islower(*p))
		{
			*q = *p - 32;
		}
		else if (isupper(*p))
		{
			*q = *p + 32;
		}
		else
		{
			*q = *p;
		}
		p++;
		q++;
	}
	*q = '\0';
}
int main()
{
	char ar[] = "yahpingLIJIANLI";
	char br[100]="";
	PasswordTranslation(ar, br);
	printf("%s\n", br);
	return 0;
}
