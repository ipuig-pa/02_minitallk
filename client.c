/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:32:43 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/21 11:44:42 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	str_to_binary(char *str, int *binary_str, int len);
void	send_to_server(int *binary_str, int pid, int size);

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		len;
	int		*binary_str;

	if (argc != 3)
		return (ft_printf("Wrong number of arguments\n"), 1);
	server_pid = ft_atoi(argv[1]);
	if (!server_pid)
		return (ft_printf("Wrong arg PID\n"), 1);
	len = ft_strlen(argv[2]);
	if (len == 0)
		return (ft_printf("Wrong arg string. Write the message to send to the server\n"), 1);
	binary_str = (int *)malloc((len + 1) * 8 * sizeof(int));
	if (!binary_str)
		return (1);
	str_to_binary(argv[2], binary_str, len);
	send_to_server(binary_str, server_pid, ((len + 1) * 8));
	free(binary_str);
	return (0);
}

void	str_to_binary(char *str, int *binary_str, int len)
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
			binary_str[i] = c % 2;
			c = c / 2;
			bit_count++;
			i--;
		}
		while (bit_count < 8)
		{
			binary_str[i] = 0;
			bit_count++;
			i--;
		}
		len--;
	}
}

void	send_to_server(int *binary_str, int pid, int size)
{
	int	i;
	int	signal;

	i = 0;
	while (i < size)
	{
		signal = SIGUSR1;
		if (binary_str[i] == 1)
			signal = SIGUSR2;
		kill(pid, signal);
		//mirar si puc rebaixar temps
		usleep(50);
		i++;
	}
}
