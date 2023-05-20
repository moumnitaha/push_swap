/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:03:35 by tmoumni           #+#    #+#             */
/*   Updated: 2022/11/19 17:55:11 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	count;
	size_t	strlen;

	count = 0;
	strlen = ft_strlen((char *)str);
	while (count++ <= strlen)
	{
		if (*(char *)str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
