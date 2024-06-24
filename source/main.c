#include "../include/process_copy.h"

int main(int argc, char** argv) {
	int pronum;
	int blocksize;
	if (argv[3] == 0)
		pronum = 5;
	else
		pronum = atoi(argv[3]);
	
	int res;
	res = check_pram(argc, argv[1], pronum);
	if (res == -1) {
		printf("check_pram error!\n");
		return -1;
	}

	blocksize = blocksize_cur(argv[1], pronum);
	process_create(argv[1], argv[2], pronum, blocksize);

	for (int i = 0; i < pronum; i++) {
		process_wait();
	}

	return 0;
}
