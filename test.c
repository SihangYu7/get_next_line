#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;
	printf("Regular file with multiple lines\n");
	fd = open("file", O_RDONLY);
	printf("fd is %d\n", fd);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
    // One more line will be NULL
    printf("\nNULL should be printed as we get one more line after the file ending\n");
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);


	printf("\nThe file only has one char with newline\n");
	fd = open("1char", O_RDONLY);
	printf("Fd is now %d\n", fd);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	
	printf("\nThe file only has one char without newline\n");
	fd = open("1charnonl", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
}