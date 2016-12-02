// Add eight values
// Illustrates passing arguments on stack

.global main

/*** Data section ***/
.data

format: .asciz "Result = %d\n"


/*** Text section ***/
.text

addEight:
    push {ip, lr}

    // The function will change r4-r7, so they must be saved
    // on the stack
    push {r4-r7}

    // Load arguments off stack
    ldr r4, [sp, #24]
    ldr r5, [sp, #28]
    ldr r6, [sp, #32]
    ldr r7, [sp, #36]

    // Add 'em up
    add r0, r0, r1
    add r0, r0, r2
    add r0, r0, r3
    add r0, r0, r4
    add r0, r0, r5
    add r0, r0, r6
    add r0, r0, r7

    // Restore r4-r7
    pop {r4-r7}

    // Return
    pop {ip, pc}


main:
    push {ip, lr}

    // Load four arguments in registers
    mov r0, #0
    mov r1, #1
    mov r2, #2
    mov r3, #3

    // Put next four arguments on stack

    // Move stack pointer to create space for four values
    sub sp, sp, #16  // 4 values * 4 bytes each = 16 bytes

    mov r4, #4
    str r4, [sp, #12]  // Store to address in sp + 12 bytes

    mov r4, #5
    str r4, [sp, #8]

    mov r4, #6
    str r4, [sp, #4]

    mov r4, #7
    str r4, [sp]

    // Call the function
    bl addEight

    // Deallocate stack space
    add sp, sp, #16

    // Print
    mov r1, r0
    ldr r0, =format
    bl printf

    // Return
    mov r0, #0
    pop {ip, pc}
