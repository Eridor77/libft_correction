/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlavallo <rlavallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:53:45 by rlavallo          #+#    #+#             */
/*   Updated: 2014/11/06 17:29:56 by rlavallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	if ((unsigned int)c >= ' ' && (unsigned int)c <= '~')
		return (1);
	return (0);
}
