#ifndef ERRORS_H
#define ERRORS_H
#include <errno.h>
struct error_info {
    int code;
    const char* name;
    const char* message;
};
#define ENTRY(_errno, _code, _msg) { _errno, #_code, _msg }
static const struct error_info error_table[] =
{
#if defined (EPERM)
  ENTRY(EPERM, "EPERM", "Not owner"),
#endif
#if defined (ENOENT)
  ENTRY(ENOENT, "ENOENT", "No such file or directory"),
#endif
#if defined (ESRCH)
  ENTRY(ESRCH, "ESRCH", "No such process"),
#endif
#if defined (EINTR)
  ENTRY(EINTR, "EINTR", "Interrupted system call"),
#endif
#if defined (EIO)
  ENTRY(EIO, "EIO", "I/O error"),
#endif
#if defined (ENXIO)
  ENTRY(ENXIO, "ENXIO", "No such device or address"),
#endif
#if defined (E2BIG)
  ENTRY(E2BIG, "E2BIG", "Arg list too long"),
#endif
#if defined (ENOEXEC)
  ENTRY(ENOEXEC, "ENOEXEC", "Exec format error"),
#endif
#if defined (EBADF)
  ENTRY(EBADF, "EBADF", "Bad file number"),
#endif
#if defined (ECHILD)
  ENTRY(ECHILD, "ECHILD", "No child processes"),
#endif
#if defined (EWOULDBLOCK) /* Put before EAGAIN, sometimes aliased */
  ENTRY(EWOULDBLOCK, "EWOULDBLOCK", "Operation would block"),
#endif
#if defined (EAGAIN)
  ENTRY(EAGAIN, "EAGAIN", "No more processes"),
#endif
#if defined (ENOMEM)
  ENTRY(ENOMEM, "ENOMEM", "Not enough space"),
#endif
#if defined (EACCES)
  ENTRY(EACCES, "EACCES", "Permission denied"),
#endif
#if defined (EFAULT)
  ENTRY(EFAULT, "EFAULT", "Bad address"),
#endif
#if defined (ENOTBLK)
  ENTRY(ENOTBLK, "ENOTBLK", "Block device required"),
#endif
#if defined (EBUSY)
  ENTRY(EBUSY, "EBUSY", "Device busy"),
#endif
#if defined (EEXIST)
  ENTRY(EEXIST, "EEXIST", "File exists"),
#endif
#if defined (EXDEV)
  ENTRY(EXDEV, "EXDEV", "Cross-device link"),
#endif
#if defined (ENODEV)
  ENTRY(ENODEV, "ENODEV", "No such device"),
#endif
#if defined (ENOTDIR)
  ENTRY(ENOTDIR, "ENOTDIR", "Not a directory"),
#endif
#if defined (EISDIR)
  ENTRY(EISDIR, "EISDIR", "Is a directory"),
#endif
#if defined (EINVAL)
  ENTRY(EINVAL, "EINVAL", "Invalid argument"),
#endif
#if defined (ENFILE)
  ENTRY(ENFILE, "ENFILE", "File table overflow"),
#endif
#if defined (EMFILE)
  ENTRY(EMFILE, "EMFILE", "Too many open files"),
#endif
#if defined (ENOTTY)
  ENTRY(ENOTTY, "ENOTTY", "Not a typewriter"),
#endif
#if defined (ETXTBSY)
  ENTRY(ETXTBSY, "ETXTBSY", "Text file busy"),
#endif
#if defined (EFBIG)
  ENTRY(EFBIG, "EFBIG", "File too large"),
#endif
#if defined (ENOSPC)
  ENTRY(ENOSPC, "ENOSPC", "No space left on device"),
#endif
#if defined (ESPIPE)
  ENTRY(ESPIPE, "ESPIPE", "Illegal seek"),
#endif
#if defined (EROFS)
  ENTRY(EROFS, "EROFS", "Read-only file system"),
#endif
#if defined (EMLINK)
  ENTRY(EMLINK, "EMLINK", "Too many links"),
#endif
#if defined (EPIPE)
  ENTRY(EPIPE, "EPIPE", "Broken pipe"),
#endif
#if defined (EDOM)
  ENTRY(EDOM, "EDOM", "Math argument out of domain of func"),
#endif
#if defined (ERANGE)
  ENTRY(ERANGE, "ERANGE", "Math result not representable"),
#endif
#if defined (ENOMSG)
  ENTRY(ENOMSG, "ENOMSG", "No message of desired type"),
#endif
#if defined (EIDRM)
  ENTRY(EIDRM, "EIDRM", "Identifier removed"),
#endif
#if defined (ECHRNG)
  ENTRY(ECHRNG, "ECHRNG", "Channel number out of range"),
#endif
#if defined (EL2NSYNC)
  ENTRY(EL2NSYNC, "EL2NSYNC", "Level 2 not synchronized"),
#endif
#if defined (EL3HLT)
  ENTRY(EL3HLT, "EL3HLT", "Level 3 halted"),
#endif
#if defined (EL3RST)
  ENTRY(EL3RST, "EL3RST", "Level 3 reset"),
#endif
#if defined (ELNRNG)
  ENTRY(ELNRNG, "ELNRNG", "Link number out of range"),
#endif
#if defined (EUNATCH)
  ENTRY(EUNATCH, "EUNATCH", "Protocol driver not attached"),
#endif
#if defined (ENOCSI)
  ENTRY(ENOCSI, "ENOCSI", "No CSI structure available"),
#endif
#if defined (EL2HLT)
  ENTRY(EL2HLT, "EL2HLT", "Level 2 halted"),
#endif
#if defined (EDEADLK)
  ENTRY(EDEADLK, "EDEADLK", "Deadlock condition"),
#endif
#if defined (ENOLCK)
  ENTRY(ENOLCK, "ENOLCK", "No record locks available"),
#endif
#if defined (EBADE)
  ENTRY(EBADE, "EBADE", "Invalid exchange"),
#endif
#if defined (EBADR)
  ENTRY(EBADR, "EBADR", "Invalid request descriptor"),
#endif
#if defined (EXFULL)
  ENTRY(EXFULL, "EXFULL", "Exchange full"),
#endif
};
#endif // ERRORS_H
