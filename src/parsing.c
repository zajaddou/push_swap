/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:23:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/03/24 07:12:33 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	check_args(char *av[])
{
	while (*(++av))
		if (!is_valid(*av))
			ft_exit("Invalid Args");
}

static	char	*combine_args(int ac, char **av)
{
	char	*input;
	char	*temp;
	int		i;

	i = 0;
	input = NULL;
	while (++i < ac)
	{
		temp = input;
		input = ft_strjoin(input, av[i]);
		free(temp);
		if ((i + 1) < ac)
		{
			temp = input;
			input = ft_strjoin(input, " ");
			free(temp);
		}
	}
	i = -1;
	while (input[++i])
		if ((input[i] >= 9 && input[i] <= 13))
			input[i] = ' ';
	if (is_empty(input))
		ft_exit("Empty String");
	return (input);
}

static	int	*create_list(int size, char *input)
{
	int		*list;
	char	**split;
	int		i;

	i = 0;
	split = ft_malloc(sizeof(char *) * (size + 1));
	split = ft_split(input, ' ');
	split[size] = NULL;
	free(input);
	list = ft_malloc(sizeof(int) * size);
	i = -1;
	while (split[++i] != NULL)
		list[i] = extra_atoi(split[i]);
	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
	return (list);
}

int	count_word(char const *s)
{
	int	c_words;
	int	i;

	i = 0;
	c_words = 0;
	while (s[i])
	{
		if (!((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
		{
			c_words++;
			while (s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
				i++;
		}
		else
			i++;
	}
	return (c_words);
}

void	parsing(int ac, char **av, int *size, t_stack **stack_a)
{
	char	*input;
	int		*list;
	int		i;

	if (ac == 1)
		ft_exit(NULL);
	check_args(av);
	input = combine_args(ac, av);
	*size = count_word(input);
	list = create_list(*size, input);
	if (is_duplicate(list, *size))
		ft_exit("Duplicate input");
	if (is_sorted(list, *size))
		ft_exit(NULL);
	i = -1;
	while (++i < *size)
		add_node(stack_a, list[i]);
}
