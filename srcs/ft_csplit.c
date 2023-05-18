/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:36:45 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/17 15:24:25 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static size_t	get_word_len(const char *s, char *charset)
{
	size_t	word_len;

	word_len = 0;
	while (s[word_len] != '\0' && !ft_strchr(charset, s[word_len]))
		++word_len;
	return (word_len);
}

static char	*get_next_words(const char **s, char *charset)
{
	size_t	word_len;
	char	*word;
	int		i;

	i = 0;
	while (ft_strchr(charset, (*s)[i]))
		i++;
	(*s) += i;
	word_len = get_word_len(*s, charset);
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (word != NULL)
		ft_strlcpy(word, *s, word_len + 1);
	*s += word_len;
	return (word);
}

static size_t	count_words(const char *s, char *charset)
{
	size_t	size_split;
	size_t	i;
	bool	is_word;

	i = 0;
	size_split = 0;
	is_word = false;
	while (s[i] != '\0')
	{
		if (ft_strchr(charset, s[i]))
		{
			if (is_word == true)
			{
				++size_split;
				is_word = false;
			}
		}
		else
			is_word = true;
		i++;
	}
	return (size_split + (is_word == true));
}

void	free_strs(char **strs)
{
	size_t	incre;

	incre = 0;
	while (strs[incre] != NULL)
	{
		free(strs[incre]);
		++incre;
	}
	free(strs);
}

char	**ft_csplit(const char *s, char *charset)
{
	size_t	size_split;
	size_t	i;
	char	**split;

	if (s == NULL)
		return (NULL);
	size_split = count_words(s, charset);
	split = (char **)malloc((size_split + 1) * sizeof(char *));
	if (split != NULL)
	{	
		i = 0;
		split[size_split] = NULL;
		while (i < size_split)
		{
			split[i] = get_next_words(&s, charset);
			if (split[i] == NULL)
			{
				free_strs(split);
				split = NULL;
				break ;
			}
			++i;
		}
	}
	return (split);
}
