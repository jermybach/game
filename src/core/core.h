#pragma once

#if defined(_WIN32)
#define OS_WINDOWS 1
#endif

#ifndef OS_WINDOWS
#define OS_WINDOWS 0
#endif

#if defined(_MSC_VER)
#define COMPILER_CL 1
#endif

#ifndef COMPILER_CL
#define COMPILER_CL 0
#endif

#include <assert.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#include "basetypes.h"
#include "debug.h"
#include "macros.h"
#include "memory.h"
#include "math/minmax.h"
#include "threads.h"
#include "strutils.h"