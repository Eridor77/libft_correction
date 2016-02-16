/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlavallo <rlavallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 16:23:31 by rlavallo          #+#    #+#             */
/*   Updated: 2016/02/16 12:56:49 by rlavallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s1;
	if (!ptr[0] && !s2[0])
		return (ptr);
	while (*ptr)
	{
		if (*ptr == s2[0] || s2[0] == '\0')
		{
			i = 0;
			while (*(ptr + i) == s2[i] || s2[0] == '\0')
			{
				if (s2[i + 1] == '\0')
					return (ptr);
				i++;
			}
		}
		ptr++;
	}
	return (NULL);
}
