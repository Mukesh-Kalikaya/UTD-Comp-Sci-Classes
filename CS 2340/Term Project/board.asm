.data
                .align  2                                           # Make sure board starts on a word boundary.
                .globl  board
                .globl  occupied_count
board:          .space  144                                         # 36 squares * 4 bytes each
occupied_count: .word   6

.text
                .globl  initialize_board
initialize_board:
    la      $t0,                board
    li      $t1,                0
    li      $t2,                36

board_clear_loop:
    beq     $t1,                $t2,            board_set_starts
    sw      $zero,              0($t0)
    addiu   $t0,                $t0,            4
    addiu   $t1,                $t1,            1
    j       board_clear_loop

board_set_starts:
    la      $t0,                board

    # Human starts at the top-left and moves diagonally inward.
    li      $t1,                1
    sw      $t1,                0($t0)                              # row 1, column 1
    li      $t1,                2
    sw      $t1,                28($t0)                             # row 2, column 2
    li      $t1,                3
    sw      $t1,                56($t0)                             # row 3, column 3

    # Computer starts at the bottom-right and moves diagonally inward.
    li      $t1,                -3
    sw      $t1,                84($t0)                             # row 4, column 4
    li      $t1,                -2
    sw      $t1,                112($t0)                            # row 5, column 5
    li      $t1,                -1
    sw      $t1,                140($t0)                            # row 6, column 6

    li      $t1,                6
    sw      $t1,                occupied_count
    jr      $ra
