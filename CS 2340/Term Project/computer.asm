.text
    .globl  computer_move
computer_move:
    addiu   $sp,                    $sp,                    -32
    sw      $s0,                    0($sp)
    sw      $s1,                    4($sp)
    sw      $s2,                    8($sp)
    sw      $s3,                    12($sp)
    sw      $s4,                    16($sp)
    sw      $s5,                    20($sp)
    sw      $s6,                    24($sp)
    sw      $ra,                    28($sp)

    li      $s0,                    0                                               # source square index

computer_source_loop:
    slti    $t0,                    $s0,                    36
    beq     $t0,                    $zero,                  computer_no_move

    sll     $t1,                    $s0,                    2
    la      $t2,                    board
    addu    $t2,                    $t2,                    $t1
    lw      $s1,                    0($t2)
    bgez    $s1,                    computer_next_source

    li      $t0,                    6
    div     $s0,                    $t0
    mflo    $s2                                                                     # source row
    mfhi    $s3                                                                     # source column
    li      $s4,                    -1                                              # row change

computer_row_loop:
    addu    $t0,                    $s2,                    $s4
    bltz    $t0,                    computer_next_row
    slti    $t1,                    $t0,                    6
    beq     $t1,                    $zero,                  computer_next_row
    move    $s6,                    $t0                                             # candidate row
    li      $t7,                    -1                                              # column change

computer_col_loop:
    addu    $t2,                    $s3,                    $t7
    bltz    $t2,                    computer_next_col
    slti    $t3,                    $t2,                    6
    beq     $t3,                    $zero,                  computer_next_col

    # The destination cannot be the source square.
    bne     $s4,                    $zero,                  computer_test_square
    beq     $t7,                    $zero,                  computer_next_col

computer_test_square:
    li      $t4,                    6
    mul     $t5,                    $s6,                    $t4
    addu    $t5,                    $t5,                    $t2
    sll     $t5,                    $t5,                    2
    la      $t6,                    board
    addu    $t6,                    $t6,                    $t5
    lw      $t8,                    0($t6)
    bne     $t8,                    $zero,                  computer_next_col

    # Computer values are negative, so subtract one to grow the chain.
    addiu   $t8,                    $s1,                    -1
    sw      $t8,                    0($t6)
    li      $v0,                    1
    j       computer_move_done

computer_next_col:
    addiu   $t7,                    $t7,                    1
    slti    $t0,                    $t7,                    2
    bne     $t0,                    $zero,                  computer_col_loop

computer_next_row:
    addiu   $s4,                    $s4,                    1
    slti    $t0,                    $s4,                    2
    bne     $t0,                    $zero,                  computer_row_loop

computer_next_source:
    addiu   $s0,                    $s0,                    1
    j       computer_source_loop

computer_no_move:
    move    $v0,                    $zero

computer_move_done:
    lw      $s0,                    0($sp)
    lw      $s1,                    4($sp)
    lw      $s2,                    8($sp)
    lw      $s3,                    12($sp)
    lw      $s4,                    16($sp)
    lw      $s5,                    20($sp)
    lw      $s6,                    24($sp)
    lw      $ra,                    28($sp)
    addiu   $sp,                    $sp,                    32
    jr      $ra
