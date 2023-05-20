/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:32:02 by tmoumni           #+#    #+#             */
/*   Updated: 2022/11/19 19:24:07 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*stralloc(size_t start, size_t strlen, size_t len)
{
	char	*str;

	if (start <= strlen)
	{
		if (len <= strlen - start)
			str = (char *)malloc((len + 1) * sizeof(char));
		else
			str = (char *)malloc((strlen - start + 1) * sizeof(char));
	}
	else
		str = (char *)malloc(sizeof(char));
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;
	size_t	strlen;

	if (!s)
		return (NULL);
	count = 0;
	strlen = ft_strlen(s);
	if (len > strlen)
		len = strlen;
	str = stralloc(start, strlen, len);
	if (!str)
		return (NULL);
	if (start < strlen)
	{
		while (s[count + start] && count < len)
		{
			str[count] = s[start + count];
			count++;
		}
	}
	str[count] = '\0';
	return (str);
}
