/*system.h - is a library to interacting with system
 *SamOS - is a my OS, that I don't created...
 */

#include "system.h"

#if defined(__cplusplus)
extern "C" {
#endif

//unsigned char inited_cpuinfo = 0;
//unsigned char error_out = 0;
uint8_t seedd = 0;

/*Arch - is a function/macros to find architecture processor
 *
 *All architectures:
 * |__ i386 (x86) = 0;
 * |__ x86-64 = 1;
 * |__ ARM = 2;
 * |__ ARM64 = 3;
 * |__ RISK_V_32 = 4;
 * |__ RISK_V_64 = 5
 * |__ RISKV_128 = 6
 * |__ PowerPC = 7
 * |__ MIPS = 8
 * |__ S390X = 9
 * |__ Other = 255
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
#elif defined(__riscv) && __riscv_xlen == 64
  #define ARCH 5
#elif defined(__riscv) && __riscv_xlen == 128
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

uint8_t arch(void) {
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
  #elif defined(__riscv) && __riscv_xlen == 64
    return 5;
  #elif defined(__riscv) && __riscv_xlen == 128
    return 6;
  #elif defined(__powerpc__)
    return 7;
  #elif defined(__mips__)
    return 8;
  #elif defined(__s390x__)
    return 9;
  #else
    return 255;
  #endif
}

/* Type OS - is a function/macros to find type OS
 *
 * All OS:
 * |__ Windows systems = 0;
 * |__ UNIX-like systems = 1;
 * |__ BSD-like systems = 2;
 * |__ ToyOS = 3;
 * |__ Other = 255;
 */

#if defined(_WIN32) || defined(_WIN64)
  #define TYPE_OS 0
#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__ANDROID__)
  #define TYPE_OS 1
#elif defined(__FreeBSD__) || defined(__OpenBSD__) ||  defined(__NetBSD__)
  #define TYPE_OS 2
#elif defined(__toyos__)
  #define TYPE_OS 3
//#elif defined(__SamOS__)
  //#define TYPE_OS 254
#else
  #define TYPE_OS 255
#endif

uint8_t type_os(void) {
  #if defined(_WIN32) || defined(_WIN64)
    return 0;
  #elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__ANDROID__)
    return 1;
  #elif defined(__FreeBSD__) || defined(__OpenBSD__) ||  defined(__NetBSD__)
    return 2;
  #elif defined(__toyos__)
    return 3;
  //#elif defined(__SamOS__)
    //return 254;
  #else
    return 255;
  #endif
}


/* OS - is a function/macros to find type OS
 *
 * All OS:
 * |__ Windows systems (x32) = 0
 * |__ Windows systems (x64) = 1
 * |__ Linux systems = 2
 * |__ Mac OS = 3
 * |__ Other Apple systems = 4
 * |__ UNIX base systems = 5
 * |__ Android systems = 6
 * |__ FreeBSD systems = 7
 * |__ OpenBSD systems = 8
 * |__ NetBSD systems = 9
 * |__ ToyOS = 10
 * |__ Other = 255
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
#elif defined(__OpenBSD__)
  #define OS 8
#elif defined(__NetBSD__)
  #define OS 9
#elif defined(__toyos__)
  #define OS 10
//#elif defined(__SamOS__)
  //#define OS 254
#else
  #define OS 255
#endif

uint8_t os(void) {
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
  #elif defined(__OpenBSD__)
    return 8;
  #elif defined(__NetBSD__)
    return 9;
  #elif defined(__toyos__)
    return 10;
  //#elif defined(__SamOS__)
    //return 254;
  #else
    return 255;
  #endif
}

/* Comp - is a function/macros to find compiler
 *
 * All compilers:
 * |__ GCC = 0;
 * |__ Clang = 1;
 * |__ Vusial Studio C = 2;
 * |__ MinGW32 = 3;
 * |__ MinGW64 = 4;
 * |__ Tiny C = 5;
 * |__ ICC (Intel C Compiler) = 6;
 * |__ Pelles C = 7;
 * |__ Other = 255
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

uint8_t comp(void) {
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

/* Lang - is a function/macros to find language program
 *
 * All languages:
 * |__ C = 0;
 * |__ C++ = 1;
 * |__ Obj C = 2;
 * |__ Obj C++ = 3;
 * |__ Other = 255
 */

#if (defined(__STDC__) && !defined(__cplusplus)) || (defined(__MSC_VER) && !defined(__cplusplus))
  #define LANG 0
#elif (defined(__STDC__) && defined(__cplusplus)) || (defined(__MSC_VER) && defined(__cplusplus))
  #define LANG 1
#elif defined(__OBJC__) && !defined(__cplusplus)
  #define LANG 2
#elif defined(__OBJC__) && defined(__cplusplus)
  #define LANG 3
#else
  #define LANG 255
#endif

uint8_t lang(void) {
  #if (defined(__STDC__) && !defined(__cplusplus)) || (defined(__MSC_VER) && !defined(__cplusplus))
    return 0;
  #elif (defined(__STDC__) && defined(__cplusplus)) || (defined(__MSC_VER) && defined(__cplusplus))
    return 1;
  #elif defined(__OBJC__) && !defined(__cplusplus)
    return 2;
  #elif defined(__OBJC__) && defined(__cplusplus)
    return 3;
  #else
    return 255;
  #endif
}


/* Cvoid - is a placeholder function rhat does nothing. */
void cvoid(void) {}


/* Input - is a function for input string from stream "stdin".
 *
 * This function returns the input value to the array specified in the first argument (const char *str).
 * In the second arggumets, you specify the size of the array into which the function should store the value (size_t size). If there is an error in the second argument, the program will fall into undefined behavior and there is a high probability of a Segmentation Fault.
 */
void input(char *str, size_t size) {
  /*char str_to_scanf[1000];
  snprintf(str_to_scanf, sizeof(str_to_scanf), " %%%zu[^\n]", size);
  scanf(str_to_scanf, str);*/
  if (fgets(str, size, stdin)) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
      str[len - 1] = '\0';
    }
    else {
      int c;
      while ((c = getchar()) != '\n' && c != EOF);
    }
    //str[strcspn(str, "\n")] = '\0';
  }
}


