/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:24:41 by tmoumni           #+#    #+#             */
/*   Updated: 2022/11/19 18:46:02 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		count;
	char		*ndst;
	const char	*nsrc;

	if (dst == src || !len)
		return (dst);
	count = 0;
	ndst = (char *)dst;
	nsrc = (const char *)src;
	if (src > dst)
	{
		while (count++ < len)
			ndst[count - 1] = nsrc[count - 1];
	}
	else
	{
		while (len--)
			ndst[len] = nsrc[len];
	}
	return (dst);
}
