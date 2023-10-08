/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:58:41 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 23:37:36 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUIILTINS_H
# define BUIILTINS_H

// typedef struct s_export t_export;
typedef struct s_data t_data;
typedef struct s_dict t_dict;
typedef struct s_dict_value t_dict_value;

void	ft_buildin_parent(char **cmd, char  **env);
void    ft_buildin_child(char **cmd, char  **env, int fd_out);
// void	ft_buildin_child(char **cmd, char  **env);
// void	ft_initdata(t_data *data, char **env);

/*cnt_builtin*/
int		ft_cntstr(char **str);
int		ft_cntdict(t_dict **dict);
int		ft_cnt_bf_equal(char *str);
int		ft_cnt_at_equal(char *str);
int		ft_cntdict_export(t_dict_value **dict);
int		ft_cntdictmain(t_dict *dict);
int		ft_findstr(char *str, char *find, int len);

/*cd*/
// void	ft_cd(char **cmd);
void	ft_cd(char **cmd, t_dict *dict);

/*pwd*/
void	ft_pwd(void);

/*echo*/
// void	ft_echo(char **str);
void	ft_echo(char **cmd , int fd_out);

/*unset*/
void	ft_unset(char **cmd, t_dict **dict);

/* env */
t_dict			*ft_getenv(char **env);
t_dict_value**	ft_getvalue_env(char **env);
t_dict_value **ft_get_value(char **str, t_dict *dict);
// t_dict_value **ft_get_value(char **str, t_dict *dict, int start);

/*export*/
void	ft_export(char **cmd, t_dict **dict);
void	ft_printvalue_ep(char **env);
void	ft_lstascend(t_dict *dict);
void	ft_swap(t_dict **dict);
int		ft_cnt_repeat(char **str, t_dict *dict);

// t_dict	*ft_addvalueexport(char **av, char **env);
void	ft_addvalueexport(char **av, t_dict *dict);
// t_dict	*ft_addvalueexport(char **av, t_dict *dict);
// t_dict	*ft_addvalueexport(char **av, t_dict *dict);
void	ft_prtexport(t_dict	*dict);
/*env*/
// void	ft_env(t_data *data);
// void	ft_env(char **env);
void	ft_env(t_dict *new_dict);

void	ft_exit(char **cmd, t_dict *dict);
/*prtlinklist*/
void	ft_prtdict(t_dict	*dict);
void	ft_prtdict_value(t_dict_value	**tmp_value);


/*prt_err*/
void	ft_prterr_builtins(int mode, char *cmd, char *str, int err);
void	ft_prterr_builtins(int mode, char *cmd, char *str, int err);

/*free*/
void	ft_freedict(t_dict **dict);
#endif