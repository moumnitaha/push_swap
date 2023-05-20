/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:28:52 by tmoumni           #+#    #+#             */
/*   Updated: 2022/10/28 14:17:40 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && (s1[count] || s2[count]))
	{
		if ((unsigned char)s1[count] > (unsigned char)s2[count])
			return (1);
		if ((unsigned char)s1[count] < (unsigned char)s2[count])
			return (-1);
		count++;
	}
	return (0);
}
