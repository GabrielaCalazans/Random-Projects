/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 02:31:16 by gacalaza          #+#    #+#             */
/*   Updated: 2023/01/13 20:18:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strcapitalize(char *str);
void	ft_putstr_fd(char *s, int fd);
char	**ft_print_message(int args, char **strs);

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
	free (result);
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
		str = ft_strcapitalize(strs[i]);
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

char	*ft_strcapitalize(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (str);
	while (str[count] != '\0')
	{
		if (str[count] >= 'a' && str[count] <= 'z')
		{
			str[count] = str[count] - 32;
		}
		else if (str[count] >= 'A' && str[count] <= 'Z')
		{
			str[count] = str[count] + 32;
		}
		count++;
	}
	return (str);
}
