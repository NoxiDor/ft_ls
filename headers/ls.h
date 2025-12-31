//
// Created by jazema on 12/31/25.
//

#ifndef LS_H
#define LS_H
#include <linux/limits.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

// File relative

typedef enum e_file_type
{
	EFT_FILE,
	EFT_DIRECTORY,
	EFT_LINK
} t_file_type;

typedef struct s_file
{
	t_list		*children;
	char		full_path[PATH_MAX];
	char		displayed_name[PATH_MAX];
	t_file_type	type;
	int			hidden;
	int			mode;
}				t_file;

// Function headers

t_list	*get_content(char *path, int recursively);
void	free_file(t_file *file);

#endif
