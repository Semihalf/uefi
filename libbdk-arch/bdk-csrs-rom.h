#ifndef __BDK_CSRS_ROM__
#define __BDK_CSRS_ROM__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2014  Cavium Networks (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.

 *   * Neither the name of Cavium Networks nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.

 * This Software, including technical data, may be subject to U.S. export  control
 * laws, including the U.S. Export Administration Act and its  associated
 * regulations, and may be subject to export or import  regulations in other
 * countries.

 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR
 * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO
 * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR
 * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM
 * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,
 * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF
 * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR
 * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 ***********************license end**************************************/


/**
 * @file
 *
 * Configuration and status register (CSR) address and type definitions for
 * Cavium ROM.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration ROM_CRYPT_E
 *
 * ROM Crypt Enumeration
 * Enumerates the values of ROM_CSIB_S[CRYPT].
 */
enum rom_crypt_e {
	ROM_CRYPT_E_BSSK = 0x2,
	ROM_CRYPT_E_NONE = 0x0,
	ROM_CRYPT_E_SSK = 0x1,
	ROM_CRYPT_E_ENUM_LAST = 0x3,
};

/**
 * Enumeration ROM_XFER_MSG_E
 *
 * ROM Boot Transfer Message Enumeration
 * Enumerates the messages written to OCX_TLK()_LNK_DATA<15:0> and read from
 * OCX_RLK()_LNK_DATA<15:0> during ROM boot.
 * In these descriptions:
 *   * "Client" refers to the ROM code on the CNXXXX which is booting.
 *   * "Server" refers to the code running on another node which is serving an image
 *     into the client.
 */
