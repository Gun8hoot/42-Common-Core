/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:51:35 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/29 13:53:04 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_hex(unsigned int nb, char *base);
int	ft_putstr(char *str);
int	ft_putnbr(long nb);
int	ft_putchar(char c);
int	ft_pourcent(void);
int	ft_pointer(void *ptr);
int	ft_unsputnbr(unsigned int nb);

#endif