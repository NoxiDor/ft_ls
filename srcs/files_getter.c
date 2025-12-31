//
// Created by jazema on 12/31/25.
//

#include <stdlib.h>

#include "ls.h"

static t_file	*get_blank_file(void)
{
	t_file	*result;

	result = malloc(sizeof(t_file));
	if (!result)
		return (NULL);
	result->children = NULL;
	result->full_path[0] = 0;
	result->displayed_name[0] = 0;
	result->hidden = 0;
	return (result);
}

t_list	*get_content(char *path, int recursively)
{
	t_list	*result;

	result = NULL;
	return (result);
}
