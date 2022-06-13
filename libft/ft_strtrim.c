/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:50:50 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/12/11 20:35:00 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcmp(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1 == set[i])
			return (0);
		i++;
	}
	return (1);
}

static unsigned int	front_trim(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (!ft_charcmp(s1[i], s2) && s1[i] != '\0')
		i++;
	return (i);
}

static unsigned int	back_trim(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(s1) - 1;
	i = len;
	while (!ft_charcmp(s1[i], s2) && len-- > 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ptr;
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = front_trim(s1, set);
	end = back_trim(s1, set);
	len = end - start + 1;
	if (start > len)
		len = 1;
	ptr = ft_substr(s1, start, len);
	return (ptr);
}
