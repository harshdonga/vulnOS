#### Before we get into OS, we need to know how does everything come to life!

- Your BIOS lives on special ROM/flash memory chip on motherboard along with CPU and connected storage device(HDD/SSD)
- BIOS itself/Motherboard copies basically the assembler code/firmware to the RAM & tells CPU to point the `instruction pointer` to this address on RAM
- CPU has several registers(eax, ebx...) and pointers(stack, instruction...)
So now, firmware tells CPU to talk to storage device and get it's content on RAM too!
- Till now there is no concept of file system. Raw contents from `Master Boot Record` (probably first 2MiB, bootloader) gets copied to RAM
- Now CPU executes bootloader (which knows FS, partitions...). For GRUB, it looks into `/boot/grub/grub.cfg`
- Relevant kernel binary is loaded into RAM (our entrypoint!!)
- Bootloader looks for certain MAGIC number to recognize the file as kernel! 
- it also makes relevant structures and stores pointer to `EAX`, also stores the above MAGIC number to `EBX`


#### Insert 'We need to define the Universe first' meme :fearful:
How are we going to output anything!?
A'int using any standard libs, then how?

- Well there is specific location `0xb8000` on RAM, whatever we write on that is picked by graphic card.
- We store one unit character/number info and one is left for foreground/background color info. Pretty cool to know about this!