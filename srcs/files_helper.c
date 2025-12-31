#include <stdlib.h>

#include "ls.h"

static void	free_children(t_file *file)
{
	t_list	*tmp;
	t_list	*next;

	tmp = file->children;
	while (tmp)
	{
		free_file(tmp->data);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	file->children = NULL;
}

// Recursive function to free a file (custom struct) and all its children
void	free_file(t_file *file)
{
	if (!file)
		return ;
	free_children(file);
	free(file);
}
