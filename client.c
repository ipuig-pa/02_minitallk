/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:32:43 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/20 11:34:53 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (!server_pid)
	{
		ft_printf("Wrong arg PID");
		return (0);
	}
	len = ft_strlen(str);
	if (len == 0)
	{
		ft_printf("Wrong arg string. Write the message to send to the server");
		return (0);
	}
	binnary_str = (int *)malloc((len + 1) * 8 * sizeof(int));
	str_to_binary(argv[2], binnary_str, len);
	send_to_server(binnary_str, pid, ((len + 1) * 8));
	free(binnary_str);
	return (0);
}

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

void	send_to_server(int *binnary_str, int pid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		signal = SIGUSR1;
		if (binnary_str[i] == 1)
			signal = SIGUSR2;
		kill(server_pid, signal);
		//mirar si puc rebaixar temps
		usleep(500);
		i++;
	}
}
