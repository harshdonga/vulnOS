# vulnOS

Custom operating system/can of worms project from scratch

Checkout [notes](notes/) to understand the repo!


#### Build/Compile/install
Jump into the directory & run
`make install`

#### Run
Can be tested using:

- QEMU(preferred)
`qemu-system-i386 -kernel ./kernel/vuln_kernel.bin`

- GRUB
You'll need to modify `/boot/grub/grub.cfg` & add a `menuentry` like below:
    ```
    menuentry 'VulnOS' {
        linux <path-to-your-bin>
        boot
    }
    ```

#### Build system info
`Linux debian 6.1.0-31-arm64 #1 SMP Debian 6.1.128-1 (2025-02-07) aarch64 GNU/Linux`


#### Questions/Sugestions?
Reach out: [Linkedin](https://www.linkedin.com/in/harsh-donga/)