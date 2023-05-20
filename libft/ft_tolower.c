/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:26 by tmoumni           #+#    #+#             */
/*   Updated: 2022/11/19 14:59:34 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	n;

	if (c == EOF)
		return (-1);
	n = (unsigned char)c;
	if (n >= 'A' && n <= 'Z')
		n = n + 32;
	return (n);
}
