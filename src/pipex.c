/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:26:20 by tonted            #+#    #+#             */
/*   Updated: 2022/04/10 08:34:56 by tonted           ###   ########.fr       */
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
#include "errors.h"

void	open_output(t_pipex *vars, int argc, char **argv)
{
	vars->fd_array[i_fd_out(argc)] = open(argv[i_fd_out(argc)], O_CREAT | O_WRONLY);
	if (vars->fd_array[i_fd_out(argc)] == -1)
	{
		free_init(vars);
		exit_errno(errno);
	}
}

bool	last_cmd(int i, int cmd)
{
	return (i + 1 == cmd);
}

pid_t	fork_execute(t_pipex vars, char **argv, int argc)
{
	pid_t 	id;
	int		i;

	i = 0;
	while (i < vars.cmds)
	{		
		if(last_cmd(i, vars.cmds))
			open_output(&vars, argc, argv); 
		id = fork();
		if (id == 0)
		{	
			dup2(fd_read_end(&vars.fd_array[i * 2]), STDIN_FILENO);
			dup2(fd_write_end(&vars.fd_array[i * 2]), STDOUT_FILENO);
			execve(get_path_exec(vars.path_bin, argv[i + 2]),
				ft_split(argv[i + 2], ' '), NULL);
			perror(strerror(errno));
			exit(1);
		}
		else
			close(fd_write_end(&vars.fd_array[i * 2]));
		i++;
	}
	return (id);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	vars;
	int i = 0;

	if (argc < 5)
		exit_mess(ERR_ARGS_LESS);
	// if (is_here_doc(argv[1]))
	// 	here_doc();
	init(&vars, argc, argv, envp);
	waitpid(fork_execute(vars, argv, argc), NULL, 0);
	free_init(&vars);
	return (0);
}
