#include "cmd_runner.h"

int cmd_handler(const char* cmd)
{
  #ifdef DEBUG
    usart_send_str(cmd);
   #endif
  return 0;
}