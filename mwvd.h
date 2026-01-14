/**
 * 云固件Linux内核模块MWVD
 * IOCTL 通讯协议头文件
 *
 * Copyright 2025 ~ 2026 陆伟峰(wave.lu@gmail.com)
 *
 */
#ifndef _UAPI_LINUX_MWVD_H
#define _UAPI_LINUX_MWVD_H

/**
 * IOCTL commands
 * 
 */

#define MWVD_SET_FD 0x4C00
#define MWVD_CLR_FD 0x4C01

/* /dev/mwvd-control interface */
#define MWVD_CTL_ADD 0x4C80
#define MWVD_CTL_REMOVE 0x4C81
#define MWVD_CTL_GET_FREE 0x4C82
#endif /* _UAPI_LINUX_MWVD_H */