/* Triple print - is a function for printing three lines at time to the stream tou specify.
 *
 * This function uses copying with preservation of the cursor location (memcpy), as well as only ane call to "fputs()", witch makes it much more productive than several strcat at once, as well as several puts, and one printf with formatting.
 * You can also choose which array is more convenient for you: static or dynamic, using the flag passed during compilation.
 *
 * All possible return values of the function:
 * |__ 0 = successfully output a string to the specified stream;
 * |__ 1 + not flag "use_dynamic_massive" = possible stack overflow due to too much text, solution: shorten the message or call the function twise;
 * |__ 1 + flag "use_dynamic_massive" = failed to create a dynamc array to store a string, solution: repeat the call again;
 * |__ 2 = any line is not filled, which may lead to incorrect line output, solution: fill the lines with text or use "double_print()".
 */
uint8_t triple_print(const char *str1, const char *str2, const char *str3, FILE *stream) {
  size_t sstr1 = strlen(str1), sstr2 = strlen(str2), sstr3 = strlen(str3);
  size_t total = sstr1 + sstr2 + sstr3;
  //uint8_t ret_to_succ = 0;

  #if defined(use_dynamic_massive)
    char *buffer = (char*)calloc((total + 1) * sizeof(char));
    if (buffer == NULL) {
      return 1;
    }
  #else
    if (total >= (4096 * 1024)) {
      return 1;
    }
    char buffer[total + 1];
  #endif

  char *p = buffer;
  if (sstr1 == 0 || sstr2 == 0 || sstr3 == 0) {
    return 2;
  }

  memcpy(p, str1, sstr1);
  p += sstr1;
  memcpy(p, str2, sstr2);
  p += sstr2;
  memcpy(p, str3, sstr3);
  p += sstr3;

  buffer[total] = '\0';
  fputs(buffer, stream);
  #if defined(use_dynamic_massive)
    free(buffer);
  #endif
  return 0;
}


