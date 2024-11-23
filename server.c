/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:32:54 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/23 12:10:51 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void			signal_handler(int signum);
unsigned char	power(int base, int power);
int				fill_str(char *str, unsigned char current_char);

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Welcome.\nServer's PID is %d\n", getpid());
	while (1)
		pause();
	return (0);
}

void	signal_handler(int signum)
{
	static unsigned char	current_char;
	static int				bit_count;
	static char				*str;
	static int				converter;

	if (signum == SIGUSR2)
		current_char = current_char + power(2, (63 - converter - bit_count));
	bit_count++;
	if (bit_count == 64 && converter == 0)
	{
		str = (char *)malloc(current_char * sizeof(char));
		if (!str)
			exit(1);
		converter = 56;
		bit_count = 0;
		current_char = 0;
	}
	else if (bit_count == 8 && converter == 56)
	{
		if (!str)
			exit(1);
		converter = fill_str(str, current_char);
		current_char = 0;
		bit_count = 0;
	}
}

int	fill_str(char *str, unsigned char current_char)
{
	static int	i;
	int			j;
	int			converter;

	converter = 56;
	if (current_char != 0)
	{
		str[i] = current_char;
		i++;
	}
	else
	{
		j = 0;
		while (j < i)
		{
			write(1, &str[j], 1);
			j++;
		}
		write(1, "\n", 1);
		free(str);
		converter = 0;
	}
	return (converter);
}

unsigned char	power(int base, int power)
{
	unsigned char	res;

	res = 1;
	while (power != 0)
	{
		res = res * base;
		power--;
	}
	return (res);
}
