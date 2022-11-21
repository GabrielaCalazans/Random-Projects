#include<unistd.h>
#include<stdio.h>

char    *ft_strcapitalize(char *str);
void	ft_putchar(char c);
void	ft_loopchar(char *c);

int main()
{
    char *Atest = "DEPOIS DA ft_strcase ";
    char *btest = "ANTES DA ft_strpcase ";
	char strtest[] = "oi, tudo Bem? 42paLavras quarEnta-e-duas; cinquenta+e+um";
	char str2[] = "gabrieLa tá fO...";


    ft_loopchar(btest);
    ft_putchar('\n');
    ft_loopchar(strtest);
    ft_putchar('\n');
    ft_loopchar(str2);
    ft_putchar('\n');
    
    ft_loopchar(Atest);
    ft_strcapitalize(strtest);
    ft_strcapitalize(str2);
    ft_putchar('\n');
    ft_loopchar(strtest);
    ft_putchar('\n');
    ft_loopchar(str2);	

    return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_loopchar(char *c)
{
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	count;

	count = 0;
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
