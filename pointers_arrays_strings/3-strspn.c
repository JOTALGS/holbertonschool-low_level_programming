#include "main.h"

unsigned int
_strspn(char *s, char *accept)
{
	int i;
	int y;
	unsigned int ct;

	ct = 0;
	for (i = 0; accept[i] != '\0'; i++)
	{
		for (y = 0; s[y] != '\0'; y++)
		{
			if (s[y] == accept[i])
			{
				ct++;
				break;
			}
		}
	}
	return (ct + 1);
}
