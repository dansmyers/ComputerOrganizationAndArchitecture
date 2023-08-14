// Calling a function using bl

.global _start


/*** Text section ***/
.text

// A function is identified by a label
// This function returns 3
returnThree:
    push {ip, lr}

    mov r0, #3

    pop {ip, pc}


_start:
    push {ip, lr}

    // Call the function
    bl returnThree

    // Return
    pop {ip, pc} 
