/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclay <lclay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:43:01 by lclay             #+#    #+#             */
/*   Updated: 2019/09/26 02:03:03 by lclay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int		i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char		**split(char const *s, char **array, char c)
{
	size_t		i;
	size_t		j;
	size_t		l;

	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		j = 0;
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			array[l] = ft_strsub(s, i, j);
			if (array[l] == NULL)
				free(array[l]);
			l++;
			i = i + j;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	array[l] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	size_t		k;

	if (!s)
		return (NULL);
	k = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (k + 1));
	if (array == NULL)
		return (NULL);
	array = split(s, array, c);
	return (array);
}
