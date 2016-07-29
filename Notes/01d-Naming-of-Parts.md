# Naming of Parts

### History

The first general-purpose programmable electronic computer was the ENIAC ("Electronic Numerical Integrator and Calculator") designed 
by John Mauchley and J. Presper Eckhert at the University of Pennsylvania. Construction began on the system in 1943 and it was unveiled
to the public in February of 1946. The U.S. Army financed the system (at a cost of $7 million in today's currency) to automate the 
construction of artillery ballistics tables.

There had been earlier attempts, going all the way back to the 17th and 18th centuries, to design automated computing machines. One
notable breakthrough came in 1801 when the Frenchman Joseph Marie Jacquard designed a automated loom that used punched cards to encode
weaving patterns.

The English engineer Charles Babbage designed two important computing machines: the Difference Engine, which he began 
designing in 1822, and the more powerful Analytical Engine, which he first described in 1837.

The Difference Engine was a mechanical calculator that used gears and wheels to evaluate polynomial functions. At the time,
scientifc and engineering calculations were performed by human "computers" who relied on tables of function
evaluations&mdash;logarithms, trigonmetric functions, and so forth&mdash;for their work. Babbage designed the Difference Engine to 
automate the construction of these tables. 

Although the Difference Engine was impressive for its time, Babbage's reputation as "the Father of the Computer" rests on the 
Analytical Engine, the first machine capable of true general purpose ("Turing-complete") computation. The Engine's design implemented 
all the essential elements of a computer&mdash;including arithmetic, logic, branching control operations, and memory&mdash;using only 
mechanical parts. It even included a printer!

Despite considerable funding from the British government, Babbage never actually completed any of his machines. This was due, at least 
in part, to the difficulty of manufacturing the precision components his designs required with the tools of the day. A working 
Difference Enging was finally constructed in the 1990's using 19th Century manufacturing tolerances, demonstrating that Babbage's 
designs were actually feasible.

In addition to his work on the Engines, Babbage made contributions to cryptography and assisted Isambard Kingdom Brunel in the
construction of the Great Western Railway, one of the signifant engineering feats of the age. He also led a campaign to ban street 
musicians, whom he loathed.

One of Babbage's collaborators on the Analytical Engine was Lady Ada Lovelace, who designed the first algorithm intended to execute on 
a machine. She is therefore regarded as the first programmer. The Ada programming language is named in her honor.

Lady Ada's scientific accomplishment was due, in part, to terrible parenting. Her father was Lord Byron, the tempestuous Romantic poet,
who abandoned his family when Ada was only one month old. He died&mdash;tempestuously and Romantically&mdash;of infection eight years
later while fighting in the Greek War of Independence.

Byron fathered multiple illegetimate children and carried on numerous affairs during his marriage, possibly including one with his 
half-sister (!). Her experience with Byron soured Lady Ada's mother on the literary men, and she pushed her daughter to study science
and mathematics instead.

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


Translating the basic von Neumann
