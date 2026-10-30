.data
human_source_row_prompt:    .asciiz "Choose one of your H numbers. Row (1-6): "
human_source_col_prompt:    .asciiz "Column (1-6): "
human_dest_row_prompt:      .asciiz "Choose an empty neighboring square. Row (1-6): "
human_dest_col_prompt:      .asciiz "Column (1-6): "
human_bad_move_message:     .asciiz "That space is incorrect. Please try again.\n"
human_good_move_message:    .asciiz "Move accepted.\n"

.text
                            .globl  human_move
human_move:
    addiu   $sp,                $sp,                        -24
    sw      $s0,                0($sp)
    sw      $s1,                4($sp)
    sw      $s2,                8($sp)
    sw      $s3,                12($sp)
    sw      $s4,                16($sp)
    sw      $ra,                20($sp)

human_move_retry:
    la      $a0,                human_source_row_prompt
    li      $v0,                4
    syscall
    li      $v0,                5
    syscall
    move    $s0,                $v0

    la      $a0,                human_source_col_prompt
    li      $v0,                4
    syscall
    li      $v0,                5
    syscall
    move    $s1,                $v0

    la      $a0,                human_dest_row_prompt
    li      $v0,                4
    syscall
    li      $v0,                5
    syscall
    move    $s2,                $v0

    la      $a0,                human_dest_col_prompt
    li      $v0,                4
    syscall
    li      $v0,                5
    syscall
    move    $s3,                $v0

    # Check all four coordinates before using them as array positions.
    blt     $s0,                1,                          human_move_invalid
    bgt     $s0,                6,                          human_move_invalid
    blt     $s1,                1,                          human_move_invalid
    bgt     $s1,                6,                          human_move_invalid
    blt     $s2,                1,                          human_move_invalid
    bgt     $s2,                6,                          human_move_invalid
    blt     $s3,                1,                          human_move_invalid
    bgt     $s3,                6,                          human_move_invalid

    # Convert the coordinates to zero-based row and column numbers.
    addiu   $s0,                $s0,                        -1
    addiu   $s1,                $s1,                        -1
    addiu   $s2,                $s2,                        -1
    addiu   $s3,                $s3,                        -1

    # Find the source square and make sure it belongs to the human player.
    li      $t0,                6
    mul     $t1,                $s0,                        $t0
    addu    $t1,                $t1,                        $s1
    sll     $t2,                $t1,                        2
    la      $t3,                board
    addu    $t3,                $t3,                        $t2
    lw      $s4,                0($t3)
    blez    $s4,                human_move_invalid

    # Find the destination square and make sure it is empty.
    mul     $t4,                $s2,                        $t0
    addu    $t4,                $t4,                        $s3
    sll     $t5,                $t4,                        2
    la      $t6,                board
    addu    $t5,                $t6,                        $t5
    lw      $t7,                0($t5)
    bne     $t7,                $zero,                      human_move_invalid

    # The source and destination must be next to each other.
    subu    $t0,                $s0,                        $s2
    bgez    $t0,                human_row_difference_ready
    subu    $t0,                $zero,                      $t0
human_row_difference_ready:
    slti    $t1,                $t0,                        2
    beq     $t1,                $zero,                      human_move_invalid

    subu    $t0,                $s1,                        $s3
    bgez    $t0,                human_col_difference_ready
    subu    $t0,                $zero,                      $t0
human_col_difference_ready:
    slti    $t1,                $t0,                        2
    beq     $t1,                $zero,                      human_move_invalid

    # Add the next number to the chosen empty square.
    addiu   $t0,                $s4,                        1
    sw      $t0,                0($t5)

    la      $a0,                human_good_move_message
    li      $v0,                4
    syscall
    j       human_move_done

human_move_invalid:
    la      $a0,                human_bad_move_message
    li      $v0,                4
    syscall
    j       human_move_retry

human_move_done:
    lw      $s0,                0($sp)
    lw      $s1,                4($sp)
    lw      $s2,                8($sp)
    lw      $s3,                12($sp)
    lw      $s4,                16($sp)
    lw      $ra,                20($sp)
    addiu   $sp,                $sp,                        24
    jr      $ra
