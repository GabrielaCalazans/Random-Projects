/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:23:20 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/21 23:28:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**ft_print_message(int args, char **strs);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_reverse_str(char *str);

int	main(int argc, char *argv[])
{
	int		i;
	char	**result;

	i = 0;
	if (argc < 2)
		return (0);
	while (argv[i] != NULL)
		i++;
	result = ft_print_message(i, argv);
	if (!result)
		return (0);
	return (0);
}

char	**ft_print_message(int args, char **strs)
{
	int		i;
	char	*str;
	char	**result;

	i = 1;
	result = (char **)malloc(sizeof(char *) * args);
	if (!result || !strs)
		return (NULL);
	while (args >= i)
	{
		str = ft_reverse_str(strs[i]);
		if (!str)
		{
			free(str);
			str = "\0";
			return (result);
		}
		result[i - 1] = str;
		ft_putstr_fd(result[i - 1], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	result[i] = NULL;
	free (str);
	return (result);
}

char	*ft_reverse_str(char *str)
{
	char	*rev;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	rev = (char *)malloc(sizeof(char) * (len + 1));
	if (!rev)
		return (NULL);
	i = 0;
	j = len - 1;
	if (!str)
		return (NULL);
	while (i <= len)
		rev[i++] = str[j--];
	rev[i] = '\0';
	return (rev);
}

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		write(fd, &s[count], 1);
		count++;
	}
}
