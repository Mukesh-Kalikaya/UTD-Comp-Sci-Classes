.data
winner_human_label: .asciiz "\nYour highest number: "
winner_comp_label:  .asciiz "\nComputer's highest number: "
winner_human:       .asciiz "\nCongratulations! You won!\n"
winner_comp:        .asciiz "\nThe computer reached the higher number. Better luck next time!\n"
winner_tie:         .asciiz "\nIt is a tie! Both players reached the same highest number.\n"

.text
                    .globl  show_winner
show_winner:
    addiu   $sp,                $sp,                -20
    sw      $s0,                0($sp)
    sw      $s1,                4($sp)
    sw      $s2,                8($sp)
    sw      $s3,                12($sp)
    sw      $ra,                16($sp)

    li      $s0,                0                                                                   # highest human number
    li      $s1,                0                                                                   # highest computer number
    li      $s2,                0                                                                   # square index

winner_scan_loop:
    slti    $t0,                $s2,                36
    beq     $t0,                $zero,              winner_print_scores

    sll     $t1,                $s2,                2
    la      $t2,                board
    addu    $t2,                $t2,                $t1
    lw      $s3,                0($t2)
    beq     $s3,                $zero,              winner_next_square
    bgtz    $s3,                winner_check_human

    # Convert the computer's negative value to a positive number.
    subu    $t3,                $zero,              $s3
    ble     $t3,                $s1,                winner_next_square
    move    $s1,                $t3
    j       winner_next_square

winner_check_human:
    ble     $s3,                $s0,                winner_next_square
    move    $s0,                $s3

winner_next_square:
    addiu   $s2,                $s2,                1
    j       winner_scan_loop

winner_print_scores:
    la      $a0,                winner_human_label
    li      $v0,                4
    syscall
    move    $a0,                $s0
    li      $v0,                1
    syscall

    la      $a0,                winner_comp_label
    li      $v0,                4
    syscall
    move    $a0,                $s1
    li      $v0,                1
    syscall

    bgt     $s0,                $s1,                winner_print_human
    blt     $s0,                $s1,                winner_print_computer
    la      $a0,                winner_tie
    li      $v0,                4
    syscall
    j       winner_done

winner_print_human:
    la      $a0,                winner_human
    li      $v0,                4
    syscall
    j       winner_done

winner_print_computer:
    la      $a0,                winner_comp
    li      $v0,                4
    syscall

winner_done:
    lw      $s0,                0($sp)
    lw      $s1,                4($sp)
    lw      $s2,                8($sp)
    lw      $s3,                12($sp)
    lw      $ra,                16($sp)
    addiu   $sp,                $sp,                20
    jr      $ra
