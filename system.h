/*system.h - is a libruary to interacting with system
 *SamOS - is a my OS, that I don't created...
 */
#if !defined(SYSTEM_H)
#define SYSTEM_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//#include <sys/stat.h>
//#include <sys/types.h>

#if defined(_WIN32) || defined(_WIN64)
  #include <windows.h>
  #include <shellapi.h>
  #include <processthreadsapi.h>
  #include <mmsystem.h>
  //#define STAT_FUNC stat
#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__ANDROID__)
  #include <unistd.h>
  #include <sys/wait.h>
  #include <errno.h>
  #include <termios.h>
  #include <fcntl.h>
  #define STAT_FUNC stat
//#elif defined(__SamOS__)
  //#include <samos/system.h>
  //system("#okak");
#else
  #warning "You are using an operating system that is not supported by this library because there is no suitable library for you (although you can just skip this)"
#endif

#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION_TESTING 4

#if VERSION_TESTING != 0
  #warning "This is test version, and functions is not stable!"
#endif

uint8_t arch(void);
uint8_t os(void);
uint8_t type_os(void);
uint8_t comp(void);
uint8_t lang(void);
void cvoid();
void input(char *str, size_t size);
uint8_t triple_print(const char *str1, const char *str2, const char *str3, FILE *stream);
uint8_t double_print(const char *str1, const char *str2, FILE *stream);
void delay(long double second);
void delay_not_restrictions(long double second);
/*void command(char *main_command, size_t buf_size, const char *argument1, const char *argument2, const char *argument3, const char *argument4, const char *argument5, const char *argument6);*/
//void command(char *commandd);
uint8_t msg_print(int8_t level, const char *msg, uint8_t action);
//void init_cpuinfo(void);
void clear_screen(void);
uint8_t conf_user(const char *msg, uint8_t choise);
void name_user(char *save_name, size_t size);
void password_user(char *save_password, size_t size);
//int copy(const char *full_path_from, const char *full_path_to);
//int move(const char *full_path_from, const char *full_path_to);
//int remove(const char *full_path_to_remove, int o);
int8_t verification_name_user(const char *name, size_t size);
int8_t verification_password_user(const char *password, size_t size);
uint8_t print_with_delay(const char *text, long double sec);
void print_in_color(const char *text, uint8_t color);
void fprint_in_color(const char *text, uint8_t color, FILE *stream);
uint64_t urand64(void);
uint32_t urand32(void);
uint16_t urand16(void);
uint8_t urand8(void);
uint64_t urand_in_range(uint64_t n, uint64_t m);
int64_t rand64(void);
int32_t rand32(void);
int16_t rand16(void);
int8_t rand8(void);
int64_t rand_in_range(int64_t n, int64_t m);
//uint8_t kbhit(void);

//extern unsigned char inited_cpuinfo;
//extern unsigned char error_out;
extern uint8_t seedd;

#define CRITICAL_ERR -2
#define ERR -1
#define MSG 1
#define WARN 0
#define INFO 2
#define COMMAND 3

#define NO_SHUTDOWN 0
#define SHUTDOWN 1

/*#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37
#define BRIGHTBLACK 90
#define BRIGHTRED 91
#define BRIGHTGREEN 92
#define BRIGHTYELLOW 93
#define BRIGHTBLUE 94
#define BRIGHTMAGENTA 95
#define BRIGHTCYAN 96
#define BRIGHTWHITE 97*/

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7
#define BRIGHTBLACK 8
#define BRIGHTRED 9
#define BRIGHTGREEN 10
#define BRIGHTYELLOW 11
#define BRIGHTBLUE 12
#define BRIGHTMAGENTA 13
#define BRIGHTCYAN 14
#define BRIGHTWHITE 15

#define BUF_SIZE 4096

//#define PATH_POSIX "/" // To function copy, move and remove
//#define PATH_WINDOWS "\\" // To function copy, move and remove

#endif
