/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:26:20 by tonted            #+#    #+#             */
/*   Updated: 2022/01/21 01:34:23 by tonted           ###   ########.fr       */
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

#define PATH "PATH="
#define LEN_PATH 5
#define SEP_PATH ':'

char	**path_bin(char **envp)
{
	while (*envp)
	{
		if (!(ft_strncmp(PATH, *envp, LEN_PATH)))
			return(ft_split(&(*envp)[LEN_PATH], SEP_PATH));
		envp++;
	}
	return (NULL);
}

int main(int argc, char *argv[], char *envp[])
{
	char	**path;

	// TODO message for minimum 4 args
	(void)argc;
	// if (argc < 5)
	// 	return (EXIT_FAILURE);
	path = path_bin(envp);
	ft_puttabstr_fd(path, 1);
	ft_puttabstr_fd(&argv[1], 1);

	
	// TODO free
	free(path);
	return (0);
}
