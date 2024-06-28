/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:57:03 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/27 21:57:39 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parse.h"
#include "ft_error.h"
#include "vector.h"

t_ambient	create_ambient(char **vals)
{
	t_ambient	amb;

	if (arg_len(vals) != 2)
		ft_error(error_init);
	atod(vals[0], &amb.ratio);
	amb.rgb = color(vals[1]);
	return (amb);
}

void	create_light(t_light **head, char **vals)
{
	t_light	*light;

	if (arg_len(vals) < 2 && arg_len(vals) < 4)
		ft_error(error_init);
	light = ft_malloc(sizeof(t_light));
	light->point = point(vals[0]);
	atod(vals[1], &light->ratio);
	light->rgb = color(vals[2]);
	light->next = NULL;
	add_light_to_list(head, light);
}
