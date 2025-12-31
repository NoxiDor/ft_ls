//
// Created by jazema on 12/31/25.
//

#include "ls.h"


void	execute(char *folder, int flags)
{
	t_list *content;

	content = get_content(folder, HAS_FLAG(flags, ECF_REC));
	if (!content)
		return ;
	sort_files(&content, flags);
	display_files(content, flags);
	free_files(content);
}
