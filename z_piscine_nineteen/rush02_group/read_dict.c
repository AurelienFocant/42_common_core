#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* start reading main ()
 * at the bottom
 * these are all helper functions
 */

void	ft_print_number(char *nbr, char **keys, char **values);


/* count every char of file
 * to copy the whole thing
 * inside a str
 */
int	ft_count_chars(int fd)
{
	int count_chars;
	char buff;

	count_chars = 0;
	while (read(fd, &buff, 1))
	{
		count_chars++;
	}
	return count_chars;
}

void ft_copydict_instring(char *str, int fd)
{
	int i;	
	char buff;

	i = 0;
	while (read(fd, &buff, 1))
	{
		str[i] = buff;
		i++;
	}
	str[i] = '\0';
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}


/* counts lines but only
 * if theres a numerical char on it
 * to be sure it doesn't count
 * any empty line
 */
int	ft_count_lines(char *str)
{
	int count;
	
	count = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		if (ft_isnum(*str) && *str)
		{
			count++;
			while (ft_isnum(*str) && *str)
				str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
	return (count);
}


/* basically a ft_strlen
 * but adds more stopping points 
 * than just '\0'
 */
int		ft_lensep(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != ':')
		i++;
	return (i);
}


/* we enter this function when 
 * we find a key == numero in the dict
 * or a value == a letter in the dict
 * we find the len of that word until next sep
 * and malloc enough space
 * + '\0' of course
 */
/* we can then copy char by char
 * using the pointer from original string
 */
char	*ft_fill_word(char *str)
{
	int len;
	char *word;
	int i;

	len = ft_lensep(str);
	word = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		word[i] = *str;
		str++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_fill_keys(char **keys, char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		if (ft_isnum(*str) && *str)
		{
			keys[i] = ft_fill_word(str); 
			i++;
			while(ft_isnum(*str))
					str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
}

void	ft_fill_values(char **values, char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		while (!ft_isalpha(*str) && *str)
			str++;
		if (ft_isalpha(*str) && *str)
		{
			values[i] = ft_fill_word(str); 
			i++;
			while(ft_isalpha(*str))
					str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
}

/* free the whole array of char*
 */
void	ft_free(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr[i]);
}

int main(int argc, char **argv)
{
	int fd;
	int char_count;
	char *str;
	int line_count;
	char **keys;
	char **values;

	if (argc < 2 || argc > 3)
		return (1);


	/* opens the file, read every char, close the file
	 * to know the size of str
	 */
	fd = open(argv[1], 0);
	char_count = ft_count_chars(fd);
	close(fd);


	/* allocate the string to the right size
	 * open the file again
	 * write everything in the string
	 */
	str = malloc(sizeof(char) * (char_count + 1));
	fd = open(argv[1], 0);
	ft_copydict_instring(str, fd);


	/* count lines, doesnt count empty lines
	 * allocate two arrays of same size
	 * they are arrays of char *ptr
	 * last ptr set to null to signify end of array
	 */
	line_count = ft_count_lines(str);
	keys = malloc(sizeof(char *) * (line_count + 1));
	keys[line_count] = 0;
	values = malloc(sizeof(char *) * (line_count + 1));
	values[line_count] = 0;


	/* basically some kind of ft_split
	 * to go get every word
	 * and fill corresponding array
	 * maybe could be only one funciton ?
	 * it has slightly different rules though
	 */
	ft_fill_keys(keys, str);
	ft_fill_values(values, str);


	/* this just to see that the arrays are correctly filled
	 * will be deleted
	 */
	/*
	int i = 0;
	while (keys[i])
	{
		printf("key: %s value: %s\n", keys[i], values[i]);	
		i++;
	}
	*/

	/* goes to the next file
	 * and pass in the arrays
	 * both files could use lots of cleaning
	 * and lots of bugs still
	 */
	ft_print_number(argv[2], keys, values);

	/* lets not forget to free everything, 
	 * should check for null pointers,
	 * etc etc
	 * could run valgrind when file a bit cleaner
	 */
	ft_free(keys);
	ft_free(values);
	free(keys);
	free(values);

	free(str);
}
