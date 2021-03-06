/*
 * Copyright 2013 MongoDB, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef MONGOC_TESTS_H
#define MONGOC_TESTS_H


#ifdef BSON_DISABLE_ASSERT
# undef BSON_DISABLE_ASSERT
#endif


#ifdef BSON_DISABLE_CHECKS
# undef BSON_DISABLE_CHECKS
#endif


#include <assert.h>
#include <bson.h>
#include <stdio.h>
#include <time.h>
#ifdef _WIN32
# include <process.h>
#endif


BSON_BEGIN_DECLS


#ifdef _WIN32
# define gettestpid _getpid
#else
# define gettestpid getpid
#endif


#define assert_cmpstr(a, b)                                             \
   do {                                                                 \
      if (((a) != (b)) && !!strcmp((a), (b))) {                         \
         fprintf(stderr, "FAIL\n\nAssert Failure: \"%s\" != \"%s\"\n",  \
                         a, b);                                         \
         abort();                                                       \
      }                                                                 \
   } while (0)


#define assert_cmpint(a, eq, b)                                         \
   do {                                                                 \
      if (!((a) eq (b))) {                                              \
         fprintf(stderr, "FAIL\n\nAssert Failure: %d %s %d\n"           \
                         "%s:%d  %s()\n",                               \
                         a, #eq, b,                                     \
                         __FILE__, __LINE__, __FUNCTION__);             \
         abort();                                                       \
      }                                                                 \
   } while (0)


extern char *TEST_RESULT;

void
run_test (const char *name,
          void (*func) (void));

BSON_END_DECLS

#endif /* MONGOC_TESTS_H */
