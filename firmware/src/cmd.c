#include "enginectl.h"
#include "uart.h"
#include "servoctl.h"
#include "cmd.h"

/**
 * @file cmd.c
 * @author Denis Vashchuk
 *
 * Command handlers implemented here.
 * @func cmd_help cmd_go_forward cmd_go_backward cmd_engines_stop cmd_turn_right cmd_turn_left
 * @param command null terminated string which contains command
 * @return command execution status
 */

extern int get_args(const char* text, int count, ...);
static cmd_status_t cmd_help(const char* );
static cmd_status_t cmd_go_forward(const char* );
static cmd_status_t cmd_go_backward(const char* );
static cmd_status_t cmd_turn_right(const char*);
static cmd_status_t cmd_turn_left(const char*);
static cmd_status_t cmd_go_forward_continuously(const char*);
static cmd_status_t cmd_engines_stop(const char*);

static cmd_t commands[] = {
		{.name="help", .arguments="show help message\0", .function=cmd_help },
		{.name="go_forward", .arguments="<time (ms)> <speed 0..100>\0", .function=cmd_go_forward },
		{.name="go_backward", .arguments="<time (ms)> <speed 0..100>\0", .function=cmd_go_backward },
		{.name="go_cont", .arguments="<speed 0..100>\0", .function=cmd_go_forward_continuously },
		{.name="engines_stop", .arguments="stop all engines\0", .function=cmd_engines_stop },
		{.name="turn_right", .arguments="<angle> <dir 0|1>\0", .function=cmd_turn_right },
		{.name="turn_left", .arguments="<angle> <dir 0|1>\0", .function=cmd_turn_left },
}; //*< available commands array, see cmd_t type definition

#define COMMAND_SIZE sizeof(commands)/sizeof(cmd_t)

static cmd_status_t cmd_help(const char* command)
{
	usart_send_str("\r\n\r\nNeuraxis available commands:\n\r");
	for(int i=0; i<COMMAND_SIZE; i++)
	{
		usart_send_str(commands[i].name);
		usart_send_str("\t\t\t\t");
		usart_send_str(commands[i].arguments);
		usart_send_str("\n\r");
	}

	usart_send_str("\n\r");
	return CMD_SUCCESSFUL;
}

cmd_status_t cmd_go_forward(const char* command )
{
	int speed, time;
	get_args(command,  2, &time, &speed);
	if(speed > 100 || speed < 0 )
		return CMD_ERROR;

	engine_go_forward(time, speed);
	return CMD_SUCCESSFUL;
}

cmd_status_t cmd_go_backward(const char*command )
{
	int speed, time;
	get_args(command,  2, &time, &speed);
	if(speed > 100 || speed < 0 )
			return CMD_ERROR;

	engine_go_backward(time, speed);
	return CMD_SUCCESSFUL;
}

static cmd_status_t cmd_go_forward_continuously(const char* command) {
	int speed;
	get_args(command,  1, &speed);
	if(speed > 100 || speed < 0 )
			return CMD_ERROR;

	engine_go_forward_continuously(speed);
	return CMD_SUCCESSFUL;

}

static cmd_status_t cmd_engines_stop(const char* command)
{
	engine_stop();
	return CMD_SUCCESSFUL;
}

static cmd_status_t cmd_turn_right(const char* command)
{
	int angle, dir;
	get_args(command,  2, &angle, &dir);

	if(dir) {
		engine_turn_right_forward(angle);
	}
	else {
		engine_turn_right_backward(angle);
	}

	return CMD_SUCCESSFUL;
}

static cmd_status_t cmd_turn_left(const char* command)
{
	int angle, dir;
	get_args(command,  2, &angle, &dir);

	if(dir) {
		engine_turn_left_forward(angle);
	}
	else {
		engine_turn_left_backward(angle);
	}

	return CMD_SUCCESSFUL;
}


static int cmd_cmp(const char* full_command, const char* command_name)
{
	int i;
	for(i=0; command_name[i] !='\0' && full_command[i]!=' '; i++)
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
		if ( !cmd_cmp( command, commands[i].name))
			return commands[i].function(command);
	}
	return CMD_UNDEFINED;
}

/**
 * @brief Check command availability
 * @param  command string with command for check
 */
int cmd_check(const char* command)
{
	for(int i=0; i<COMMAND_SIZE; i++) {
		if ( !cmd_cmp(command, commands[i].name))
			return 1;
	}	
	return 0;
}