/* Double print - is a function for printing two lines at time to the stream tou specify.
 *
 * This function uses copying with preservation of the cursor location (memcpy), as well as only ane call to "fputs()", witch makes it much more productive than several strcat at once, as well as several puts, and one printf with formatting.
 * You can also choose which array is more convenient for you: static or dynamic, using the flag passed during compilation.
 *
 * All possible return values of the function:
 * |__ 0 = successfully output a string to the specified stream.
 * |__ 1 + not flag "use_dynamic_massive" = possible stack overflow due to too much text, solution: shorten the message or call the function twise;
 * |__ 1 + flag "use_dynamic_massive" = failed to create a dynamc array to store a string, solution: repeat the call again;
 * |__ 2 = any line is not filled, which may lead to incorrect line output, solution: fill the lines with text or use "double_print()".
 */
uint8_t double_print(const char *str1, const char *str2, FILE *stream) {
  size_t sstr1 = strlen(str1), sstr2 = strlen(str2);
  size_t total = sstr1 + sstr2;
  //uint8_t ret_to_succ = 0;

  #if defined(use_dynamic_massive)
    char *buffer = (char*)calloc((total + 1) * sizeof(char));
    if (buffer == NULL) {
      return 1;
    }
  #else
    if (total >= (4096 * 1024)) {
      return 1;
    }
    char buffer[total + 1];
  #endif

  char *p = buffer;
  if (sstr1 == 0) {
    return 2;
  }
  memcpy(p, str1, sstr1); p += sstr1;
  memcpy(p, str2, sstr2); p += sstr2;

  buffer[total] = '\0';
  fputs(buffer, stream);
  #if defined(use_dynamic_massive)
    free(buffer);
  #endif
  return 0;
}

/*void cycle(void *func, int val, const char *arg1, const char *arg2, const char *arg3, const char *arg4) {
  for (int i, i < val, i++) {
    if (arg1 == NULL) {
      func();
    }
    else if (arg2 == NULL) {
      func(arg1);
    }
    else if (arg3 == NULL) {
      func(arg1, arg2);
    }
    else if (arg3 != NULL) {
      func(arg1, arg2, arg3);
    }
  }
}*/


/* Delay - is a function for sleep program
 *
 * This feature creates nanosecond delays, which in reality are based on the processor speed.
 *
 * The only argument this function accepts is seconds in 80 or 128 bit format (long double seconds)
 * Important warning: this feature does not work on operating systems that do not support either TYPE_OS 0, TYPE_OS 1 or TYPE_OS 2 macros!
 */
void delay(long double second) {
  if (second > 18446744073) {
    second = 18446744073;
  }
  uint64_t nanosecond = (uint64_t)(second * 1000000000);
  #if defined(old_mode_delay)
    #if TYPE_OS == 0
      Sleep(nanosecond / 1000000);
    #elif TYPE_OS == 1 || TYPE_OS == 2
      #if defined(use_usleep)
        usleep(nanosecond / 1000);
      #else
        sleep(nanosecond / 1000000000);
      #endif
    #else
      #warning "the 'delay()' function is not supported in your operating system"
    #endif
  #else
    #if TYPE_OS == 0
      //double millisecond_w = second * 1000;
      //Sleep((DWORD)(millisecond_w));
      #warning "If you use the 'delay()' function on a Windows system, please note that you must either lingthe project with the 'winmm.lib' library or use '-old_mode_delay'!"
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
      uint64_t nsec = (uint64_t)(nanosecond % 1000000000ULL);

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
      #warning "the 'delay()' function is not supported in your operating system"
    #endif
  #endif
}


/* Delay not restrictions - is a delay function without any time limits. */
void delay_not_restrictions(long double seconds) {
  const double max_delay = 18446744073;
  while (seconds > max_delay) {
    delay(max_delay);
    seconds -= max_delay;
  }
  delay(seconds);
}


/* Print with delay - is a function for printing letters with a certain delay.
 *
 * All values that can be returned:
 * |__ 0 = the text was printed successfully;
 * |__ 1 = there is either no text or it has been lost, solution: insert text.
 */
