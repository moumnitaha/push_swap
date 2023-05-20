/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:33:03 by tmoumni           #+#    #+#             */
/*   Updated: 2022/11/20 13:08:19 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	count;

	count = ft_strlen((char *)str);
	while (count >= 0 && count <= ft_strlen((char *)str))
	{
		if (str[count] == (char)c)
			return ((char *)str + count);
		count--;
	}
	return (NULL);
}
