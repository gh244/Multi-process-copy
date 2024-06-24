# 常用变量
TARGET=xx# 存储目标名
CC=gcc# 存储编译器命令
INCLUDE_PATH=../include# 存储头文件路径
LIBRARY_PATH=../library# 存储库路径
INSTALL_PATH=/user/bin# 存储安装路径
CFLAGS=-I$(INCLUDE_PATH) -c -g -Wall# 编译选项
CPPLAGS=-D# 预处理选项

SRCFILE=$(wildcard *.c)
DSTFILE=$(patsubst %.c,%.o,$(SRCFILE))

$(TARGET):$(DSTFILE)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $< $(CFLAGS)

clean:
	rm -rf $(TARGET) $(DSTFILE)

output:
	echo $(INSTALL_PATH)/$(TARGET)

install:
	sudo cp $(TARGET) $(INSTALL_PATH)
