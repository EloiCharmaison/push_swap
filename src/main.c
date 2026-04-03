/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 22:46:08 by marvin            #+#    #+#             */
/*   Updated: 2026/02/05 22:46:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (!arg_checker(argc, argv, &a))
		return (0);
	if (!is_sorted(&a))
	{
		if (a.size <= 5)
			sort_small(&a, &b);
		else
			sort_big(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}

int	arg_checker(int argc, char **argv, t_stack *a)
{
	char	**args;

	if (argc < 2)
	{
		error_exit();
		return (0);
	}
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			error_exit();
		fill_stack_tab(args, a);
		free_tab(args);
	}
	else
		fill_stack(argc, argv, a);
	return (1);
}

void	free_exit(char **tab)
{
	free_tab(tab);
	error_exit();
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
	{
		error_exit();
		return ;
	}
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
}
