#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int process_create(const char* src, const char* dest, int pronum, int blocksize) {
	pid_t pid;
	// 循环创建子进程
	int i = 0;
	while (i < pronum) {
		pid = fork();
		if(!pid) break;
		i++;
	}
	if (!pid) {
		printf("The %d child process is running\n", i);
		// 移动光标
		int pos = i * blocksize;
		char str_pos[10];
		sprintf(str_pos, "%d", pos);
		// 子进程重载拷贝
		execl("./copy.o", "copy.o", src, dest, str_pos, NULL);
	}
	else if (pid > 0) printf("The parent process is running\n");

	return 0;
}
