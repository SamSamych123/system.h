/*system.h - is a libruary to interacting with system
 *SamOS - is a my OS, that I don't created...
 */

#include "system.h"

#if defined(__cplusplus)
extern "C" {
#endif

//unsigned char inited_cpuinfo = 0;
//unsigned char error_out = 0;

/*Arch - is a function/macros to find architecture processor
 *All architectures: i386 (x86) = 0, x86-64 = 1, ARM = 2, ARM64 = 3, RISK_V_32 = 4, RISK_V_64 = 5, RISKV_128 = 6, PowerPC = 7, MIPS = 8, S390X = 9, other = 255
 */

#if defined(__i386__) || defined(_M_IX86)
  #define ARCH 0
#elif defined(__x86_64__) || defined(_M_X64)
  #define ARCH 1
#elif defined(__arm__) || defined(_M_ARM)
  #define ARCH 2
#elif defined(__aarch64__) || defined(_M_ARM64)
  #define ARCH 3
#elif defined(__riscv) && __riscv_xlen == 32
  #define ARCH 4
#elif defined(__riskv) && __riscv_xlen == 64
  #define ARCH 5
#elif defined(__riskv) && __riscv_xlen == 128
  #define ARCH 6
#elif defined(__powerpc__)
  #define ARCH 7
#elif defined(__mips__)
  #define ARCH 8
#elif defined(__s390x__)
  #define ARCH 9
#else
  #define ARCH 255
#endif

int arch(void) {
  #if defined(__i386__) || defined(_M_IX86)
    return 0;
  #elif defined(__x86_64__) || defined(_M_X64)
    return 1;
  #elif defined(__arm__) || defined(_M_ARM)
    return 2;
  #elif defined(__aarch64__) || defined(_M_ARM64)
    return 3;
  #elif defined(__riscv) && __riscv_xlen == 32
    return 4;
  #elif defined(__riskv) && __riscv_xlen == 64
    return 5;
  #elif defined(__riskv) && __riscv_xlen == 128
    return 6;
  #elif defined(__powerpc__)
    return 7;
  #elif defined(__mips__)
    return 8;
  #elif defined(__s390x__)
    return 9;
  #els
    return 255;
  #endif
}

/*Type OS - is a function/macros to find type OS
 *All OS: Windows systems = 0, UNIX base systems = 1, FreeBSD systems = 2, ToyOS = 3, other = 255
 */

#if defined(_WIN32) || defined(_WIN64)
  #define TYPE_OS 0
#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__ANDROID__)
  #define TYPE_OS 1
#elif defined(__FreeBSD__)
  #define TYPE_OS 2
#elif defined(__toyos__)
  #define TYPE_OS 3
//#elif defined(__SamOS__)
  //#define TYPE_OS 254
#else
  #define TYPE_OS 255
#endif

int type_os(void) {
  #if defined(_WIN32) || defined(_WIN64)
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


/*OS - is a function/macros to find type OS
 *All OS: Windows systems = 0, Linux systems = 1, Mac OS = 2, Other Apple systems = 3, UNIX base systems = 4, Android systems = 5, FreeBSD systems = 6, ToyOS = 7, other = 255
 */

#if defined(_WIN32) && !defined(_WIN64)
  #define OS 0
#elif defined(_WIN32) && defined(_WIN64)
  #define OS 1
#elif defined(__linux__)
  #define OS 2
#elif defined(__APPLE__) && defined(__MACH__)
  #define OS 3
#elif defined(__APPLE__) && !defined(__MACH__)
  #define OS 4
#elif defined(__unix__)
  #define OS 5
#elif defined(__ANDROID__)
  #define OS 6
#elif defined(__FreeBSD__)
  #define OS 7
#elif defined(__toyos__)
  #define OS 8
//#elif defined(__SamOS__)
  //#define OS 254
#else
  #define OS 255
#endif

int os(void) {
  #if defined(_WIN32) && !defined(_WIN64)
    return 0;
  #elif defined(_WIN32) && defined(_WIN64)
    return 1;
  #elif defined(__linux__)
    return 2;
  #elif defined(__APPLE__) && defined(__MACH__)
    return 3;
  #elif defined(__APPLE__) && !defined(__MACH__)
    return 4;
  #elif defined(__unix__)
    return 5;
  #elif defined(__ANDROID__)
    return 6;
  #elif defined(__FreeBSD__)
    return 7;
  #elif defined(__toyos__)
    return 8;
  //#elif defined(__SamOS__)
    //return 254;
  #else
    return 255;
  #endif
}

/*Comp - is a function/macros to find compiler
 *All compilers: GCC = 0, Clang = 1, Vusial Studio C = 2, MinGW32 = 3, MinGW64 = 4, Tiny C = 5, ICC (Intel C Compiler) = 6, Pelles C = 7, other = 255
 */

#if defined(__GNUC__) &&  !defined(__clang__)
  #define COMP 0
#elif defined(__GNUC__) &&  defined(__clang__)
  #define COMP 1
#elif defined(_MSC_VER)
  #define COMP 2
#elif defined(__MINGW32__) && !defined(__MINGW64__)
  #define COMP 3
#elif defined(__MINGW32__) && defined(__MINGW64__)
  #define COMP 4
#elif defined(__TINYC__)
  #define COMP 5
#elif defined(__INTEL_COMPILER)
  #define COMP 6
#elif defined(__POCC)
  #define COMP 7
#else
  #define COMP 255
#endif

int comp(void) {
  #if defined(__GNUC__) && !defined(__clang__)
    return 0;
  #elif defined(__GNUC__) && defined(__clang__)
    return 1;
  #elif defined(_MSC_VER)
    return 2;
  #elif defined(__MINGW32__) && !defined(__MINGW64__)
    return 3;
  #elif defined(__MINGW32__) && defined(__MINGW64__)
    return 4;
  #elif defined(__TINYC__)
    return 5;
  #elif defined(__INTEL_COMPILER)
    return 6;
  #elif defined(__POCC)
    return 7;
  #else
    return 255;
  #endif
}

/*Lang - is a function/macros to find language programm
 *All languages: C = 0, C++ = 1, Obj C = 2, Obj C++ = 3, other = 255
 */

#if (defined(__STDC__) && !defined(_cplusplus)) || (defined(__MSC_VER) && !defined(_cplusplus))
  #define LANG 0
#elif (defined(__STDC__) && defined(_cplusplus)) || (defined(__MSC_VER) && defined(_cplusplus))
  #define LANG 1
#elif defined(__OBJC__) && !defined(__cplusplus))
  #define LANG 2
#elif defined(__OBJC__) && defined(__cplusplus))
  #define LANG 3
#else
  #define LANG 255
#endif

int lang(void) {
  #if (defined(__STDC__) && !defined(_cplusplus)) || (defined(__MSC_VER) && !defined(_cplusplus))
    return 0;
  #elif (defined(__STDC__) && defined(_cplusplus)) || (defined(__MSC_VER) && defined(_cplusplus))
    return 1;
  #elif defined(__OBJC__) && !defined(__cplusplus))
    return 2;
  #elif defined(__OBJC__) && defined(__cplusplus))
    return 3;
  #else
    return 255;
  #endif
}

/*Delay - is a function to sleep programm*/
void delay(double second) {
  if (second >= 18446744073) {
    second = 18446744072;
  }
  uint64_t nanosecond = (uint64_t)(second * 1000000000);
  #if TYPE_OS == 0
    //double millisecond_w = second * 1000;
    //Sleep((DWORD)(millisecond_w));
    TIMECAPS tc;
    if (timeGetDevCaps(&tc, sizeof(tc)) == MMSYSERR_BADDEVICEID) {
      return;
    }
    timeBeginPeriod(tc.wPeriodMin);

    HANDLE hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
    if (!hTimer) {
      timeEndPeriod(tc.wPeriodMin);
      return;
    }

    LARGE_INTEGER liDueTime;

    LONGLONG intervals = (LONGLONG)(nanosecond / 100);
    liDueTime.QuadPart = -intervals;

    SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, FALSE);

    WaitForSingleObject(hTimer, INFINITE);

    CloseHandle(hTimer);
    timeEndPeriod(tc.wPeriodMin);
  #elif TYPE_OS == 1 || TYPE_OS == 2
    //double microsecond_u = second * 1000000;
    //usleep((useconds_t)(microsecond_u));

    //time_t sec = (time_t)(nanosecond / 1e9);
    //long nsec = (long)(nanosecond - (double)sec * 1e9);

    time_t sec = (time_t)(nanosecond / 1000000000ULL);
    long nsec = (long)(nanosecond % 1000000000ULL);

    if (nsec >= 1000000000L) {
      sec += 1;
      nsec -= 1000000000L;
    }
    if (nsec < 0) {
      sec -= 1;
      nsec += 1000000000L;
    }

    struct timespec req = { .tv_sec = sec, .tv_nsec = nsec };
    struct timespec rem;

    while (nanosleep(&req, &rem) == -1 && errno == EINTR) {
      req = rem;
    }
  //#elif defined(__SamOS__)
    //sleep(second);
  //}
  #else
    /*double microsecond = second * 1000000;
    for (volatile unsigned long int i = 0; i < microsecond; i++) {
      //Okak, okak-kak, and programming time in time table
    }*/
    #error "the 'delay()' function is not supported in your operating system"
  #endif
}

void delay_not_restrictions(double seconds) {
  if (seconds >= 18446774073 && seconds <= 36893548146) {
    delay(seconds - (seconds - 18446774073));
    delay(seconds - 18446774073);
  }
  else if (seconds >= 36893548146 && seconds <= 55340322219) {
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - 18446774073);
  }
  else if (seconds >= 55340322219 && seconds <= 73787096292) {
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - 18446774073);
  }
  else if (seconds >= 73787096292 && seconds <= 92233870365) {
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - 18446774073);
  }
  else if (seconds >= 92233870365 && seconds <= 110680644438) {
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - 18446774073);
  }
  else if (seconds >= 110680644438 && seconds <= 129127418511) {
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - 18446774073);
  }
  else if (seconds >= 129127418511 && seconds <= 147574192584) {
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - 18446774073);
  }
  else if (seconds >= 147574192584 && seconds <= 166020966657) {
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - 18446774073);
  }
  else if (seconds >= 166020966657 && seconds <= 184467740730) {
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - (seconds - 18446774073));
    delay(seconds - 18446774073);
  }
}

