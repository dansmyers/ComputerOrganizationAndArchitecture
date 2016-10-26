/* This is a comment */
// So is this

// This program is equivalent to
//
//     int main() {
//         return 100;
//     }

// You can check the return code of a program at
// the command line using
//
//     prompt$ echo $?

// Influenced by thinkingeek's ARM in Raspberry Pi
// tutorials:
//
// thinkingeek.com/arm-assembler-raspberrr-pi)

.global main

main:
    // For now, this statement is magic
    // It has to do with beginning a new function
    push {ip, lr}

    // Move 100 into register r0
    // #100 indicates the literal value 100
    // This way of loading data is also called "immediate addressing"
    mov r0, #100

    // Return from main
    // More magic, but that's okay
    pop {ip, pc}
