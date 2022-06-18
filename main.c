/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:24:18 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/18 17:35:21 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char *ft_putu(unsigned int i)
{
	long size;
	char *ada;
	size = nbsize(i);
	ada = malloc (sizeof(char) * (size + 1));
	if (!ada)
		return(NULL);
	ada[size] = '\0';
	while (i > 0)
	{
		ada[size--] = 48 + (i % 10);
		i /= 10;
	}
	return (ada);
}



#include <stdio.h>
int main()
{
	unsigned int i  = putu(42);
	printf("%u", i);
}
