/*
	Licensed to the Apache Software Foundation (ASF) under one
	or more contributor license agreements.  See the NOTICE file
	distributed with this work for additional information
	regarding copyright ownership.  The ASF licenses this file
	to you under the Apache License, Version 2.0 (the
	"License"); you may not use this file except in compliance
	with the License.  You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing,
	software distributed under the License is distributed on an
	"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
	KIND, either express or implied.  See the License for the
	specific language governing permissions and limitations
	under the License.
*/

/* Architecture definition header file */

/**
 * @file arch.h
 * @author Mike Scott
 * @date 23rd February 2016
 * @brief Architecture Header File
 *
 * Specify Processor Architecture
 *
 */

/* NOTE: There is only one user configurable section in this header - see below */

#ifndef ARCH_H
#define ARCH_H
#include <stdint.h>

namespace amcl {

/*** START OF USER CONFIGURABLE SECTION - set architecture ***/

#define CHUNK @WL@		/**< size of chunk in bits = wordlength of computer = 16, 32 or 64. Note not all curve options are supported on 16-bit processors - see rom.c */

/*** END OF USER CONFIGURABLE SECTION ***/

/* Create Integer types */
/* Support for C99?  Note for GCC need to explicitly include -std=c99 in command line */


using byte = uint8_t;			/**< 8-bit unsigned integer */
using sign8 = int8_t;			/**< 8-bit signed integer */
using sign16 = int16_t;			/**< 16-bit signed integer */
using sign32 = int32_t;			/**< 32-bit signed integer */
using sign64 = int64_t;			/**< 64-bit signed integer */
using unsign32 = uint32_t;		/**< 32-bit unsigned integer */
using unsign64 = uint64_t;		/**< 64-bit unsigned integer */

#define uchar unsigned char  /**<  Unsigned char */

/* Don't mess with anything below this line unless you know what you are doing */
/* This next is probably OK, but may need changing for non-C99-standard environments */

/* This next is probably OK, but may need changing for non-C99-standard environments */

#if CHUNK==16

#define chunk int16_t		/**< C type corresponding to word length */
#define dchunk int32_t		/**< Always define double length chunk type if available */

#endif

#if CHUNK == 32

#define chunk int32_t		/**< C type corresponding to word length */
#define dchunk int64_t		/**< Always define double length chunk type if available */

#endif

#if CHUNK == 64

    #define chunk int64_t		/**< C type corresponding to word length */
    #ifdef __GNUC__
       #define dchunk __int128		/**< Always define double length chunk type if available - GCC supports 128 bit type  ??? */
    #endif

    #ifdef __clang__
       #define dchunk __int128
    #endif

#endif

#ifdef dchunk
#define COMBA      /**< Use COMBA method for faster muls, sqrs and reductions */
#endif

}

#endif
