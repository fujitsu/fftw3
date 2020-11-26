/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Nov 24 01:07:49 JST 2020 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 20 -name t1bv_20 -include dft/simd/t1b.h -sign 1 */

/*
 * This function contains 123 FP additions, 88 FP multiplications,
 * (or, 77 additions, 42 multiplications, 46 fused multiply/add),
 * 54 stack variables, 4 constants, and 40 memory accesses
 */
#include "dft/simd/t1b.h"

static void t1bv_20(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     VENTER();
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 38)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 38), MAKE_VOLATILE_STRIDE(20, rs)) {
	       V T4, TX, T1m, T1K, TF, T14, T15, TQ, Tf, Tq, Tr, T1O, T1P, T1Q, T1w;
	       V T1z, T1A, TY, TZ, T10, T1L, T1M, T1N, T1p, T1s, T1t, T1i, T1j;
	       {
		    V T1, TW, T3, TU, TV, T2, TT, T1k, T1l;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    TV = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
		    TW = BYTW(&(W[TWVL * 28]), TV);
		    T2 = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
		    T3 = BYTW(&(W[TWVL * 18]), T2);
		    TT = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    TU = BYTW(&(W[TWVL * 8]), TT);
		    T4 = VSUB(T1, T3);
		    TX = VSUB(TU, TW);
		    T1k = VADD(T1, T3);
		    T1l = VADD(TU, TW);
		    T1m = VSUB(T1k, T1l);
		    T1K = VADD(T1k, T1l);
	       }
	       {
		    V T9, T1n, TK, T1v, TP, T1y, Te, T1q, Tk, T1u, Tz, T1o, TE, T1r, Tp;
		    V T1x;
		    {
			 V T6, T8, T5, T7;
			 T5 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 T6 = BYTW(&(W[TWVL * 6]), T5);
			 T7 = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 T8 = BYTW(&(W[TWVL * 26]), T7);
			 T9 = VSUB(T6, T8);
			 T1n = VADD(T6, T8);
		    }
		    {
			 V TH, TJ, TG, TI;
			 TG = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 TH = BYTW(&(W[TWVL * 24]), TG);
			 TI = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 TJ = BYTW(&(W[TWVL * 4]), TI);
			 TK = VSUB(TH, TJ);
			 T1v = VADD(TH, TJ);
		    }
		    {
			 V TM, TO, TL, TN;
			 TL = LD(&(x[WS(rs, 17)]), ms, &(x[WS(rs, 1)]));
			 TM = BYTW(&(W[TWVL * 32]), TL);
			 TN = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 TO = BYTW(&(W[TWVL * 12]), TN);
			 TP = VSUB(TM, TO);
			 T1y = VADD(TM, TO);
		    }
		    {
			 V Tb, Td, Ta, Tc;
			 Ta = LD(&(x[WS(rs, 16)]), ms, &(x[0]));
			 Tb = BYTW(&(W[TWVL * 30]), Ta);
			 Tc = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Td = BYTW(&(W[TWVL * 10]), Tc);
			 Te = VSUB(Tb, Td);
			 T1q = VADD(Tb, Td);
		    }
		    {
			 V Th, Tj, Tg, Ti;
			 Tg = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 Th = BYTW(&(W[TWVL * 14]), Tg);
			 Ti = LD(&(x[WS(rs, 18)]), ms, &(x[0]));
			 Tj = BYTW(&(W[TWVL * 34]), Ti);
			 Tk = VSUB(Th, Tj);
			 T1u = VADD(Th, Tj);
		    }
		    {
			 V Tw, Ty, Tv, Tx;
			 Tv = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Tw = BYTW(&(W[TWVL * 16]), Tv);
			 Tx = LD(&(x[WS(rs, 19)]), ms, &(x[WS(rs, 1)]));
			 Ty = BYTW(&(W[TWVL * 36]), Tx);
			 Tz = VSUB(Tw, Ty);
			 T1o = VADD(Tw, Ty);
		    }
		    {
			 V TB, TD, TA, TC;
			 TA = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 TB = BYTW(&(W[0]), TA);
			 TC = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 TD = BYTW(&(W[TWVL * 20]), TC);
			 TE = VSUB(TB, TD);
			 T1r = VADD(TB, TD);
		    }
		    {
			 V Tm, To, Tl, Tn;
			 Tl = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 Tm = BYTW(&(W[TWVL * 22]), Tl);
			 Tn = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 To = BYTW(&(W[TWVL * 2]), Tn);
			 Tp = VSUB(Tm, To);
			 T1x = VADD(Tm, To);
		    }
		    TF = VSUB(Tz, TE);
		    T14 = VSUB(T9, Te);
		    T15 = VSUB(Tk, Tp);
		    TQ = VSUB(TK, TP);
		    Tf = VADD(T9, Te);
		    Tq = VADD(Tk, Tp);
		    Tr = VADD(Tf, Tq);
		    T1O = VADD(T1u, T1v);
		    T1P = VADD(T1x, T1y);
		    T1Q = VADD(T1O, T1P);
		    T1w = VSUB(T1u, T1v);
		    T1z = VSUB(T1x, T1y);
		    T1A = VADD(T1w, T1z);
		    TY = VADD(Tz, TE);
		    TZ = VADD(TK, TP);
		    T10 = VADD(TY, TZ);
		    T1L = VADD(T1n, T1o);
		    T1M = VADD(T1q, T1r);
		    T1N = VADD(T1L, T1M);
		    T1p = VSUB(T1n, T1o);
		    T1s = VSUB(T1q, T1r);
		    T1t = VADD(T1p, T1s);
	       }
	       T1i = VADD(T4, Tr);
	       T1j = VADD(TX, T10);
	       ST(&(x[WS(rs, 15)]), VFNMSI(T1j, T1i), ms, &(x[WS(rs, 1)]));
	       ST(&(x[WS(rs, 5)]), VFMAI(T1j, T1i), ms, &(x[WS(rs, 1)]));
	       {
		    V T1T, T1R, T1S, T1X, T1Z, T1V, T1W, T1Y, T1U;
		    T1T = VSUB(T1N, T1Q);
		    T1R = VADD(T1N, T1Q);
		    T1S = VFNMS(LDK(KP250000000), T1R, T1K);
		    T1V = VSUB(T1L, T1M);
		    T1W = VSUB(T1O, T1P);
		    T1X = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1W, T1V));
		    T1Z = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1V, T1W));
		    ST(&(x[0]), VADD(T1K, T1R), ms, &(x[0]));
		    T1Y = VFNMS(LDK(KP559016994), T1T, T1S);
		    ST(&(x[WS(rs, 8)]), VFMAI(T1Z, T1Y), ms, &(x[0]));
		    ST(&(x[WS(rs, 12)]), VFNMSI(T1Z, T1Y), ms, &(x[0]));
		    T1U = VFMA(LDK(KP559016994), T1T, T1S);
		    ST(&(x[WS(rs, 4)]), VFNMSI(T1X, T1U), ms, &(x[0]));
		    ST(&(x[WS(rs, 16)]), VFMAI(T1X, T1U), ms, &(x[0]));
	       }
	       {
		    V T1D, T1B, T1C, T1H, T1J, T1F, T1G, T1I, T1E;
		    T1D = VSUB(T1t, T1A);
		    T1B = VADD(T1t, T1A);
		    T1C = VFNMS(LDK(KP250000000), T1B, T1m);
		    T1F = VSUB(T1w, T1z);
		    T1G = VSUB(T1p, T1s);
		    T1H = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1G, T1F));
		    T1J = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1F, T1G));
		    ST(&(x[WS(rs, 10)]), VADD(T1m, T1B), ms, &(x[0]));
		    T1I = VFMA(LDK(KP559016994), T1D, T1C);
		    ST(&(x[WS(rs, 6)]), VFMAI(T1J, T1I), ms, &(x[0]));
		    ST(&(x[WS(rs, 14)]), VFNMSI(T1J, T1I), ms, &(x[0]));
		    T1E = VFNMS(LDK(KP559016994), T1D, T1C);
		    ST(&(x[WS(rs, 2)]), VFNMSI(T1H, T1E), ms, &(x[0]));
		    ST(&(x[WS(rs, 18)]), VFMAI(T1H, T1E), ms, &(x[0]));
	       }
	       {
		    V TR, T16, T1e, T1b, T13, T1d, Tu, T1a;
		    TR = VFMA(LDK(KP618033988), TQ, TF);
		    T16 = VFMA(LDK(KP618033988), T15, T14);
		    T1e = VFNMS(LDK(KP618033988), T14, T15);
		    T1b = VFNMS(LDK(KP618033988), TF, TQ);
		    {
			 V T11, T12, Ts, Tt;
			 T11 = VFNMS(LDK(KP250000000), T10, TX);
			 T12 = VSUB(TY, TZ);
			 T13 = VFMA(LDK(KP559016994), T12, T11);
			 T1d = VFNMS(LDK(KP559016994), T12, T11);
			 Ts = VFNMS(LDK(KP250000000), Tr, T4);
			 Tt = VSUB(Tf, Tq);
			 Tu = VFMA(LDK(KP559016994), Tt, Ts);
			 T1a = VFNMS(LDK(KP559016994), Tt, Ts);
		    }
		    {
			 V TS, T17, T1g, T1h;
			 TS = VFNMS(LDK(KP951056516), TR, Tu);
			 T17 = VFMA(LDK(KP951056516), T16, T13);
			 ST(&(x[WS(rs, 19)]), VFNMSI(T17, TS), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 1)]), VFMAI(T17, TS), ms, &(x[WS(rs, 1)]));
			 T1g = VFNMS(LDK(KP951056516), T1b, T1a);
			 T1h = VFMA(LDK(KP951056516), T1e, T1d);
			 ST(&(x[WS(rs, 7)]), VFNMSI(T1h, T1g), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 13)]), VFMAI(T1h, T1g), ms, &(x[WS(rs, 1)]));
		    }
		    {
			 V T18, T19, T1c, T1f;
			 T18 = VFMA(LDK(KP951056516), TR, Tu);
			 T19 = VFNMS(LDK(KP951056516), T16, T13);
			 ST(&(x[WS(rs, 11)]), VFNMSI(T19, T18), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 9)]), VFMAI(T19, T18), ms, &(x[WS(rs, 1)]));
			 T1c = VFMA(LDK(KP951056516), T1b, T1a);
			 T1f = VFNMS(LDK(KP951056516), T1e, T1d);
			 ST(&(x[WS(rs, 3)]), VFNMSI(T1f, T1c), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 17)]), VFMAI(T1f, T1c), ms, &(x[WS(rs, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     VTW(0, 15),
     VTW(0, 16),
     VTW(0, 17),
     VTW(0, 18),
     VTW(0, 19),
     { TW_NEXT, VL, 0 }
};

static const ct_desc desc = { 20, XSIMD_STRING("t1bv_20"), twinstr, &GENUS, { 77, 42, 46, 0 }, 0, 0, 0 };

void XSIMD(codelet_t1bv_20) (planner *p) {
     X(kdft_dit_register) (p, t1bv_20, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 20 -name t1bv_20 -include dft/simd/t1b.h -sign 1 */

/*
 * This function contains 123 FP additions, 62 FP multiplications,
 * (or, 111 additions, 50 multiplications, 12 fused multiply/add),
 * 54 stack variables, 4 constants, and 40 memory accesses
 */
#include "dft/simd/t1b.h"

static void t1bv_20(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     VENTER();
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 38)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 38), MAKE_VOLATILE_STRIDE(20, rs)) {
	       V T4, T10, T1B, T1R, TF, T14, T15, TQ, Tf, Tq, Tr, T1N, T1O, T1P, T1t;
	       V T1w, T1D, TT, TU, T11, T1K, T1L, T1M, T1m, T1p, T1C, T1i, T1j;
	       {
		    V T1, TZ, T3, TX, TY, T2, TW, T1z, T1A;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    TY = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
		    TZ = BYTW(&(W[TWVL * 28]), TY);
		    T2 = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
		    T3 = BYTW(&(W[TWVL * 18]), T2);
		    TW = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    TX = BYTW(&(W[TWVL * 8]), TW);
		    T4 = VSUB(T1, T3);
		    T10 = VSUB(TX, TZ);
		    T1z = VADD(T1, T3);
		    T1A = VADD(TX, TZ);
		    T1B = VSUB(T1z, T1A);
		    T1R = VADD(T1z, T1A);
	       }
	       {
		    V T9, T1k, TK, T1s, TP, T1v, Te, T1n, Tk, T1r, Tz, T1l, TE, T1o, Tp;
		    V T1u;
		    {
			 V T6, T8, T5, T7;
			 T5 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 T6 = BYTW(&(W[TWVL * 6]), T5);
			 T7 = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 T8 = BYTW(&(W[TWVL * 26]), T7);
			 T9 = VSUB(T6, T8);
			 T1k = VADD(T6, T8);
		    }
		    {
			 V TH, TJ, TG, TI;
			 TG = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 TH = BYTW(&(W[TWVL * 24]), TG);
			 TI = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 TJ = BYTW(&(W[TWVL * 4]), TI);
			 TK = VSUB(TH, TJ);
			 T1s = VADD(TH, TJ);
		    }
		    {
			 V TM, TO, TL, TN;
			 TL = LD(&(x[WS(rs, 17)]), ms, &(x[WS(rs, 1)]));
			 TM = BYTW(&(W[TWVL * 32]), TL);
			 TN = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 TO = BYTW(&(W[TWVL * 12]), TN);
			 TP = VSUB(TM, TO);
			 T1v = VADD(TM, TO);
		    }
		    {
			 V Tb, Td, Ta, Tc;
			 Ta = LD(&(x[WS(rs, 16)]), ms, &(x[0]));
			 Tb = BYTW(&(W[TWVL * 30]), Ta);
			 Tc = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Td = BYTW(&(W[TWVL * 10]), Tc);
			 Te = VSUB(Tb, Td);
			 T1n = VADD(Tb, Td);
		    }
		    {
			 V Th, Tj, Tg, Ti;
			 Tg = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 Th = BYTW(&(W[TWVL * 14]), Tg);
			 Ti = LD(&(x[WS(rs, 18)]), ms, &(x[0]));
			 Tj = BYTW(&(W[TWVL * 34]), Ti);
			 Tk = VSUB(Th, Tj);
			 T1r = VADD(Th, Tj);
		    }
		    {
			 V Tw, Ty, Tv, Tx;
			 Tv = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Tw = BYTW(&(W[TWVL * 16]), Tv);
			 Tx = LD(&(x[WS(rs, 19)]), ms, &(x[WS(rs, 1)]));
			 Ty = BYTW(&(W[TWVL * 36]), Tx);
			 Tz = VSUB(Tw, Ty);
			 T1l = VADD(Tw, Ty);
		    }
		    {
			 V TB, TD, TA, TC;
			 TA = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 TB = BYTW(&(W[0]), TA);
			 TC = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 TD = BYTW(&(W[TWVL * 20]), TC);
			 TE = VSUB(TB, TD);
			 T1o = VADD(TB, TD);
		    }
		    {
			 V Tm, To, Tl, Tn;
			 Tl = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 Tm = BYTW(&(W[TWVL * 22]), Tl);
			 Tn = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 To = BYTW(&(W[TWVL * 2]), Tn);
			 Tp = VSUB(Tm, To);
			 T1u = VADD(Tm, To);
		    }
		    TF = VSUB(Tz, TE);
		    T14 = VSUB(T9, Te);
		    T15 = VSUB(Tk, Tp);
		    TQ = VSUB(TK, TP);
		    Tf = VADD(T9, Te);
		    Tq = VADD(Tk, Tp);
		    Tr = VADD(Tf, Tq);
		    T1N = VADD(T1r, T1s);
		    T1O = VADD(T1u, T1v);
		    T1P = VADD(T1N, T1O);
		    T1t = VSUB(T1r, T1s);
		    T1w = VSUB(T1u, T1v);
		    T1D = VADD(T1t, T1w);
		    TT = VADD(Tz, TE);
		    TU = VADD(TK, TP);
		    T11 = VADD(TT, TU);
		    T1K = VADD(T1k, T1l);
		    T1L = VADD(T1n, T1o);
		    T1M = VADD(T1K, T1L);
		    T1m = VSUB(T1k, T1l);
		    T1p = VSUB(T1n, T1o);
		    T1C = VADD(T1m, T1p);
	       }
	       T1i = VADD(T4, Tr);
	       T1j = VBYI(VADD(T10, T11));
	       ST(&(x[WS(rs, 15)]), VSUB(T1i, T1j), ms, &(x[WS(rs, 1)]));
	       ST(&(x[WS(rs, 5)]), VADD(T1i, T1j), ms, &(x[WS(rs, 1)]));
	       {
		    V T1Q, T1S, T1T, T1X, T1Z, T1V, T1W, T1Y, T1U;
		    T1Q = VMUL(LDK(KP559016994), VSUB(T1M, T1P));
		    T1S = VADD(T1M, T1P);
		    T1T = VFNMS(LDK(KP250000000), T1S, T1R);
		    T1V = VSUB(T1K, T1L);
		    T1W = VSUB(T1N, T1O);
		    T1X = VBYI(VFMA(LDK(KP951056516), T1V, VMUL(LDK(KP587785252), T1W)));
		    T1Z = VBYI(VFNMS(LDK(KP951056516), T1W, VMUL(LDK(KP587785252), T1V)));
		    ST(&(x[0]), VADD(T1R, T1S), ms, &(x[0]));
		    T1Y = VSUB(T1T, T1Q);
		    ST(&(x[WS(rs, 8)]), VSUB(T1Y, T1Z), ms, &(x[0]));
		    ST(&(x[WS(rs, 12)]), VADD(T1Z, T1Y), ms, &(x[0]));
		    T1U = VADD(T1Q, T1T);
		    ST(&(x[WS(rs, 4)]), VSUB(T1U, T1X), ms, &(x[0]));
		    ST(&(x[WS(rs, 16)]), VADD(T1X, T1U), ms, &(x[0]));
	       }
	       {
		    V T1G, T1E, T1F, T1y, T1I, T1q, T1x, T1J, T1H;
		    T1G = VMUL(LDK(KP559016994), VSUB(T1C, T1D));
		    T1E = VADD(T1C, T1D);
		    T1F = VFNMS(LDK(KP250000000), T1E, T1B);
		    T1q = VSUB(T1m, T1p);
		    T1x = VSUB(T1t, T1w);
		    T1y = VBYI(VFNMS(LDK(KP951056516), T1x, VMUL(LDK(KP587785252), T1q)));
		    T1I = VBYI(VFMA(LDK(KP951056516), T1q, VMUL(LDK(KP587785252), T1x)));
		    ST(&(x[WS(rs, 10)]), VADD(T1B, T1E), ms, &(x[0]));
		    T1J = VADD(T1G, T1F);
		    ST(&(x[WS(rs, 6)]), VADD(T1I, T1J), ms, &(x[0]));
		    ST(&(x[WS(rs, 14)]), VSUB(T1J, T1I), ms, &(x[0]));
		    T1H = VSUB(T1F, T1G);
		    ST(&(x[WS(rs, 2)]), VADD(T1y, T1H), ms, &(x[0]));
		    ST(&(x[WS(rs, 18)]), VSUB(T1H, T1y), ms, &(x[0]));
	       }
	       {
		    V TR, T16, T1d, T1b, T13, T1e, Tu, T1a;
		    TR = VFNMS(LDK(KP951056516), TQ, VMUL(LDK(KP587785252), TF));
		    T16 = VFNMS(LDK(KP951056516), T15, VMUL(LDK(KP587785252), T14));
		    T1d = VFMA(LDK(KP951056516), T14, VMUL(LDK(KP587785252), T15));
		    T1b = VFMA(LDK(KP951056516), TF, VMUL(LDK(KP587785252), TQ));
		    {
			 V TV, T12, Ts, Tt;
			 TV = VMUL(LDK(KP559016994), VSUB(TT, TU));
			 T12 = VFNMS(LDK(KP250000000), T11, T10);
			 T13 = VSUB(TV, T12);
			 T1e = VADD(TV, T12);
			 Ts = VFNMS(LDK(KP250000000), Tr, T4);
			 Tt = VMUL(LDK(KP559016994), VSUB(Tf, Tq));
			 Tu = VSUB(Ts, Tt);
			 T1a = VADD(Tt, Ts);
		    }
		    {
			 V TS, T17, T1g, T1h;
			 TS = VSUB(Tu, TR);
			 T17 = VBYI(VSUB(T13, T16));
			 ST(&(x[WS(rs, 17)]), VSUB(TS, T17), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 3)]), VADD(TS, T17), ms, &(x[WS(rs, 1)]));
			 T1g = VADD(T1a, T1b);
			 T1h = VBYI(VSUB(T1e, T1d));
			 ST(&(x[WS(rs, 11)]), VSUB(T1g, T1h), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 9)]), VADD(T1g, T1h), ms, &(x[WS(rs, 1)]));
		    }
		    {
			 V T18, T19, T1c, T1f;
			 T18 = VADD(Tu, TR);
			 T19 = VBYI(VADD(T16, T13));
			 ST(&(x[WS(rs, 13)]), VSUB(T18, T19), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 7)]), VADD(T18, T19), ms, &(x[WS(rs, 1)]));
			 T1c = VSUB(T1a, T1b);
			 T1f = VBYI(VADD(T1d, T1e));
			 ST(&(x[WS(rs, 19)]), VSUB(T1c, T1f), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 1)]), VADD(T1c, T1f), ms, &(x[WS(rs, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     VTW(0, 15),
     VTW(0, 16),
     VTW(0, 17),
     VTW(0, 18),
     VTW(0, 19),
     { TW_NEXT, VL, 0 }
};

static const ct_desc desc = { 20, XSIMD_STRING("t1bv_20"), twinstr, &GENUS, { 111, 50, 12, 0 }, 0, 0, 0 };

void XSIMD(codelet_t1bv_20) (planner *p) {
     X(kdft_dit_register) (p, t1bv_20, &desc);
}
#endif
