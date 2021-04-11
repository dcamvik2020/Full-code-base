set disassembly-flavor intel
info file
# set breakpoint to second command, see the length of first command (to _start it can't set breakpoint)
b * _start + 5
display /6i $eip
display $eflags
display /x $edi
display /x $esi
display /x $edx
display /x $ecx
display /x $ebx
display /x $eax
display /16xw $esp
display /x $ebp
# set address of beginning .data section here
#display /64xb 0x080490a4
disassemble _start
set history save on
