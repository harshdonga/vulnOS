void printf(char* str) {
    unsigned short* video_memory = (unsigned short*)0xb8000;

    for(int i = 0; str[i] != '\0'; ++i){
        video_memory[i] = (video_memory[i] & 0xFF00) | str[i];
    }
}


extern "C" void vuln_kernel(void* multiboot_structure, unsigned int magic_number) {
    printf("Hi from VulnOS, this is just can of worms!");

    while(1);
}