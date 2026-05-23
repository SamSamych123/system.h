/*system.h - is a libruary to interacting with system
 *SamOS - is a my OS, that I don't created...
 */
#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
//#include <sys/stat.h>
//#include <sys/types.h>

#if defined(_WIN32) || defined(_WIN64)
  #include <windows.h>
  #include <shellapi.h>
  #include <processthreadsapi.h>
  #define STAT_FUNC stat
#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__ANDROID__)
  #include <unistd.h>
  #include <sys/wait.h>
  #define STAT_FUNC stat
//#elif defined(__SamOS__)
  //#include <samos/system.h>
  //system("#okak");
#else
  #warning "You are using an operating system that is not supported by this library because there is no suitable library for you (although you can just skip this)"
#endif

#define VERSION_MAGOR 0
#define VERSION_MINOR 1
#define VERSION_TESTING 1

#warning "This is test version, and functions is not stable"
int arch(void);
int os(void);
int comp(void);
//int lang(void);
void delay(double millisecond);
/*void command(char *main_command, size_t buf_size, const char *argument1, const char *argument2, const char *argument3, const char *argument4, const char *argument5, const char *argument6);*/
void command(char *commandd);
void msg_print(int level, const char *msg, int action);
void init_cpuinfo(void);
void clear_screen(void);
int conf_user(const char *msg, int choise);
void name_user(char *save_name);
void password_user(char *save_password);
//void copy(const char *full_path_to_copy, const char *full_path_to_paste);
//void remove(const char *full_path_to_remove, int o);
int verification_name_user(const char *name);
int verification_password_user(const char *password);
void print_with_delay(const char *text, int sec);

unsigned char inited_cpuinfo = 0;
unsigned char error_out = 0;

#define CRITICAL_ERR -2
#define ERR -1
#define MSG 1
#define WARN 0
#define INFO 2
#define COMMAND 3

#define NO_SHUTDOWN 0
#define SHUTDOWN 1

#endif
