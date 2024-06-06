/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:13:08 by siyu              #+#    #+#             */
/*   Updated: 2024/06/06 11:20:21 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// Read content from fd and store into buff until '\n' is encountered or the end of file is reached
// If an error occucrs or the end of file is reached without reading any data, it frees a buffer and returns NULL by gnl_free
// This function will dynamically allocates a temp_buff for reading, appends the read content to the existing buff and manage mem allocation
char	*read_store(int fd, char *buff)
{
	char	*temp_buff; // A temp buff to hold data from file in each iteration
	ssize_t	bytes; // Store the num of by bytes read from file 

	bytes = 1; // Initialize bytes to enter loop
	temp_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // BUFFER_SIZE + 1 to hold NULL
	if (!temp_buff)
		return (gnl_free(&buff));
	while ((buff && bytes > 0 && !ft_strchr(buff, '\n')) || !buff) // Continue to read from file, until...
	{
		bytes = read(fd, temp_buff, BUFFER_SIZE); // Read up to BUFFER_SIZE bytes from fd into temp buff
		if (bytes < 0) // Handle read error
		{
			free(temp_buff);
			return (gnl_free(&buff));
		}
		if (bytes == 0) // Handle end of file
			break ;
		temp_buff[bytes] = '\0'; //NULL terminate the temp buff
		buff = gnl_strjoin(buff, temp_buff); // Joins the exsiting buff and temp buff into a new buff
	}
	free(temp_buff);
	if (strlen_to(buff, '\0') > 0) // Check buff length
		return (buff); // Return the buff if containing any data
	return (NULL); // Return NULL if empty
}

// Extract a substring from the given buff up to and including the first '\n' char (if exist) and return its substr
char	*extract_line(char *buff)
{
	char	*line; // Store the extracted line includes '\n' if exist
	size_t	len; // Length of he line includes '\n' if exist

	len = strlen_to(buff, '\n');
	if (buff[len] == '\n') // Adjust the length if '\n' exist 
		len++; // Include '\n' to its length
	line = gnl_substr(buff, 0, len); // Extract the substring from bufer from 0 to len position and store it in line
	if (!line)
		return (NULL);
	return (line);
}

// Process the given buff by finding the first occurence of '\n' and creat new string starting just after '\n'
// If no '\n' found, or if an error occurs during malloc, free original buff return NULL
char	*trim_to_nextline(char *buff)
{
	char	*remain_buff; // Store the new string after '\n' char
	char	*newline_pos; // store a pointer to the first occurence of '\n' in buffer
	int		newstr_i; // newstring index position, start from the first char after '\n'

	newline_pos = ft_strchr(buff, '\n'); // Find the first occurence of '\n' in buff
	if (!newline_pos) // Check for '\n'
	{
		remain_buff = NULL;
		return (gnl_free(&buff));
	}
	else // Calculate newstring position
		newstr_i = (newline_pos - buff) + 1;
	if (!buff[newstr_i]) // Check if this position is ending
		return (gnl_free(&buff));
	remain_buff = gnl_substr(buff, newstr_i, strlen_to(buff, '\0') - newstr_i); // Extract a substring from buffer from newstring to end
	gnl_free(&buff); // Free original buff
	if (!remain_buff) // Handle malloc fail
		return (NULL);
	return (remain_buff);
}

// Use OPEN_MAX to handle multiple fd at one time
// A constant that represents the max num of files that can be open simultaneously by a process
// And static buff retains vlue across multiple calls to main function
// buff[fd] is indexed by fd which allows function to store and manage separate buffers for each fd
// Each buff[fd] points to the current buffer for that specific fd
char	*get_next_line(int fd)
{
	static char		*buff[OPEN_MAX]; // Creates the static buffer array with a size of OPEN_MAX
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_store(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	nextline = extract_line(buff[fd]);
	if (!nextline)
		return (gnl_free(&buff[fd]));
	buff[fd] = trim_to_nextline(buff[fd]);
	return (nextline);
}
