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
                               |          |
                           ---------  ----------
                           | Input |  | Output |
                           ---------  ----------
                               |          |
                          ------------------------
                          |  Persistent Storage  |
                          ------------------------
```

Earlier computers, like the ENIAC, had to encode their programs in the physical connections between logical components.

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
