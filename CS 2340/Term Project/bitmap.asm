.data   0x10008000
                .align  2
bitmap_buffer:  .space  4096                                        # 32 rows * 32 columns * 4 bytes

.text
                .globl  draw_bitmap
draw_bitmap:
    # Clear the entire bitmap to a dark background.
    la      $t0,                bitmap_buffer
    li      $t1,                1024                                # 32 * 32 display units
    li      $t2,                0x00101010                          # dark gray

bitmap_clear_loop:
    sw      $t2,                0($t0)
    addiu   $t0,                $t0,                4
    addiu   $t1,                $t1,                -1
    bgtz    $t1,                bitmap_clear_loop

    # Visit each square on the 6 by 6 game board.
    li      $t0,                0                                   # board row

bitmap_row_loop:
    li      $t1,                0                                   # board column

bitmap_col_loop:
    # Find the board value at board[row * 6 + column].
    li      $t2,                6
    mul     $t3,                $t0,                $t2
    addu    $t3,                $t3,                $t1
    sll     $t3,                $t3,                2
    la      $t4,                board
    addu    $t4,                $t4,                $t3
    lw      $t5,                0($t4)

    beq     $t5,                $zero,              bitmap_next_col
    bgtz    $t5,                bitmap_human_color

    # Computer numbers are negative. Make the value positive for the color.
    subu    $t6,                $zero,              $t5
    sll     $t6,                $t6,                2               # number * 4 controls the green shade
    sll     $t6,                $t6,                8
    li      $t7,                0x00FF0020                          # red computer color
    or      $t7,                $t7,                $t6
    j       bitmap_color_ready

bitmap_human_color:
    sll     $t6,                $t5,                2               # number * 4 controls the green shade
    sll     $t6,                $t6,                8
    li      $t7,                0x000000FF                          # blue human color
    or      $t7,                $t7,                $t6

bitmap_color_ready:
    # Put the square in the center of the display.
    # Each game square is 3 display units wide and tall.
    # The +8 leaves a 7-unit outer border and a 1-unit inner border.
    li      $t2,                3
    mul     $t6,                $t0,                $t2
    addiu   $t6,                $t6,                8               # display row
    mul     $t8,                $t1,                $t2
    addiu   $t8,                $t8,                8               # display column

    # Each display row contains 32 words.
    sll     $t6,                $t6,                5               # display row * 32
    addu    $t6,                $t6,                $t8
    sll     $t6,                $t6,                2               # convert word index to byte offset
    la      $t9,                bitmap_buffer
    addu    $t9,                $t9,                $t6

    # Fill a 2 by 2 block in the center of this game square.
    sw      $t7,                0($t9)
    sw      $t7,                4($t9)
    addiu   $t9,                $t9,                128             # move down one display row (32 * 4)
    sw      $t7,                0($t9)
    sw      $t7,                4($t9)

bitmap_next_col:
    addiu   $t1,                $t1,                1
    slti    $t2,                $t1,                6
    bne     $t2,                $zero,              bitmap_col_loop

    addiu   $t0,                $t0,                1
    slti    $t2,                $t0,                6
    bne     $t2,                $zero,              bitmap_row_loop

    jr      $ra
