# Rookit-Arsenal


Chap 2 code and compiled .com files
Tested on DosBox 


ivtprint.c - print interruption vector table  
tsr.asm - install new ISR 0x187 to get global buffer address, hook 0x09 interruption    
hooktsr.c - read from global buffer with 0x187 ISR

May be compilled with open-watcom (masm compiller)  
http://openwatcom.org/download.php


##

in /_com files/   
ivt.com  
tsr.com  
tsrclient.com



