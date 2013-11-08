#ifndef CMD_H
#define CMD_H

typedef enum { CMD_SUCCESSFUL, CMD_UNDEFINED, CMD_ERROR, CMD_EXCEPTIO } cmd_status_t; 

cmd_status_t cmd_run(const char* command);
int cmd_check(const char* command);

typedef struct
{
	char name[16];
	char description[32];
	int (*function)(const char*);
	
} cmd_t;

extern cmd_t commands[];

#endif