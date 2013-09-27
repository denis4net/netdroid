#ifndef  SHELL_H
#define SHELL_H

/*size of command, uart rx buffer size */
#define CMD_SIZE 1024

/*init shell*/
int shell_init( int  (*handler)(const char*));

/* byte received*/
void usart_irq_handler();

#endif