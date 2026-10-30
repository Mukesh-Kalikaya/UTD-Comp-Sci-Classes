.data
board_header:   .asciiz "       1     2     3     4     5     6\n"
board_indent:   .asciiz "    "
board_row_lead: .asciiz " "
board_line:     .asciiz "+-----+-----+-----+-----+-----+-----+\n"
board_space:    .asciiz "     "
board_human:    .asciiz " H"
board_comp:     .asciiz " C"
board_pad_one:  .asciiz "  "
board_pad_two:  .asciiz " "
board_bar:      .asciiz "|"
board_newline:  .asciiz "\n"

.text
                .globl  draw_board
draw_board:
    addiu   $sp,            $sp,                -8
    sw      $s0,            0($sp)
    sw      $s1,            4($sp)

    la      $a0,            board_header
    li      $v0,            4
    syscall

    la      $a0,            board_indent
    li      $v0,            4
    syscall
    la      $a0,            board_line
    li      $v0,            4
    syscall

    li      $s0,            0                                           # row index

draw_row_loop:
    slti    $t0,            $s0,                6
    beq     $t0,            $zero,              draw_board_done

    # Print the row number on the left.
    la      $a0,            board_row_lead
    li      $v0,            4
    syscall
    addiu   $a0,            $s0,                1
    li      $v0,            1
    syscall
    la      $a0,            board_pad_one
    li      $v0,            4
    syscall

    li      $s1,            0                                           # column index

draw_col_loop:
    slti    $t0,            $s1,                6
    beq     $t0,            $zero,              draw_row_end

    la      $a0,            board_bar
    li      $v0,            4
    syscall

    li      $t0,            6
    mul     $t1,            $s0,                $t0
    addu    $t1,            $t1,                $s1
    sll     $t1,            $t1,                2
    la      $t2,            board
    addu    $t2,            $t2,                $t1
    lw      $t3,            0($t2)

    beq     $t3,            $zero,              draw_empty_cell
    bgtz    $t3,            draw_human_cell

    # Computer numbers are stored as negative values.
    la      $a0,            board_comp
    li      $v0,            4
    syscall
    subu    $a0,            $zero,              $t3
    li      $v0,            1
    syscall
    li      $t4,            -10
    ble     $t3,            $t4,                draw_comp_two_digits
    la      $a0,            board_pad_one
    li      $v0,            4
    syscall
    j       draw_cell_done

draw_comp_two_digits:
    la      $a0,            board_pad_two
    li      $v0,            4
    syscall
    j       draw_cell_done

draw_human_cell:
    la      $a0,            board_human
    li      $v0,            4
    syscall
    move    $a0,            $t3
    li      $v0,            1
    syscall
    li      $t4,            10
    bge     $t3,            $t4,                draw_human_two_digits
    la      $a0,            board_pad_one
    li      $v0,            4
    syscall
    j       draw_cell_done

draw_human_two_digits:
    la      $a0,            board_pad_two
    li      $v0,            4
    syscall
    j       draw_cell_done

draw_empty_cell:
    la      $a0,            board_space
    li      $v0,            4
    syscall

draw_cell_done:
    addiu   $s1,            $s1,                1
    j       draw_col_loop

draw_row_end:
    la      $a0,            board_bar
    li      $v0,            4
    syscall
    la      $a0,            board_newline
    li      $v0,            4
    syscall

    la      $a0,            board_indent
    li      $v0,            4
    syscall
    la      $a0,            board_line
    li      $v0,            4
    syscall

    addiu   $s0,            $s0,                1
    j       draw_row_loop

draw_board_done:
    lw      $s0,            0($sp)
    lw      $s1,            4($sp)
    addiu   $sp,            $sp,                8
    jr      $ra
