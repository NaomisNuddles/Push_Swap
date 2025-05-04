/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/03 20:06:59 by nleandro         ###   ########.fr       */
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

# define ERRORS "Er01:		Stack Already Sorted! [UNLOGGED ERROR]\n\
Er02:		No Stack Provided! [UNLOGGED ERROR]\n\
Er03:		Falid to Allocate Stacks!\n\
Er04:		Invalid Stack - Not Space Divided, Not Sign Defined, Not Digit Types!\n\
Er05:		Number Out of Range!\n\
Er06:		Repeated Numbers Found!\n\
Er07:		UDF - Did Not Find Sorting Product!\n\
Er08:		UDF - Lost Sorting Product!\n\
Er09:		UDF - Lost Stacks!\n\
Er10:		UDF - Did Not Sort Stack a!\n\
"

typedef enum e_rules
{
	NOOP,
	PUSH,
	SWAP,
	LOOP,
	DUMB
}	t_rules;

typedef enum e_lock
{
	ALL_A,
	ALL_B,
	SEMI_B
}	t_lock;

typedef struct s_stk
{
	int		top;
	int		stk[MAX_STACK_SIZE];
}	t_stk;

typedef struct s_ops
{
	int	num;
	int	sx;
	int	rx;
	int	rrx;
	int	px;
}	t_ops;

typedef struct s_stacks
{
	t_stk	*a;
	t_stk	*b;
	t_ops	*op_a;
	t_ops	*op_b;
	t_rules	do_a;
	t_rules	do_b;
}	t_stacks;

//	wemap_read.c
//static void		get_a_ops(t_stacks *data);
void			get_ops(t_stacks *data);

//	wemap_build.c
//static int 				weight_val(int num, int n_num);
//static int				get_push_cost(t_stacks *data, char stk);
//static int				get_cost(t_stacks *data, t_rules type, t_rules rev, char stk);
void			build_wemap(t_stacks *data);

//	wemap_utils.c
//static void		lock_both(t_stacks *data);
//static void		lock_reverse(t_stacks *data);
//static void		lock_ops(t_stacks *data, t_lock path);
void			clean_wemap(t_stacks *data);
void			get_wemap(t_stacks *data);

//	stk_math.c
int				stk_min(t_stk *stk);
int				stk_next_min(t_stk *stk, int p_min);
int				stk_max(t_stk *stk);
int				stk_next_max(t_stk *stk, int p_max);

//	stk_comp.c
int				stk_poke(t_stk *stk, int num);
bool			stk_issort(t_stk *stk);
bool			stk_issort_rev(t_stk *stk);
int				stk_sendback_num(t_stk *stk);

//	stk_ops_do.c
//static void		do_both(t_stacks *data);
//static void		do_one_a(t_stacks *data);
//static void		do_one_b(t_stacks *data);
void 			write_ops(t_stacks *data);
bool			do_ops(t_stacks *data);

//	stk_ops_dumb.c
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

//	stk_parsing.c
bool			arg_issplit(char *arg);
bool			arg_isvalid(char *arg);
bool			arg_pop(char *arg, t_stk *stk);
bool			args_pick(int cnt, char **args, t_stk *stk);

//	aux_utils.c
//static void		set_stacks_vals (t_stacks *data);
t_stacks		*set_stacks(void);
void			free_stacks(t_stacks *data);
void			error_log(char	*err);

#endif //PUSH_SWAP_H