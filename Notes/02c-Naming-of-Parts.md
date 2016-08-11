# Naming of Parts


### An Example System Architecture

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
  
  - A **clock** that controls the timing and synchronization of the CPU's operations. The clock signal is provided by a quartz crystal that oscillates regularly between low and high voltages when supplied with a current. CPU clock frequencies are measured in gigahertz (GHz). A 1 GHz signal osciallates between low and high 1 billion times per second. 
  
  Clock speed is *one* factor influencing CPU performance. Within a single family of CPUs, more expensive processors might offer faster clock speeds and higher performance. You can't, however, make meaningful performance comparisons between CPUs of different families using clock speed alone.

  An "overclocked" CPU is one that has been tweaked to run at a higher-than-normal clock frequency: this increases the CPU's performance, but generates additional heat that must be dissipated by heat sinks and fans.

Each **core** of the CPU is an independent computational unit, having its own ALU, control logic, registers, and (in some cases) cache. Low-cost embedded processors are typically **single-core**, but most laptop and server CPUs are **multi-core**: the CPU contains multiple independent processing units, each capable of fetching and executing its own stream of instructions. 

A multi-core system can execute multiple tasks in parallel, and share data across its cores through main memory. It's challenging, however, to keep multiple threads of a program synchronized across multiple cores. The Raspberry Pi 3's CPU has four cores.

### Main Memory

**Dynamic Random-Access Memory (DRAM)**

The basic technology for main memories is **dynamic random-access memory (DRAM)**. The memory is "random-access" in the sense that it is possible to read data values in arbitrary order with no performance penalty. Other storage devices, like hard disks and tape drives, are not random-access and work best when large blocks of data are read sequentially.

A DRAM module is organized as a two-dimensional grid of cells. Each cell uses a single capacitor and a transistor to store one bit. The charges in the capacitors steadily decay, so the data stored in the memory must be *refreshed* every few hundred milliseconds. For this reason, DRAM is **volatile** memory: any data it stores is lost when the computer loses power. **Non-volatile** storage, like flash drives and hard disks, persist data during power loss.

The chief advantage of DRAM is its simplicity. The single capacitor-transistor circuit is compact, so billions of bits can be stored on a single chip, making DRAM very efficient from a cost/bit perspective.

An alternative memory technology is **static random-access memory (SRAM)**. Each SRAM cell uses six transistors to store a single bit. SRAM is faster than DRAM and does not require refresh cycles, but the complexity of its circuit means that it cannot achieve the high densities and cost/bit efficiency of DRAM. SRAM is commonly used in CPU cache memories.

**How Programs Use Memory**

When a program runs, the memory available to it is, conceptually, a **big linear array of bytes**. This array is called the program's **address space**.

Each byte in the address space has an index, beginning with index 0 and extending to some maximum index that depends on the total number of bytes. In an architecture with a 32-bit address space, each program has, conceptually, 2^32 total bytes of memory available and the maximum byte index is 2^32 - 1.

The memory available to a program is divided into three regions:
  1. The top of the address space stores the program's **code** and any static data it uses, such as hardcoded strings.
  
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
```

**Virtual Memory**

The previous discussion made it sound like every program runs in its own private 4 GB address space when it executes. This is, in fact, an illusion. A typical desktop computer might have 2-8 GB of total physical RAM available, but run dozens of programs simultaneously&mdash;there isn't enough RAM for each program to have its own private address space.

Instead, all programs running on the system are actually *sharing* the underlying physical memory in a way that maintains the *illusion* of a large private address space for each program. This illusion is called **virtual memory** and is implemented by the OS and the hardware working together as a team. 

Virtual memory is complex, but it allows every program to execute without worrying about how other programs are using memory. This frees application programmers (that's us) from worrying about tedious low-level memory management issues, which is a very good thing.

We'll study VM in detail in CMS 330 when we discuss operating systems. For now, you may assume that every program runs with a private address space like the one in the diagram.

### Buses and I/O Devices

**Another One Rides the Bus**

A bus is, physically, just a group of wires that connect components on the computer. Rather than a single bus, like in von Neumann's design, modern computers typically have a hierarchy of buses, with faster, shorter buses at higher levels and slower, larger buses at lower levels. The fastest connection is reserved for main memory, which helps keep the CPU supplied with data and instructions.

An important parameter of a bus is its **width**, the number of bits it can move in a single transfer. A bus with a width of one is called a **serial bus**: it transfers only one bit at at time. Older buses, like PCI, had widths of 32 or 64 bits. It turns out, however, that designing large parallel buses is hard, because synchronizing transfers on 32 or 64 different wires is difficult and electrical "crosstalk" between wires leads to errors. The trend, therefore, has been towards highly optimizied serial buses, like USB ("Universal Serial Bus") and PCI Express, that drive bits through a system at very high clock speeds with low error rates.

**Persistant Storage Devices**

DRAM is volatile: it only stores information as long as the computer is powered. Computers also need non-volatile storage to persist information between power cycles. The most important persistant storage device is the **rotating magnetic hard disk**, followed by **solid-state drives (SSDs)**.

A hard disk drive consists of one or more *platters*, each with two surfaces. Like a CD or an old-school vinyl record, each surface is divided into a large number of concentric *tracks*, each each track is divided into thousands of 512-byte *sectors*. Sectors are the basic unit of data storage on a hard disk.

The platters are mounted to a central spindle that continuously spins at speeds of up to 15000 RPM while the drive is powered on.

The surface of each platter is coated with a magnetically active material. Each platter surface has a *read/write head* that can rad the data in a sector by sensing its magnetic properties or write to a sector by changing its magnetic characteristics. Each head is attached to a motorized arm that can seek across the surface of the platter to reach different tracks. The combination of seeking and rotation allows the head to read and write any sector on the surface.

Hard disks have excellent cost/bit characteristics: a commercial-grade 1 TB disk costs less than $100. The downside is that they are **slow**, with a typical access time of 10 ms.

```
A side view of a disk drive with two platters and four surfaces.

Each surface has its own dedicated read/write head and arm.

arms and read/write heads
        |
        |
        |        
----    v      |
   |--------[]  |
   |     ----------------  platter
   |--------[]  |
   |            |
   |--------[]  |
   |     ----------------  platter
   |--------[]  |
   |            |
----         spindle
```

A solid-state drive is based on **flash memory**, a nonvolatile storage technology. Unlike disk, flash drives have no mechnical parts. The primary advantage of flash is its speed: an average read may take only 100 microseconds, 100 times faster than disk. It has three primary disadvantages:

  1. Flash is still quite a bit more expensive that disk on a cost/bit basis.
  
  2. A flash cell can only be written when it's in a special "erased" state. Writing sometimes requires juggling data around the drive in order to free up a sufficiently large block of "erased" cells in the right place for a new write. For this reason, flash write performance is highly variable. In some cases, flash writes can be an order of magnitude *slower* than disk.
  
  3. Writing to a flash cell actually degrades the cell and, after a certain point, renders it unusable. All SSDs implement "wear-leveling" protocols to spread the effect of writes across the entire drive and keep any one block from decying too quickly. This is usually not an issue for home users, but it has implications for companies like Facebook that use SSDs in the their datacenters.


### Coming Attractions

This note has been a high-level overview of several key concepts in computer architecture. We'll revisit many of these ideas throughout the course, so you'll get to see them again from different angles.

Now that we're familiar with the basics of computer organization, we'll dive into the issue data storage and representation, starting with the most basic units of information: bits and bytes.



