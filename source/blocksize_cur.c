#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int blocksize_cur(const char* src, int pronum) {
	// 文件创建
	int fd = open(src, O_RDONLY);
	// 文件打开失败
	if (fd == -1) {
		perror("Open %s error\n", src);
		return -1;
	}
	// 计算文件大小
	int fsize = lseek(fd, 0, SEEK_END);

	// 计算任务量
	int taskSize = fsize / pronum;
	int remainder = fsize % pronum;
	if (remainder != 0) taskSize += 1;
	
	// 文件关闭
	close(fd);

	return taskSize;
}
