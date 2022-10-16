/*
 * Library: libcrc
 * File:    include/checksum.h
 * Author:  Lammert Bies
 *
 * This file is licensed under the MIT License as stated below
 *
 * Copyright (c) 1999-2018 Lammert Bies
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Description
 * -----------
 * The headerfile include/checksum.h contains the definitions and prototypes
 * for routines that can be used to calculate several kinds of checksums.
 */

// clang-format off
#ifndef DEF_LIBCRC_CHECKSUM_H
#define DEF_LIBCRC_CHECKSUM_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LIBCRC_ENABLE_ALL
#define LIBCRC_CRC8_ENABLED
#define LIBCRC_CRC16_ENABLED
#define LIBCRC_CRC32_ENABLED
#define LIBCRC_CRC64_ENABLED
#define LIBCRC_CCITT_ENABLED
#define LIBCRC_DNP_ENABLED
#define LIBCRC_KERMIT_ENABLED
#define LIBCRC_SICK_ENABLED
#define LIBCRC_NMEA_ENABLED
#endif

/*
 * #define CRC_POLY_xxxx
 *
 * The constants of the form CRC_POLY_xxxx define the polynomials for some well
 * known CRC calculations.
 */

#ifdef LIBCRC_CRC16_ENABLED
#define	CRC_POLY_16		0xA001
#endif
#ifdef LIBCRC_CRC32_ENABLED
#define	CRC_POLY_32		0xEDB88320ul
#endif
#ifdef LIBCRC_CRC64_ENABLED
#define	CRC_POLY_64		0x42F0E1EBA9EA3693ull
#endif
#ifdef LIBCRC_CCITT_ENABLED
#define	CRC_POLY_CCITT	0x1021
#endif
#ifdef LIBCRC_DNP_ENABLED
#define	CRC_POLY_DNP	0xA6BC
#endif
#ifdef LIBCRC_KERMIT_ENABLED
#define	CRC_POLY_KERMIT	0x8408
#endif
#ifdef LIBCRC_SICK_ENABLED
#define	CRC_POLY_SICK	0x8005
#endif

/*
 * #define CRC_START_xxxx
 *
 * The constants of the form CRC_START_xxxx define the values that are used for
 * initialization of a CRC value for common used calculation methods.
 */

#ifdef LIBCRC_CRC8_ENABLED
#define		CRC_START_8		0x00
#endif
#ifdef LIBCRC_CRC16_ENABLED
#define		CRC_START_16		0x0000
#define		CRC_START_MODBUS	0xFFFF
#endif
#ifdef LIBCRC_CCITT_ENABLED
#define		CRC_START_XMODEM	0x0000
#define		CRC_START_CCITT_1D0F	0x1D0F
#define		CRC_START_CCITT_FFFF	0xFFFF
#endif
#ifdef LIBCRC_KERMIT_ENABLED
#define		CRC_START_KERMIT	0x0000
#endif
#ifdef LIBCRC_SICK_ENABLED
#define		CRC_START_SICK		0x0000
#endif
#ifdef LIBCRC_DNP_ENABLED
#define		CRC_START_DNP		0x0000
#endif
#ifdef LIBCRC_CRC32_ENABLED
#define		CRC_START_32		0xFFFFFFFFul
#endif
#ifdef LIBCRC_CRC64_ENABLED
#define		CRC_START_64_ECMA	0x0000000000000000ull
#define		CRC_START_64_WE		0xFFFFFFFFFFFFFFFFull
#endif

/*
 * Prototype list of global functions
 */

#ifdef LIBCRC_NMEA_ENABLED
unsigned char *		checksum_NMEA(      const unsigned char *input_str, unsigned char *result  );
#endif
#ifdef LIBCRC_CRC8_ENABLED
uint8_t			crc_8(              const unsigned char *input_str, size_t num_bytes       );
uint8_t			update_crc_8(       uint8_t  crc, unsigned char c                          );
#endif
#ifdef LIBCRC_CRC16_ENABLED
uint16_t		crc_16(             const unsigned char *input_str, size_t num_bytes       );
uint16_t		crc_modbus(         const unsigned char *input_str, size_t num_bytes       );
uint16_t		update_crc_16(      uint16_t crc, unsigned char c                          );
#endif
#ifdef LIBCRC_CRC32_ENABLED
uint32_t		crc_32(             const unsigned char *input_str, size_t num_bytes       );
uint32_t		update_crc_32(      uint32_t crc, unsigned char c                          );
#endif
#ifdef LIBCRC_CRC64_ENABLED
uint64_t		crc_64_ecma(        const unsigned char *input_str, size_t num_bytes       );
uint64_t		crc_64_we(          const unsigned char *input_str, size_t num_bytes       );
uint64_t		update_crc_64_ecma( uint64_t crc, unsigned char c                          );
#endif
#ifdef LIBCRC_CCITT_ENABLED
uint16_t		crc_ccitt_1d0f(     const unsigned char *input_str, size_t num_bytes       );
uint16_t		crc_ccitt_ffff(     const unsigned char *input_str, size_t num_bytes       );
uint16_t		crc_xmodem(         const unsigned char *input_str, size_t num_bytes       );
uint16_t		update_crc_ccitt(   uint16_t crc, unsigned char c                          );
#endif
#ifdef LIBCRC_DNP_ENABLED
uint16_t		crc_dnp(            const unsigned char *input_str, size_t num_bytes       );
uint16_t		update_crc_dnp(     uint16_t crc, unsigned char c                          );
#endif
#ifdef LIBCRC_KERMIT_ENABLED
uint16_t		crc_kermit(         const unsigned char *input_str, size_t num_bytes       );
uint16_t		update_crc_kermit(  uint16_t crc, unsigned char c                          );
#endif
#ifdef LIBCRC_SICK_ENABLED
uint16_t		crc_sick(           const unsigned char *input_str, size_t num_bytes       );
uint16_t		update_crc_sick(    uint16_t crc, unsigned char c, unsigned char prev_byte );
#endif

/*
 * Global CRC lookup tables
 */

#ifdef LIBCRC_CRC32_ENABLED
extern const uint32_t	crc_tab32[];
#endif
#ifdef LIBCRC_CRC64_ENABLED
extern const uint64_t	crc_tab64[];
#endif

#ifdef __cplusplus
}// Extern C
#endif

#endif  // DEF_LIBCRC_CHECKSUM_H
// clang-format on