/*Print with delay - is a function for printing letters with a certain delay.*/
void print_with_delay(const char *text, double sec) {
  if (text == NULL) {
    return;
  }
  size_t i = 0;
  size_t strlen_text = strlen(text);
  setbuf(stdout, NULL);
  for(i = 0; i < strlen_text; i++) {
    if (putchar(text[i]) == EOF) {
      perror("putchar failed");
      return;
    }
    if (i != strlen_text - 1) {
      delay(sec);
    }
  }
  fflush(stdout);
}

/*Command - is a function to execute command*/
/*void command(char command,, size_t buf_size, const char *arg1, const char *arg2, const char *arg3, const char *arg4, const char *arg5, const char *arg6) {
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
    fprintf(stdout, "Warning: %s\n", msg);
  }
  else if (level == MSG) {
    fprintf(stdout, "%s\n", msg);
  }
  else if (level == INFO) {
    fprintf(stdout, "Info: %s\n", msg);
  }
  else if (level == COMMAND) {
    fprintf(stdout, "Execute command '%s'...\n", msg);
    system(msg);
  }
  else {
    fprintf(stderr, "Error: not found action!\n");
  }
}

/*Init_cpuinfo - is a function to save information processor*/
/*void init_cpuinfo(void) {
  #if defined(_WIN32)
   #error "error: 'init_cpuinfo' is not working on Windows!"
  #elif defined(__linux__) || defined (__Unix__)
    system("lscpu > ~/cpuinfo.d");
    inited_cpuinfo = 1;
  #else
    #error "error: 'init_cpuinfo' is not working on your OS!"
  #endif
}*/

