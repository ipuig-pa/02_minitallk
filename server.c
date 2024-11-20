/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:32:54 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/20 14:29:49 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft\libft.h"

static int	bit_count;

unsigned char	power(base, power)
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

void	signal_handler(int signum)
{
	static unsigned char	current_char;

	// if (signum == SIGUSR1)
	// {
	// 	bit_count--;
	// }
	else if (signum == SIGUSR2)
	{
		current_char = current_char + power(2, bit_count);
	}
	bit_count--;
	if (bit_count == 0)
	{
		write(1, &current_char, 1);
		bit_count = 8;
	}
}
//sigemptyset per buidar el contingut random que hi havia a la sa.mask, de manera que no hi ha garbage values de senyals per bloquejar
//include siginfo per poder keep track del clinet pid?

//sigaction is better than signal because it provides consistent behavior across UNIX platforms, it enables further options and prevents race condition (sigaction() is atomic - no race condition)
int	main(void)
{
	struct sigaction	sa;

	bit_count = 0;
	sigemptyset(&sa.sa_mask)
	sa.sa_handler = &signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa_handler, NULL);
	sigaction(SIGUSR2, &sa_handler, NULL);
	ft_printf("Welcome.\nServer's PID is %d\n", pgetpid());
	while (1)
		pause();
	return (0);
}

//understand termination sign



//CLAUDE PER ESPERAR EL TORN DEL CLIENT
// Global variable to store the character being received
typedef struct s_server_data {
    unsigned char   current_char;
    int            bit_count;
} t_server_data;

t_server_data g_data;

void handler(int signum)
{
    // Build the character bit by bit
    if (signum == SIGUSR1)
        g_data.current_char |= (1 << g_data.bit_count);
    g_data.bit_count++;
    
    // If we received all 8 bits
    if (g_data.bit_count == 8)
    {
        // If it's not the null terminator, print the character
        if (g_data.current_char != '\0')
            write(1, &g_data.current_char, 1);
        else
            write(1, "\n", 1);  // Print newline at end of string
            
        // Reset for next character
        g_data.current_char = 0;
        g_data.bit_count = 0;
    }
}

int main(void)
{
    struct sigaction sa;
    
    // Initialize global variable
    g_data.current_char = 0;
    g_data.bit_count = 0;
    
    // Print server PID
    ft_printf("Server PID: %d\n", getpid());
    
    // Set up signal handling
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = &handler;
    sa.sa_flags = 0;
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    // Wait for signals indefinitely
    while (1)
        pause();
    
    return (0);
}


