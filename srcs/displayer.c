//
// Created by jazema on 12/31/25.
//

#include "ls.h"

static void	display_folder(t_list *files, int flags)
{
	t_list	*current;
	t_file	*current_file;

	(void)flags;
	current = files;
	while (current)
	{
		current_file = current->data;
		if (!current_file->hidden || HAS_FLAG(flags, ECF_A))
		{
			ft_putstr(current_file->displayed_name);
			if (current->next)
				ft_putstr("  ");
		}
		current = current->next;
	}
	ft_putstr("\n");
}

void	display_files(t_list *files, int flags)
{
	t_list	*current;
	t_file	*current_file;

	if (!HAS_FLAG(flags, ECF_REC))
	{
		display_folder(files, flags);
		return ;
	}
	current = files;
	while (current)
	{
		current_file = current->data;
		if (current_file->type == EFT_DIRECTORY)
		{
			ft_putstr(current_file->full_path);
			ft_putstr(":\n");
			display_folder(current_file->children, flags);
		}
		current = current->next;
	}
}
