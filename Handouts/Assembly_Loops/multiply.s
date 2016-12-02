// Multiply two integers in a loop

.global main
.extern printf


/*** Data section ***/
.data

a: .word 5
b: .word 6
prod: .word 0
format: .asciz "%d x %d = %d\n"

/*** Text section ***/
.text

main:
    push {ip, lr}

    // Register assignments:
    //  r0: prod
    //  r1: a
    //  r2: b
    //  r3: loop index variable

    // Initial loads
    mov r0, #0

    ldr r1, =a
    ldr r1, [r1]

    ldr r2, =b
    ldr r2, [r2]

    mov r3, #0

  for:
    // Test i < b
    cmp r3, r2

    // Branch on opposite quality
    // if i >= b, jump around loop body
    bge end

    // Loop body
    add r0, r0, r1  // prod += a
    add r3, r3, #1  // i++

    b for

  end:
    // Store result
    ldr r4, =prod
    str r0, [r4]

    // Print
    mov r3, r0  // move prod to r3
    ldr r0, =format  // Load format address

    // a and b are already in r1 and r2

    bl printf

    // Return
    pop {ip, pc}
