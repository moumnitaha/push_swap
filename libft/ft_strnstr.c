/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:38:52 by tmoumni           #+#    #+#             */
/*   Updated: 2022/10/28 16:23:55 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	i;
	char	*hstck;
	char	*ndl;

	count = 0;
	hstck = (char *)haystack;
	ndl = (char *)needle;
	if (!ft_strlen(ndl))
		return (hstck);
	while (count < len && hstck[count])
	{
		i = 0;
		while (ndl[i] && hstck[count + i] == ndl[i] && (count + i) < len)
				i++;
		if (needle[i] == '\0')
			return ((char *)haystack + count);
		else
			count++;
	}
	return (NULL);
}