enum rom_xfer_msg_e {
	ROM_XFER_MSG_E_BOOT_DONE = 0x2002,
	ROM_XFER_MSG_E_BOOT_ERROR = 0x2001,
	ROM_XFER_MSG_E_BOOT_READ0 = 0x3000,
	ROM_XFER_MSG_E_BOOT_READ1 = 0x3001,
	ROM_XFER_MSG_E_BOOT_READ10 = 0x300a,
	ROM_XFER_MSG_E_BOOT_READ100 = 0x3064,
	ROM_XFER_MSG_E_BOOT_READ101 = 0x3065,
	ROM_XFER_MSG_E_BOOT_READ102 = 0x3066,
	ROM_XFER_MSG_E_BOOT_READ103 = 0x3067,
	ROM_XFER_MSG_E_BOOT_READ104 = 0x3068,
	ROM_XFER_MSG_E_BOOT_READ105 = 0x3069,
	ROM_XFER_MSG_E_BOOT_READ106 = 0x306a,
	ROM_XFER_MSG_E_BOOT_READ107 = 0x306b,
	ROM_XFER_MSG_E_BOOT_READ108 = 0x306c,
	ROM_XFER_MSG_E_BOOT_READ109 = 0x306d,
	ROM_XFER_MSG_E_BOOT_READ11 = 0x300b,
	ROM_XFER_MSG_E_BOOT_READ110 = 0x306e,
	ROM_XFER_MSG_E_BOOT_READ111 = 0x306f,
	ROM_XFER_MSG_E_BOOT_READ112 = 0x3070,
	ROM_XFER_MSG_E_BOOT_READ113 = 0x3071,
	ROM_XFER_MSG_E_BOOT_READ114 = 0x3072,
	ROM_XFER_MSG_E_BOOT_READ115 = 0x3073,
	ROM_XFER_MSG_E_BOOT_READ116 = 0x3074,
	ROM_XFER_MSG_E_BOOT_READ117 = 0x3075,
	ROM_XFER_MSG_E_BOOT_READ118 = 0x3076,
	ROM_XFER_MSG_E_BOOT_READ119 = 0x3077,
	ROM_XFER_MSG_E_BOOT_READ12 = 0x300c,
	ROM_XFER_MSG_E_BOOT_READ120 = 0x3078,
	ROM_XFER_MSG_E_BOOT_READ121 = 0x3079,
	ROM_XFER_MSG_E_BOOT_READ122 = 0x307a,
	ROM_XFER_MSG_E_BOOT_READ123 = 0x307b,
	ROM_XFER_MSG_E_BOOT_READ124 = 0x307c,
	ROM_XFER_MSG_E_BOOT_READ125 = 0x307d,
	ROM_XFER_MSG_E_BOOT_READ126 = 0x307e,
	ROM_XFER_MSG_E_BOOT_READ127 = 0x307f,
	ROM_XFER_MSG_E_BOOT_READ128 = 0x3080,
	ROM_XFER_MSG_E_BOOT_READ129 = 0x3081,
	ROM_XFER_MSG_E_BOOT_READ13 = 0x300d,
	ROM_XFER_MSG_E_BOOT_READ130 = 0x3082,
	ROM_XFER_MSG_E_BOOT_READ131 = 0x3083,
	ROM_XFER_MSG_E_BOOT_READ132 = 0x3084,
	ROM_XFER_MSG_E_BOOT_READ133 = 0x3085,
	ROM_XFER_MSG_E_BOOT_READ134 = 0x3086,
	ROM_XFER_MSG_E_BOOT_READ135 = 0x3087,
	ROM_XFER_MSG_E_BOOT_READ136 = 0x3088,
	ROM_XFER_MSG_E_BOOT_READ137 = 0x3089,
	ROM_XFER_MSG_E_BOOT_READ138 = 0x308a,
	ROM_XFER_MSG_E_BOOT_READ139 = 0x308b,
	ROM_XFER_MSG_E_BOOT_READ14 = 0x300e,
	ROM_XFER_MSG_E_BOOT_READ140 = 0x308c,
	ROM_XFER_MSG_E_BOOT_READ141 = 0x308d,
	ROM_XFER_MSG_E_BOOT_READ142 = 0x308e,
	ROM_XFER_MSG_E_BOOT_READ143 = 0x308f,
	ROM_XFER_MSG_E_BOOT_READ144 = 0x3090,
	ROM_XFER_MSG_E_BOOT_READ145 = 0x3091,
	ROM_XFER_MSG_E_BOOT_READ146 = 0x3092,
	ROM_XFER_MSG_E_BOOT_READ147 = 0x3093,
	ROM_XFER_MSG_E_BOOT_READ148 = 0x3094,
	ROM_XFER_MSG_E_BOOT_READ149 = 0x3095,
	ROM_XFER_MSG_E_BOOT_READ15 = 0x300f,
	ROM_XFER_MSG_E_BOOT_READ150 = 0x3096,
	ROM_XFER_MSG_E_BOOT_READ151 = 0x3097,
	ROM_XFER_MSG_E_BOOT_READ152 = 0x3098,
	ROM_XFER_MSG_E_BOOT_READ153 = 0x3099,
	ROM_XFER_MSG_E_BOOT_READ154 = 0x309a,
	ROM_XFER_MSG_E_BOOT_READ155 = 0x309b,
	ROM_XFER_MSG_E_BOOT_READ156 = 0x309c,
	ROM_XFER_MSG_E_BOOT_READ157 = 0x309d,
	ROM_XFER_MSG_E_BOOT_READ158 = 0x309e,
	ROM_XFER_MSG_E_BOOT_READ159 = 0x309f,
	ROM_XFER_MSG_E_BOOT_READ16 = 0x3010,
	ROM_XFER_MSG_E_BOOT_READ160 = 0x30a0,
	ROM_XFER_MSG_E_BOOT_READ161 = 0x30a1,
	ROM_XFER_MSG_E_BOOT_READ162 = 0x30a2,
	ROM_XFER_MSG_E_BOOT_READ163 = 0x30a3,
	ROM_XFER_MSG_E_BOOT_READ164 = 0x30a4,
	ROM_XFER_MSG_E_BOOT_READ165 = 0x30a5,
	ROM_XFER_MSG_E_BOOT_READ166 = 0x30a6,
	ROM_XFER_MSG_E_BOOT_READ167 = 0x30a7,
	ROM_XFER_MSG_E_BOOT_READ168 = 0x30a8,
	ROM_XFER_MSG_E_BOOT_READ169 = 0x30a9,
	ROM_XFER_MSG_E_BOOT_READ17 = 0x3011,
	ROM_XFER_MSG_E_BOOT_READ170 = 0x30aa,
	ROM_XFER_MSG_E_BOOT_READ171 = 0x30ab,
	ROM_XFER_MSG_E_BOOT_READ172 = 0x30ac,
	ROM_XFER_MSG_E_BOOT_READ173 = 0x30ad,
	ROM_XFER_MSG_E_BOOT_READ174 = 0x30ae,
	ROM_XFER_MSG_E_BOOT_READ175 = 0x30af,
	ROM_XFER_MSG_E_BOOT_READ176 = 0x30b0,
	ROM_XFER_MSG_E_BOOT_READ177 = 0x30b1,
	ROM_XFER_MSG_E_BOOT_READ178 = 0x30b2,
	ROM_XFER_MSG_E_BOOT_READ179 = 0x30b3,
	ROM_XFER_MSG_E_BOOT_READ18 = 0x3012,
	ROM_XFER_MSG_E_BOOT_READ180 = 0x30b4,
	ROM_XFER_MSG_E_BOOT_READ181 = 0x30b5,
	ROM_XFER_MSG_E_BOOT_READ182 = 0x30b6,
	ROM_XFER_MSG_E_BOOT_READ183 = 0x30b7,
	ROM_XFER_MSG_E_BOOT_READ184 = 0x30b8,
	ROM_XFER_MSG_E_BOOT_READ185 = 0x30b9,
	ROM_XFER_MSG_E_BOOT_READ186 = 0x30ba,
	ROM_XFER_MSG_E_BOOT_READ187 = 0x30bb,
	ROM_XFER_MSG_E_BOOT_READ188 = 0x30bc,
	ROM_XFER_MSG_E_BOOT_READ189 = 0x30bd,
	ROM_XFER_MSG_E_BOOT_READ19 = 0x3013,
	ROM_XFER_MSG_E_BOOT_READ190 = 0x30be,
	ROM_XFER_MSG_E_BOOT_READ191 = 0x30bf,
	ROM_XFER_MSG_E_BOOT_READ192 = 0x30c0,
	ROM_XFER_MSG_E_BOOT_READ193 = 0x30c1,
	ROM_XFER_MSG_E_BOOT_READ194 = 0x30c2,
	ROM_XFER_MSG_E_BOOT_READ195 = 0x30c3,
	ROM_XFER_MSG_E_BOOT_READ196 = 0x30c4,
	ROM_XFER_MSG_E_BOOT_READ197 = 0x30c5,
	ROM_XFER_MSG_E_BOOT_READ198 = 0x30c6,
	ROM_XFER_MSG_E_BOOT_READ199 = 0x30c7,
	ROM_XFER_MSG_E_BOOT_READ2 = 0x3002,
	ROM_XFER_MSG_E_BOOT_READ20 = 0x3014,
	ROM_XFER_MSG_E_BOOT_READ200 = 0x30c8,
	ROM_XFER_MSG_E_BOOT_READ201 = 0x30c9,
	ROM_XFER_MSG_E_BOOT_READ202 = 0x30ca,
	ROM_XFER_MSG_E_BOOT_READ203 = 0x30cb,
	ROM_XFER_MSG_E_BOOT_READ204 = 0x30cc,
	ROM_XFER_MSG_E_BOOT_READ205 = 0x30cd,
	ROM_XFER_MSG_E_BOOT_READ206 = 0x30ce,
	ROM_XFER_MSG_E_BOOT_READ207 = 0x30cf,
	ROM_XFER_MSG_E_BOOT_READ208 = 0x30d0,
	ROM_XFER_MSG_E_BOOT_READ209 = 0x30d1,
	ROM_XFER_MSG_E_BOOT_READ21 = 0x3015,
	ROM_XFER_MSG_E_BOOT_READ210 = 0x30d2,
	ROM_XFER_MSG_E_BOOT_READ211 = 0x30d3,
	ROM_XFER_MSG_E_BOOT_READ212 = 0x30d4,
	ROM_XFER_MSG_E_BOOT_READ213 = 0x30d5,
	ROM_XFER_MSG_E_BOOT_READ214 = 0x30d6,
	ROM_XFER_MSG_E_BOOT_READ215 = 0x30d7,
	ROM_XFER_MSG_E_BOOT_READ216 = 0x30d8,
	ROM_XFER_MSG_E_BOOT_READ217 = 0x30d9,
	ROM_XFER_MSG_E_BOOT_READ218 = 0x30da,
	ROM_XFER_MSG_E_BOOT_READ219 = 0x30db,
	ROM_XFER_MSG_E_BOOT_READ22 = 0x3016,
	ROM_XFER_MSG_E_BOOT_READ220 = 0x30dc,
	ROM_XFER_MSG_E_BOOT_READ221 = 0x30dd,
	ROM_XFER_MSG_E_BOOT_READ222 = 0x30de,
	ROM_XFER_MSG_E_BOOT_READ223 = 0x30df,
	ROM_XFER_MSG_E_BOOT_READ224 = 0x30e0,
	ROM_XFER_MSG_E_BOOT_READ225 = 0x30e1,
	ROM_XFER_MSG_E_BOOT_READ226 = 0x30e2,
	ROM_XFER_MSG_E_BOOT_READ227 = 0x30e3,
	ROM_XFER_MSG_E_BOOT_READ228 = 0x30e4,
	ROM_XFER_MSG_E_BOOT_READ229 = 0x30e5,
	ROM_XFER_MSG_E_BOOT_READ23 = 0x3017,
	ROM_XFER_MSG_E_BOOT_READ230 = 0x30e6,
	ROM_XFER_MSG_E_BOOT_READ231 = 0x30e7,
	ROM_XFER_MSG_E_BOOT_READ232 = 0x30e8,
	ROM_XFER_MSG_E_BOOT_READ233 = 0x30e9,
	ROM_XFER_MSG_E_BOOT_READ234 = 0x30ea,
	ROM_XFER_MSG_E_BOOT_READ235 = 0x30eb,
	ROM_XFER_MSG_E_BOOT_READ236 = 0x30ec,
	ROM_XFER_MSG_E_BOOT_READ237 = 0x30ed,
	ROM_XFER_MSG_E_BOOT_READ238 = 0x30ee,
	ROM_XFER_MSG_E_BOOT_READ239 = 0x30ef,
	ROM_XFER_MSG_E_BOOT_READ24 = 0x3018,
	ROM_XFER_MSG_E_BOOT_READ240 = 0x30f0,
	ROM_XFER_MSG_E_BOOT_READ241 = 0x30f1,
	ROM_XFER_MSG_E_BOOT_READ242 = 0x30f2,
	ROM_XFER_MSG_E_BOOT_READ243 = 0x30f3,
	ROM_XFER_MSG_E_BOOT_READ244 = 0x30f4,
	ROM_XFER_MSG_E_BOOT_READ245 = 0x30f5,
	ROM_XFER_MSG_E_BOOT_READ246 = 0x30f6,
	ROM_XFER_MSG_E_BOOT_READ247 = 0x30f7,
	ROM_XFER_MSG_E_BOOT_READ248 = 0x30f8,
	ROM_XFER_MSG_E_BOOT_READ249 = 0x30f9,
	ROM_XFER_MSG_E_BOOT_READ25 = 0x3019,
	ROM_XFER_MSG_E_BOOT_READ250 = 0x30fa,
	ROM_XFER_MSG_E_BOOT_READ251 = 0x30fb,
	ROM_XFER_MSG_E_BOOT_READ252 = 0x30fc,
	ROM_XFER_MSG_E_BOOT_READ253 = 0x30fd,
	ROM_XFER_MSG_E_BOOT_READ254 = 0x30fe,
	ROM_XFER_MSG_E_BOOT_READ255 = 0x30ff,
	ROM_XFER_MSG_E_BOOT_READ26 = 0x301a,
	ROM_XFER_MSG_E_BOOT_READ27 = 0x301b,
	ROM_XFER_MSG_E_BOOT_READ28 = 0x301c,
	ROM_XFER_MSG_E_BOOT_READ29 = 0x301d,
	ROM_XFER_MSG_E_BOOT_READ3 = 0x3003,
	ROM_XFER_MSG_E_BOOT_READ30 = 0x301e,
	ROM_XFER_MSG_E_BOOT_READ31 = 0x301f,
	ROM_XFER_MSG_E_BOOT_READ32 = 0x3020,
	ROM_XFER_MSG_E_BOOT_READ33 = 0x3021,
	ROM_XFER_MSG_E_BOOT_READ34 = 0x3022,
	ROM_XFER_MSG_E_BOOT_READ35 = 0x3023,
	ROM_XFER_MSG_E_BOOT_READ36 = 0x3024,
	ROM_XFER_MSG_E_BOOT_READ37 = 0x3025,
	ROM_XFER_MSG_E_BOOT_READ38 = 0x3026,
	ROM_XFER_MSG_E_BOOT_READ39 = 0x3027,
	ROM_XFER_MSG_E_BOOT_READ4 = 0x3004,
	ROM_XFER_MSG_E_BOOT_READ40 = 0x3028,
	ROM_XFER_MSG_E_BOOT_READ41 = 0x3029,
	ROM_XFER_MSG_E_BOOT_READ42 = 0x302a,
	ROM_XFER_MSG_E_BOOT_READ43 = 0x302b,
	ROM_XFER_MSG_E_BOOT_READ44 = 0x302c,
	ROM_XFER_MSG_E_BOOT_READ45 = 0x302d,
	ROM_XFER_MSG_E_BOOT_READ46 = 0x302e,
	ROM_XFER_MSG_E_BOOT_READ47 = 0x302f,
	ROM_XFER_MSG_E_BOOT_READ48 = 0x3030,
	ROM_XFER_MSG_E_BOOT_READ49 = 0x3031,
	ROM_XFER_MSG_E_BOOT_READ5 = 0x3005,
	ROM_XFER_MSG_E_BOOT_READ50 = 0x3032,
	ROM_XFER_MSG_E_BOOT_READ51 = 0x3033,
	ROM_XFER_MSG_E_BOOT_READ52 = 0x3034,
	ROM_XFER_MSG_E_BOOT_READ53 = 0x3035,
	ROM_XFER_MSG_E_BOOT_READ54 = 0x3036,
	ROM_XFER_MSG_E_BOOT_READ55 = 0x3037,
	ROM_XFER_MSG_E_BOOT_READ56 = 0x3038,
	ROM_XFER_MSG_E_BOOT_READ57 = 0x3039,
	ROM_XFER_MSG_E_BOOT_READ58 = 0x303a,
	ROM_XFER_MSG_E_BOOT_READ59 = 0x303b,
	ROM_XFER_MSG_E_BOOT_READ6 = 0x3006,
	ROM_XFER_MSG_E_BOOT_READ60 = 0x303c,
	ROM_XFER_MSG_E_BOOT_READ61 = 0x303d,
	ROM_XFER_MSG_E_BOOT_READ62 = 0x303e,
	ROM_XFER_MSG_E_BOOT_READ63 = 0x303f,
	ROM_XFER_MSG_E_BOOT_READ64 = 0x3040,
	ROM_XFER_MSG_E_BOOT_READ65 = 0x3041,
	ROM_XFER_MSG_E_BOOT_READ66 = 0x3042,
	ROM_XFER_MSG_E_BOOT_READ67 = 0x3043,
	ROM_XFER_MSG_E_BOOT_READ68 = 0x3044,
	ROM_XFER_MSG_E_BOOT_READ69 = 0x3045,
	ROM_XFER_MSG_E_BOOT_READ7 = 0x3007,
	ROM_XFER_MSG_E_BOOT_READ70 = 0x3046,
	ROM_XFER_MSG_E_BOOT_READ71 = 0x3047,
	ROM_XFER_MSG_E_BOOT_READ72 = 0x3048,
	ROM_XFER_MSG_E_BOOT_READ73 = 0x3049,
	ROM_XFER_MSG_E_BOOT_READ74 = 0x304a,
	ROM_XFER_MSG_E_BOOT_READ75 = 0x304b,
	ROM_XFER_MSG_E_BOOT_READ76 = 0x304c,
	ROM_XFER_MSG_E_BOOT_READ77 = 0x304d,
	ROM_XFER_MSG_E_BOOT_READ78 = 0x304e,
	ROM_XFER_MSG_E_BOOT_READ79 = 0x304f,
	ROM_XFER_MSG_E_BOOT_READ8 = 0x3008,
	ROM_XFER_MSG_E_BOOT_READ80 = 0x3050,
	ROM_XFER_MSG_E_BOOT_READ81 = 0x3051,
	ROM_XFER_MSG_E_BOOT_READ82 = 0x3052,
	ROM_XFER_MSG_E_BOOT_READ83 = 0x3053,
	ROM_XFER_MSG_E_BOOT_READ84 = 0x3054,
	ROM_XFER_MSG_E_BOOT_READ85 = 0x3055,
	ROM_XFER_MSG_E_BOOT_READ86 = 0x3056,
	ROM_XFER_MSG_E_BOOT_READ87 = 0x3057,
	ROM_XFER_MSG_E_BOOT_READ88 = 0x3058,
	ROM_XFER_MSG_E_BOOT_READ89 = 0x3059,
	ROM_XFER_MSG_E_BOOT_READ9 = 0x3009,
	ROM_XFER_MSG_E_BOOT_READ90 = 0x305a,
	ROM_XFER_MSG_E_BOOT_READ91 = 0x305b,
	ROM_XFER_MSG_E_BOOT_READ92 = 0x305c,
	ROM_XFER_MSG_E_BOOT_READ93 = 0x305d,
	ROM_XFER_MSG_E_BOOT_READ94 = 0x305e,
	ROM_XFER_MSG_E_BOOT_READ95 = 0x305f,
	ROM_XFER_MSG_E_BOOT_READ96 = 0x3060,
	ROM_XFER_MSG_E_BOOT_READ97 = 0x3061,
	ROM_XFER_MSG_E_BOOT_READ98 = 0x3062,
	ROM_XFER_MSG_E_BOOT_READ99 = 0x3063,
	ROM_XFER_MSG_E_BOOT_START = 0x2000,
	ROM_XFER_MSG_E_NONE = 0x0,
	ROM_XFER_MSG_E_SERVER_ACK = 0x1000,
	ROM_XFER_MSG_E_SERVER_ERROR = 0x1001,
	ROM_XFER_MSG_E_ENUM_LAST = 0x3100,
};