uint8_t print_with_delay(const char *text, long double sec) {
  if (text == NULL) {
    return 1;
  }
  size_t i = 0;
  size_t strlen_text = strlen(text);
  setbuf(stdout, NULL);
  for(i = 0; i < strlen_text; i++) {
    if (putchar(text[i]) == EOF) {
      perror("putchar failed");
      return 1;
    }
    if (i != strlen_text - 1) {
      delay(sec);
    }
  }
  fflush(stdout);
  return 0;
}


/* Command - is a function to execute command */
/*void command(char command,, size_t buf_size, const char *arg1, const char *arg2, const char *arg3, const char *arg4, const char *arg5, const char *arg6) {
    snprintf(command, buf_size, "%s %s %s %s %s %s", arg1, arg2, arg3, arg4, arg5, arg6);
    system(command);
}*/


/* Msg_print - is a function to print from varible "msg" with level.
 *
 * This function takes 3 arguments:
 * |__ 1. The message level;
 * |__ 2. The message itself;
 * |__ 3. The action (in some cases).
 *
 * All levels:
 * |__ Critical error = -2;
 * |__ Error = -1;
 * |__ Warning = 0;
 * |__ Standart message = 1;
 * |__ Information = 2;
 * |__ Command execute = 3.
 *
 * All actions:
 * |__ Not shutdown = 0;
 * |__ Shutdown = 1.
 *
 * If tou select level -2, or if you select level -1 and action 1, the program will print an error to stderr and terminate.
 * If tou select level 3, the program will print a message about running command n and tun the command you entered.
 * Otherwisem the programm will print message and counte running.
 */
uint8_t msg_print(int8_t level, const char *msg, uint8_t action) {
  //char messeg[4096];
  if (level == CRITICAL_ERR) {
    //fprintf(stderr, "\033[91mCRITICAL ERROR: %s! Shutdown program...\033[0m\n", msg);
    //triple_print("\033[91mCRITICAL ERROR: ", msg, "! Shutdown program...\033[0m\n", stderr);
    triple_print("CRITICAL ERROR: ", msg, "! Shutdown program...\n", stderr);
    exit(1);
  }
  else if (level == ERR) {
    if (action == NO_SHUTDOWN) {
      //fprintf(stderr, "\033[31mError: %s!\033[0m\n", msg);
      //triple_print("\033[31mError: ", msg, "!\033[0m\n", stderr);
      triple_print("Error: ", msg, "!\n", stderr);
    }
    else if (action == SHUTDOWN) {
      //fprintf(stderr, "\033[31mError: %s! Shutdown program...\033[0m\n", msg);
      //triple_print("\033[31mError: ", msg, "! Shutdown program...\033[0m\n", stderr);
      triple_print("Error: ", msg, "! Shutdown program...\n", stderr);
      exit(1);
    }
  }
   else if (level == WARN) {
    //fprintf(stdout, "\033[33mWarning: %s\033[0m\n", msg);
    //triple_print("\033[33mWarning: ", msg, "!\033[0m\n", stdout);
    triple_print("Warning: ", msg, "!\n", stdout);
  }
  else if (level == MSG) {
    //fprintf(stdout, "%s\n", msg);
    //double_print(msg, "\n", stdout);
    double_print(msg, "\n", stdout);
  }
  else if (level == INFO) {
    //fprintf(stdout, "\033[mInfo: %s\033[0m\n", msg);
    //triple_print("\033[32mInfo: ", msg, "\033[0m\n", stdout);
    triple_print("Info: ", msg, "\n", stdout);
  }
  /*else if (level == COMMAND) {
    //fprintf(stdout, "\033[2mExecute command '%s'...\n", msg);
    //triple_print("\033[34mExecute command: '", msg, "'...\033[0m\n", stdout);
    triple_print("Execute command: '", msg, "'...\n", stdout);
    system(msg);
  }*/
  else {
    //fprintf(stderr, "\033[1mError: not found action!\033[0m\n");
    return 1;
  }
  return 0;
}


/* Init_cpuinfo - is a function to save information processor */
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


/* Clear_screen - is a function to clear screen.
 * Function cleared screen from terminal.
 */
