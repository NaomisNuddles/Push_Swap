/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/02/17 17:02:18 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/includes/libft.h"
# include "utils/includes/ft_printf.h"
# include "utils/includes/get_next_line.h"

# ifndef STACK_SIZE
#  define MAX_STACK_SIZE 100000
# endif

# define ERRORS "Er01:		Stack Already Sorted!\n\
Er02:		No Stack Provided!\n\
Er03:		Falid to Allocate Stacks!\n\
Er04:		Invalid Stack - Not Space Divided, Not Sign Defined, Not Digit Types!\n\
Er05:		Repeated Numbers Found!\n\
Er06:		Undefined - Did Not Find Sorting Product!\n\
Er07:		Undefined - Did Not Exited Stack b!\n\
Er08:		Undefined - Did Not Sort Stack a!\n\
"

typedef enum e_rules
{
	NON,
	PUSH,
	SWAP,
	LOOP,
	DUMB
}	t_rules;

typedef struct s_stk
{
	int		top;
	int		stk[MAX_STACK_SIZE];
}	t_stk;

typedef struct s_stacks
{
	t_stk	*a;
	t_stk	*b;
	t_rules	do_a;
	t_rules	do_b;
}	t_stacks;

//	stk_ops_dumb.c
bool			stk_issorted(t_stk *stk);
bool			ft_stk_swap(t_stk *stk);
bool			ft_stk_push(t_stk *stk_src, t_stk *stk_dst);
bool			ft_stk_cycle(t_stk *stk);
bool			ft_stk_illegal(t_stk *stk);

//	stk_ops_core.c
bool			stk_isempty(t_stk *stk);
bool			stk_isfull(t_stk *stk);
void			stk_push(t_stk *stk, int val);
int				stk_pop(t_stk *stk);
int				stk_pop_zed(t_stk *stk);

//	stk_ops_comp.c
int				stk_poke(t_stk *stk, int num);
int				stk_min(t_stk *stk);
int				stk_next_min(t_stk *stk, int p_min);
int				stk_max(t_stk *stk);
int				stk_next_max(t_stk *stk, int p_max);

//	stk_aux_read.c
int				stk_ordered(t_stk *stk);

//	args_to_stk.c
bool			arg_issplit(char *arg);
bool			arg_isvalid(char *arg);
bool			arg_pop(char *arg, t_stk *stk);
bool			args_pick(int cnt, char **args, t_stk *stk);

//	aux_utils.c
t_stacks		*set_stacks(void);
void			free_stacks(t_stacks *data);
void			error_log(char	*err);

#endif //PUSH_SWAP_H