#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char *name)
{
	int ans = 0;
	for(int i = 0; name[i]; i++)
		ans += (int)name[i] * (i+1);
	return (ans * 19) % 101;
}

int add(char **table, char *name)
{
	int pos = hash(name);
	int k;
	//verifica se a posição da chave tá na hash
    if(strcmp(table[pos], name) == 0)
		return 0;
	else
	{
		for(int j = 1; j <= 19; j++)
		{
			k = (pos + (23*j) + (j*j)) % 101;
			if(strcmp(table[k], name) == 0)
				return 0;
		}
	}

	if(strcmp(table[pos], "") == 0)
	{
		strcpy(table[pos], name);
		return 1;
	}
	else
	{
		for(int j = 1; j <= 19; j++)
		{
			k = (pos + (23*j) + (j*j)) % 101;
			if(strcmp(table[k], "") == 0)
			{
				strcpy(table[k], name);
				return 1;
			}
		}
	}
	return 0;
}

int del(char **table, char *name)
{
	for(int i = 0; i < 101; i++)
	{
		if(strcmp(table[i], name) == 0)
		{
			strcpy(table[i], "");
			return 1;
		}
	}
	return 0;
}

int main()
{
	char **table;
	int n;
	scanf("%d", &n);
	int count;
	for(int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		table = malloc(sizeof(char *) * 101);
		for(int i = 0; i < 101; i++)
			table[i] = malloc(sizeof(char) * 1002);
		count = 0;
		for(int j = 0; j < m; j++)
		{
			char op[100];
			scanf("%s", op);
			char *ptr = op + 4;
			if(op[0] == 'A')
			{
				if(add(table, ptr))
				{
					count += 1;
				}
			}
			if(op[0] == 'D')
			{
				if(del(table, ptr))
				{
					count -= 1;
				}
			}
		}
		printf("%d\n", count);
		for(int i = 0; i < 101; i++)
		{
			if(strcmp(table[i], "") != 0)
				printf("%d:%s\n", i, table[i]);
		}
	}
	free(table);
	return 0;
}