void clear_screen(void) {
  if (type_os() == 0) {
    system("cls");
  }
  /*else if (type_os() == 1 || type_os() == 2) {
    system("clear");
  }*/
  else {
    printf("\033[2J\033[H");
  }
}


/* Conf_user - is a function to scan strean "stdin" to save user confirmation (y - yes/n - no)
 *
 * If choice = 0 and the user enters N or n, then 0 will be returned, otherwise 1 will be returned.
 * If choice = 1 and the user enters Y or Y, then 1 will be returned, otherwise 0 will be returned.*/
uint8_t conf_user(const char *msg, uint8_t choise) {
  char input_conf;
  if (choise == 0) {
    double_print(msg, " [Y, n]: ", stdout);
    scanf(" %c ", &input_conf);
    if (input_conf == 'n' || input_conf == 'N') {
      return 0;
    }
    else {
      return 1;
    }
  }
  if (choise == 1) {
    double_print(msg, " [y, N]: ", stdout);
    scanf(" %c ", &input_conf);
    if (input_conf == 'y' || input_conf == 'Y') {
      return 1;
    }
    else {
      return 0;
    }
  }
}


/* Name user - is a function to print text "Enter your name (max: %d symbols): ", scaning stdin and writed in developer varible through pointer "name".
 *
 * This function takes two arguments:
 * |__ 1. The name (char *name);
 * |__ 2. The maxtimum allowable size of the entered name (size_t size).
 *
 * Warning: please, create either a static array and enter sizeof as the second argument, or a dynamic array and either the size of than array!
 * If the actual array size is smaller than the size entered in the second argument, the program will experience indefined behavior!
 */
void name_user(char *save_name, size_t size) {
  char okak[BUF_SIZE];
  snprintf(okak, sizeof(okak), "%zu", size);
  triple_print("Enter your name (max: ", okak, " symbols): ", stdout);
  input(save_name, size);
}


/* Verefication name user - is a function for verefication username.
 *
 * This function takes two arguments:
 * |__ 1. The name (const char *name);
 * |__ 2. The maxtimum allowable size of the entered name (size_t size).
 *
 * All possible return values of the function:
 * |__ 0 = the data entered by the user and the data you provied in the arguments match.
 * |__ -1 + not flag "use_dynamic_massive" = possible stack overflow due to too much text, solution: shorten the message or call the function twise;
 * |__ -1 + flag "use_dynamic_massive" = failed to create a dynamc array to store a string, solution: repeat the call again.
 * |__ 1 = the data entered by the user and the data you provied in the arguments do not match.
 */
