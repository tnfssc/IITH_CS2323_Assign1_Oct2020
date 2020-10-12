addi $s0, $zero, 10
addi $s1, $zero, 9
sb $s0, -10($sp)
sb $s1, -9($sp)
lb $s2, -9($sp)
addi $sp, $sp, -1
addi $sp, $sp, -2
addi $sp, $sp, -3
addi $sp, $sp, -5
addi $sp, $sp, -9
addi $sp, $sp, -14
addi $sp, $sp, -23
addi $sp, $sp, -37
lb $s3, 0($sp)
