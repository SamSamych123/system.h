/*system.h - is a libruary to interacting with system
 *SamOS - is a my OS, that I don't created...
 */

#include "system.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*Arch - is a function to find architecture processor
 *All architectures: x86-64 = 0, i386 (x86) = 1, ARM = 2, ARM64 = 3, RISC V: 32 = 4, 64 = 5, 128 = 6, other = 255
 */

int arch(void) {
  #if defined(__x86_64__)
    return 0;
  #elif defined(__i386__)
    return 1;
  #elif defined(__arm__)
    return 2;
  #elif defined(__aarch64__)
    return 3;
  #elif defined(__riscv)
    #if __riscv_xlen == 32
      return 4;
    #elif __riscv_xlen == 64
      return 5;
    #elif __riscv_xlen == 128
      return 6;
    #endif
  #else
    return 255;
  #endif
}

/*Type OS - is a function to find type OS
 *All OS: Windows systems = 0, UNIX base systems = 1, FreeBSD systems = 2, ToyOS = 3, other = 255
 */
int type_os(void) {
  #if defined(_WIN32)
    return 0;
  #elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__ANDROID__)
    return 1;
  #elif defined(__FreeBSD__)
    return 2;
  #elif defined(__toyos__)
    return 3;
  //#elif defined(__SamOS__)
    //return 254;
  #else
    return 255;
  #endif
}


/*OS - is a function to find type OS
 *All OS: Windows systems = 0, Linux systems = 1, Apple systems = 2, Android systems = 4, UNIX base systems = 3, FreeBSD systems = 5, ToyOS = 6, other = 255
 */
int os(void) {
  #if defined(_WIN32)
    return 0;
  #elif defined(__linux__)
    return 1;
  #elif defined(__APPLE__)
    return 2;
  #elif defined(__unix__)
    return 3;
  #elif defined(__ANDROID__)
    return 4;
  #elif defined(__FreeBSD__)
    return 5;
  #elif defined(__toyos__)
    return 6;
  //#elif defined(__SamOS__)
    //return 254;
  #else
    return 255;
  #endif
}

/*Comp - is a function to find compiler
 *All compilers: GCC = 0, Clang = 1, Microsoft C = 2, other = 255
 */
int comp(void) {
  #if defined(__GNUC__)
    #if !defined(__clang__)
      return 0;
    #else
      return 1;
    #endif
  #elif defined(_MSC_VER)
    return 2;
  #else
    return 255;
  #endif
}

/*Lang - is a function to find language programm
 *All languages: C = 0, C++ = 1, other = 255
 *This function is not working, but I'm don't hurry programming this function
 */
/*int lang(void) {
  #if defined(__c)
    return 0;
  #elif defined(__cplusplus)
    return 1;
  #else
    return 255;
  #endif
}*/

/*Delay - is a function to sleep programm*/
void delay(double millisecond) {
  double second_w = millisecond * 1000;
  double second_u = millisecond * 1000000;
  #if defined(_WIN32)
    Sleep((DWORD)(second_w));
  #elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__ANDROID__)
    usleep((useconds_t)(second_u));
  //#elif defined(__SamOS__)
    //sleep(second);
  #else
    for (unsigned long int x = 0; x < (unsigned long int)second_u; x++) {
      //Okak, okak-kak, and programming time in time table
      sleep(1);
    }
  #endif
}

/*Print with delay - is a function for printing letters with a certain delay.*/
void print_with_delay(const char *text, int sec) {
  unsigned int i = 0;
  for(i = 0; i < strlen(text); i++) {
    printf("%c", text[i]);
    delay((double)sec);
  }
}

/*Command - is a function to execute command*/
/*void command(char *command,, size_t buf_size, const char *arg1, const char *arg2, const char *arg3, const char *arg4, const char *arg5, const char *arg6) {
    snprintf(command, buf_size, "%s %s %s %s %s %s", arg1, arg2, arg3, arg4, arg5, arg6);
    system(command);
}*/

void command(char *commandd) {
  system(commandd);
}

/*Msg_print - is a function to print from varible "msg" with level
 *All levels: critical error = -2, error = -1, warning = 0, msg = 1, information = 2, command = 3
 */
void msg_print(int level, const char *msg, int action) {
  if (level == CRITICAL_ERR) {
    //printf("CRITICAL ERROR: %s! Shutdown programm...", msg);
    fprintf(stderr, "CRITICAL ERROR: %s! Shutdown programm...\n", msg);
    exit(1);
  }
  else if (level == ERR) {
    if (action == NO_SHUTDOWN) {
      //printf("Error: %s!", msg);
      fprintf(stderr, "Error: %s!\n", msg);
    }
    else if (action == SHUTDOWN) {
      //printf("Error: %s! Shutdown programm...", msg);
      fprintf(stderr, "Error: %s! Shutdown programm...\n", msg);
      exit(1);
     }
  }
   else if (level == WARN) {
    printf("Warning: %s\n", msg);
  }
  else if (level == MSG) {
    printf("%s\n", msg);
  }
  else if (level == INFO) {
    printf("Info: %s\n", msg);
  }
  else if (level == COMMAND) {
    printf("Execute command '%s'...\n", msg);
    system(msg);
  }
  else {
    fprintf(stderr, "Error: not found action!\n");
  }
}

