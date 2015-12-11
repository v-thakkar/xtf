/*
 * Xen x86 public interface
 */

#ifndef XEN_PUBLIC_ARCH_X86_XEN_H
#define XEN_PUBLIC_ARCH_X86_XEN_H

#if defined (__i386__)
# include "xen-x86_32.h"
#elif defined (__x86_64__)
# include "xen-x86_64.h"
#else
# error Bad architecture
#endif

#include "cpuid.h"

#ifndef __ASSEMBLY__
typedef unsigned long xen_pfn_t;

/*
 * Send an array of these to HYPERVISOR_set_trap_table().
 * Terminate the array with a sentinel entry, with traps[].address==0.
 * The privilege level specifies which modes may enter a trap via a software
 * interrupt. On x86/64, since rings 1 and 2 are unavailable, we allocate
 * privilege levels as follows:
 *  Level == 0: Noone may enter
 *  Level == 1: Kernel may enter
 *  Level == 2: Kernel may enter
 *  Level == 3: Everyone may enter
 */
struct xen_trap_info {
    uint8_t       vector;  /* exception vector                              */
    uint8_t       flags;   /* 0-3: privilege level; 4: clear event enable?  */
    uint16_t      cs;      /* code selector                                 */
    unsigned long address; /* code offset                                   */
};

#endif

#endif /* XEN_PUBLIC_ARCH_X86_XEN_H */

/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
