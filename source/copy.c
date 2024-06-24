#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <pthread.h>
#include <signal.h>

int main(int argc, char* argv[])
{
	// 校验参数个数是否合法，必须是3个
	if (argc != 4) {
		printf("copy函数参数个数错误！\n");
		return -1;
	}
	// 打开源文件，以只读的方式
	int fdSource = open(argv[1],O_RDONLY);
	// 判断返回值，失败就报错
	if (fdSource == -1) {
		printf("copy函数源文件打开失败！\n");
		return -1;
	}
	// 打开目标文件，以写|不存在就创建|TRUNC方式
	umask(0000);
	int fdTarget = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0644);

	// 判断返回值，失败就报错
	if (fdTarget == -1) {
		printf("copy函数目标文件打开失败！\n");
		close(fdSource);
		return -1;
	}

	// 循环
	char buf[1024] = "";
	int len = 0;
	// 设置光标位置
	int pos = atoi(argv[3]);
	lseek(fdTarget, 0, pos);
	while(1) {
		// 从源文件读取内容
		len = read(fdSource, buf, sizeof(buf));
		// 判断返回值，是0说明读完了，结束循环，-1就出错打印日志
		if (len == -1) {
			printf("copy函数读取错误!\n");
			return -1;
		}
		else if (len == 0) {
			break;
		}
		// 把读取到的内
		// 容写入目标文件
		write(fdTarget, buf, len);
	}
	// 关闭打开的两个文件
	close(fdTarget);
	close(fdSource);
	return 0;
}
