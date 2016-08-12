# The von Neumann Architecture

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

### The Stored Program Concept

Earlier computers, like the ENIAC, had to encode their programs in the physical connections between logical components. "Programming"
such a computer required taking apart its hardware and rebuilding it to implement a new sequence of operations. 

This approach clearly limited productivity, so computer designers quickly hit on a better solution: storing the program's instructions
in memory where they can be read just like data. The **stored program concept** is the foundation of all modern computer 
architectures.
