//
// Created by jazema on 12/31/25.
//

#ifndef LS_H
# define LS_H

# include <linux/limits.h>

// Structures, enums and macros

// Basic chained list

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

// Flags related

# define HAS_FLAG(flags, flag) ((flags) & (flag))

typedef enum s_command_flag
{
	ECF_L	= 1 << 0,
	ECF_REC	= 1 << 1,
	ECF_REV	= 1 << 2,
	ECF_A	= 1 << 3,
	ECF_T	= 1 << 4,
}			t_command_flag;

// Files related

typedef enum e_file_type
{
	EFT_FILE,
	EFT_DIRECTORY,
	EFT_LINK
}	t_file_type;

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

// Files related

t_list	*get_content(char *path, int recursively);
void	free_file(t_file *file);
void	free_files(t_list *files);

// Files sorting
void	sort_files(t_list **content_ptr, int flags);

// Execution related

void	execute(char *folder, int flags);

// Displaying related

void	display_files(t_list *files, int flags);

// Helpers

void	ft_putstr(char *str);
char	*ft_strcat(char *dest, char const *src);
t_list	*init_node(void *content, t_list *next);

#endif
