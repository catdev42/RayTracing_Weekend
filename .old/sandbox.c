#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int		g_pid;

void	bad_infinite(void)
{
	while (1)
		;
}

int	check_status(int status, int seconds)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGALRM)
			printf("Bad function: timed out after %i seconds", seconds);
		return (WTERMSIG(status));
	}
	return (0);
}

void	handle_alarm(int sig)
{
	if (sig == SIGALRM)
		kill(g_pid, SIGKILL);
}

int	sandbox(void (*f)(void), int seconds)
{
	int					status;
	int					pid;
	struct sigaction	s;

	s.sa_handler = handle_alarm;
	sigaction(SIGALRM, &s, NULL);
	pid = fork();
	g_pid = pid;
	if (pid == 0)
	{
		// s.sa_handler = SIG_DFL;
		// sigaction(SIGALRM, &s, NULL);
		// alarm(seconds);
		f();		
		exit(0);
	}
	alarm(seconds);
	if (waitpid(pid, &status, 0) < 0)
		printf("waitpid didn't like it\n");
	if (check_status(status, seconds))
		return (1);
	return (0);
}

int	main(void)
{
	int returned_signal;
	returned_signal = sandbox(bad_infinite, 1);
	// strsignal(returned_signal+127);
	// printf("%s\n", strerror(14));
	printf("%i\n", returned_signal);
}