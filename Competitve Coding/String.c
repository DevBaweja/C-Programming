#include<stdio.h>
#include<string.h>
#define SIZE 5
int main()
{
	char str[SIZE];
	printf("Enter String \n");
	scanf("%s",str);
	// printf("%s",str);
	// printf("%d",strlen(str));
	int i;
	for(i=0;i<strlen(str);i++)
		printf("%c",str[i]);
	
	printf("\n");
	int j=0;
	while(str[j]!='\0')
		{
			printf("%c",str[j]);
			j++;	
		}
	return 0;
}


