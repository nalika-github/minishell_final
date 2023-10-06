/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:33:50 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 06:12:45 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

typedef struct s_rdr t_rdr;
typedef struct s_data t_data;
typedef struct s_env t_env;
typedef struct s_rdr t_rdr;
typedef struct s_list t_list;
typedef struct s_minishell t_minishell;

void	ft_initdata(t_minishell *ms, char **env);

void branch_parent(t_minishell *ms, t_list *tb_lst, int *fd_read);

void	ft_mainexec(t_minishell *ms);
char	**ft_findpath(char **env);
// void	ft_execute(t_list *tb_lst, char **env, int nbr_cmd);
void ft_execute(t_minishell *ms, t_list *tb_lst);
// void ft_execute(t_list *tb_lst, t_dict *dict, int nbr_cmd);
// void	ft_initdata_exec(t_list *tb_lst);
void	ft_initdata_exec(t_list *tb_lst, char **env);
int		ft_check_buildin(char **cmd);
void	ft_prt_type(int type);
/* ft_getfile */
void	ft_getfd(t_list *tb_lst);
int	ft_getfd_in(t_list *tb_lst);
int	ft_getfd_out(t_list *tb_lst);
int	ft_cnt_infile(t_list *table_list);
int	ft_cnt_outfile(t_list *table_list);
int	ft_cnt_heredoc(t_list *table_list);

/*ft_cnt_execute*/
int		ft_cntfile(t_rdr *file);
int		ft_cntcmd(t_list *table_list);
void	ft_countexec(t_list *tb_lst);

/*ft_check_name*/
int	ft_checkfile(t_list *tb_lst);
void ft_dup2(t_list *tb_lst, int *fd_tmp_read, int nbr_cmd);
/*ft_execve*/
void	ft_execvecmd(char **cmd, char **path, char **tmp_env);
void	ft_execvepath(char **path, char **tmp_env);
void	ft_parent(t_list *tb_lst,int *fd_tmp_read, int nbr_cmd , char **env);
// void	ft_child(t_list *tb_lst, int nbr_cmd, char **env, int *fd_tmp_read);
void	branch_child(t_minishell  *ms, t_list *tb_lst, int *fd_tmp_read);
// void	ft_child(t_list *tb_lst, int nbr_cmd, t_dict *dict, int *fd_tmp_read);
// void	ft_parent(t_list *tb_lst,int *fd_tmp_read, int nbr_cmd , t_dict *dict);
/*ft_execute*/
// void ft_dup2(int i, t_list *tb_lst, int *fd_tmp_read, int nbr_cmdd);
int		ft_check_builtin(char **cmd);
// void	ft_waitpid(t_list *tb_lst_cpy);
void ft_waitpid(t_minishell *ms, t_list *tb_lst_cpy);
void ft_close_pipe(t_minishell *ms, t_list *tb_lst);

void	ft_prterr(int mode, char *txt);
// void	ft_prterr(int mode);
void	ft_prterrexec(char *str, int errno, int mode);

int	ft_findchar(char *s1, char s2);

/*ft_heredoc*/
int	ft_heredoc(t_list *table_list, int cnt_heredoc);

/*ft_unset*/
// void	ft_unset(char **cmd, t_dict *dict);

// void	ft_heredoc(int ac, char **av);
#endif
