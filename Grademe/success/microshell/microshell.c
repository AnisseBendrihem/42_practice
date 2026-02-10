#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


void error(char *s)
{
    while(*s)
        write(2,s++,1);
}
int cd(char **argv,int i)
{
    if(i != 2)
    {
        error("error: cd: bad arguments\n");
        return(1);
    }
    if(chdir(argv[1]) == -1)
    {
        error("error: cd: cannot change directory to ");
        error(argv[1]);
        error("\n");
        return(1);
    }
    return(0);
}

void set_pipe(int has_pipe,int *fd,int end)
{
    if(has_pipe && dup2(fd[end],end) == -1)
    {
        error("error: fatal\n");
        exit(1);
    }
    else if(has_pipe && (close(fd[0]) == -1 || close(fd[1]) == -1))
    {
        error("error: fatal\n");
        exit(1);
    }
}
int exec(char **argv,char **envp,int i,int has_pipe)
{
    int status;
    int fd[2];
    int pid;
    if(!has_pipe && !strcmp(*argv,"cd"))
        return(cd(argv,i));
    if(has_pipe && pipe(fd) == -1)
    {
        error("error: fatal\n");
        exit(1);
    }
    pid = fork();
    if(pid == -1)
    {
        error("error: fatal\n");
        exit(1);
    }
    if(pid == 0)
    {
        argv[i] = 0;
        set_pipe(has_pipe,fd,1);
        if(!strcmp(*argv,"cd"))
            exit(cd(argv,i));
        if(execve(*argv,argv,envp) == -1)
        {
            error("error: cannot execute ");
            error(argv[0]);
            error("\n");
            exit(1);
        }
    }
    waitpid(pid,&status,0);
    set_pipe(has_pipe,fd,0);
    return(WEXITSTATUS(status) && WIFEXITED(status));
}

int main(int ac, char**argv,char **envp)
{
    (void)ac;
    int i = 0;
    int status = 0;

    while(argv[i])
    {
        argv += i+1;
        i = 0;
        while(argv[i] && strcmp(argv[i],"|") && strcmp(argv[i],";"))
            i++;
        if(i)
            status = exec(argv,envp,i,argv[i] && !strcmp(argv[i],"|"));
    }
    return(status);
}