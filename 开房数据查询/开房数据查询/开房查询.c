#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char strpath[256] ="H:\\CC++\\大数据相关数据\\kaifang.txt";
char savepath[256] = { 0 };


void showlish(char str[256])
{
	
	FILE* fp =fp=fopen(strpath, "r");
	if (fp==NULL)
	{
		printf("文件打开失败！\n");
	}
	while (!feof(fp))
	{
		char reader[1024] = { 0 };
		fgets(reader, 1024, fp);
		char* p = strstr(reader, str);
		if (p!=NULL)
		{
			puts(reader);
		}

	}
	fclose(fp);
}
void main()
{
	
	char str[256] = { 0 };
	scanf("%s", str);
	time_t start, end;
	time(&start);
	showlish(str);
	time(&end);
	printf("花费%f的时间！\n", difftime(end,start));


	system("pause");
}