// Using printf

// This program is equivalent to
//
//     int main() {
//         printf("Value = %d\n", 101);
//         return 0;
//     }

// Up to four function arguments may be passed in
// registers r0 to r3
//
// The first argument is in r0
// The second is in r1
// and so forth


.global main

// Declare printf as an external function
.extern printf


/*** Data section ***/
.data

// A constant string can be declared using a
// label and the .asciz command
format: .asciz "Value = %d\n"


/*** Text section ***/
.text

main:
    push {ip, lr}

    // The first argument is the address
    // of the format string
    ldr r0, =format

    // The second argument is the value
    // to print
    mov r1, #1

    // Call printf
    bl printf

    // Return
    mov r0, #0
    pop {ip, pc}

