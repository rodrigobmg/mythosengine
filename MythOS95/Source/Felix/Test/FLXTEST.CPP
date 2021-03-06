//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//
//            _,'|             _.-''``-...___..--';)
//           /_ \'.      __..-' ,      ,--...--'''
//          <\    .`--'''       `     /'
//           `-';'               ;   ; ;  Felix the Fixed-point Library
//     __...--''     ___...--_..'  .;.'
//    (,__....----'''       (,..--''
//
//                    Microsoft Windows 95/98/NT Version
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
//                         *** Tester Application ***
//  Flxtest.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <assert.h>
#include <math.h>
#include "../inc/felix.hpp"

using namespace std;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//      The main routine.  This drives the test.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void main()
{
   Flx16 a, b, c;
   Flx16 a1,b1,c1;
   clock_t        ticks;
   clock_t        start;

   cout << "葦� Felix Tester (C) 1994-1999 Charybdis Enterprises, Inc. 憶�\n";

   printf("\n\nMUL_DIV Section-------\n");
   a  = -32760;
   b  = -32;
   c  = 67;
   a1 = flx_muldiv(a,b,c);
   printf("(%f * %f) /  %f = %f\n",(float)a,(float)b,(float)c,(float)a1);

   printf("\n\nMUL Section-------\n");
   a = 47;
   b = 131;
   a1 = a * b;
   printf("(%f * %f) = %f\n",(float) a, (float)b,(float) a1);


   printf("\n\nDIV Section-------\n");
   a = 17;
   b = 128;
   c = 4;

   c = b / a;
   printf ("%f / %f = %f\n",(float)b,(float)a,(float)c);


   printf("\n\nSIN Section-------\n");
   a = 17;
   b = 128;
   c = 234;

   printf ("SIN of %f is %f \n",(float)a,(float)a.sin());
   printf ("ASIN of %f is %f \n",(float)flx_sin(a),(float)flx_asin(flx_sin(a)));
   printf ("SIN of %f is %f \n",(float)b,(float)flx_sin(b));
   printf ("ASIN of %f is %f \n",(float)flx_sin(b),(float)flx_asin(flx_sin(b)));
   printf ("SIN of %f is %f \n",(float)c,(float)flx_sin(c));
   printf ("ASIN of %f is %f \n",(float)flx_sin(c),(float)flx_asin(flx_sin(c)));


   printf("\n\nCOS Section-------\n");
   a = 17;
   b = 128;
   c = 234;

   printf ("COS of %f is %f \n",(float)a,(float)flx_cos(a));
   printf ("ACOS of %f is %f \n",(float)flx_cos(a),(float)flx_acos(flx_cos(a)));
   printf ("COS of %f is %f \n",(float)b,(float)flx_cos(b));
   printf ("ACOS of %f is %f \n",(float)flx_cos(b),(float)flx_acos(flx_cos(b)));
   printf ("COS of %f is %f \n",(float)c,(float)flx_cos(c));
   printf ("ACOS of %f is %f \n",(float)flx_cos(c),(float)flx_acos(flx_cos(c)));

   printf("\n\nTAN Section-------\n");
   a = 17;
   b = 128;
   c = 234;

   printf ("TAN of %f is %f \n",(float)a,(float)flx_tan(a));
   printf ("COT of %f is %f \n",(float)a,(float)flx_cot(a));
   printf ("TAN of %f is %f \n",(float)b,(float)flx_tan(b));
   printf ("COT of %f is %f \n",(float)b,(float)flx_cot(b));
   printf ("TAN of %f is %f \n",(float)c,(float)flx_tan(c));
   printf ("COT of %f is %f \n",(float)c,(float)flx_cot(c));





   printf("\n\nSQRT Section-------\n");


   printf("Hit any key to begin Benchmark Timings.\n");
   getch();
   start=clock();
   int i,j;
   ticks=0;
   for (j=0;j < 50;j++)
   {
       for (i=0;i < 20000;i++)
       {
           a = i;
           a.sqrt();
           b = i+6384;
           b.sqrt();
           c = i+12767;
           c.sqrt();
       }
   }
   ticks += (clock() - start);

   Flx16 time;
   time = ((Flx16)((long)ticks)/(Flx16)CLOCKS_PER_SEC);
   printf("It took %f seconds to do %d sqrt operations!\n",(float)time,i*j*3);
   printf("That is %f sqrt operations per second.\n",(float)(i*j*3)/(float)time);
   double fa,fb,fc;

#if 0
   start=clock();
   ticks = 0;
   for (j=0;j < 50;j++)
   {
       for (i=0;i < 20000;i++)
       {
           fa = i;
           sqrt(fa);
           fb = i+6384;
           sqrt(fb);
           fc = i+12767;
           sqrt(fc);
       }
   }
   ticks += (clock() - start);

//   Flx16 time;
   time = ((Flx16)((long)ticks)/(Flx16)CLOCKS_PER_SEC);
   printf("HARDWARE is Capable of:");
   printf(" %f sqrt operations per second.\n",(float)(i*j*3)/(float)time);
   printf("<press any key to continue>\n");
   getch();

   printf("\n\n");
#endif

   int clevel = 500000;
   printf("Checking precision on %d sqrt operations.\n",clevel);
   double  accumulate;
   accumulate = 0;
   for (i=0;i<clevel;i++)
   {
       a = flx_rand().abs();
       fa = (float)a;
       fa = sqrt(fa);
       fb = (float)a.sqrt();
       fc = fa-fb;
       if (fc < 0.0)
       {
           fc = -fc;
       }
       fc = fc / fa;
       accumulate = accumulate + fc;
   }

   fb = accumulate / ((double)clevel);

   printf ("Flx sqrt average percent error is %f %.\n\n\n",fb * 100.0);

//   a = 0.04;
//   b = 5160;
   a = flx_rand().abs();
   b = flx_rand().abs();
   c.flx = 0x75d9b3f;

   double v;

   printf("%f is represented as %x\n",(float)a,a);
   printf("--->sqrt is %f (%x)\n",(float)a.sqrt(),a.sqrt());
   v = (float)a;
   v = sqrt(v);
   printf("--->Coprocessor verification is %f\n\n",v);

   printf("%f is represented as %x\n",(float)b,b);
   printf("--->sqrt is %f (%x)\n",(float)b.sqrt(),b.sqrt());
   v = (float)b;
   v = sqrt(v);
   printf("--->Coprocessor verification is %f\n\n",v);

   printf("%f is represented as %x\n",(float)c,c);
   printf("--->sqrt is %f (%x)\n",(float)c.sqrt(),c.sqrt());
   v = (float)c;
   v = sqrt(v);
   printf("--->Coprocessor verification is %f\n\n",v);

   printf("\nComplete!\n");
}


//葦� End of module - Flxtest.cpp 憶�
