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
/* Generated on Tue Nov 24 01:06:11 JST 2020 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw.native -fma -compact -variables 4 -pipeline-latency 4 -n 2 -name n1_2 -include dft/scalar/n.h */

/*
 * This function contains 4 FP additions, 0 FP multiplications,
 * (or, 4 additions, 0 multiplications, 0 fused multiply/add),
 * 5 stack variables, 0 constants, and 8 memory accesses
 */
#include "dft/scalar/n.h"

static void n1_2(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, MAKE_VOLATILE_STRIDE(8, is), MAKE_VOLATILE_STRIDE(8, os)) {
	       E T1, T2, T3, T4;
	       T1 = ri[0];
	       T2 = ri[WS(is, 1)];
	       ro[WS(os, 1)] = T1 - T2;
	       ro[0] = T1 + T2;
	       T3 = ii[0];
	       T4 = ii[WS(is, 1)];
	       io[WS(os, 1)] = T3 - T4;
	       io[0] = T3 + T4;
	  }
     }
}

static const kdft_desc desc = { 2, "n1_2", { 4, 0, 0, 0 }, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1_2) (planner *p) { X(kdft_register) (p, n1_2, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw.native -compact -variables 4 -pipeline-latency 4 -n 2 -name n1_2 -include dft/scalar/n.h */

/*
 * This function contains 4 FP additions, 0 FP multiplications,
 * (or, 4 additions, 0 multiplications, 0 fused multiply/add),
 * 5 stack variables, 0 constants, and 8 memory accesses
 */
#include "dft/scalar/n.h"

static void n1_2(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, MAKE_VOLATILE_STRIDE(8, is), MAKE_VOLATILE_STRIDE(8, os)) {
	       E T1, T2, T3, T4;
	       T1 = ri[0];
	       T2 = ri[WS(is, 1)];
	       ro[WS(os, 1)] = T1 - T2;
	       ro[0] = T1 + T2;
	       T3 = ii[0];
	       T4 = ii[WS(is, 1)];
	       io[WS(os, 1)] = T3 - T4;
	       io[0] = T3 + T4;
	  }
     }
}

static const kdft_desc desc = { 2, "n1_2", { 4, 0, 0, 0 }, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1_2) (planner *p) { X(kdft_register) (p, n1_2, &desc);
}

#endif
