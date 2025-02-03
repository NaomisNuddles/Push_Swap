/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/02/03 16:43:25 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/includes/libft.h"
# include "utils/includes/ft_printf.h"
# include "utils/includes/get_next_line.h"

# ifndef STACK_SIZE
#  define MAX_STACK_SIZE 4294967295
# endif

# define ERRORS "Er01:		Stack Already Sorted!\n\
Er02:		No Stack Provided!\n\
Er03:		Falid to Allocate Stacks!\n\
Er04:		Invalid Stack (non numbers, not space divided, sign undefined)!\n\
Er05:		Repeated Numbers!\n\
Er06:		!\n\
Er07:		!\n\
Er08:		!\n\
Er09:		!\n\
"

typedef struct s_stk
{
	int		top;
	int		stk[MAX_STACK_SIZE];
}	t_stk;

typedef struct s_stacks
{
	t_stk	*a;
	t_stk	*b;
	bool	do_a;
	bool	do_b;
}	t_stacks;

//	stk_aux_dumb_ops.c
bool			ft_stk_swap(t_stk *stk);
bool			ft_stk_push(t_stk *stk_src, t_stk *stk_dst);
bool			ft_stk_cycle(t_stk *stk);
bool			ft_stk_illegal(t_stk *stk);


//	stk_aux_ops.c
bool			stk_isempty(t_stk *stk);
bool			stk_isfull(t_stk *stk);
void			stk_push(t_stk *stk, int val);
int				stk_pop(t_stk *stk);
int				stk_pop_zed(t_stk *stk);

//	stk_aux_utils.c
t_stacks		*set_stacks(void);
void			free_stacks(t_stacks *data);

//	arg_aux_checks.c
bool			arg_issplit(char *arg);
bool			arg_isneg(char *arg);
bool			arg_ispos(char *arg);
bool			arg_isvalid(char *arg);

//	args_to_stk.c
bool			arg_pop(char *arg, t_stk *stk);
bool			args_pick(int cnt, char **args, t_stk *stk);

//	aux_utils.c
void			error_log(char	*err);
int				atoi_unlim(const char *src);

#endif //PUSH_SWAP_H