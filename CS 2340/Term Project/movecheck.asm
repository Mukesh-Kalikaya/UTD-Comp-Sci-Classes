.text
    .globl  has_player_move
has_player_move:
    addiu   $sp,                        $sp,                    -28
    sw      $s0,                        0($sp)
    sw      $s1,                        4($sp)
    sw      $s2,                        8($sp)
    sw      $s3,                        12($sp)
    sw      $s4,                        16($sp)
    sw      $s5,                        20($sp)
    sw      $s6,                        24($sp)

    move    $s0,                        $a0                                             # player sign
    li      $s1,                        0                                               # source square index

movecheck_source_loop:
    slti    $t0,                        $s1,                    36
    beq     $t0,                        $zero,                  movecheck_no

    sll     $t1,                        $s1,                    2
    la      $t2,                        board
    addu    $t2,                        $t2,                    $t1
    lw      $s2,                        0($t2)

    bgtz    $s0,                        movecheck_check_human
    bgez    $s2,                        movecheck_next_source
    j       movecheck_check_neighbors

movecheck_check_human:
    blez    $s2,                        movecheck_next_source

movecheck_check_neighbors:
    li      $t0,                        6
    div     $s1,                        $t0
    mflo    $s3                                                                         # source row
    mfhi    $s4                                                                         # source column
    li      $s5,                        -1                                              # row change

movecheck_row_loop:
    addu    $t0,                        $s3,                    $s5
    bltz    $t0,                        movecheck_next_row
    slti    $t1,                        $t0,                    6
    beq     $t1,                        $zero,                  movecheck_next_row
    move    $s6,                        $t0                                             # save candidate row for the column loop
    li      $t7,                        -1                                              # column change

movecheck_col_loop:
    addu    $t2,                        $s4,                    $t7
    bltz    $t2,                        movecheck_next_col
    slti    $t3,                        $t2,                    6
    beq     $t3,                        $zero,                  movecheck_next_col

    # Do not treat the source square as its own neighbor.
    bne     $s5,                        $zero,                  movecheck_test_square
    beq     $t7,                        $zero,                  movecheck_next_col

movecheck_test_square:
    li      $t4,                        6
    mul     $t5,                        $s6,                    $t4
    addu    $t5,                        $t5,                    $t2
    sll     $t5,                        $t5,                    2
    la      $t6,                        board
    addu    $t6,                        $t6,                    $t5
    lw      $t8,                        0($t6)
    beq     $t8,                        $zero,                  movecheck_yes

movecheck_next_col:
    addiu   $t7,                        $t7,                    1
    slti    $t0,                        $t7,                    2
    bne     $t0,                        $zero,                  movecheck_col_loop

movecheck_next_row:
    addiu   $s5,                        $s5,                    1
    slti    $t0,                        $s5,                    2
    bne     $t0,                        $zero,                  movecheck_row_loop

movecheck_next_source:
    addiu   $s1,                        $s1,                    1
    j       movecheck_source_loop

movecheck_yes:
    li      $v0,                        1
    j       movecheck_done

movecheck_no:
    move    $v0,                        $zero

movecheck_done:
    lw      $s0,                        0($sp)
    lw      $s1,                        4($sp)
    lw      $s2,                        8($sp)
    lw      $s3,                        12($sp)
    lw      $s4,                        16($sp)
    lw      $s5,                        20($sp)
    lw      $s6,                        24($sp)
    addiu   $sp,                        $sp,                    28
    jr      $ra
