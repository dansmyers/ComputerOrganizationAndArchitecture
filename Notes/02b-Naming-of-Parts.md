# Naming of Parts

### History

**Pre-20th Century**

There had been many attempts, going all the way back to the 17th and 18th centuries, to design automated calculating machines. One
notable breakthrough came in 1801 when the Frenchman Joseph Marie Jacquard designed a programmable loom that used punched cards to 
encode weaving patterns.

The English engineer Charles Babbage (1791-1871) designed two important computing machines: the difference engine, a mechanical 
calculator that he began designing in 1822, and the more powerful analytical engine, which he first described in 1837. The latter was 
the first machine capable of true general-purpose computation.

The analytical engine's design implemented all the essential elements of a computer&mdash;including arithmetic, logic, branching 
control operations, and memory&mdash;using only mechanical parts. It even had a printer! The engine stored its programs on punched 
cards, similar to Jacquard's loom.

Despite decades of work and funding from the British government, Babbage never actually completed any of his machines. A working 
difference engine was finally constructed in the 1990's using 19th Century manufacturing tolerances, demonstrating the feasibility of 
Babbage's designs. Babbage did build one part of the analytical engine, but a complete system has never been constructed.

In addition to his work on the engines, Babbage made contributions to cryptography and assisted Isambard Kingdom Brunel in the
construction of the Great Western Railway, one of the great engineering feats of the Victorian Era. He also led public campaigns 
against the nuisance of street musicians, whom he loathed.

Despite his present-day reputation as "the Father of the Computer," Babbage's work was not influential in its own 
time. The important ideas he proposed were eventually reinvented, 100 years later, by the first electronic computer designers in the
1940's.

Lady Ada Lovelace (1815-1852), one of Babbage's collaborators, designed the first algorithm intended to execute on the analytical
engine and is therefore regarded as the first computer programmer. The Ada language is named in her honor.

Lady Ada's scientific accomplishment was due, in part, to terrible parenting. Her father was Lord Byron, the tempestuous Romantic poet,
who abandoned his family in 1816 when Ada was only one month old. He died&mdash;tempestuously and Romantically&mdash;of infection eight
years later while fighting in the Greek War of Independence.

Byron fathered multiple illegitimate children during his life and carried on numerous affairs during his marriage, including, 
allegedly, one with his half-sister (tempestuous!). Her experience with Byron soured Lady Ada's mother on literary pursuits, and she
pushed her daughter to study science and mathematics instead.

**ENIAC and EDVAC**

The first general-purpose programmable electronic computer was the ENIAC ("Electronic Numerical Integrator and Calculator") designed 
by John Mauchley and J. Presper Eckhert at the University of Pennsylvania. Construction began on the system in 1943 and it was unveiled
to the public in February of 1946. The U.S. Army financed the system (at a cost of $7 million in today's currency) to automate the 
construction of artillery ballistics tables.

### The von Neumann Architecture

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

This architecture is more of a conceptual model than a real computer design.


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
