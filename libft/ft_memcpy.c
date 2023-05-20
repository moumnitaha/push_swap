/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:41:04 by tmoumni           #+#    #+#             */
/*   Updated: 2022/11/19 14:58:49 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ndst;
	const char	*nsrc;
	size_t		count;

	if (dst == src)
		return (dst);
	count = 0;
	ndst = (char *)dst;
	nsrc = (const char *)src;
	while (count < n)
	{
		ndst[count] = nsrc[count];
		count++;
	}
	return (dst);
}
