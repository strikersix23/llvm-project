//===----------------- LLDBAssert.h ------------------------------*- C++-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_UTILITY_LLDBASSERT_H
#define LLDB_UTILITY_LLDBASSERT_H

#include "llvm/ADT/StringRef.h"
#include <mutex>

#ifndef NDEBUG
#define lldbassert(x) assert(x)
#else
#if defined(__clang__)
// __FILE_NAME__ is a Clang-specific extension that functions similar to
// __FILE__ but only renders the last path component (the filename) instead of
// an invocation dependent full path to that file.
#define lldbassert(x)                                                          \
  do {                                                                         \
    static std::once_flag _once_flag;                                          \
    lldb_private::_lldb_assert(static_cast<bool>(x), #x, __FUNCTION__,         \
                               __FILE_NAME__, __LINE__, _once_flag);           \
  } while (0)
#else
#define lldbassert(x)                                                          \
  do {                                                                         \
    static std::once_flag _once_flag;                                          \
    lldb_private::_lldb_assert(static_cast<bool>(x), #x, __FUNCTION__,         \
                               __FILE__,  __LINE__, _once_flag);               \
  } while (0)
#endif
#endif

namespace lldb_private {

/// Don't use _lldb_assert directly. Use the lldbassert macro instead so that
/// LLDB asserts become regular asserts in NDEBUG builds.
void _lldb_assert(bool expression, const char *expr_text, const char *func,
                  const char *file, unsigned int line,
                  std::once_flag &once_flag);

/// The default LLDB assert callback, which prints to stderr.
typedef void (*LLDBAssertCallback)(llvm::StringRef message,
                                   llvm::StringRef backtrace,
                                   llvm::StringRef prompt);

/// Replace the LLDB assert callback.
void SetLLDBAssertCallback(LLDBAssertCallback callback);

} // namespace lldb_private

#endif // LLDB_UTILITY_LLDBASSERT_H
