#include <stdio.h>
#include <unistd.h>

int check_pram(int argc, const char* src, int pronum) {
	// 参数量为3个或者4个，其他参数量报错
	if (argc < 3 || argc > 4) {
		printf("Wrong number of parameters!\n");
		return -1;
	}

	// 验证src文件的有效性
	int res = access(src, F_OK);// 返回0表示文件存在，非0不存在
	if (res != 0) {
		printf("The file is not exist!\n");
		return -1;
	}

	// 验证进程数，范围：1-10
	// argc为3时走默认，为4时需验证
	if (argc == 4) {
		if (pronum < 1 || pronum > 10) {
			printf("Wrong number of pronum!\n");
			return -1;
		}
	}

	return 0;
}
