/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:02:53 by tmoumni           #+#    #+#             */
/*   Updated: 2022/11/20 10:56:47 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_head(char const *s1, char const *set)
{
	size_t	index;

	index = 0;
	while (ft_strchr(set, s1[index]) && s1[index])
		index++;
	return (index);
}

static size_t	trim_tail(char const *s1, char const *set)
{
	size_t	index;

	if (!ft_strlen((char *)s1))
		return (0);
	index = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[index]) && index)
		index--;
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	count;

	if (!s1 || !set)
		return (NULL);
	start = trim_head(s1, set);
	end = trim_tail(s1, set);
	count = 0;
	if (start <= end && ft_strlen((char *)s1))
		str = (char *)malloc(((end - start) + 2) * sizeof(char));
	else
		str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	while (start <= end && ft_strlen((char *)s1))
	{
		str[count] = s1[start];
		start++;
		count++;
	}
	str[count] = '\0';
	return (str);
}
