#ifndef CMDLOG_H
#define CMDLOG_H

#include "memcached/extension_loggers.h"

//#define COMMAND_LOGGING
#define CMDLOG_INPUT_SIZE 400

/*command log stats structure */
struct cmd_log_stats {
    int bgndate, bgntime;
    int enddate, endtime;
    int file_count;
    int stop_cause; /* how stopped */
    uint32_t entered_commands;   /* number of entered command */
    uint32_t skipped_commands; /* number of skipped command */
};

void cmdlog_init(EXTENSION_LOGGER_DESCRIPTOR *logger);
void cmdlog_final(void);
int cmdlog_start(bool *already_started);
int cmdlog_stop(bool *already_stopped);
struct cmd_log_stats *cmdlog_stats(void);
bool cmdlog_write(char client_ip[], char *command);
#endif