#include<stdio.h>
#include<string.h>
int GetWordNumber(char string[]);
int GetCharNumber(char string[]);
int main(int argc ,char *argv[])
{
	char buff[256];
	char string[10000] = "\0";
	FILE *fp = NULL;
	int sum = 0;
	fp = fopen(argv[2],"r");
	if(fp == NULL)
	{
		printf("文件读取失败\n");
		return -1;
	}
	while(!feof(fp))
	{
		if(fgets(buff,255,fp) != NULL)
		{
			strcat(string,buff);
		}
	} 
	puts(string);
	if(argc != 3)
	{
		printf("arguments error!\n");
	}
	else
	{
		if(strcmp(argv[1],"-w") == 0)
		{
			sum = GetWordNumber(buff);
			printf("单词数： %d\n",sum);
		}
		else if(strcmp(argv[1],"-c") == 0)
		{
			sum = GetCharNumber(buff);
			printf("字符数： %d\n",sum);
		}
	}	
}
int GetWordNumber(char string[])
{
	int i, in_word, word_num;
    word_num = 0;
    in_word = 0;
    for (i = 0; string[i]; i++) 
    {
        if (string[i] == ' ') 
        {
            	in_word = 0;
        }
        else if (in_word == 0) 
        {
            	word_num++;
            	in_word = 1;
		}
	}
    return word_num;
}
int GetCharNumber(char string[])
{
	int sum = 0;
	int i ;
	for(i = 0;string[i] != '\0'; i++)
	{
		if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') )
		{
			sum ++;
		}
	}
	return sum ;
}

