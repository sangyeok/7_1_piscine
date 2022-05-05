/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:26:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 21:14:33 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_number
{
	int				key;
	char			*value;
	struct s_number	*next;
}	t_number;

typedef struct s_digits
{
	int				key;
	char			*value;
	struct s_digits	*next;
}	t_digits;

void	init_all(char **input, char **dict, \
		t_number **number, t_digits **digit);
int		check_exists_num(int key, t_number *number);
int		check_exists_digit(int key, t_digits *digit);
void	sep_num(char *input, t_number *number, \
		t_digits *digit, int len_input);
void	ft_free(char **input, char **dict, \
		t_number **number, t_digits **digit);
int		is_zero(char *input, t_number *number, int len_input, int *flag);
int		check_dict(int argc, char **argv, char **input, char **dict);
int		check_input_part1(char **input, int check);
int		check_input_part2(char **input, char *temp, int count, int check);
int		check_digit(int key_digit, t_digits **digit, char *value);
int		check_num(int key_num, t_number **number, char *num);
int		ft_atoi(char *str);
int		ft_push_num(t_number **number, int key, char **value);
int		ft_push_digit(t_digits **digit, int key, char **value);
void	ft_puterr(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_read(char *dict, t_number **number, t_digits **digit);
int		ft_isspace(char c);
int		ft_isprintable(char c);
char	*ft_strndup(char *str, int size);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
void	ft_num_sort(t_number **number);
void	ft_digit_sort(t_digits **digit);
int		ft_parse_line(char *line, t_number **number, t_digits **digit);
void	find_node(int num, t_number *number, int *flag);

#endif
