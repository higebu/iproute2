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
	__SEG6_MOBILE_MAX,
};

#define SEG6_MOBILE_MAX	(__SEG6_MOBILE_MAX - 1)

enum {
	SEG6_MOBILE_ACTION_UNSPEC = 0,
	SEG6_MOBILE_ACTION_END_MAP = 1,	/* RFC 9433 Section 6.2 */

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
