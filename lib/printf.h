/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:51:35 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/31 16:24:58 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_printf(const char *str, ...);
size_t	ft_hex(unsigned int nb, char *base);
size_t	ft_putstr(char *str);
size_t	ft_putnbr(long nb);
size_t	ft_putchar(char c);
size_t	ft_pourcent(void);
size_t	ft_pointer(void *ptr);
size_t	ft_unsputnbr(unsigned int nb);
size_t	ft_ulhex(unsigned long nb, char *base)


#endif