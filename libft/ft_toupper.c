/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:10:28 by tmoumni           #+#    #+#             */
/*   Updated: 2022/11/19 14:59:15 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	n;

	if (c == EOF)
		return (-1);
	n = (unsigned char)c;
	if (n >= 'a' && n <= 'z')
		n = n - 32;
	return (n);
}
