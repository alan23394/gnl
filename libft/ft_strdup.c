/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 20:52:19 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/27 16:13:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = ft_strnew(ft_strlen(s1));
	//return (dup ? ft_strcpy(dup, s1) : 0);
	return (dup ? ft_strncpy(dup, s1, ft_strlen(s1)) : 0);
}
