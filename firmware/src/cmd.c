#include "enginectl.h"
#include "uart.h"
#include "servoctl.h"
#include "cmd.h"

extern int sscanf(const char *str, const char *fmt, ...);
extern int sprintf(char **out, const char *format, ...);

static cmd_status_t cmd_help(const char* );

cmd_t commands[] = {
	{ "help", "show help message", cmd_help }
};
#define COMMAND_SIZE sizeof(commands)/sizeof(cmd_t)

static cmd_status_t cmd_stub(const char* command)
{
	return CMD_SUCCESSFUL; /* on success */
}

static cmd_status_t cmd_help(const char* command)
{
	usart_send_str("\r\n\r\nWebDroid available commands:\n\r");
	for(int i=0; i<1; i++)
	{
		usart_send_str(commands[i].name);
		usart_send_str("\t\t\t");
		usart_send_str(commands[i].description);
		usart_send_str("\n\r");
	}
	
	usart_send_str("\n\r");
	return CMD_SUCCESSFUL;
}

static int _cmd_cmp(const char* full_command, const char* command_name)
{
	int i;
	for(i=0; command_name[i]!=0 && full_command[i]!=' '; i++)
	{
		if(full_command[i]-command_name[i]!=0)
			return full_command[i]-command_name[i];
	}
	
	return 0;
}

/*****************************************************************************************/

/**
 * @brief Run command and return status
 * @param command command string and its parameters
 */
cmd_status_t cmd_run(const char* command)
{
	for(int i=0; i<COMMAND_SIZE; i++) {
				if ( !_cmd_cmp(commands[i].name, command))
					return commands[i].function(command);
	}
	return CMD_UNDEFINED;;
}

/**
 * @brief Check command availability
 * @param  command string with command for check
 */
int cmd_check(const char* command)
{
	for(int i=0; i<COMMAND_SIZE; i++) {
				if ( !_cmd_cmp(commands[i].name, command))
					return 1;
	}	
	return 0;
}