/**
 * Structure ROM_CLIB_S
 *
 * ROM Code Load Information-Block Structure
 * This 256-byte structure is stored in Flash to specify how an image is loaded by the on-chip
 * boot ROM. This structure is neither signed nor encrypted.
 *
 * All fields in this structure are stored in the Flash in little-endian order.
 */
union rom_clib_s {
	uint64_t u[32];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1984_2047          : 64; /**< [2047:1984] Reserved. */
		uint64_t reserved_1920_1983          : 64; /**< [1983:1920] Reserved. */
		uint64_t reserved_1856_1919          : 64; /**< [1919:1856] Reserved. */
		uint64_t reserved_1792_1855          : 64; /**< [1855:1792] Reserved. */
		uint64_t reserved_1728_1791          : 64; /**< [1791:1728] Reserved. */
		uint64_t reserved_1664_1727          : 64; /**< [1727:1664] Reserved. */
		uint64_t reserved_1600_1663          : 64; /**< [1663:1600] Reserved. */
		uint64_t reserved_1536_1599          : 64; /**< [1599:1536] Reserved. */
		uint64_t reserved_1472_1535          : 64; /**< [1535:1472] Reserved. */
		uint64_t reserved_1408_1471          : 64; /**< [1471:1408] Reserved. */
		uint64_t reserved_1344_1407          : 64; /**< [1407:1344] Reserved. */
		uint64_t reserved_1280_1343          : 64; /**< [1343:1280] Reserved. */
		uint64_t reserved_1216_1279          : 64; /**< [1279:1216] Reserved. */
		uint64_t reserved_1152_1215          : 64; /**< [1215:1152] Reserved. */
		uint64_t reserved_1088_1151          : 64; /**< [1151:1088] Reserved. */
		uint64_t reserved_1024_1087          : 64; /**< [1087:1024] Reserved. */
		uint64_t csib_sign7                  : 64; /**< [1023:960] CSIB signature, word 7. */
		uint64_t csib_sign6                  : 64; /**< [959:896] CSIB signature, word 6. */
		uint64_t csib_sign5                  : 64; /**< [895:832] CSIB signature, word 5. */
		uint64_t csib_sign4                  : 64; /**< [831:768] CSIB signature, word 4. */
		uint64_t csib_sign3                  : 64; /**< [767:704] CSIB signature, word 3. */
		uint64_t csib_sign2                  : 64; /**< [703:640] CSIB signature, word 2. */
		uint64_t csib_sign1                  : 64; /**< [639:576] CSIB signature, word 1. */
		uint64_t csib_sign0                  : 64; /**< [575:512] CSIB signature, word 0. If this ROM_CLIB_S corresponds to a trusted image, this
                                                                 contains a EC-DSA signature across the 128 bytes of the ROM_CSIB_S. The
                                                                 signature must authenticate against ROM_CSIB_S[ROTPK*] for trusted boot to proceed. */
		uint64_t reserved_448_511            : 64; /**< [511:448] Reserved. */
		uint64_t reserved_384_447            : 64; /**< [447:384] Reserved. */
		uint64_t reserved_320_383            : 64; /**< [383:320] Reserved. */
		uint64_t reserved_256_319            : 64; /**< [319:256] Reserved. */
		uint64_t size                        : 64; /**< [255:192] Size. The size of the TBL1FW material in bytes.  Must be 192 KB (0x30000).

                                                                 INTERNAL: Future ROM code may allow this to be mode flexible.
                                                                 If so, must be in increments of 1 KB.
                                                                 For simulation purposes if MIO_FUS_DAT2[ROM_INFO<5>] is
                                                                 set, there is only 4 KB of NBL1FW and TBL1FW code, at
                                                                 addresses 0x20000 - 0x20FFFF and 0x21000 - 0x21FFFF. */
		uint64_t offset                      : 64; /**< [191:128] Offset address. The flash address for first byte of image.
                                                                 Must be 0x20000 for NBL1FW, 0x50000 for TBL1FW.

                                                                 In NBL1FW, the first 256 bytes are ignored, should be zeroes or random data.

                                                                 In TBL1FW, the first 256 bytes of the image should be
                                                                 random data for cypher security.  The first instruction
                                                                 executed will be at [OFFSET] + 0x100.

                                                                 INTERNAL: Future ROM code may allow this to be more flexible.
                                                                 If so, must be aligned to 1 KB. Must be >= 1 KB (past the
                                                                 ROM_CLIB_S and ROM_CSIB_S headers). */
		uint64_t ver                         : 8;  /**< [127:120] Version number.  0x0 to indicate first version of this format.
                                                                 INTERNAL: Opaque to ROM, until we have a second version. */
		uint64_t reserved_64_119             : 56; /**< [119: 64] Reserved. */
		uint64_t magic                       : 64; /**< [ 63:  0] Magic number.  Contains "CVM_CLIB" in ASCII (0x42494c43_5f4d5643)
                                                                 to indicate a valid ROM_CLIB_S structure. */
#else
		uint64_t magic                       : 64;
		uint64_t reserved_64_119             : 56;
		uint64_t ver                         : 8;
		uint64_t offset                      : 64;
		uint64_t size                        : 64;
		uint64_t reserved_256_319            : 64;
		uint64_t reserved_320_383            : 64;
		uint64_t reserved_384_447            : 64;
		uint64_t reserved_448_511            : 64;
		uint64_t csib_sign0                  : 64;
		uint64_t csib_sign1                  : 64;
		uint64_t csib_sign2                  : 64;
		uint64_t csib_sign3                  : 64;
		uint64_t csib_sign4                  : 64;
		uint64_t csib_sign5                  : 64;
		uint64_t csib_sign6                  : 64;
		uint64_t csib_sign7                  : 64;
		uint64_t reserved_1024_1087          : 64;
		uint64_t reserved_1088_1151          : 64;
		uint64_t reserved_1152_1215          : 64;
		uint64_t reserved_1216_1279          : 64;
		uint64_t reserved_1280_1343          : 64;
		uint64_t reserved_1344_1407          : 64;
		uint64_t reserved_1408_1471          : 64;
		uint64_t reserved_1472_1535          : 64;
		uint64_t reserved_1536_1599          : 64;
		uint64_t reserved_1600_1663          : 64;
		uint64_t reserved_1664_1727          : 64;
		uint64_t reserved_1728_1791          : 64;
		uint64_t reserved_1792_1855          : 64;
		uint64_t reserved_1856_1919          : 64;
		uint64_t reserved_1920_1983          : 64;
		uint64_t reserved_1984_2047          : 64;
#endif
	} s;
};

