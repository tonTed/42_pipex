/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:26:20 by tonted            #+#    #+#             */
/*   Updated: 2022/04/04 15:42:35 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* know functions
** open
** read
** close
** write
** malloc
** free
** exit
*/

/* unknow functions <unistd.h>
** https://www.gladir.com/CODER/CLINUX/referenceunistd.htm
** 
** int access(const char *pathname, int mode);
** Cette fonction permet de vérifier le mode d'accès d'un fichier.
**
** int unlink(const char *pathname);
** Cette fonction permet de supprimer un ou plusieurs fichiers.
**
** int pipe(int fildes[2]);
** Cette fonction permet d'effectuer la création d'un canal entre processus.
** 
** int dup(int fildes);
** Cette fonction permet de dupliquer le descripteur de fichier.
**
** int dup2(int fildes, int fildes2);
** Cette fonction permet de dupliquer le descripteur de fichier dans un autre fichier de descripteur connu.
**
** int execve(const char *path, char *const argv[], char *const envp[]);
** Cette fonction permet d'exécuter un processus enfant avec un tableau d'arguments et ses variables d'environnement.
**
** pid_t fork(void);
** Cette fonction permet de créer un processus fils ou enfant.
**
** void perror(const char *s);
** Cette procédure envoi un message d'erreur sur la sortie standard d'erreur.
**
** char *strerror(int noerr);
** Cette fonction pointe sur le message d'erreur correspondant à «noerr».
**
** unknow functions <sys/wait.h>
** pid_t waitpid(pid_t pid, int *status, int options);
** Cette fonction permet de mettre en attente jusqu'à la fin d'un processus fils ayant un numéro de processus spécifié (PID).
**
** pid_t wait(int *stat_loc);
** Cette fonction permet de mettre en attente jusqu'à la fin d'un processus fils.
*/

#include "pipex.h"

char	**get_path_bin(char **envp)
{
	while (*envp)
	{
		if (!(ft_strncmp(PATH, *envp, LEN_PATH)))
			return(ft_split(&(*envp)[LEN_PATH], SEP_PATH));
		envp++;
	}
	return (NULL);
}

char	*get_path_exec(char **path_bin, char *cmd)
{
	u_int32_t	i;
	char		*cmd_path;
	char		*tmp;

	if (ft_ischarinstr('/', cmd))
		return(cmd);	
	i = 0;
	while (path_bin[i])
	{
		tmp = ft_strjoin(path_bin[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (ft_strdup("wtf"));
}

int	set_fd_array(t_pipex *vars, int cmds){

	int	i;
	int fds[2];

	vars->fd_array = (int *)malloc(sizeof(int) * (vars->cmds) * 2);
	i = 1;
	while (--cmds)
	{
		pipe(fds);
		vars->fd_array[i++] = fds[1];
		vars->fd_array[i++] = fds[0];
	}
	return(i);
}

int count_cmds(int argc)
{
	return (argc - 3);
}

void	exit_mess(int err_no)
{
	perror(strerror(err_no));
	exit(err_no);
}

void	init(t_pipex *vars, int argc, char **argv, char **envp)
{
	int last_index;

	vars->cmds = count_cmds(argc);
	last_index = set_fd_array(vars, vars->cmds);
	if (vars->fd_array[5] == -1)
		exit_mess(errno);
	vars->path_bin = get_path_bin(envp);
	vars->fd_array[0] = open(argv[i_file_in()], O_RDONLY);
	vars->fd_array[last_index] = open(argv[i_file_out(argc)], O_CREAT | O_WRONLY);
}

int	read_in(int fds[2])
{
	return (fds[0]);
}

int	write_out(int fds[2])
{
	return (fds[1]);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	vars;
	pid_t 	id;
	int i = 0;
	char	*path_exec;
	int fd_in;
	int fd_out;

	init(&vars, argc, argv, envp);
	i = 0;
	while (i < vars.cmds)
	{		
		id = fork();
		fd_in = read_in(&vars.fd_array[i * 2]);
		fd_out =  write_out(&vars.fd_array[i * 2]);
		
		if (id == 0)
		{
			
			char	*args_exec[] = {argv[i + 2], NULL}; 

			path_exec = get_path_exec(vars.path_bin, argv[i + 2]);
			dup2(fd_in, STDIN_FILENO);
			dup2(fd_out, STDOUT_FILENO);
			execve(path_exec, args_exec, envp);
			perror(strerror(errno));
			exit(1);
		}
		else
		{
			close(fd_out);
			close(fd_in);
		}
		i++;
	}
	waitpid(id, NULL, 0);
	ft_puttabint_fd(vars.fd_array, 6, 1);
	return (0);
}
