/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:26:20 by tonted            #+#    #+#             */
/*   Updated: 2022/03/09 10:32:17 by tonted           ###   ########.fr       */
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
#include <string.h>
#include <errno.h>

#define PATH "PATH="
#define LEN_PATH 5
#define SEP_PATH ':'

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
		i++;
	}
	return (NULL);
}

int main(int argc, char *argv[], char *envp[])
{
	char	**path_bin;
	char	*path_exec;
	char	*args_exec[] = {"ls", "-l", NULL};
	char	**env_exec = {NULL};

	// TODO message for minimum 4 args
	(void)argc;
	// if (argc < 5)
	// 	return (EXIT_FAILURE);
	path_bin = get_path_bin(envp);
	path_exec = get_path_exec(path_bin, "ls");
	printf("%s\n", path_exec);
	if (!path_exec)
		printf(">>>>> %s\n", strerror(errno));
	else
		execve(path_exec, args_exec, env_exec);

	
	// TODO free
	free(path_bin);
	return (0);
}
