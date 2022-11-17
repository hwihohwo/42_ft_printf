/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:12:23 by seonghwc          #+#    #+#             */
/*   Updated: 2022/11/17 18:55:56 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_info
{
	int	c_flag;
	int	s_flag;
	int	p_flag;
	int	d_flag;
	int	i_flag;
	int	u_flag;
	int	x_flag;
	int	low_x_flag;
	int	percent_flag;
	int	width;
	int	minus_flag;
	int	zero_flag;
	int	dot_flag;
	int	precision;
	int	shap_flag;
	int	space_flag;
	int	plus_flag;
	int	length;
	int	c_null_flag;
}	t_info;

int		ft_printf(const char *str, ...);
int		ft_printf_bonus(const char *str, ...);
t_list	*make_buffer(const char *str);
int		count_string_length(const char *str, int j);
char	*make_tmp(int count, const char *str);
int		is_specifier(char c, char *specifier);
int		substitute_and_print(t_list *buffer, t_info *info, va_list *ap);
int		print(char *str, t_info *info);
void	input_info(char *str, t_info *info);
void	check_specifier(char c, t_info *info);
void	initializing_info(t_info *info);
void	input_flags(char c, t_info *info);
int		check_flags(char c);
int		calc_length(int base, unsigned long num);
char	*write_num(int base, long num, int precision);
char	*write_num_upper(int base, long num, int precision);
void	free_all(char *arr1, char *arr2);
char	*make_string(t_info *info, va_list *ap);
char	*make_width(t_info *info, int essential_length);
char	*make_essential_string(t_info *info, va_list *ap);
char	*c_result(va_list *ap, t_info *info);
char	*s_result(va_list *ap, t_info *info);
char	*p_result(va_list *ap);
char	*d_result(t_info *info, va_list *ap);
char	*u_result(t_info *info, va_list *ap);
char	*low_x_result(t_info *info, va_list *ap);
char	*x_result(t_info *info, va_list *ap);
char	*percent_result(void);
void	put_d_front(int num, char *ret1, t_info *info);
int		ft_atoi(const char *str);
t_list	*ft_lstnew(void *content);
int		ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	check_zero_flag(char *ret);
#endif