/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/03/31 18:19:31 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*set_stacks(void)
{
	t_stacks	*data;

	data = malloc(sizeof(t_stacks));
	if (!data)
		return (NULL);
	data->a = malloc(sizeof(t_stk));
	if (!data->a)
		return (free(data), NULL);
	data->b = malloc(sizeof(t_stk));
	if (!data->b)
		return (free(data->a), free(data), NULL);
	data->a->top = -1;
	data->b->top = -1;
	data->at_wrg = 0;
	data->do_a = NOOP;
	data->do_b = NOOP;
	return (data);
}

void	free_stacks(t_stacks *data)
{
	if (data)
	{
		free(data->a);
		free(data->b);
		free(data);
	}
}

void	error_log(char	*err)
{
	if (ft_atoi(&err[2]) == 1)
		ft_printf(">	%s:	Stack Already Sorted!\n", err);
	else if (ft_atoi(&err[2]) == 0)
		ft_printf("Errors:\n%s", ERRORS);
	else if (ft_atoi(&err[2]) == 2)
		return ;
	else
	{
		ft_printf(">	%s\n", err);
		write(2, "error\n", 6);
	}
}
