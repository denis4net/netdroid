#ifndef CMD_H
#define CMD_H

typedef enum { CMD_SUCCESSFUL, CMD_UNDEFINED, CMD_ERROR, CMD_EXCEPTION } cmd_status_t; 

cmd_status_t cmd_run(const char* command);
int cmd_check(const char* command);

typedef struct
{
	const char* name;
	const char* arguments;
	const int (*function)(const char*);
	
} cmd_t;


#endif
