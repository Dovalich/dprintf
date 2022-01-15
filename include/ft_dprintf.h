/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:36:58 by nammari           #+#    #+#             */
/*   Updated: 2022/01/15 20:06:55 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdbool.h>

# define ERROR -1

typedef int	(*t_func)(va_list *varlist, const char* str, int fd);

typedef struct t_flag_struct {
	bool	pad_zero;
	bool	left_justify;
	bool	disp_sign;
	bool	disp_space;
	bool	disp_hex_prefix;
	bool	sign_printed;
	int		width_nb;
	int		precision_nb;
	int		prefix_char_count;
	int		fd;

}				t_flag_values;

typedef struct s_var_func_holder {
	int		format;
	t_func	treat_function;
	void	*next;
}				t_var_func;

//Union to manage my va_args_int
typedef union s_type_holder {
	unsigned int	u_digit;
	unsigned long	ul_digit;
	int				digit;	
}				t_type_holder;

//Flags_Checkers
bool				is_width_flag(const char *str, int *index);
bool				is_precision_flag(const char *str, int *index);
bool				is_primary_flag(char c);
bool				wildcard_width_checker(const char	*str);
bool				wildcard_precision_checker(const char	*str);

//Specifier_checkers
bool				ft_ishex(char c);
bool				is_specifier(char c);

//Arguments_checkers
bool				is_valid_argument(const char	*str);

//Disp_sign_and_hex_prefix
void				disp_sign(char format,
						t_flag_values *flag, char	*string);

//Chained_lists
int					list_add_front(t_var_func **list, t_var_func *ls_new);
t_var_func			*create_list(void);
t_var_func			*new_struct(int format,
						int (*ptr_func)(va_list*, const char*, int));
t_var_func			*get_element(t_var_func *ptr, char c);
void				free_list(t_var_func *ptr);

//Digit_utils
char				*ft_itoa_base(long num, char *to_base,
						int base_len);
char				*ft_u_itoa_base(unsigned long num, char *to_base,
						int base_len);
int					count_unum_len(unsigned long long num, int base_len);
int					count_num_len(long long num, int base_len);
char				*base_creator(char format);

//flag_values_fill
t_flag_values		*init_to_zero(int fd);
void				get_flag_data(const char	*str,
						char format, t_flag_values *flag);
void				get_width(const char	*str, char format,
						t_flag_values *flag);
void				get_precision(const char	*str,
						char format, t_flag_values *flag);

//Digit_print
int					print_digit(const char *str, t_type_holder *my_type,
						t_flag_values *flag);
int					get_flags(const char *str,
						char *string, t_flag_values *flag);
int					get_sign(char *string, char format,
						t_flag_values *flag);
int					print_number(char *string, t_flag_values *flag,
						int format);
//digit_lead_chars
int					count_digit_prefix(t_flag_values *flag,
						char format, char *string);
//utils
int					ft_count_len(char *string);
int					get_biggest(int a, int b);

//Print_string
int					print_string(char *string, t_flag_values *flag);
int					treat_string(va_list *varlist, const char*str, int fd);
int					count_printed_chars_string(int precision,
						int width, int len);
int					disp_null(int precision);
int					count_null_width(t_flag_values *flag);
int					put_string(char *str, int len, t_flag_values *flag);
int					print_space(int *width, t_flag_values *flag);

//print_pointer
int					treat_pointer(va_list *varlist, const char *str, int fd);

//print_char
int					print_char(char mychar, t_flag_values *flag);
int					treat_char(va_list *varlist, const char	*str, int fd);

//print_percent
int					treat_percent(va_list *valist, const char *str, int fd);

//Treat_digit
int					treat_digit(va_list	*varlist, const char *str, int fd);

//Error function
int					error_malloc(void);
//printf 
int					format_parser(va_list *ap,
						const char	*str, t_var_func *ptr, int fd);
int					ft_dprintf(int fd, const char	*str, ...);
#endif
