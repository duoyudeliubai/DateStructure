#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char strpath[256] ="H:\\CC++\\�������������\\kaifang.txt";
char savepath[256] = { 0 };


void showlish(char str[256])
{
	
	FILE* fp =fp=fopen(strpath, "r");
	if (fp==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
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
	printf("����%f��ʱ�䣡\n", difftime(end,start));


	system("pause");
}