int8_t verification_name_user(const char *name, size_t size) {
  #if defined(use_dynamic_massive)
    char *namee = (char*)malloc((size + 1) * sizeof(char));
    if (namee == NULL) {
      return -1;
    }
  #else
    if (size > 4096 * 1024) {
      return -1;
    }
    char namee[size + 1];
  #endif
  char okak[BUF_SIZE];
  snprintf(okak, sizeof(okak), "%zu", size);
  triple_print("Enter your name (max: ", okak, " symbols): ", stdout);
  input(namee, sizeof(namee));
  if (strcmp(name, namee) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}


/* Password user - is a function to print text "Enter your password (max: %d symbols): ", scaning stdin and writed in developer varible through pointer "password".
 *
 * This function takes two arguments:
 * |__ 1. The name (char *save_password);
 * |__ 2. The maxtimum allowable size of the entered name (size_t size).
 *
 * Warning: please, create either a static array and enter sizeof as the second argument, or a dynamic array and either the size of than array!
 * If the actual array size is smaller than the size entered in the second argument, the program will experience indefined behavior!
 */
void password_user(char *save_password, size_t size) {
  char okak[BUF_SIZE];
  snprintf(okak, sizeof(okak), "%zu", size);
  triple_print("Enter your password (max: ", okak, " symbols): ", stdout);
  input(save_password, size);
}


/* Verefication password user - is a function for verefication user password.
 *
 * This function takes two arguments:
 * |__ 1. The name (const char *password);
 * |__ 2. The maxtimum allowable size of the entered name (size_t size).
 *
 * All possible return values of the function:
 * |__ 0 = the data entered by the user and the data you provied in the arguments match.
 * |__ -1 + not flag "use_dynamic_massive" = possible stack overflow due to too much text, solution: shorten the message or call the function twise;
 * |__ -1 + flag "use_dynamic_massive" = failed to create a dynamc array to store a string, solution: repeat the call again.
 * |__ 1 = the data entered by the user and the data you provied in the arguments do not match.
 */
int8_t verification_password_user(const char *password, size_t size) {
  #if defined(use_dynamic_massive)
    char *passwordd = (char*)malloc((size + 1) * sizeof(char));
    if (passwordd == NULL) {
      return -1;
    }
  #else
    if (size > 4096 * 1024) {
      return -1;
    }
    char passwordd[size + 1];
  #endif
  char okak[BUF_SIZE];
  snprintf(okak, sizeof(okak), "%zu", size);
  triple_print("Enter your password (max: ", okak, " symbols): ", stdout);
  input(passwordd, sizeof(passwordd));
  if (strcmp(password, passwordd) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}

/* Print in color - is a function for print text from varible "text" to stream "stdout" (standart stream for print text) in color (0-7 = standart colors, 8-15 = bright colors).
 *
 * All support colors to print:
 * 0 = Standart, name macros - BLACK;
 * 1 = Red, name macros - RED;
 * 2 = Green, name macros - GREEN;
 * 3 = Yellow (or brown), name macros - YELLOW;
 * 4 = Blue, name macros - BLUE;
 * 5 = Magenta, name macros - MAGENTA;
 * 6 = Cyan, name macros - CYAN;
 * 7 = White (or light gray), name macros - WHITE;
 * 8 = Bright black (or dark gray), name macros - BRIGHTBLACK;
 * 9 = Bright red, name macros - BRIGHTRED;
 * 10 = Bright green, name macros - BRIGHTGREEN;
 * 11 = Bright yellow, name macros - BRIGHTYELLOW;
 * 12 = Bright blue, name macros - BRIGHTBLUE;
 * 13 = Bright magenta, name macros - BRIGHTMAGENTA;
 * 14 = Bright cyan, name macros - BRIGHTCYAN;
 * 15 = Bright white (or clean white), name macros - BRIGHTWHITE.
 *
 * This function don't have support formats (example - %s or %d). Please, unite strings for functions "strcat()" from string.h or "snprintf()" from stdio.h.
*/

void print_in_color(const char *text, uint8_t color) {
  //char buffer[BUF_SIZE];
  #if TYPE_OS == 0
    HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color) {
      case BLACK:
        SetConsoleTextAttribute(hC, 0);
        break;
      case RED:
        SetConsoleTextAttribute(hC, FOREGROUND_RED);
        break;
      case GREEN:
        SetConsoleTextAttribute(hC, FOREGROUND_GREEN);
        break;
      case YELLOW:
        SetConsoleTextAttribute(hC, FOREGROUND_RED | FOREGROUND_GREEN);
        break;
      case BLUE:
        SetConsoleTextAttribute(hC, FOREGROUND_BLUE);
        break;
      case MAGENTA:
        SetConsoleTextAttribute(hC, FOREGROUND_RED | FOREGROUND_BLUE);
        break;
      case CYAN:
        SetConsoleTextAttribute(hC, FOREGROUND_GREEN | FOREGROUND_BLUE);
        break;
      case WHITE:
        SetConsoleTextAttribute(hC, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
        break;
      case BRIGHTBLACK:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | 0);
        break;
      case BRIGHTRED:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_RED);
        break;
      case BRIGHTGREEN:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        break;
      case BRIGHTYELLOW:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        break;
      case BRIGHTBLUE:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        break;
      case BRIGHTMAGENTA:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
        break;
      case BRIGHTCYAN:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        break;
      case BRIGHTWHITE:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
        break;
    }
    fputs(text, stdout);
    SetConsoleTextAttribute(hC, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
  #elif TYPE_OS == 1 || TYPE_OS == 2
    switch (color) {
      case BLACK:
        triple_print("\033[30m", text, "\033[0m", stdout);
        break;
      case RED:
        triple_print("\033[31m", text, "\033[0m", stdout);
        break;
      case GREEN:
        triple_print("\033[32m", text, "\033[0m", stdout);
        break;
      case YELLOW:
        triple_print("\033[33m", text, "\033[0m", stdout);
        break;
      case BLUE:
        triple_print("\033[34m", text, "\033[0m", stdout);
        break;
      case MAGENTA:
        triple_print("\033[35m", text, "\033[0m", stdout);
        break;
      case CYAN:
        triple_print("\033[36m", text, "\033[0m", stdout);
        break;
      case WHITE:
        triple_print("\033[37m", text, "\033[0m", stdout);
        break;
      case BRIGHTBLACK:
        triple_print("\033[90m", text, "\033[0m", stdout);
        break;
      case BRIGHTRED:
        triple_print("\033[91m", text, "\033[0m", stdout);
        break;
      case BRIGHTGREEN:
        triple_print("\033[92m", text, "\033[0m", stdout);
        break;
      case BRIGHTYELLOW:
        triple_print("\033[93m", text, "\033[0m", stdout);
        break;
      case BRIGHTBLUE:
        triple_print("\033[94m", text, "\033[0m", stdout);
        break;
      case BRIGHTMAGENTA:
        triple_print("\033[95m", text, "\033[0m", stdout);
        break;
      case BRIGHTCYAN:
        triple_print("\033[96m", text, "\033[0m", stdout);
        break;
      case BRIGHTWHITE:
        triple_print("\033[97m", text, "\033[0m", stdout);
        break;
      default:
        fputs(text, stdout);
    }
  #else
    #warning "Function 'print_in_color()' do not work in your system!"
    fputs(text, stdout);
  #endif
}

/* Fprint in color - is a function for print text from varible "text" to one stream (from varible "stream") in color (0-7 = standart colors, 8-15 = bright colors).
 *
 * All colors to print:
 * 0 = Standart, name macros - BLACK;
 * 1 = Red, name macros - RED;
 * 2 = Green, name macros - GREEN;
 * 3 = Yellow (or brown), name macros - YELLOW;
 * 4 = Blue, name macros - BLUE;
 * 5 = Magenta, name macros - MAGENTA;
 * 6 = Cyan, name macros - CYAN;
 * 7 = White (or light gray), name macros - WHITE;
 * 8 = Bright black (or dark gray), name macros - BRIGHTBLACK;
 * 9 = Bright red, name macros - BRIGHTRED;
 * 10 = Bright green, name macros - BRIGHTGREEN;
 * 11 = Bright yellow, name macros - BRIGHTYELLOW;
 * 12 = Bright blue, name macros - BRIGHTBLUE;
 * 13 = Bright magenta, name macros - BRIGHTMAGENTA;
 * 14 = Bright cyan, name macros - BRIGHTCYAN;
 * 15 = Bright white (or clean white), name macros - BRIGHTWHITE.
 *
 *
 * This function don't have support formats (example - %s or %d). Please, unite strings through functions "strcat()" from string.h or "snprintf()" from stdio.h.
*/

void fprint_in_color(const char *text, uint8_t color, FILE *stream) {
  #if TYPE_OS == 0
    HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color) {
      case BLACK:
        SetConsoleTextAttribute(hC, 0);
        break;
      case RED:
        SetConsoleTextAttribute(hC, FOREGROUND_RED);
        break;
      case GREEN:
        SetConsoleTextAttribute(hC, FOREGROUND_GREEN);
        break;
      case YELLOW:
        SetConsoleTextAttribute(hC, FOREGROUND_RED | FOREGROUND_GREEN);
        break;
      case BLUE:
        SetConsoleTextAttribute(hC, FOREGROUND_BLUE);
        break;
      case MAGENTA:
        SetConsoleTextAttribute(hC, FOREGROUND_RED | FOREGROUND_BLUE);
        break;
      case CYAN:
        SetConsoleTextAttribute(hC, FOREGROUND_GREEN | FOREGROUND_BLUE);
        break;
      case WHITE:
        SetConsoleTextAttribute(hC, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
        break;
      case BRIGHTBLACK:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | 0);
        break;
      case BRIGHTRED:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_RED);
        break;
      case BRIGHTGREEN:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        break;
      case BRIGHTYELLOW:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        break;
      case BRIGHTBLUE:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        break;
      case BRIGHTMAGENTA:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
        break;
      case BRIGHTCYAN:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        break;
      case BRIGHTWHITE:
        SetConsoleTextAttribute(hC, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
        break;
      default:
        break;
    }
    fputs(text, stream);
    SetConsoleTextAttribute(hC, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
  #elif TYPE_OS == 1 || TYPE_OS == 2
    switch (color) {
      case BLACK:
        triple_print("\033[30m", text, "\033[0m", stream);
        break;
      case RED:
        triple_print("\033[31m", text, "\033[0m", stream);
        break;
      case GREEN:
        triple_print("\033[32m", text, "\033[0m", stream);
        break;
      case YELLOW:
        triple_print("\033[33m", text, "\033[0m", stream);
        break;
      case BLUE:
        triple_print("\033[34m", text, "\033[0m", stream);
        break;
      case MAGENTA:
        triple_print("\033[35m", text, "\033[0m", stream);
        break;
      case CYAN:
        triple_print("\033[36m", text, "\033[0m", stream);
        break;
      case WHITE:
        triple_print("\033[37m", text, "\033[0m", stream);
        break;
      case BRIGHTBLACK:
        triple_print("\033[90m", text, "\033[0m", stream);
        break;
      case BRIGHTRED:
        triple_print("\033[91m", text, "\033[0m", stream);
        break;
      case BRIGHTGREEN:
        triple_print("\033[92m", text, "\033[0m", stream);
        break;
      case BRIGHTYELLOW:
        triple_print("\033[93m", text, "\033[0m", stream);
        break;
      case BRIGHTBLUE:
        triple_print("\033[94m", text, "\033[0m", stream);
        break;
      case BRIGHTMAGENTA:
        triple_print("\033[95m", text, "\033[0m", stream);
        break;
      case BRIGHTCYAN:
        triple_print("\033[96m", text, "\033[0m", stream);
        break;
      case BRIGHTWHITE:
        triple_print("\033[97m", text, "\033[0m", stream);
        break;
      default:
        fputs(text, stream);
    }
  #else
    #warning "Function print_in_text() do not work in your system!"
    fputs(text, stream);
  #endif
}

uint64_t urand64(void) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  return (uint64_t)rand() * (uint64_t)rand();
}