/**
 * Structure ROM_CSIB_S
 *
 * ROM Code Signature Information-Block Structure
 * All fields in this structure are stored in the Flash in little-endian order.
 */
union rom_csib_s {
	uint64_t u[32];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nonce3                      : 64; /**< [2047:1984] Nonce, continued. */
		uint64_t nonce2                      : 64; /**< [1983:1920] Nonce, continued. */
		uint64_t nonce1                      : 64; /**< [1919:1856] Nonce, continued. */
		uint64_t nonce0                      : 64; /**< [1855:1792] Nonce, word 0.  Opaque to ROM code, for hash hardening.
                                                                 The certificate signer assigns this random nonce to the certificate. */
		uint64_t uuid1                       : 64; /**< [1791:1728] Reserved for software for use as name/UUID, continued. */
		uint64_t uuid0                       : 64; /**< [1727:1664] Reserved for software for use as name/UUID. Opaque to ROM code. */
		uint64_t sw9                         : 64; /**< [1663:1600] Reserved for software, continued. */
		uint64_t sw8                         : 64; /**< [1599:1536] Reserved for software, continued. */
		uint64_t sw7                         : 64; /**< [1535:1472] Reserved for software, continued. */
		uint64_t sw6                         : 64; /**< [1471:1408] Reserved for software, continued. */
		uint64_t sw5                         : 64; /**< [1407:1344] Reserved for software, continued. */
		uint64_t sw4                         : 64; /**< [1343:1280] Reserved for software, continued. */
		uint64_t sw3                         : 64; /**< [1279:1216] Reserved for software, continued. */
		uint64_t sw2                         : 64; /**< [1215:1152] Reserved for software, continued. */
		uint64_t sw1                         : 64; /**< [1151:1088] Reserved for software, continued. */
		uint64_t sw0                         : 64; /**< [1087:1024] Reserved for software, word 0. Opaque to ROM code. */
		uint64_t rotpk7                      : 64; /**< [1023:960] Public key, word 7. */
		uint64_t rotpk6                      : 64; /**< [959:896] Public key, word 6. */
		uint64_t rotpk5                      : 64; /**< [895:832] Public key, word 5. */
		uint64_t rotpk4                      : 64; /**< [831:768] Public key, word 4. */
		uint64_t rotpk3                      : 64; /**< [767:704] Public key, word 3. */
		uint64_t rotpk2                      : 64; /**< [703:640] Public key, word 2. */
		uint64_t rotpk1                      : 64; /**< [639:576] Public key, word 1. */
		uint64_t rotpk0                      : 64; /**< [575:512] Public key, word 0.
                                                                 An ECDSA-with-SHA256 signature used to validate this certificate.
                                                                 ROM boot compares an AES256 hash of ROTPK0..3 with FUSF_ROTPK().

                                                                 INTERNAL: In TBSA this is a hash of the SubjectPublicKey. */
		uint64_t fs3                         : 64; /**< [511:448] TBL1FW image's SHA256 hash, continued. */
		uint64_t fs2                         : 64; /**< [447:384] TBL1FW image's SHA256 hash, continued. */
		uint64_t fs1                         : 64; /**< [383:320] TBL1FW image's SHA256 hash, continued. */
		uint64_t fs0                         : 64; /**< [319:256] TBL1FW image's SHA256 hash, word 0.
                                                                 ROM boot compares this hash to the hash of the loaded image. */
		uint64_t size                        : 64; /**< [255:192] Size. Indicates the size of the TBL1FW material in bytes.  Must match the value in
                                                                 ROM_CLIB_S[SIZE]. */
		uint64_t reserved_128_191            : 64; /**< [191:128] Reserved. */
		uint64_t ver                         : 8;  /**< [127:120] Version number.  0x0 to indicate first version of this format.
                                                                 INTERNAL: Opaque to ROM, until we have a second version. */
		uint64_t nvcnt                       : 8;  /**< [119:112] Trusted firmware NV counter to avoid replay attacks.
                                                                 Compared to population_count(FUSF_CTL[ROM_T_CNT]).  Values > 63 are reserved.
                                                                 INTERNAL: In TBSA this is the TrustedFirmwareNVCounter. */
		uint64_t reserved_72_111             : 40; /**< [111: 72] Reserved. */
		uint64_t expose                      : 1;  /**< [ 71: 71] Enable HUK/EK exposure to TBL1FW and later.  This would
                                                                 generally be set for a secure boot.  Non-trusted software
                                                                 can be booted in a similar manner to if trusted-mode = 0 by clearing
                                                                 this bit. */
		uint64_t bkpt                        : 1;  /**< [ 70: 70] ROM code will breakpoint immediately before executing TBL1FW.
                                                                 If set, [SIDEN] must be set.
                                                                 Note breakpoints before this point are not possible due to security reasons. */
		uint64_t reserved_69_69              : 1;  /**< [ 69: 69] Reserved. */
		uint64_t siden                       : 1;  /**< [ 68: 68] Enable secure external invasive debug during boot.
                                                                 This debug mode is intended only for TBL1FW debug and will
                                                                 break the trust model.  Later debug must use a debug
                                                                 certificate authenticated in TBL1FW as specified in the
                                                                 ARM Trusted Boot System Architecture (TBSA). */
		uint64_t crypt                       : 4;  /**< [ 67: 64] Firmware encryption. Enumerated in ROM_CRYPT_E. */
		uint64_t magic                       : 64; /**< [ 63:  0] Magic number.  Contains "CVM_CSIB" in ASCII (0x42495343_5f4d5643)
                                                                 to indicate a valid ROM_CSIB_S structure. */
#else
		uint64_t magic                       : 64;
		uint64_t crypt                       : 4;
		uint64_t siden                       : 1;
		uint64_t reserved_69_69              : 1;
		uint64_t bkpt                        : 1;
		uint64_t expose                      : 1;
		uint64_t reserved_72_111             : 40;
		uint64_t nvcnt                       : 8;
		uint64_t ver                         : 8;
		uint64_t reserved_128_191            : 64;
		uint64_t size                        : 64;
		uint64_t fs0                         : 64;
		uint64_t fs1                         : 64;
		uint64_t fs2                         : 64;
		uint64_t fs3                         : 64;
		uint64_t rotpk0                      : 64;
		uint64_t rotpk1                      : 64;
		uint64_t rotpk2                      : 64;
		uint64_t rotpk3                      : 64;
		uint64_t rotpk4                      : 64;
		uint64_t rotpk5                      : 64;
		uint64_t rotpk6                      : 64;
		uint64_t rotpk7                      : 64;
		uint64_t sw0                         : 64;
		uint64_t sw1                         : 64;
		uint64_t sw2                         : 64;
		uint64_t sw3                         : 64;
		uint64_t sw4                         : 64;
		uint64_t sw5                         : 64;
		uint64_t sw6                         : 64;
		uint64_t sw7                         : 64;
		uint64_t sw8                         : 64;
		uint64_t sw9                         : 64;
		uint64_t uuid0                       : 64;
		uint64_t uuid1                       : 64;
		uint64_t nonce0                      : 64;
		uint64_t nonce1                      : 64;
		uint64_t nonce2                      : 64;
		uint64_t nonce3                      : 64;
#endif
	} s;
};


/**
 * NCB - rom_mem#
 */
typedef union bdk_rom_memx {
	uint64_t u;
	struct bdk_rom_memx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO - Boot-rom data. The maximum address accessible is specified with MIO_BOOT_ROM_LIMIT. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_rom_memx_s              cn85xx; */
	/* struct bdk_rom_memx_s              cn88xx; */
} bdk_rom_memx_t;

static inline uint64_t BDK_ROM_MEMX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ROM_MEMX(unsigned long param1)
{
	if (((param1 <= 2047)))
		return 0x000087D000000000ull + (param1 & 2047) * 0x8ull;
	csr_fatal("BDK_ROM_MEMX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ROM_MEMX(...) bdk_rom_memx_t
#define bustype_BDK_ROM_MEMX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ROM_MEMX(p1) (p1)
#define arguments_BDK_ROM_MEMX(p1) (p1),-1,-1,-1
#define basename_BDK_ROM_MEMX(...) "ROM_MEMX"

#endif /* __BDK_CSRS_ROM__ */
