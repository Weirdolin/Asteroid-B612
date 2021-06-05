#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *GetNext(char *match)
{
	int *pNext = NULL;
	int i = 0;
	pNext = (int*)malloc(sizeof(int)*256);
	memset(pNext,-1,sizeof(int)*256);

	//赋值
	for(i = 0;i<strlen(match);i++)
	{
		pNext[match[i]] = i;
	}

	return pNext;
}

int Sunday(char *src,char *match)
{
	if(src == NULL || match == NULL)return -1;

	//获得next
	int *pNext = NULL;
	pNext = GetNext(match);

	//匹配
	int i = 0;
	int j = 0;
	int k = i;

	while(i < strlen(src)&&j < strlen(match))
	{
		//相等
		if(src[i] == match[j])
		{
			i++;
			j++;
		}
		//不想等
		else
		{
			if(k+strlen(match) < strlen(src))
			{
				k = k+strlen(match)-pNext[src[k+strlen(match)]];
				i = k;
				j = 0;
			}
			else
			{
				return -1;
			}
		}
	}

	//是否成功
	if(j == strlen(match))
	{
		return k;
	}
	else
	{
		return -1;
	}
}

int main()
{
	char *src = "abserwrcabc";
	char *match = "abcabc";
	printf("%d\n",Sunday(src,match));
	return 0;
}
