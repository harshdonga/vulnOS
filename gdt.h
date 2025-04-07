#ifndef __GDT_H
#define __GDT_H

#include "types.h"
class GlobalDescriptorTable {
    public:
        class SegmentDescriptor {
            private:
                /*
                Represents 8 bytes of segment entry (each represent 1 byte)
                limit - limit - ptr - ptr - ptr - access - flags+limit - ptr
                */
                uint16_t limit_lo;
                uint16_t base_lo;
                uint16_t base_hi;
                uint8_t type;
                uint8_t flags_limit_hi;
                uint8_t base_vhi;
            public:
                SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);
                uint32_t base();
                uint32_t limit();
        } __attribute__((packed));
    
    // Really bad way to initialize for whole memory, but who cares atm, right?
    SegmentDescriptor null_segment_selector;
    SegmentDescriptor unused_segment_selector;
    SegmentDescriptor code_segment_selector;
    SegmentDescriptor data_segment_selector;

    public:
        GlobalDescriptorTable();
        ~GlobalDescriptorTable();

        // Methods to return offset of code segment, same for data segment
        uint16_t codeSegmentSelector();
        uint16_t dataSegmentSelector();
};

#endif