#ifndef UCAPI_CORTEX_M_PRIORITIES_H_INCLUDED
#define UCAPI_CORTEX_M_PRIORITIES_H_INCLUDED

#include "registers/scb.h"

/* A priority register is always 8 bits wide.
 * 
 * +---+---+---+---+---+---+---+---+-------------+
 * | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | BIT         |
 * +---+---+---+---+---+---+---+---+-------------+
 * | p | p | p | p | 0 | 0 | 0 | 0 | PBITS(4)    |
 * +---+---+---+---+---+---+---+---+-------------+
 * | g | g | g | s | s | s | s | s | PRIGROUP(4) | aircr.priogroup = 4 means 5 subpriority bits
 * +===+===+===+===+===+===+===+===+=============+
 * | G | G | G | S | 0 | 0 | 0 | 0 | PRIORITY    |
 * +---+---+---+---+---+---+---+---+-------------+
 *
 * PBITS        Is the number of priority bits actually implemented by the
 *              vendor. Priority bits fill the register from msb to lsb.
 *              
 * PRIGROUP     Is a user defined value determining the number of priority
 *              groups by partitioning the priority field into bits for
 *              the group priority (G) and bits for the subpriority (S).
 * 
 * Example:     In the example above we have 3 group priority bits and we
 *              have 1 subpriority bit. Thus there are 8 group priority
 *              values and 2 subpriority values. A currently running isr
 *              will be preempted if an interrupt with lower priority group
 *              value becomes pending. If two interrupts with the same
 *              group priority are pending at the same time the subpriority
 *              will decide which isr will be executed first. However,
 *              there will be no preemption between them.
 */

#define PRIORITIES_RESERVED_BITS (8 - SCB_PRIORITY_BITS_VALUE)
#define PRIORITIES_SUBPRIORITY_BITS (8 - SCB_GROUP_PRIORITY_BITS_VALUE)

#define PRIORITIES_SUBPRIORITY_BITS_USED (PRIORITIES_RESERVED_BITS - PRIORITIES_SUBPRIORITY_BITS)
#if PRIORITIES_SUBPRIORITY_BITS_USED < 0
#   undef PRIORITIES_SUBPRIORITY_BITS_USED
#   define PRIORITIES_SUBPRIORITY_BITS_USED 0
#endif /* PRIORITIES_SUBPRIORITY_BITS_USED */

#define PRIORITIES_GROUPPRIORITY_BITS_USED (SCB_GROUP_PRIORITY_BITS_VALUE - PRIORITIES_SUBPRIORITY_BITS_USED)
#if PRIORITIES_GROUPPRIORITY_BITS_USED < 0
#   undef PRIORITIES_GROUPPRIORITY_BITS_USED
#   define PRIORITIES_GROUPPRIORITY_BITS_USED 0
#endif /* PRIORITIES_GROUPPRIORITY_BITS_USED */

/* the highest priority value denotes the lowest priority */
#define PRIORITIES_SUBPRIORITY_LOWEST ((1 << PRIORITIES_SUBPRIORITY_BITS_USED) - 1)
#define PRIORITIES_GROUPPRIORITY_LOWEST ((1 << PRIORITIES_GROUPPRIORITY_BITS_USED) - 1)

struct cortex_m_priority {
    union {
        unsigned char priority;
        struct {
#if PRIORITIES_RESERVED_BITS
            unsigned char __reserved0:PRIORITIES_RESERVED_BITS;
#endif /* PRIORITIES_RESERVED_BITS */
#if PRIORITIES_SUBPRIORITY_BITS_USED  
            unsigned char subpriority:PRIORITIES_SUBPRIORITY_BITS_USED;
#endif /* PRIORITIES_SUBPRIORITY_BITS_USED */
#if PRIORITIES_GROUPPRIORITY_BITS_USED
            unsigned char grouppriority:PRIORITIES_GROUPPRIORITY_BITS_USED;
#endif /* PRIORITIES_GROUPPRIORITY_BITS_USED */
        };
    };
};
   
static inline void cortex_m_set_prigroup(void)
{
    scb->aircr.prigroup = SCB_GROUP_PRIORITY_BITS;
}

#endif /* UCAPI_CORTEX_M_PRIORITIES_H_INCLUDED */