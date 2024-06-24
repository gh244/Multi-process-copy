#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/wait.h>

int check_pram(int argc, const char* src, int pronum);
int blocksize_cur(const char* src, int pronum);
int process_wait(void);
int process_create(const char* src, const char* dest, int pronum, int blocksize);
