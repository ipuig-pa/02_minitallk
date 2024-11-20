#include "libft/libft.h"

void	str_to_binary(char *str, int *binnary_str, int len)
{
	int	i;
	int	c;
	int	bit_count;

	i = ((len + 1) * 8) - 1;
	while (len >= 0)
	{
		c = (int)str[len];
		bit_count = 0;
		while (c != 0)
		{
			binnary_str[i] = c % 2;
			c = c / 2;
			bit_count++;
			i--;
		}
		while (bit_count < 8)
		{
			binnary_str[i] = 0;
			bit_count++;
			i--;
		}
		len--;
	}
}

int	main(void)
{
	int		i;
	int		len;
	int		*binnary_str;
	char	*str = "He";

	len = ft_strlen(str);
	binnary_str = (int *)malloc((len + 1) * 8 * sizeof(int));
	str_to_binary(str, binnary_str, len);
	i = 0;
	while (i < ((len + 1) * 8))
	{
		ft_printf("%i", binnary_str[i]);
		i++;
	}
	free(binnary_str);
	return (0);
}

