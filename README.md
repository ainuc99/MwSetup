# MwSetup
Multiware linux kernel module userspace setup tool

云固件内核模块mwvd.ko的用户空间设置程序

https://github.com/ainuc99/MwSetup


# 编译

下载后，进入目录，直接make就可以编译了

```
make
```

# 安装

默认安装目录为/sbin，需要使用root权限

```
make install
```

# 使用

创建虚拟磁盘并附加镜像文件（image_file_path）

```
mwsetup -c /dev/mwvd0 image_file_path
```

卸载镜像文件并关闭虚拟磁盘

```
mwsetup -d /dev/mwvd0
```

