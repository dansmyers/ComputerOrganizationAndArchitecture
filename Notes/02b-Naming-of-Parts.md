# Naming of Parts

### The von Neumann Architecture and the Stored Program Concept

As you'll recall from the last note, John von Neumann wrote *First Draft of a Report on the EDVAC* in 1945, which became the first
public description of a stored program computer.

Von Neumann's report described a computer built from six basic "organs":

  - A "central arithmetical" unit that performed calculations
  - A "central control" unit that was responsible for interpreting and sequencing the program's instructions
  - Memory, which stores the program's instructions, its constant data, and any variables it manipulates as it executes
  - A persistent recording medium that provides permanent storage for data and programs: punched cards and teletype tape filled this role in von Neumann's day
  - Input and output organs for reading and writing the persistent storage device

An implied seventh organ is the *bus* that connects all of the other organs together and allows them to exchange information.

```
  ----------------  -----------            ----------
  |   Central    |  | Central |            | Main   |
  | Arithmetical |  | Control |            | Memory |
  ----------------  -----------            ----------
         |               |                      |
  ---------------------------------------------------- Bus
                               ^          |
                               |          v
                           ---------  ----------
                           | Input |  | Output |
                           ---------  ----------
                               ^          |
                               |          v
                          ------------------------
                          |  Persistent Storage  |
                          ------------------------
```

Earlier computers, like the ENIAC, had to encode their programs in the physical connections between logical components. "Programming"
such a computer, therefore, required taking apart its hardware and rebuilding it to implement a new sequence of operations.

This approach clearly limited productivity. Computer designers quickly hit on a better solution: storing the program's instructions in
memory where they can be read just like data. This **stored program concept** is the foundation of almost all modern computer
architecture designs.

### A General System Architecture

```
-----------
|         |
|   CPU   |
|         |
-----------
     |                   ----------------                          ------------
     |  Front-side bus   |              |        Memory bus        |          |
-------------------------|  I/O Bridge  |--------------------------|  Memory  |
                         |              |                          |          |
                         ----------------                          ------------
                                |
                                |          Main system bus (PCI)
-------------------------------------------------------------------------------
                   |                   |                        |
                   |                   |                        |
                   |               ---------           ---------------------
                   |               |  GPU  |           |  Expansion slots  |
                   |               ---------           ---------------------
                   |
                   |
                   |                    Peripheral I/O bus
-------------------------------------------------------------------------------            
           |                         |                       |
           |                         |                       |
       ---------                ----------         -----------------------
       |  USB  |                |  SATA  |         |  Network interface  |
       ---------                ----------         -----------------------
           |                         |                       |
           |                         |                       |
-------------------------       ----------                   v
|  Additional off-chip  |       |  Disk  |             To the Internet
|       devices         |       ----------
------------------------- 
```

### The Central Processing Unit (CPU)

The CPU is the driver of all the activity in a computer system. It interprets instructions, performs calculations, and supervises 
interaction with memory and I/O devices.

Here are some of the common components that make up a CPU:

  - The **arithmetic-logic unit (ALU)** that performs calculations and comparisons
  - **Registers**, temporary storage locations for individual data values that are currently being used in calculations. There are also specialized registers that store important state information for an executing program. The Raspberry Pi 3's CPU has 17 32-bit registers, of which 12 are used for general computation and 5 have specialized functions.
  - **Cache**, a small, fast block of memory built into the CPU that stores frequently accessed data. Cache exists to bridge the gap between the CPU and main memory. An intelligent caching strategy keeps important data close to the CPU and prevents time-consuming transfers to and from main memory. We'll have a lot more to say about caching later in the course.




### Main Memory

**Dynamic Random Access Memory (DRAM)**

**How Programs Use Memory**


### Buses and I/O Devices
