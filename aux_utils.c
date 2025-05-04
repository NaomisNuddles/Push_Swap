/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/04 12:39:54 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_stacks_vals(t_stacks *data)
{
	data->a->top = -1;
	data->op_a->num = 0;
	data->op_a->sx = 0;
	data->op_a->rx = 0;
	data->op_a->rrx = 0;
	data->op_a->px = 0;
	data->do_a = NOOP;
	data->b->top = -1;
	data->op_b->num = -1;
	data->op_b->sx = 0;
	data->op_b->rx = 0;
	data->op_b->rrx = 0;
	data->op_b->px = 0;
	data->do_b = NOOP;
}

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
	data->op_a = malloc(sizeof(t_ops));
	if (!data->b)
		return (free(data->b), free(data->a), free(data), NULL);
	data->op_b = malloc(sizeof(t_ops));
	if (!data->b)
		return (free(data->op_a), free(data->b), free(data->a), \
		free(data), NULL);
	set_stacks_vals (data);
	return (data);
}

void	free_stacks(t_stacks *data)
{
	if (data)
	{
		free(data->a);
		free(data->b);
		free(data->op_a);
		free(data->op_b);
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
