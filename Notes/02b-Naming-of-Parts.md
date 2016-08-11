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
such a computer required taking apart its hardware and rebuilding it to implement a new sequence of operations. 

This approach clearly limited productivity, so computer designers quickly hit on a better solution: storing the program's instructions
in memory where they can be read just like data. The **stored program concept** is now the foundation of almost all modern computer architectures.

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

When we speak of "computer architecture," we're usually referring to the design of the CPU. For example: 
  - What basic instructions can it execute?
  - How are those instructions implemented as physical hardware?
  - What performance-enhancing features does it support?

Modern CPUs are among the most complex system ever devised by humans. From a programmer's perspective, however, the CPU can be thought of as a collection of a few key elements:

  - An **arithmetic-logic unit (ALU)** that performs calculations and comparisons. This is the modern version of von Neumann's central arithmetical organ.
  
  - **Control logic** that fetches and decodes instructions. This is the spiritual successor to von Neumann's central control organ.
  
  - **Registers**, temporary storage locations for individual data values that are currently being used in calculations. The Raspberry Pi 3's CPU has 17 registers, of which 12 are used for general computation and 5 have specialized functions. We'll talk about the Pi's register set when we introduce assembly language programming.
  
  - **Cache**, a small, fast block of memory built into the CPU that stores frequently accessed data. Cache exists to bridge the gap between the CPU and main memory. An intelligent caching strategy keeps important data close to the CPU and prevents time-consuming transfers to and from main memory. We'll have a lot more to say about caching later in the course.
  
  - A **clock** that controls the timing and synchronization of the CPU's operations. The clock signal is provided by a quartz crystal that oscillates regularly between low and high voltages when supplied with a current. CPU clock frequencies are measured in gigahertz (GHz)&mdash;a 1 GHz signal completes 1 billion oscillations per second. 
  
  Clock speed is *one* factor influencing CPU performance. Within a single family of CPU designs, clock speed may be used to differentiate between more expensive and cheaper designs. You can't, however, make meaningful performance comparisons between CPUs of different families using clock speed alone.

  An "overclocked" CPU is one that has been tweaked to run at a higher-than-normal clock frequency: this increases the CPU's performance, but generates additional heat that must be dissipated by heat sinks and fans.

Each **core** of the CPU is an independent computational unit, having its own ALU, control logic, registers, and (in some cases) cache. Low-cost embedded processors are typically **single-core**, but most laptop and server CPUs are **multi-core**: the CPU contains multiple independent processing units, each capable of fetching and executing its own stream of instructions. 

A multi-core system can execute multiple tasks in parallel, and share data across its cores through main memory. It's challenging, however, to keep multiple threads of a program synchronized across multiple cores. The Raspberry Pi 3's CPU has four cores.

### Main Memory

**Dynamic Random Access Memory (DRAM)**

**How Programs Use Memory**

When a program runs, the memory available to it is, conceptually, a **big linear array of bytes**. This array is called the program's **address space**.

Each byte in the address space has an index, beginning with index 0 and extending to some maximum index that depends on the total number of bytes. In an architecture with a 32-bit address space, each program has, conceptually, 2^32 total bytes of memory available and the maximum byte index is 2^32 - 1.

The memory available to a program is divided into three regions:
  1. The top of the address space stores the program's code and any static data it uses, like hardcoded strings.
  
  2. The second region is called the **heap** and stores dynamically allocated data items that are created and deleted as the program runs. In a Java program, this would include objects created with the `new` keyword. The heap grows downwards (toward higher memory addresses) as more dynamic data is allocated and shrinks upwards as items are deallocated.
  
  3. The third region is the **stack**, which stores local variables and keeps track of the program's history of function calls. Like the heap, the stack can grow and shrink as the program executes. We'll spend more time in the future discussing the stack's role in program execution.

```
A canonical 32-bit address space

-----------------------------  Byte index 0
|    Code and static data   |
|                           |
----------------------------- 
|           Heap            |
|  (dynamically-allocated)  |
|                           |
-----------------------------
|             |             |
|             |             | Heap grows and shrinks as data is dynamically allocated
|             v             | and freed by the program (new in Java, malloc and free
|                           | in C).
|     Unallocated space     |         
|                           |
|             ^             | Stack grows and shrinks as the program calls and returns
|             |             | from functions.
|             |             |
-----------------------------
|           Stack           |
|                           |
|   (local variables and    |
|  function call history)   |
|                           |
-----------------------------  Byte index 2^32 - 1






### Buses and I/O Devices
