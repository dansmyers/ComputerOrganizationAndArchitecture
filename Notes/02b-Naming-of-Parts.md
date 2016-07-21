# Naming of Parts

### The von Neumann Architecture

Von Neumann's report described a computer built from six basic "organs":

  - A "central arithmetical" unit that performed calculations
  - A "central control" unit that was responsible for interpreting and sequencing the program's instructions; the control and arithmetic units are 
  - Memory, which stores the program's instructions, its constant data, and an work-in-progress values it produces as it executes
  - A persistent recording medium, such as punched cards or tape, that could provide permanent storage
  - Input and output organs to facilitate reading and writing the persistent storage device

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