/*Init_cpuinfo - is a function to save information processor*/
void init_cpuinfo(void) {
  #if defined(_WIN32)
   #error "error: 'init_cpuinfo' is not working on Windows!"
  #elif defined(__linux__) || defined (__Unix__)
    system("lscpu > ~/cpuinfo.d");
    inited_cpuinfo = 1;
  #else
    #error "error: 'init_cpuinfo' is not working on your OS!"
  #endif
}

/*Clear_screen - is a function to clear screen
 *Function cleared screen from terminal
 */
void clear_screen(void) {
  printf("\033[2J\033[H");
}

/*Conf_user - is a function to scan strean "stdin" to save user confirmation (y - yes/n - no)*/
int conf_user(const char *msg, int choise) {
  char input_conf;
  if (choise == 0) {
    printf("%s [Y, n]: ", msg);
    scanf("%1c", &input_conf);
    if (input_conf == 'n' || input_conf == 'N') {
      return 1;
    }
    else {
      return 0;
    }
  }
  if (choise == 1) {
    printf("%s [y, N]: ", msg);
    scanf("%1c", &input_conf);
    if (input_conf == 'y' || input_conf == 'Y') {
      return 1;
    }
    else {
      return 0;
    }
  }
}


/*Name_user - is a function to print text "Enter your new name (max: 30 symbols): ", scaning stdin (max symbols: 30 symbols) and writed in developer varible through pointer "name".
 *Warning! Please, make a varible to value 31 (example: "char new_main[31];") or dynamic varible! Else: error "Segmentation fault", if user enter better or the same maximum leght varible.
 */
void name_user(char *save_name) {
  printf("Enter your name (max: 30 symbols): ");
  scanf("%30s", save_name);
}

int verification_name_user(const char *name) {
  char namee[31];
  printf("Enter your name (max: 30 symbols): ");
  scanf("%30s", namee);
  return strcmp(name, namee);
}

/*Name_user - is a function to print text "Enter your new name (max: 100 symbols): ", scaning stdin (max symbols: 100 symbols) and writed in developer varible through pointer "name".
 *Warning! Please, make a varible to value 101 (example: "char new_main[101];") or make dynamic varible! Else: error "Segmentation fault", if user enter better or the same maximum leght varible.
 */
void password_user(char *save_password) {
  printf("Enter your password (max: 100 symbols): ");
  scanf("%100s", save_password);
}

int verification_password_user(const char *password) {
  char passwordd[101];
  printf("Enter your password (max: 100 symbols): ");
  scanf("%100s", passwordd);
  return strcmp(passwordd, password);
}

/*
xcopy /E - copy dir
copy - copy file
del - delete file
rmdir - delete dir
*/
/*void copy(const char *full_path_to_copy, const char *full_path_to_paste) {
  if (type_os() == 1) {
    char command[100] = "cp ";
    strcpy(command, full_path_to_copy);
    strcpy(command, " ");
    strcpy(command, full_path_to_paste);
    system(command);
}

int remove(const char *full_path_to_remove, int o) {
  if (type_os() == 1) {
    if (strcmp(full_path_to_copy, ".") == 0 || strcmp(full_path_to_copy, "..") == 0) {
      if (error_out == 1) {
        perror("Error! Directory '.' or '..' is not have a action copy!");
        return -1;
      }
      else {
        return -1;
      }
    }
    if (o == 0) {
      char command[100] = "rm ";
    }
    else if {o == 1) {
      char command[100] = "rm -rf";
    }
    else {
      fprintf(stderr, "Error: not found type file!\n");
      return -1;
    }  
    strcpy(command, full_path_to_remove);
    system(command);
  }
  else if (type_os() == 0) {
    if (strcmp(full_path_to_copy, ".") == 0 || strcmp(full_path_to_copy, "..") == 0) {
      if (error_out == 1) {
        perror("Error! Directory '.' or '..' is not have a action copy!");
        return -1;
      }
      else {
        return -1;
      }
    }
    if (o == 0) {
      char command[100] = "del ";
    }
    else if {o == 1) {
      char command[100] = "rmdir /S /Q ";
    }
    else {
      fprintf(stderr, "Error: not found type file!\n");
      return -1;
    }  
    strcpy(command, full_path_to_remove);
    system(command);
  }
}*/

#ifdef __cplusplus
}
#endif
