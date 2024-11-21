/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:32:54 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/21 12:52:27 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void			signal_handler(int signum);
unsigned char	power(int base, int power);

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

	if (signum == SIGUSR2)
		current_char = current_char + power(2, (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char != 0)
			write(1, &current_char, 1);
		else
			write(1, "\n", 1);
		current_char = 0;
		bit_count = 0;
	}
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
