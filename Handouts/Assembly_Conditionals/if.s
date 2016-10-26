// Implementing a basic if using conditional branching

// This program is equivalent to
//
//     int main() {
//         int x = 0;
//
//         if (x == 0) {
//           x++;
//         }
//
//         return x;
//     }

.global main


/*** Data section ***/
.data

x: .word 2


/*** Text section ***/
.text

main:
    push {ip, lr}

    ldr r0, =x
    ldr r0, [r0]

    // Compare instruction performs subtraction and
    // sets condition codes, but doesn't change
    // register values
    cmp r0, #0  // check x - 0

    // Branch if the result of the previous
    // comparison was NOT-EQUAL to 0
    //
    // That is if x != 0, jump AROUND the body of the
    // if statement
    bne done

    // Body of if, excecutes if x == 0
    add r0, r0, #1

  done:
    pop {ip, pc}

