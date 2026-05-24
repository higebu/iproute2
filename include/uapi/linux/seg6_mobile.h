/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 *  SRv6 Mobile User Plane (RFC 9433) UAPI
 *
 *  This namespace is dedicated to SRv6 Mobile User Plane behaviors
 *  registered under LWTUNNEL_ENCAP_SEG6_MOBILE.  It is deliberately
 *  kept separate from SEG6_LOCAL_* because some attributes (for
 *  example a next-hop SID) carry different semantics depending on the
 *  behavior.
 */
#ifndef _LINUX_SEG6_MOBILE_H
#define _LINUX_SEG6_MOBILE_H

enum {
	SEG6_MOBILE_UNSPEC,
	SEG6_MOBILE_ACTION,	/* u32 - behavior identifier */
	SEG6_MOBILE_NH6,	/* in6_addr - replacement SID (End.MAP) or
				 * next-hop SID (other behaviors)
				 */
	SEG6_MOBILE_COUNTERS,	/* nested - per-behavior packets/bytes/errors */
	SEG6_MOBILE_SRC_ADDR,	/* in6_addr - outer IPv6 SA template
				 * (Source UPF Prefix for GTP-U encap)
				 */
	SEG6_MOBILE_V4_MASK_LEN,	/* u8 - SID IPv4 portion length, 1..32 */
	SEG6_MOBILE_PDU_TYPE,		/* u8 - 4-bit PDU Type for the PDU
					 * Session Container (0=DL, 1=UL); the
					 * attribute presence selects long
					 * GTPv1-U + PSC over short GTPv1-U
					 */
	SEG6_MOBILE_V6_SRC_PREFIX_LEN,	/* u8 - Source UPF Prefix length P,
					 * 1..127, default 64 when unset
					 */
	__SEG6_MOBILE_MAX,
};

#define SEG6_MOBILE_MAX	(__SEG6_MOBILE_MAX - 1)

enum {
	SEG6_MOBILE_ACTION_UNSPEC = 0,
	SEG6_MOBILE_ACTION_END_MAP = 1,		/* RFC 9433 Section 6.2 */
	SEG6_MOBILE_ACTION_END_M_GTP4_E = 2,	/* RFC 9433 Section 6.6 */

	__SEG6_MOBILE_ACTION_MAX,
};

#define SEG6_MOBILE_ACTION_MAX	(__SEG6_MOBILE_ACTION_MAX - 1)

enum {
	SEG6_MOBILE_CNT_UNSPEC,
	SEG6_MOBILE_CNT_PACKETS,
	SEG6_MOBILE_CNT_BYTES,
	SEG6_MOBILE_CNT_ERRORS,
	SEG6_MOBILE_CNT_PAD,
	__SEG6_MOBILE_CNT_MAX,
};

#define SEG6_MOBILE_CNT_MAX	(__SEG6_MOBILE_CNT_MAX - 1)

#endif /* _LINUX_SEG6_MOBILE_H */
