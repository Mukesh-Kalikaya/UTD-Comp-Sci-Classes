.data
main_title:         .asciiz "\n========== NUMBER CHAIN ==========\n"
main_rules:         .asciiz "You are H. The computer is C.\nChoose one of your numbers, then an empty neighboring square.\nNeighbors can be horizontal, vertical, or diagonal.\nThe new square gets one more than the number you chose.\nWhen no more moves are possible, the highest number wins.\nBitmap colors: blue = H, red = computer, dark = empty.\n"
main_you_first:     .asciiz "\nYou go first!\n"
main_comp_first:    .asciiz "\nThe computer goes first!\n"
main_human_turn:    .asciiz "\nYour turn.\n"
main_comp_turn:     .asciiz "\nComputer's turn...\n"
main_human_pass:    .asciiz "You have no valid moves. Your turn is skipped.\n"
main_comp_pass:     .asciiz "The computer has no valid moves. Its turn is skipped.\n"

.text
                    .globl  main

main:
    la      $a0,                        main_title
    li      $v0,                        4
    syscall

    la      $a0,                        main_rules
    li      $v0,                        4
    syscall

    jal     initialize_board
    jal     draw_board
    jal     draw_bitmap

    # Seed the random number generator with the current time.
    li      $v0,                        30
    syscall
    move    $t0,                        $a0
    li      $a0,                        0
    move    $a1,                        $t0
    li      $v0,                        40
    syscall

    # Random result is 0 or 1, so either side can start.
    li      $v0,                        42
    li      $a0,                        0
    li      $a1,                        2
    syscall
    move    $s0,                        $a0                                                                                                                                                                                                                                                                                                                     # 0 = human turn, 1 = computer turn
    li      $s1,                        0                                                                                                                                                                                                                                                                                                                       # consecutive skipped turns

    beq     $s0,                        $zero,              main_print_you_first
    la      $a0,                        main_comp_first
    li      $v0,                        4
    syscall
    j       main_game_loop

main_print_you_first:
    la      $a0,                        main_you_first
    li      $v0,                        4
    syscall

main_game_loop:
    # Stop if all 36 squares are used.
    lw      $t0,                        occupied_count
    li      $t1,                        36
    bge     $t0,                        $t1,                main_game_over

    beq     $s0,                        $zero,              main_human_turn_start
    j       main_computer_turn_start

main_human_turn_start:
    li      $a0,                        1                                                                                                                                                                                                                                                                                                                       # positive board numbers belong to H
    jal     has_player_move
    beq     $v0,                        $zero,              main_human_pass_turn

    la      $a0,                        main_human_turn
    li      $v0,                        4
    syscall
    jal     human_move

    lw      $t0,                        occupied_count
    addiu   $t0,                        $t0,                1
    sw      $t0,                        occupied_count
    li      $s1,                        0                                                                                                                                                                                                                                                                                                                       # a real move resets the pass count
    jal     draw_board
    jal     draw_bitmap
    li      $s0,                        1
    j       main_game_loop

main_human_pass_turn:
    la      $a0,                        main_human_pass
    li      $v0,                        4
    syscall
    li      $s0,                        1
    addiu   $s1,                        $s1,                1
    li      $t0,                        2
    beq     $s1,                        $t0,                main_game_over
    j       main_game_loop

main_computer_turn_start:
    li      $a0,                        -1                                                                                                                                                                                                                                                                                                                      # negative board numbers belong to C
    jal     has_player_move
    beq     $v0,                        $zero,              main_computer_pass_turn

    la      $a0,                        main_comp_turn
    li      $v0,                        4
    syscall
    jal     computer_move
    beq     $v0,                        $zero,              main_computer_pass_turn

    lw      $t0,                        occupied_count
    addiu   $t0,                        $t0,                1
    sw      $t0,                        occupied_count
    li      $s1,                        0
    jal     draw_board
    jal     draw_bitmap
    li      $s0,                        0
    j       main_game_loop

main_computer_pass_turn:
    la      $a0,                        main_comp_pass
    li      $v0,                        4
    syscall
    li      $s0,                        0
    addiu   $s1,                        $s1,                1
    li      $t0,                        2
    beq     $s1,                        $t0,                main_game_over
    j       main_game_loop

main_game_over:
    jal     show_winner
    li      $v0,                        10
    syscall
