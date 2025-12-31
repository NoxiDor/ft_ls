//
// Created by jazema on 12/31/25.
//

#include <stdlib.h>

#include "ls.h"
#include "dirent.h"

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

static t_file_type	parse_file_type(unsigned char d_type)
{
	if (d_type == DT_DIR)
		return (EFT_DIRECTORY);
	if (d_type == DT_REG)
		return (EFT_FILE);
	if (d_type == DT_LNK)
		return (EFT_LINK);
	return (EFT_FILE);
}

static t_file *parse_file(char *base_path, struct dirent *entry)
{
	t_file	*result;

	result = get_blank_file();
	if (!result)
		return (NULL);
	ft_strcat(result->full_path, base_path);
	ft_strcat(result->full_path, entry->d_name);
	ft_strcat(result->displayed_name, entry->d_name);
	result->hidden = entry->d_name[0] == '.';
	result->type = parse_file_type(entry->d_type);
	result->mode = 0; //TODO -> Recuperer les permissions du fichier pour l'affichage du flag '-l'
	return (result);
}

t_list	*get_content(char *path, int recursively)
{
	t_list			*result;
	t_list			*new_node;
	t_file			*tmp;
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(path);
	if (!dir)
		return (NULL);
	result = NULL;
	entry = readdir(dir);
	while (entry)
	{
		tmp = parse_file(path, entry);
		if (!tmp)
			continue ;
		if (recursively)
			tmp->children = get_content(tmp->full_path, recursively);
		new_node = init_node(tmp, result);
		if (new_node == result)
			free_file(tmp);
		result = new_node;
		entry = readdir(dir);
	}
	closedir(dir);
	return (result);
}
