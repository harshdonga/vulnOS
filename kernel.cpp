#include "types.h"
#include "gdt.h"

void printf(char* str) {
    static uint16_t* video_memory = (uint16_t*)0xb8000;

    for(int i = 0; str[i] != '\0'; ++i){
        video_memory[i] = (video_memory[i] & 0xFF00) | str[i];
    }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void call_constructors() {
    for(constructor* i = &start_ctors; i != &end_ctors; i++) {
        (*i)();
    }
}


extern "C" void vuln_kernel(void* multiboot_structure, uint32_t magic_number) {
    printf("Hi from VulnOS, this is just can of worms!");

    GlobalDescriptorTable gdt;

    while(1);
}