/*Clear_screen - is a function to clear screen
 *Function cleared screen from terminal
 */
void clear_screen(void) {
  if (type_os() == 0) {
    system("cls");
  }
  else if (type_os() == 1/* || type_os() == 2*/) {
    system("clear");
  }
  else {
    printf("\033[2J\033[H");
  }
}

/*Conf_user - is a function to scan strean "stdin" to save user confirmation (y - yes/n - no)*/
/*If choice = 0 and the user enters N or n, then 0 will be returned, otherwise 1 will be returned.
If choice = 1 and the user enters Y or Y, then 1 will be returned, otherwise 0 will be returned.*/
int conf_user(const char *msg, int choise) {
  char input_conf;
  if (choise == 0) {
    fprintf(stdout, "%s [Y, n]: ", msg);
    scanf(" %1c", &input_conf);
    if (input_conf == 'n' || input_conf == 'N') {
      return 0;
    }
    else {
      return 1;
    }
  }
  if (choise == 1) {
    fprintf(stdout, "%s [y, N]: ", msg);
    scanf(" %1c", &input_conf);
    if (input_conf == 'y' || input_conf == 'Y') {
      return 1;
    }
    else {
      return 0;
    }
  }
  return 0;
}


/*Name_user - is a function to print text "Enter your new name (max: 30 symbols): ", scaning stdin (max symbols: 30 symbols) and writed in developer varible through pointer "name".
 *Warning! Please, make a varible to value 31 (example: "char new_main[31];") or dynamic varible! Else: error "Segmentation fault", if user enter better or the same maximum leght varible.
 */
void name_user(char *save_name) {
  fprintf(stdout, "Enter your name (max: 30 symbols): ");
  scanf(" %30s", save_name);
}

int verification_name_user(const char *name) {
  char namee[31];
  fprintf(stdout, "Enter your name (max: 30 symbols): ");
  scanf(" %30s", namee);
  return strcmp(name, namee);
}

/*Name_user - is a function to print text "Enter your new name (max: 100 symbols): ", scaning stdin (max symbols: 100 symbols) and writed in developer varible through pointer "name".
 *Warning! Please, make a varible to value 101 (example: "char new_main[101];") or make dynamic varible! Else: error "Segmentation fault", if user enter better or the same maximum leght varible.
 */
void password_user(char *save_password) {
  fprintf(stdout, "Enter your password (max: 100 symbols): ");
  scanf(" %100s", save_password);
}

int verification_password_user(const char *password) {
  char passwordd[101];
  fprintf(stdout, "Enter your password (max: 100 symbols): ");
  scanf(" %100s", passwordd);
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
