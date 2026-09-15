#ifndef __KSU_H_UTIL
#define __KSU_H_UTIL

#include "linux/fdtable.h" // IWYU pragma: keep
#include <linux/version.h>
#include <linux/syscalls.h>

/* Ref Patch: Syscall helper aliases for Kernel < 4.17/5.11
 * Explanation: ksys_close and ksys_unshare were sys_close and sys_unshare before Kernel 4.17.
 */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 11, 0)
#define ksu_close_fd close_fd
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(4, 17, 0)
#define ksu_close_fd ksys_close
#else
#define ksu_close_fd sys_close
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 17, 0)
#ifndef ksys_unshare
#define ksys_unshare sys_unshare
#endif
#ifndef ksys_close
#define ksys_close sys_close
#endif
#endif

#endif
