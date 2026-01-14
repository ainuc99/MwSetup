#
# mwsetup
# 云固件虚拟磁盘用户空间设置程序
#
#

all:
	gcc -o mwsetup mwsetup.c

install:
	cp mwsetup /sbin/mwsetup

clean:
	rm -fr mwsetup
