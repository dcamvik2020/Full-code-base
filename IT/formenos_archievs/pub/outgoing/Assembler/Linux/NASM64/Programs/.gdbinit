set disassembly-flavor intel
info file
# set breakpoint to second command, see the length of first command (to _start it can't set breakpoint)
b * _start + 1
display /6i $rip
display $eflags
display /x $r9
display /x $r8
display /x $rdi
display /x $rsi
display /x $rdx
display /x $rcx
display /x $rbx
display /x $rax
display /16xg $rsp
# set address of beginning .data section here
display /64xb 0x000000000060049c
set history save on
