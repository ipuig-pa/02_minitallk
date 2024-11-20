/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:32:54 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/20 12:10:25 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft\libft.h"

static state;
//server

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{

	}
	else if (signum == SIGUSR2)
	{

	}
}
//sigemptyset per buidar el contingut random que hi havia a la sa.mask, de manera que no hi ha garbage values de senyals per bloquejar
int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome.\nServer's PID is %d\n", pgetpid());
	sigemptyset(&sa.sa_mask)
	sa.sa_handler = &signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	signal(SIGUSR1, signal_handler_sigusr1);
	signal(SIGUSR2, signal_handler_sigusr2);
	while (1)
		pause();
	return (0);
	ft_printf("Client string is %s\n", str);

}

//understand termination sign


