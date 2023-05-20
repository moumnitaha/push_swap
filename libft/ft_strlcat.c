/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:40:04 by tmoumni           #+#    #+#             */
/*   Updated: 2022/11/20 11:44:44 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst && !dstsize)
		return (srclen);
	dstlen = ft_strlen(dst);
	count = 0;
	if ((dstsize > dstlen) && dstsize)
	{
		while (count < dstsize - dstlen - 1 && src[count])
		{
			dst[dstlen + count] = src[count];
			count++;
		}
		dst[dstlen + count] = '\0';
		return (srclen + dstlen);
	}
	return (srclen + dstsize);
}
