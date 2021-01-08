.name "Vladeeemir Poot-inn"
.comment "Number one, the best of the best, born to be chamion. Even in Corewar. Made Corewar great again"

prejump:
sti r1, %7, %1
live %1
and %0,%0,r2
zjmp %:forkmiddle

live1:	sti r1, %7, %1
live %1
zjmp %:fork3quart

live2:	sti r1, %7, %1
live %1
zjmp %:fork1quart

live3:	sti r1, %7, %1
live %1
zjmp %:prejump

forkmiddle: lfork %1600
zjmp %:live1
fork3quart: lfork %2600
zjmp %:live2
fork1quart:	lfork %600
zjmp %:init

init:	sti r1, %:live,%1
ld %355,r2
ld %4,r3
ld -21, r6
ld %-56,r7
ld %4,r8

live:	live %1
add r2,r3,r2
sti r6, %:live,r2
ldi r7,r8,r6
add r7,r8,r7
and r4, %0, r4

zjmp %:live
