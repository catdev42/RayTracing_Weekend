#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void	ft_sort(char *str)
{
	int	len;

	len = ft_strlen(str);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (str[j] > str[j + 1])
				swap(&str[j], &str[j + 1]);
		}
	}
}
void	permute(char *str, int index, int len)
{
	char	temp[len + 1];

	if (index == len - 1)
	{
		puts(str);
		return ;
	}
	for (int i = index; i < len; i++)
	{
		swap(&str[index], &str[i]);
		for (int j = 0; j < len; j++)
			temp[j] = str[j];
		temp[len] = 0;
		ft_sort(&temp[index + 1]);
		permute(temp, index + 1, len);
		swap(&str[index], &str[i]);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		puts("Usage: ./permutations <string>");
		return (1);
	}

	char *str = argv[1];
	int len = 0;
	while (str[len] != '\0')
		len++;

	permute(str, 0, len);

	return (0);
}