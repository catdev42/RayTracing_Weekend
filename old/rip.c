#include <stdbool.h>

int	check_how_many_needed(char *original)
{
	int	i;
	int	math;
	int	need_to_remove;

	i = 0;
	math = 0;
	need_to_remove = 0;
	while (original[i])
	{
		if (original[i] == '(')
		{
			math++;
		}
		else if (original[i] == ')')
		{
			math--;
			if (math < 0)
				need_to_remove++;
		}
		i++;
	}
	if (need_to_remove == 0)
		return math;
	else
	math = math - need_to_remove;
	need_to_remove = need_to_remove + math


	return (need_to_remove);
}

bool	checker(char *curr)
{
}

void	rip(char *original, int len, char *curr, int curr_len)
{
	if (curr_len == len)
		// do checks

		curr[curr_len] = original[curr_len];
	rip(original, len, curr, curr_len + 1);
	curr[curr_len] = ' ';
	rip(original, len, curr, curr_len + 1);
}