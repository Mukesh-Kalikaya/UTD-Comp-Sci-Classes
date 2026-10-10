
.data
X:          .word   0
Y:          .word   0
R:          .word   0

promptX:    .asciiz "\nEnter integer X (0 to stop): "
promptY:    .asciiz "Enter integer Y: "
promptOp:   .asciiz "Choose operation (1=AND, 2=OR, 3=NOT, 4=SLL, 5=SRL): "
promptN:    .asciiz "Enter number of bit positions to shift: "

xMsg:       .asciiz "X = "
yMsg:       .asciiz "Y = "
andMsg:     .asciiz "X&Y = "
orMsg:      .asciiz "X|Y = "
notMsg:     .asciiz "~X = "
sllMsg:     .asciiz "SLL result = "
srlMsg:     .asciiz "SRL result = "
nMsg:       .asciiz "n = "
newline:    .asciiz "\n"

.text
            .globl  main

main:
    # Prompt and Read Integer X
    li      $v0,    4
    la      $a0,    promptX
    syscall

    li      $v0,    5
    syscall
    move    $t0,    $v0

    # Stop if X is 0
    beq     $t0,    $zero,  exit

    sw      $t0,    X

    # Prompt and Read Integer Y
    li      $v0,    4
    la      $a0,    promptY
    syscall

    li      $v0,    5
    syscall
    sw      $v0,    Y

    # Ask for the operation
    li      $v0,    4
    la      $a0,    promptOp
    syscall

    li      $v0,    5
    syscall
    move    $t1,    $v0

    # Check which operation was selected
    li      $t2,    1
    beq     $t1,    $t2,    doAND

    li      $t2,    2
    beq     $t1,    $t2,    doOR

    li      $t2,    3
    beq     $t1,    $t2,    doNOT

    li      $t2,    4
    beq     $t1,    $t2,    doSLL

    li      $t2,    5
    beq     $t1,    $t2,    doSRL

    j       main

doAND:
    # Calculate X AND Y
    lw      $t0,    X
    lw      $t1,    Y
    and     $t2,    $t0,    $t1
    sw      $t2,    R

    # Print X in binary
    li      $v0,    4
    la      $a0,    xMsg
    syscall
    lw      $a0,    X
    jal     printBinary

    # Print Y in binary
    li      $v0,    4
    la      $a0,    yMsg
    syscall
    lw      $a0,    Y
    jal     printBinary

    # Print the result in binary
    li      $v0,    4
    la      $a0,    andMsg
    syscall
    lw      $a0,    R
    jal     printBinary

    j       main

doOR:
    # Calculate X OR Y
    lw      $t0,    X
    lw      $t1,    Y
    or      $t2,    $t0,    $t1
    sw      $t2,    R

    # Print X in binary
    li      $v0,    4
    la      $a0,    xMsg
    syscall
    lw      $a0,    X
    jal     printBinary

    # Print Y in binary
    li      $v0,    4
    la      $a0,    yMsg
    syscall
    lw      $a0,    Y
    jal     printBinary

    # Print the result in binary
    li      $v0,    4
    la      $a0,    orMsg
    syscall
    lw      $a0,    R
    jal     printBinary

    j       main

doNOT:
    # Calculate NOT X using NOR
    lw      $t0,    X
    nor     $t2,    $t0,    $zero
    sw      $t2,    R

    # Print X in binary
    li      $v0,    4
    la      $a0,    xMsg
    syscall
    lw      $a0,    X
    jal     printBinary

    # Print the result in binary
    li      $v0,    4
    la      $a0,    notMsg
    syscall
    lw      $a0,    R
    jal     printBinary

    j       main

doSLL:
    # Ask for the number of positions to shift
    li      $v0,    4
    la      $a0,    promptN
    syscall

    li      $v0,    5
    syscall
    move    $t3,    $v0

    # Shift X left
    lw      $t0,    X
    sllv    $t2,    $t0,    $t3
    sw      $t2,    R

    # Print X in binary
    li      $v0,    4
    la      $a0,    xMsg
    syscall
    lw      $a0,    X
    jal     printBinary

    # Print the shift amount
    li      $v0,    4
    la      $a0,    nMsg
    syscall
    move    $a0,    $t3
    li      $v0,    1
    syscall

    li      $v0,    4
    la      $a0,    newline
    syscall

    # Print the result in binary
    li      $v0,    4
    la      $a0,    sllMsg
    syscall
    lw      $a0,    R
    jal     printBinary

    j       main

doSRL:
    # Ask for the number of positions to shift
    li      $v0,    4
    la      $a0,    promptN
    syscall

    li      $v0,    5
    syscall
    move    $t3,    $v0

    # Shift X right
    lw      $t0,    X
    srlv    $t2,    $t0,    $t3
    sw      $t2,    R

    # Print X in binary
    li      $v0,    4
    la      $a0,    xMsg
    syscall
    lw      $a0,    X
    jal     printBinary

    # Print the shift amount
    li      $v0,    4
    la      $a0,    nMsg
    syscall
    move    $a0,    $t3
    li      $v0,    1
    syscall

    li      $v0,    4
    la      $a0,    newline
    syscall

    # Print the result in binary
    li      $v0,    4
    la      $a0,    srlMsg
    syscall
    lw      $a0,    R
    jal     printBinary

    j       main

# Print a number in 32-bit binary
printBinary:
    move    $t4,    $a0
    li      $t5,    31

printLoop:
    # Print the leftmost bit
    srl     $t6,    $t4,    31
    li      $v0,    1
    move    $a0,    $t6
    syscall

    # Move to the next bit
    sll     $t4,    $t4,    1
    addi    $t5,    $t5,    -1
    bgez    $t5,    printLoop

    # Print a new line
    li      $v0,    4
    la      $a0,    newline
    syscall

    jr      $ra

exit:
    # End the program
    li      $v0,    10
    syscall
