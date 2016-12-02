// A recursive program


.global main
.global countdown
.extern printf

/*** Data section ***/
.data

format: .asciz "%d\n"
blastoff: .asciz "Blastoff!\n"


/*** Text section ***/
.text

/*** Recursive countdown to zero ***/
//
// Input: count in r0
// Returns: nothing
//
// void countdown(int count) {
//     if (count <= 0) {
//         printf("Blastoff!\n");
//     } else {
//         printf("%d\n", count);
//         countdown(count - 1);
//     }
//     return;
// }

countdown:
    push {ip, lr}

    // Test if countdown <= 0
  if:
    cmp r0, #0

    // Branch on opposite
    // if count > 0, skip base case
    bgt else

    // if body: base case of recursion
    ldr r0, =blastoff
    bl printf
    b done

  else:
    // Recursive case

    // Print

    // Setup args for printf
    mov r1, r0  // Move count to r1
    ldr r0, =format  // Load format string address

    // Calling convention states that r0-r3 may change
    // Save value of count before calling printf
    push {r1}

    bl printf

    // Set r0 <- count - 1
    pop {r0}  // Pop count back into r0
    sub r0, r0, #1

    // Recursive call
    bl countdown

  done:
      pop {ip, pc}


/*** Main ***/
main:
    push {ip, lr}

    mov r0, #5
    bl countdown

    pop {ip, pc}
