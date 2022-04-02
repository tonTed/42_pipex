/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:26:20 by tonted            #+#    #+#             */
/*   Updated: 2022/03/13 12:56:42 by tonted           ###   ########.fr       */
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
	return (NULL);
}

int	try(int argc, char **argv)
{
	printf(BBLU "--- TRY ZONE ---\n" RESET);
	int	fd[2];

	if (pipe(fd))
		return (EXIT_FAILURE);
	printf(RED "fd[0]: %d - fd[1]: %d\n" RESET, fd[0], fd[1]);
	pid_t	id = fork();
	if (id < 0)
		return (EXIT_FAILURE);

	/*
		fd[0] : read
		fd[1] : write
	*/
	if (id == 0)	// child process
	{
		printf(CYN "Child process -> id: %d\n" RESET, id);
		char	str[100];

		close(fd[1]);
		read(fd[0], str, 100);
		printf("children > %s\n", str);
		close(fd[0]);
	}
	else			// parent process
	{
		printf(YEL "Parent process -> id: %d\n" RESET, id);
		close(fd[0]);
		write(fd[1], "Parent: Hello 42", strlen("Parent: Hello 42"));
	}
	return (EXIT_SUCCESS);
}

int	exec_cmd(char **path_cmd, char args_cmd)
{
	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[], char *envp[])
{
	t_pipex	vars;
	
	// if (parsing(argc, argv, envp, &vars))
	// 	return (EXIT_FAILURE);
	vars.path_bin = get_path_bin(envp);

	char	*path_exec;

	int	fd_out = open(argv[i_file_out(argc)], O_CREAT | O_WRONLY);

	
	
	int fd[2];
	pipe(fd);
	if (pipe(fd))
		return (EXIT_FAILURE);

	pid_t id = fork();
	if (id == 0)
	{
		char	*args_exec[] = {argv[2], argv[1], NULL};
		path_exec = get_path_exec(vars.path_bin, argv[2]);
		if (!path_exec)
			printf(">>>>> %s\n", strerror(errno));
		else
			execve(path_exec, args_exec, NULL);
	}
	// first exec

	// second exec

	// }
	// TODO free
	// free(path_bin);
	

	// free_end(&vars);
	return (0);
}
