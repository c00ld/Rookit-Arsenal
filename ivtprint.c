#include <stdio.h>
#define WORD unsigned short
#define IDT_001_ADDR 0         // start address of the first IVT vector
#define IDT_255_ADDR 1020     // start address of the last IVT vector
#define IDT_VECTOR_SZ 4    // size of the each IVT vector
#define BP __asm{ int 0x3 }        // breakpoint

void main() {
        WORD csAddr;            // code segment of given interrupt
        WORD ipAddr;            // starting IP for given interrupt
        short address;            // address in memory (0-1020)
        WORD vector ;            // IVT entry ID (0..255)

        vector = 0x0;
        printf("\n-- -Dumping IVT from bottom up ---\n");
        printf("Vector\tAddress\t\n");

        for(address=IDT_001_ADDR; address<=IDT_255_ADDR; address=address+IDT_VECTOR_SZ,vector++) {
                printf("%03d\t%08p\t", vector , address);
                // IVT starts at bottom of memory, so CS is always 0x0
                __asm {
                        PUSH ES
                        mov AX, 0
                        mov ES,AX
                        mov BX, address
                        mov AX, ES:[BX]
                        mov ipAddr ,AX
                        inc BX
                        inc BX
                        mov AX, ES:[BX]
                        mov csAddr, AX
                        pop ES
                };
                printf("[CS:IP] = [%04X,%04X]\n" ,csAddr, ipAddr);
        }
        return;
}

