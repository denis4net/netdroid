#ifndef  SHELL_H
#define SHELL_H

/*size of command, uart rx buffer size */
#define CMD_SIZE 64

/*init shell*/
int shell_init();

void shell_run();

#endif