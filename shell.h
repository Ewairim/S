#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <string.h>
int _myinfo(info_t *data);
int main(int argc, char **argv, char **envp);
int _env(info_t *info);
#endif SHELL_H
