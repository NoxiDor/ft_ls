//
// Created by jazema on 12/31/25.
//

#include <stdlib.h>
#include <unistd.h>

#include "ls.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

char	*ft_strcat(char *dest, char const *src)
{
	size_t	i;
	size_t	dest_length;

	dest_length = 0;
	while (dest[dest_length])
		dest_length++;
	i = 0;
	while (src[i])
	{
		dest[i + dest_length] = src[i];
		i++;
	}
	dest[i + dest_length] = '\0';
	return (dest);
}

t_list	*init_node(void *content, t_list *next)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (next);
	result->data = content;
	result->next = next;
	return (result);
}
