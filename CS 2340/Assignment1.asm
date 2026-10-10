.data
X:          .word   0
Y:          .word   0
D:          .word   0

promptX:    .asciiz "Enter integer X: "
promptY:    .asciiz "Enter integer Y: "
resultMsg:  .asciiz "The difference between X and Y (X-Y) is "

.text
            .globl  main

main:
    # Prompt and Read Integer X
    li      $v0,    4
    la      $a0,    promptX
    syscall

    li      $v0,    5
    syscall
    sw      $v0,    X

    # Prompt and Read Integer Y
    li      $v0,    4
    la      $a0,    promptY
    syscall

    li      $v0,    5
    syscall
    sw      $v0,    Y

    # Calculate the difference
    lw      $t0,    X
    lw      $t1,    Y
    sub     $t2,    $t0,        $t1
    sw      $t2,    D

    # Output
    li      $v0,    4
    la      $a0,    resultMsg
    syscall

    lw      $a0,    D
    li      $v0,    1
    syscall

    # Exit
    li      $v0,    10
    syscall