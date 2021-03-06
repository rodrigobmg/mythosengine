//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Tim Little
//
// thlspec.h
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __THLSPEC_H
#define __THLSPEC_H    1

#ifdef __cplusplus
extern "C" {
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�



#ifdef  _32X32
#define WIDTH_SHIFT             5
#define HEIGHT_SHIFT            5

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_32x32_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_32x32_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_32x32_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_32x32_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_32x32_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_32x32_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_32x32_trans_filtered
#define LH16_TRANS              vngo_lhlines16_32x32_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_32x32_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_32x32_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_32x32_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_32x32_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_32x32_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_32x32_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_32x32_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_32x32_trans

#define LZH16                   vngo_lzhlines16_32x32
#define LZH16_FILTERED          vngo_lzhlines16_32x32_filtered
#define LH16                    vngo_lhlines16_32x32
#define LH16_FILTERED           vngo_lhlines16_32x32_filtered

#define LZGH16                  vngo_lzghlines16_32x32
#define LZGH16_FILTERED         vngo_lzghlines16_32x32_filtered
#define LGH16                   vngo_lghlines16_32x32
#define LGH16_FILTERED          vngo_lghlines16_32x32_filtered
#endif                  // _32X32


#ifdef  _32X64
#define HEIGHT_SHIFT            5
#define WIDTH_SHIFT             6

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_32x64_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_32x64_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_32x64_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_32x64_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_32x64_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_32x64_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_32x64_trans_filtered
#define LH16_TRANS              vngo_lhlines16_32x64_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_32x64_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_32x64_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_32x64_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_32x64_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_32x64_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_32x64_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_32x64_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_32x64_trans

#define LZH16                   vngo_lzhlines16_32x64
#define LZH16_FILTERED          vngo_lzhlines16_32x64_filtered
#define LH16                    vngo_lhlines16_32x64
#define LH16_FILTERED           vngo_lhlines16_32x64_filtered

#define LZGH16                  vngo_lzghlines16_32x64
#define LZGH16_FILTERED         vngo_lzghlines16_32x64_filtered
#define LGH16                   vngo_lghlines16_32x64
#define LGH16_FILTERED          vngo_lghlines16_32x64_filtered
#endif                  // _32X64




#ifdef  _32X128
#define WIDTH_SHIFT             5
#define HEIGHT_SHIFT            7

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_32x128_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_32x128_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_32x128_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_32x128_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_32x128_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_32x128_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_32x128_trans_filtered
#define LH16_TRANS              vngo_lhlines16_32x128_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_32x128_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_32x128_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_32x128_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_32x128_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_32x128_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_32x128_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_32x128_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_32x128_trans

#define LZH16                   vngo_lzhlines16_32x128
#define LZH16_FILTERED          vngo_lzhlines16_32x128_filtered
#define LH16                    vngo_lhlines16_32x128
#define LH16_FILTERED           vngo_lhlines16_32x128_filtered

#define LZGH16                  vngo_lzghlines16_32x128
#define LZGH16_FILTERED         vngo_lzghlines16_32x128_filtered
#define LGH16                   vngo_lghlines16_32x128
#define LGH16_FILTERED          vngo_lghlines16_32x128_filtered
#endif                  // _32X128



#ifdef  _32X256
#define WIDTH_SHIFT             5
#define HEIGHT_SHIFT            8

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_32x256_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_32x256_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_32x256_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_32x256_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_32x256_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_32x256_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_32x256_trans_filtered
#define LH16_TRANS              vngo_lhlines16_32x256_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_32x256_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_32x256_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_32x256_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_32x256_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_32x256_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_32x256_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_32x256_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_32x256_trans

#define LZH16                   vngo_lzhlines16_32x256
#define LZH16_FILTERED          vngo_lzhlines16_32x256_filtered
#define LH16                    vngo_lhlines16_32x256
#define LH16_FILTERED           vngo_lhlines16_32x256_filtered

#define LZGH16                  vngo_lzghlines16_32x256
#define LZGH16_FILTERED         vngo_lzghlines16_32x256_filtered
#define LGH16                   vngo_lghlines16_32x256
#define LGH16_FILTERED          vngo_lghlines16_32x256_filtered
#endif                  // _32X256


#ifdef  _64X32
#define WIDTH_SHIFT             6
#define HEIGHT_SHIFT            5

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_64x32_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_64x32_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_64x32_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_64x32_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_64x32_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_64x32_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_64x32_trans_filtered
#define LH16_TRANS              vngo_lhlines16_64x32_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_64x32_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_64x32_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_64x32_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_64x32_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_64x32_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_64x32_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_64x32_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_64x32_trans

#define LZH16                   vngo_lzhlines16_64x32
#define LZH16_FILTERED          vngo_lzhlines16_64x32_filtered
#define LH16                    vngo_lhlines16_64x32
#define LH16_FILTERED           vngo_lhlines16_64x32_filtered

#define LZGH16                  vngo_lzghlines16_64x32
#define LZGH16_FILTERED         vngo_lzghlines16_64x32_filtered
#define LGH16                   vngo_lghlines16_64x32
#define LGH16_FILTERED          vngo_lghlines16_64x32_filtered
#endif                  // _64X32


#ifdef  _64X64
#define HEIGHT_SHIFT            6
#define WIDTH_SHIFT             6

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_64x64_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_64x64_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_64x64_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_64x64_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_64x64_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_64x64_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_64x64_trans_filtered
#define LH16_TRANS              vngo_lhlines16_64x64_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_64x64_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_64x64_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_64x64_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_64x64_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_64x64_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_64x64_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_64x64_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_64x64_trans

#define LZH16                   vngo_lzhlines16_64x64
#define LZH16_FILTERED          vngo_lzhlines16_64x64_filtered
#define LH16                    vngo_lhlines16_64x64
#define LH16_FILTERED           vngo_lhlines16_64x64_filtered

#define LZGH16                  vngo_lzghlines16_64x64
#define LZGH16_FILTERED         vngo_lzghlines16_64x64_filtered
#define LGH16                   vngo_lghlines16_64x64
#define LGH16_FILTERED          vngo_lghlines16_64x64_filtered
#endif                  // _64X64




#ifdef  _64X128
#define WIDTH_SHIFT             6
#define HEIGHT_SHIFT            7

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_64x128_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_64x128_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_64x128_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_64x128_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_64x128_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_64x128_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_64x128_trans_filtered
#define LH16_TRANS              vngo_lhlines16_64x128_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_64x128_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_64x128_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_64x128_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_64x128_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_64x128_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_64x128_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_64x128_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_64x128_trans

#define LZH16                   vngo_lzhlines16_64x128
#define LZH16_FILTERED          vngo_lzhlines16_64x128_filtered
#define LH16                    vngo_lhlines16_64x128
#define LH16_FILTERED           vngo_lhlines16_64x128_filtered

#define LZGH16                  vngo_lzghlines16_64x128
#define LZGH16_FILTERED         vngo_lzghlines16_64x128_filtered
#define LGH16                   vngo_lghlines16_64x128
#define LGH16_FILTERED          vngo_lghlines16_64x128_filtered
#endif                  // _64X128



#ifdef  _64X256
#define WIDTH_SHIFT             6
#define HEIGHT_SHIFT            8

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_64x256_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_64x256_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_64x256_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_64x256_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_64x256_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_64x256_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_64x256_trans_filtered
#define LH16_TRANS              vngo_lhlines16_64x256_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_64x256_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_64x256_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_64x256_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_64x256_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_64x256_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_64x256_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_64x256_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_64x256_trans

#define LZH16                   vngo_lzhlines16_64x256
#define LZH16_FILTERED          vngo_lzhlines16_64x256_filtered
#define LH16                    vngo_lhlines16_64x256
#define LH16_FILTERED           vngo_lhlines16_64x256_filtered

#define LZGH16                  vngo_lzghlines16_64x256
#define LZGH16_FILTERED         vngo_lzghlines16_64x256_filtered
#define LGH16                   vngo_lghlines16_64x256
#define LGH16_FILTERED          vngo_lghlines16_64x256_filtered
#endif                  // _64X256



#ifdef  _128X32
#define WIDTH_SHIFT             7
#define HEIGHT_SHIFT            5

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_128x32_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_128x32_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_128x32_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_128x32_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_128x32_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_128x32_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_128x32_trans_filtered
#define LH16_TRANS              vngo_lhlines16_128x32_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_128x32_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_128x32_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_128x32_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_128x32_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_128x32_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_128x32_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_128x32_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_128x32_trans

#define LZH16                   vngo_lzhlines16_128x32
#define LZH16_FILTERED          vngo_lzhlines16_128x32_filtered
#define LH16                    vngo_lhlines16_128x32
#define LH16_FILTERED           vngo_lhlines16_128x32_filtered

#define LZGH16                  vngo_lzghlines16_128x32
#define LZGH16_FILTERED         vngo_lzghlines16_128x32_filtered
#define LGH16                   vngo_lghlines16_128x32
#define LGH16_FILTERED          vngo_lghlines16_128x32_filtered
#endif                  // _128X32


#ifdef  _128X64
#define WIDTH_SHIFT             7
#define HEIGHT_SHIFT            6

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_128x64_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_128x64_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_128x64_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_128x64_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_128x64_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_128x64_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_128x64_trans_filtered
#define LH16_TRANS              vngo_lhlines16_128x64_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_128x64_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_128x64_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_128x64_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_128x64_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_128x64_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_128x64_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_128x64_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_128x64_trans

#define LZH16                   vngo_lzhlines16_128x64
#define LZH16_FILTERED          vngo_lzhlines16_128x64_filtered
#define LH16                    vngo_lhlines16_128x64
#define LH16_FILTERED           vngo_lhlines16_128x64_filtered

#define LZGH16                  vngo_lzghlines16_128x64
#define LZGH16_FILTERED         vngo_lzghlines16_128x64_filtered
#define LGH16                   vngo_lghlines16_128x64
#define LGH16_FILTERED          vngo_lghlines16_128x64_filtered
#endif                  // _128X64




#ifdef  _128X128
#define WIDTH_SHIFT             7
#define HEIGHT_SHIFT            7

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_128x128_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_128x128_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_128x128_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_128x128_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_128x128_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_128x128_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_128x128_trans_filtered
#define LH16_TRANS              vngo_lhlines16_128x128_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_128x128_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_128x128_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_128x128_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_128x128_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_128x128_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_128x128_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_128x128_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_128x128_trans

#define LZH16                   vngo_lzhlines16_128x128
#define LZH16_FILTERED          vngo_lzhlines16_128x128_filtered
#define LH16                    vngo_lhlines16_128x128
#define LH16_FILTERED           vngo_lhlines16_128x128_filtered

#define LZGH16                  vngo_lzghlines16_128x128
#define LZGH16_FILTERED         vngo_lzghlines16_128x128_filtered
#define LGH16                   vngo_lghlines16_128x128
#define LGH16_FILTERED          vngo_lghlines16_128x128_filtered
#endif                  // _128X128



#ifdef  _128X256
#define WIDTH_SHIFT             7
#define HEIGHT_SHIFT            8

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_128x256_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_128x256_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_128x256_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_128x256_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_128x256_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_128x256_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_128x256_trans_filtered
#define LH16_TRANS              vngo_lhlines16_128x256_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_128x256_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_128x256_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_128x256_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_128x256_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_128x256_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_128x256_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_128x256_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_128x256_trans

#define LZH16                   vngo_lzhlines16_128x256
#define LZH16_FILTERED          vngo_lzhlines16_128x256_filtered
#define LH16                    vngo_lhlines16_128x256
#define LH16_FILTERED           vngo_lhlines16_128x256_filtered

#define LZGH16                  vngo_lzghlines16_128x256
#define LZGH16_FILTERED         vngo_lzghlines16_128x256_filtered
#define LGH16                   vngo_lghlines16_128x256
#define LGH16_FILTERED          vngo_lghlines16_128x256_filtered
#endif                  // _128X256





#ifdef  _256X32
#define WIDTH_SHIFT             8
#define HEIGHT_SHIFT            5

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_256x32_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_256x32_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_256x32_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_256x32_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_256x32_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_256x32_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_256x32_trans_filtered
#define LH16_TRANS              vngo_lhlines16_256x32_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_256x32_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_256x32_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_256x32_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_256x32_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_256x32_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_256x32_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_256x32_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_256x32_trans

#define LZH16                   vngo_lzhlines16_256x32
#define LZH16_FILTERED          vngo_lzhlines16_256x32_filtered
#define LH16                    vngo_lhlines16_256x32
#define LH16_FILTERED           vngo_lhlines16_256x32_filtered

#define LZGH16                  vngo_lzghlines16_256x32
#define LZGH16_FILTERED         vngo_lzghlines16_256x32_filtered
#define LGH16                   vngo_lghlines16_256x32
#define LGH16_FILTERED          vngo_lghlines16_256x32_filtered
#endif                  // _256X32


#ifdef  _256X64
#define WIDTH_SHIFT             8
#define HEIGHT_SHIFT            6

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_256x64_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_256x64_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_256x64_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_256x64_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_256x64_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_256x64_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_256x64_trans_filtered
#define LH16_TRANS              vngo_lhlines16_256x64_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_256x64_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_256x64_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_256x64_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_256x64_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_256x64_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_256x64_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_256x64_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_256x64_trans

#define LZH16                   vngo_lzhlines16_256x64
#define LZH16_FILTERED          vngo_lzhlines16_256x64_filtered
#define LH16                    vngo_lhlines16_256x64
#define LH16_FILTERED           vngo_lhlines16_256x64_filtered

#define LZGH16                  vngo_lzghlines16_256x64
#define LZGH16_FILTERED         vngo_lzghlines16_256x64_filtered
#define LGH16                   vngo_lghlines16_256x64
#define LGH16_FILTERED          vngo_lghlines16_256x64_filtered
#endif                  // _256X64


#ifdef  _256X128
#define WIDTH_SHIFT             8
#define HEIGHT_SHIFT            7

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_256x128_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_256x128_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_256x128_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_256x128_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_256x128_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_256x128_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_256x128_trans_filtered
#define LH16_TRANS              vngo_lhlines16_256x128_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_256x128_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_256x128_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_256x128_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_256x128_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_256x128_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_256x128_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_256x128_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_256x128_trans

#define LZH16                   vngo_lzhlines16_256x128
#define LZH16_FILTERED          vngo_lzhlines16_256x128_filtered
#define LH16                    vngo_lhlines16_256x128
#define LH16_FILTERED           vngo_lhlines16_256x128_filtered

#define LZGH16                  vngo_lzghlines16_256x128
#define LZGH16_FILTERED         vngo_lzghlines16_256x128_filtered
#define LGH16                   vngo_lghlines16_256x128
#define LGH16_FILTERED          vngo_lghlines16_256x128_filtered
#endif                  // _256X128



#ifdef  _256X256
#define WIDTH_SHIFT             8
#define HEIGHT_SHIFT            8

#define LGH16_NTRANS_FILTERED   vngo_lghlines16_256x256_ntrans_filtered
#define LGH16_NTRANS            vngo_lghlines16_256x256_ntrans
#define LGH16_TRANS_FILTERED    vngo_lghlines16_256x256_trans_filtered
#define LGH16_TRANS             vngo_lghlines16_256x256_trans

#define LH16_NTRANS_FILTERED    vngo_lhlines16_256x256_ntrans_filtered
#define LH16_NTRANS             vngo_lhlines16_256x256_ntrans
#define LH16_TRANS_FILTERED     vngo_lhlines16_256x256_trans_filtered
#define LH16_TRANS              vngo_lhlines16_256x256_trans

#define LZGH16_NTRANS_FILTERED  vngo_lzghlines16_256x256_ntrans_filtered
#define LZGH16_NTRANS           vngo_lzghlines16_256x256_ntrans
#define LZGH16_TRANS_FILTERED   vngo_lzghlines16_256x256_trans_filtered
#define LZGH16_TRANS            vngo_lzghlines16_256x256_trans

#define LZH16_NTRANS_FILTERED   vngo_lzhlines16_256x256_ntrans_filtered
#define LZH16_NTRANS            vngo_lzhlines16_256x256_ntrans
#define LZH16_TRANS_FILTERED    vngo_lzhlines16_256x256_trans_filtered
#define LZH16_TRANS             vngo_lzhlines16_256x256_trans

#define LZH16                   vngo_lzhlines16_256x256
#define LZH16_FILTERED          vngo_lzhlines16_256x256_filtered
#define LH16                    vngo_lhlines16_256x256
#define LH16_FILTERED           vngo_lhlines16_256x256_filtered

#define LZGH16                  vngo_lzghlines16_256x256
#define LZGH16_FILTERED         vngo_lzghlines16_256x256_filtered
#define LGH16                   vngo_lghlines16_256x256
#define LGH16_FILTERED          vngo_lghlines16_256x256_filtered
#endif                  // _256X256


//
// Function Declarations.
//

void vngo_lghlines16_32x32_filtered(VngoTriangle *tri);
void vngo_lghlines16_32x32(VngoTriangle *tri);
void vngo_lzghlines16_32x32_filtered(VngoTriangle *tri);
void vngo_lzghlines16_32x32(VngoTriangle *tri);
void vngo_lhlines16_32x32_filtered(VngoTriangle *tri);
void vngo_lhlines16_32x32(VngoTriangle *tri);
void vngo_lzhlines16_32x32_filtered(VngoTriangle *tri);
void vngo_lzhlines16_32x32(VngoTriangle *tri);

void vngo_lghlines16_32x64_filtered(VngoTriangle *tri);
void vngo_lghlines16_32x64(VngoTriangle *tri);
void vngo_lzghlines16_32x64_filtered(VngoTriangle *tri);
void vngo_lzghlines16_32x64(VngoTriangle *tri);
void vngo_lhlines16_32x64_filtered(VngoTriangle *tri);
void vngo_lhlines16_32x64(VngoTriangle *tri);
void vngo_lzhlines16_32x64_filtered(VngoTriangle *tri);
void vngo_lzhlines16_32x64(VngoTriangle *tri);

void vngo_lghlines16_32x128_filtered(VngoTriangle *tri);
void vngo_lghlines16_32x128(VngoTriangle *tri);
void vngo_lzghlines16_32x128_filtered(VngoTriangle *tri);
void vngo_lzghlines16_32x128(VngoTriangle *tri);
void vngo_lhlines16_32x128_filtered(VngoTriangle *tri);
void vngo_lhlines16_32x128(VngoTriangle *tri);
void vngo_lzhlines16_32x128_filtered(VngoTriangle *tri);
void vngo_lzhlines16_32x128(VngoTriangle *tri);

void vngo_lghlines16_32x256_filtered(VngoTriangle *tri);
void vngo_lghlines16_32x256(VngoTriangle *tri);
void vngo_lzghlines16_32x256_filtered(VngoTriangle *tri);
void vngo_lzghlines16_32x256(VngoTriangle *tri);
void vngo_lhlines16_32x256_filtered(VngoTriangle *tri);
void vngo_lhlines16_32x256(VngoTriangle *tri);
void vngo_lzhlines16_32x256_filtered(VngoTriangle *tri);
void vngo_lzhlines16_32x256(VngoTriangle *tri);


void vngo_lghlines16_64x32_filtered(VngoTriangle *tri);
void vngo_lghlines16_64x32(VngoTriangle *tri);
void vngo_lzghlines16_64x32_filtered(VngoTriangle *tri);
void vngo_lzghlines16_64x32(VngoTriangle *tri);
void vngo_lhlines16_64x32_filtered(VngoTriangle *tri);
void vngo_lhlines16_64x32(VngoTriangle *tri);
void vngo_lzhlines16_64x32_filtered(VngoTriangle *tri);
void vngo_lzhlines16_64x32(VngoTriangle *tri);

void vngo_lghlines16_64x64_filtered(VngoTriangle *tri);
void vngo_lghlines16_64x64(VngoTriangle *tri);
void vngo_lzghlines16_64x64_filtered(VngoTriangle *tri);
void vngo_lzghlines16_64x64(VngoTriangle *tri);
void vngo_lhlines16_64x64_filtered(VngoTriangle *tri);
void vngo_lhlines16_64x64(VngoTriangle *tri);
void vngo_lzhlines16_64x64_filtered(VngoTriangle *tri);
void vngo_lzhlines16_64x64(VngoTriangle *tri);

void vngo_lghlines16_64x128_filtered(VngoTriangle *tri);
void vngo_lghlines16_64x128(VngoTriangle *tri);
void vngo_lzghlines16_64x128_filtered(VngoTriangle *tri);
void vngo_lzghlines16_64x128(VngoTriangle *tri);
void vngo_lhlines16_64x128_filtered(VngoTriangle *tri);
void vngo_lhlines16_64x128(VngoTriangle *tri);
void vngo_lzhlines16_64x128_filtered(VngoTriangle *tri);
void vngo_lzhlines16_64x128(VngoTriangle *tri);

void vngo_lghlines16_64x256_filtered(VngoTriangle *tri);
void vngo_lghlines16_64x256(VngoTriangle *tri);
void vngo_lzghlines16_64x256_filtered(VngoTriangle *tri);
void vngo_lzghlines16_64x256(VngoTriangle *tri);
void vngo_lhlines16_64x256_filtered(VngoTriangle *tri);
void vngo_lhlines16_64x256(VngoTriangle *tri);
void vngo_lzhlines16_64x256_filtered(VngoTriangle *tri);
void vngo_lzhlines16_64x256(VngoTriangle *tri);

void vngo_lghlines16_128x32_filtered(VngoTriangle *tri);
void vngo_lghlines16_128x32(VngoTriangle *tri);
void vngo_lzghlines16_128x32_filtered(VngoTriangle *tri);
void vngo_lzghlines16_128x32(VngoTriangle *tri);
void vngo_lhlines16_128x32_filtered(VngoTriangle *tri);
void vngo_lhlines16_128x32(VngoTriangle *tri);
void vngo_lzhlines16_128x32_filtered(VngoTriangle *tri);
void vngo_lzhlines16_128x32(VngoTriangle *tri);

void vngo_lghlines16_128x64_filtered(VngoTriangle *tri);
void vngo_lghlines16_128x64(VngoTriangle *tri);
void vngo_lzghlines16_128x64_filtered(VngoTriangle *tri);
void vngo_lzghlines16_128x64(VngoTriangle *tri);
void vngo_lhlines16_128x64_filtered(VngoTriangle *tri);
void vngo_lhlines16_128x64(VngoTriangle *tri);
void vngo_lzhlines16_128x64_filtered(VngoTriangle *tri);
void vngo_lzhlines16_128x64(VngoTriangle *tri);

void vngo_lghlines16_128x128_filtered(VngoTriangle *tri);
void vngo_lghlines16_128x128(VngoTriangle *tri);
void vngo_lzghlines16_128x128_filtered(VngoTriangle *tri);
void vngo_lzghlines16_128x128(VngoTriangle *tri);
void vngo_lhlines16_128x128_filtered(VngoTriangle *tri);
void vngo_lhlines16_128x128(VngoTriangle *tri);
void vngo_lzhlines16_128x128_filtered(VngoTriangle *tri);
void vngo_lzhlines16_128x128(VngoTriangle *tri);

void vngo_lghlines16_128x256_filtered(VngoTriangle *tri);
void vngo_lghlines16_128x256(VngoTriangle *tri);
void vngo_lzghlines16_128x256_filtered(VngoTriangle *tri);
void vngo_lzghlines16_128x256(VngoTriangle *tri);
void vngo_lhlines16_128x256_filtered(VngoTriangle *tri);
void vngo_lhlines16_128x256(VngoTriangle *tri);
void vngo_lzhlines16_128x256_filtered(VngoTriangle *tri);
void vngo_lzhlines16_128x256(VngoTriangle *tri);


void vngo_lghlines16_256x32_filtered(VngoTriangle *tri);
void vngo_lghlines16_256x32(VngoTriangle *tri);
void vngo_lzghlines16_256x32_filtered(VngoTriangle *tri);
void vngo_lzghlines16_256x32(VngoTriangle *tri);
void vngo_lhlines16_256x32_filtered(VngoTriangle *tri);
void vngo_lhlines16_256x32(VngoTriangle *tri);
void vngo_lzhlines16_256x32_filtered(VngoTriangle *tri);
void vngo_lzhlines16_256x32(VngoTriangle *tri);

void vngo_lghlines16_256x64_filtered(VngoTriangle *tri);
void vngo_lghlines16_256x64(VngoTriangle *tri);
void vngo_lzghlines16_256x64_filtered(VngoTriangle *tri);
void vngo_lzghlines16_256x64(VngoTriangle *tri);
void vngo_lhlines16_256x64_filtered(VngoTriangle *tri);
void vngo_lhlines16_256x64(VngoTriangle *tri);
void vngo_lzhlines16_256x64_filtered(VngoTriangle *tri);
void vngo_lzhlines16_256x64(VngoTriangle *tri);

void vngo_lghlines16_256x128_filtered(VngoTriangle *tri);
void vngo_lghlines16_256x128(VngoTriangle *tri);
void vngo_lzghlines16_256x128_filtered(VngoTriangle *tri);
void vngo_lzghlines16_256x128(VngoTriangle *tri);
void vngo_lhlines16_256x128_filtered(VngoTriangle *tri);
void vngo_lhlines16_256x128(VngoTriangle *tri);
void vngo_lzhlines16_256x128_filtered(VngoTriangle *tri);
void vngo_lzhlines16_256x128(VngoTriangle *tri);

void vngo_lghlines16_256x256_filtered(VngoTriangle *tri);
void vngo_lghlines16_256x256(VngoTriangle *tri);
void vngo_lzghlines16_256x256_filtered(VngoTriangle *tri);
void vngo_lzghlines16_256x256(VngoTriangle *tri);
void vngo_lhlines16_256x256_filtered(VngoTriangle *tri);
void vngo_lhlines16_256x256(VngoTriangle *tri);
void vngo_lzhlines16_256x256_filtered(VngoTriangle *tri);
void vngo_lzhlines16_256x256(VngoTriangle *tri);


#ifdef __cplusplus
}
#endif          // __cplusplus

#endif          // __THLSPEC_H

//葦� End of module - thlspec.h 憶�

