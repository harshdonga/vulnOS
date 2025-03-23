GPPPARAMS	= -fno-exceptions -fno-rtti -nostdlib -fno-builtin -fno-use-cxa-atexit -fno-leading-underscore
ASPARAMS	= --32
LDPARAMS	= -melf_i386

objects 	= loader.o kernel.o

%.o: %.cpp
		i686-linux-gnu-g++ $(GPPPARAMS) -o $@ -c $<

%.o: %.s
		i686-linux-gnu-as $(ASPARAMS) -o $@ $<

vuln_kernel.bin: linker.ld $(objects)
		i686-linux-gnu-ld $(LDPARAMS) -T $< -o $@ $(objects)

install: vuln_kernel.bin
		sudo cp $< /boot/vuln_kernel.bin