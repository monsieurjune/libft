/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:05:48 by tponutha          #+#    #+#             */
/*   Updated: 2022/10/09 19:59:48 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
GNL INSTRUCTION
0: Check fd = -1

1: if EOF(0) or ERROR(-1) check if ram = NULL
- if yes then return NULL
- if no then free(ram) before return NULL

2: Read until buffer has \n to buffer -> modifly ft_strjoin

3: Serparate buffer to two part
- 1. before \n to line -> ft_strdup
- 2. free ram and add after new line to ram -> modifly ft_substr

4: free buffer

5: Return line
*/

// Like ft_strjoin but free old text, box

static char	*sb_strjoin(char *text, char *buffer, size_t buffsize, _Bool tofree)
{
	char	*str;
	size_t	size;
	size_t	len;

	len = ft_strclen(text, 0);
	size = len + buffsize + 1;
	str = malloc(sizeof(char) * size);
	if (str)
	{
		str = ft_strncpy(str, text, len);
		str = ft_strncat(str, buffer, buffsize);
	}
	if (tofree || !str)
	{
		free(text);
		free(buffer);
	}
	return (str);
}

// read function is in here
// 1 -> Normal
// 0 -> EOF
// -1 -> Error

static ssize_t	sb_readone(int fd, char **pbuffer)
{
	ssize_t	byte;

	*pbuffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*pbuffer))
		return (-1);
	byte = read(fd, *pbuffer, BUFFER_SIZE);
	if (byte == -1 || byte == 0)
	{
		free(*pbuffer);
		return (byte);
	}
	(*pbuffer)[byte] = 0;
	return (byte);
}

// build string until it has \n + extra
// EOF & Normal give text 
// ERROR or EOF with no text give NULL

static char	*sb_readline(int fd, char *text)
{
	ssize_t	len;
	size_t	i;
	char	*buffer;
	char	flag;

	while (1)
	{
		len = sb_readone(fd, &buffer);
		if (len == 0)
			break ;
		if (len == -1)
			free(text);
		if (len == -1)
			return (NULL);
		i = ft_strclen(buffer, '\n');
		flag = (buffer[i] != '\n');
		text = sb_strjoin(text, buffer, len, 1);
		if (!flag || !text)
			break ;
	}
	return (text);
}

static char	*sb_failsafe(char *text, char *line, char *temp)
{
	free(text);
	if (line)
		free(line);
	if (temp)
		free(temp);
	return (NULL);
}

// text -> line + temp
// free(text)
// temp -> text

char	*get_next_line(int fd)
{
	size_t		i;
	size_t		templen;
	char		*line;
	char		*temp;
	static char	*text;

	if (fd == -1)
		return (NULL);
	text = sb_readline(fd, text);
	if (!text)
		return (NULL);
	i = ft_strclen(text, '\n');
	templen = ft_strclen(&text[i + (text[i] != 0)], 0);
	line = sb_strjoin(NULL, text, i + (text[i] != 0), 0);
	temp = sb_strjoin(NULL, &text[i + (text[i] != 0)], templen, 0);
	if (!line || !temp)
		return (sb_failsafe(text, line, temp));
	free(text);
	text = temp;
	if (text[0] == 0)
		text = sb_failsafe(text, NULL, NULL);
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *print;
	print = get_next_line(fd);
	while (print)
	{
		printf("%s",print);
		free(print);
		print = get_next_line(fd);
	}
	return (0);
}
*/