uint32_t urand32(void) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  return (uint32_t)rand() + (uint32_t)(rand() - (83 + 80 + 73 + 82) + 84) - (uint32_t)1488;
}

uint16_t urand16(void) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  return (uint16_t)rand();
}

uint8_t urand8(void) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  return (uint8_t)rand();
}

uint64_t urand_in_range(uint64_t n, uint64_t m) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  return n + rand() % (m - n + 1);
}


int64_t rand64(void) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  return (uint64_t)rand() * (uint64_t)rand();
}

int32_t rand32(void) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  return (uint32_t)rand() * (uint32_t)rand() - (uint32_t)(83 + 80 + 73 + 82 + 84);
}

int16_t rand16(void) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  return (uint16_t)rand();
}

int8_t rand8(void) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  return (uint8_t)rand();
}

int64_t rand_in_range(int64_t n, int64_t m) {
  if (seedd == 0) {
    srand(time(NULL));
    seedd = 1;
  }
  //return n + rand() % (m - n + 1);
  return n + (((int64_t)rand() % (m - n + 1) + (m - n + 1)) % (m - n + 1));
}

/*uint8_t kbhit(void) {
  #warning "The 'kbhit' feature is under development and is unstable! Use it at your own risk!"
  #if TYPE_OS == 0
    #warning "Function 'kbhit' is not supported for Windows!"
  #elif TYPE_OS == 1  || TYPE_OS == 2
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF) {
      ungetc(ch, stdin);
      return 1;
    }
    return 0;
  #else
    #warning "Function 'kbgit' is not supported for your OS!"
  #endif
}*/

/*xcopy /E - copy dir
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
