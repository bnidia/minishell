/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:45:12 by bnidia            #+#    #+#             */
/*   Updated: 2022/01/15 22:49:59 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file	*init_file(int fd, t_file **file);
static t_file	*check_file(int fd, t_file **file);
static void		make_string(t_file *file);
static void		delete_file(t_file **file);

/* get_next_line(int fd)
 * reads file and returns a string separated \n
 * if nothing else to read or error returns NULL
 * BUFFER_SIZE=xx will be used as the rb_ar size for the read calls */
char	*get_next_line(int fd)
{
	static t_file	*file = NULL;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (file == NULL || check_file(fd, &file) == NULL)
		file = init_file(fd, &file);
	if (file == NULL)
		return (NULL);
	file->str_len = 0;
	file->str = NULL;
	make_string(file);
	if (file->rb_size == -1 && file->str_len > 0)
	{
		free(file->str);
		file->str = NULL;
	}
	if (file->str == NULL)
	{
		delete_file(&file);
		return (NULL);
	}
	if (file->str_len > 0)
		file->str[file->str_len] = '\0';
	return (file->str);
}

/* check_file(fd, t_file)
 * check for presence of opened file in t_file ring structure
 * if t_file not found return NULL */
static t_file	*check_file(int fd, t_file **file)
{
	t_file	*initial_position;

	if ((*file)->fd == fd)
		return (*file);
	initial_position = *file;
	*file = (*file)->next;
	while (*file != initial_position)
	{
		if ((*file)->fd == fd)
			return (*file);
		*file = (*file)->next;
	}
	return (NULL);
}

/* init_file(t_file **file, int fd)
 * creating a struct file, were we store data about read file
 * and used buffer. It is circled struct.
 * Line length research says that line length fall between 45 and
 * 75 characters per line, medium is 66 chars (letters and spaces) */
static t_file	*init_file(int fd, t_file **file)
{
	t_file	*new_file;

	new_file = (t_file *)malloc(sizeof(t_file));
	if (new_file == NULL)
		return (NULL);
	new_file->fd = fd;
	new_file->rb_size = 0;
	new_file->next = new_file;
	if (*file == NULL)
		return (new_file);
	new_file->next = (*file)->next;
	(*file)->next = new_file;
	*file = new_file;
	return (*file);
}

static void	make_string(t_file *file)
{
	while (42)
	{
		if (file->rb_size == 0)
		{
			file->rb_size = read(file->fd, file->rb_ar, \
			BUFFER_SIZE);
			if (file->rb_size <= 0)
				return ;
			file->rb_pos = 0;
		}
		if (file->str_len == 0 || file->str_len + 8 >= file->str_cap)
			ft_realloc(&file->str, file->str_len, \
		&file->str_cap);
		if (file->str == NULL)
			return ;
		file->str[file->str_len++] = file->rb_ar[file->rb_pos++];
		file->rb_size--;
		if (file->rb_ar[file->rb_pos - 1] == '\n')
		{
			file->str[file->str_len] = '\0';
			return ;
		}
	}
}

static void	delete_file(t_file **file)
{
	t_file	*del_file;

	if (*file == (*file)->next)
	{
		free(*file);
		*file = NULL;
		return ;
	}
	del_file = *file;
	*file = (*file)->next;
	while (del_file != (*file)->next)
		*file = (*file)->next;
	(*file)->next = del_file->next;
	free(del_file);
	del_file = NULL;
}
