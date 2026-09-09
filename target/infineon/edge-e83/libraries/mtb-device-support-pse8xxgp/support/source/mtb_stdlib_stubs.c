/***********************************************************************************************//**
 * \file mtb_stdlib_stubs.c
 *
 * \brief
 * Implementation of the stubs for the standard library functions for the GCC_ARM compiler.
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2018-2025 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **************************************************************************************************/
#if defined(__GNUC__) && !defined(__ARMCC_VERSION) && !defined(MTB_STDLIB_STUBS_DISABLE)

#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include "cy_utils.h"
#include "cmsis_compiler.h"

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Directive 4.6', 20, \
                             'Directive requires use of typedef input instead of int but signature for following APIs needs to match stlib one')

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 14, \
                             'Rule requires const attributes for inputs for following APIs but signature needs to match stlib one')
//--------------------------------------------------------------------------------------------------
// _read
//--------------------------------------------------------------------------------------------------
__WEAK int _read(int file, char* ptr, int len);
//--------------------------------------------------------------------------------------------------
// _read
//--------------------------------------------------------------------------------------------------
__WEAK int _read(int file, char* ptr, int len)
{
    CY_UNUSED_PARAMETER(file);
    CY_UNUSED_PARAMETER(ptr);
    CY_UNUSED_PARAMETER(len);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _write
//--------------------------------------------------------------------------------------------------
__WEAK int _write(int file, char* ptr, int len);
//--------------------------------------------------------------------------------------------------
// _write
//--------------------------------------------------------------------------------------------------
__WEAK int _write(int file, char* ptr, int len)
{
    CY_UNUSED_PARAMETER(file);
    CY_UNUSED_PARAMETER(ptr);
    CY_UNUSED_PARAMETER(len);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _fstat
//--------------------------------------------------------------------------------------------------
__WEAK int _fstat(int fildes, struct stat* st);

//--------------------------------------------------------------------------------------------------
// _fstat
//--------------------------------------------------------------------------------------------------
__WEAK int _fstat(int fildes, struct stat* st)
{
    CY_UNUSED_PARAMETER(fildes);
    CY_UNUSED_PARAMETER(st);
    errno = ENOSYS;
    //We don't want to assert at this point because willing or unwillingly
    //this function gets called but in a no-op way so we need to let it pass
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _open
//--------------------------------------------------------------------------------------------------
__WEAK int _open(char* file, int flags, int mode);
//--------------------------------------------------------------------------------------------------
// _open
//--------------------------------------------------------------------------------------------------
__WEAK int _open(char* file, int flags, int mode)
{
    CY_UNUSED_PARAMETER(file);
    CY_UNUSED_PARAMETER(flags);
    CY_UNUSED_PARAMETER(mode);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _close
//--------------------------------------------------------------------------------------------------
__WEAK int _close(int fildes);
//--------------------------------------------------------------------------------------------------
// _close
//--------------------------------------------------------------------------------------------------
__WEAK int _close(int fildes)
{
    CY_UNUSED_PARAMETER(fildes);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _lseek
//--------------------------------------------------------------------------------------------------
__WEAK int _lseek(int file, int ptr, int dir);
//--------------------------------------------------------------------------------------------------
// _lseek
//--------------------------------------------------------------------------------------------------
__WEAK int _lseek(int file, int ptr, int dir)
{
    CY_UNUSED_PARAMETER(file);
    CY_UNUSED_PARAMETER(ptr);
    CY_UNUSED_PARAMETER(dir);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _getpid
//--------------------------------------------------------------------------------------------------
__WEAK int _getpid(void);
//--------------------------------------------------------------------------------------------------
// _getpid
//--------------------------------------------------------------------------------------------------
__WEAK int _getpid(void)
{
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _isatty
//--------------------------------------------------------------------------------------------------
__WEAK int _isatty(int file);
//--------------------------------------------------------------------------------------------------
// _isatty
//--------------------------------------------------------------------------------------------------
__WEAK int _isatty(int file)
{
    CY_UNUSED_PARAMETER(file);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _kill
//--------------------------------------------------------------------------------------------------
__WEAK int _kill(int pid, int sig);
//--------------------------------------------------------------------------------------------------
// _kill
//--------------------------------------------------------------------------------------------------
__WEAK int _kill(int pid, int sig)
{
    CY_UNUSED_PARAMETER(pid);
    CY_UNUSED_PARAMETER(sig);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _chown
//--------------------------------------------------------------------------------------------------
__WEAK int _chown(const char* path, uid_t owner, gid_t group);
//--------------------------------------------------------------------------------------------------
// _chown
//--------------------------------------------------------------------------------------------------
__WEAK int _chown(const char* path, uid_t owner, gid_t group)
{
    CY_UNUSED_PARAMETER(path);
    CY_UNUSED_PARAMETER(owner);
    CY_UNUSED_PARAMETER(group);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _execve
//--------------------------------------------------------------------------------------------------
__WEAK int _execve(char* name, char** argv, char** env);
//--------------------------------------------------------------------------------------------------
// _execve
//--------------------------------------------------------------------------------------------------
__WEAK int _execve(char* name, char** argv, char** env)
{
    CY_UNUSED_PARAMETER(name);
    CY_UNUSED_PARAMETER(argv);
    CY_UNUSED_PARAMETER(env);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _fork
//--------------------------------------------------------------------------------------------------
__WEAK int _fork(void);
//--------------------------------------------------------------------------------------------------
// _fork
//--------------------------------------------------------------------------------------------------
__WEAK int _fork(void)
{
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _getentropy
//--------------------------------------------------------------------------------------------------
__WEAK int _getentropy(void* buf, size_t buflen);
//--------------------------------------------------------------------------------------------------
// _getentropy
//--------------------------------------------------------------------------------------------------
__WEAK int _getentropy(void* buf, size_t buflen)
{
    CY_UNUSED_PARAMETER(buf);
    CY_UNUSED_PARAMETER(buflen);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _gettimeofday
//--------------------------------------------------------------------------------------------------
__WEAK int _gettimeofday(struct timeval* ptimeval, void* ptimezone);
//--------------------------------------------------------------------------------------------------
// _gettimeofday
//--------------------------------------------------------------------------------------------------
__WEAK int _gettimeofday(struct timeval* ptimeval, void* ptimezone)
{
    CY_UNUSED_PARAMETER(ptimeval);
    CY_UNUSED_PARAMETER(ptimezone);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _link
//--------------------------------------------------------------------------------------------------
__WEAK int _link(char* existing, char* new);
//--------------------------------------------------------------------------------------------------
// _link
//--------------------------------------------------------------------------------------------------
__WEAK int _link(char* existing, char* new)
{
    CY_UNUSED_PARAMETER(existing);
    CY_UNUSED_PARAMETER(new);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _readlink
//--------------------------------------------------------------------------------------------------
__WEAK int _readlink(const char* path, char* buf, size_t bufsize);
//--------------------------------------------------------------------------------------------------
// _readlink
//--------------------------------------------------------------------------------------------------
__WEAK int _readlink(const char* path, char* buf, size_t bufsize)
{
    CY_UNUSED_PARAMETER(path);
    CY_UNUSED_PARAMETER(buf);
    CY_UNUSED_PARAMETER(bufsize);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _stat
//--------------------------------------------------------------------------------------------------
__WEAK int _stat(const char* file, struct stat* st);
//--------------------------------------------------------------------------------------------------
// _stat
//--------------------------------------------------------------------------------------------------
__WEAK int _stat(const char* file, struct stat* st)
{
    CY_UNUSED_PARAMETER(file);
    CY_UNUSED_PARAMETER(st);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _symlink
//--------------------------------------------------------------------------------------------------
__WEAK int _symlink(const char* path1, const char* path2);
//--------------------------------------------------------------------------------------------------
// _symlink
//--------------------------------------------------------------------------------------------------
__WEAK int _symlink(const char* path1, const char* path2)
{
    CY_UNUSED_PARAMETER(path1);
    CY_UNUSED_PARAMETER(path2);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _times
//--------------------------------------------------------------------------------------------------
__WEAK int _times(struct tms* buf);
//--------------------------------------------------------------------------------------------------
// _times
//--------------------------------------------------------------------------------------------------
__WEAK int _times(struct tms* buf)
{
    CY_UNUSED_PARAMETER(buf);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _unlink
//--------------------------------------------------------------------------------------------------
__WEAK int _unlink(char* name);
//--------------------------------------------------------------------------------------------------
// _unlink
//--------------------------------------------------------------------------------------------------
__WEAK int _unlink(char* name)
{
    CY_UNUSED_PARAMETER(name);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


//--------------------------------------------------------------------------------------------------
// _wait
//--------------------------------------------------------------------------------------------------
__WEAK int _wait(int* status);
//--------------------------------------------------------------------------------------------------
// _wait
//--------------------------------------------------------------------------------------------------
__WEAK int _wait(int* status)
{
    CY_UNUSED_PARAMETER(status);
    errno = ENOSYS;
    // If we reach this point, something went wrong
    CY_ASSERT(false);
    return -1;
}


CY_MISRA_BLOCK_END('MISRA C-2012 Directive 4.6')
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13')

#endif // if defined(__GNUC__) && !defined(__ARMCC_VERSION) && !defined(MTB_STDLIB_STUBS_DISABLE)
