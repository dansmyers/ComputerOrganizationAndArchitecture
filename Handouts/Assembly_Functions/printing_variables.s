// Printing variables with printf

.global main
.extern printf

/*** Data section ***/
.data

x: .word 3
y: .word 4

format: .asciz "Value = %d\n"

/*** Text section ***/
.text

main:
    push {ip, lr}

    // Load x
    ldr r1, =x
    ldr r1, [r1]

    // Print x
    // r0 holds address of format string
    // r1 holds value of x
    ldr r0, =format
    bl printf

    // Load and print y
    ldr r1, =y
    ldr r1, [r1]
    ldr r0, =format
    bl printf

    // Return
    pop {ip, pc}
