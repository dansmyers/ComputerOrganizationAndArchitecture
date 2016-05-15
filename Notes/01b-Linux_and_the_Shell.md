# Linux and the Terminal Environment


### History


### The Terminal and the Shell

If all of your previous experience has been on Windows or Mac OS a Linux system may feel very odd at first.

The most obvious point of departure is the *terminal*, the place where you type commands for the system to execute. Windows and Mac 
systems do have built-in terminals&mdash;Windows calls its terminal the Command Prompt&mdash;but they are designed to be operated 
through a graphical user interface (GUI). 

Linux systems are pretty much the opposite: most modern distributions support GUIs, but it's still traditional for serious work to be 
done in the terminal environment. Many configuration and maintenance tasks (common in the server realm) are actually easier to handle 
with typed commands than they would be with graphical menus.

The program that receives and interpreting your commands is called the *shell*. The shell is also responsible for launching new 
programs. The most default shell program on most Linux systems is called `bash`.

The shell program prints a prompt for your commands, which typically identifies your username and the current working directory (more on that below). On Cloud9 my prompt looks like this:

```
dmyers@cms230:~/workspace $
```

For clarity, I will just use

```
prompt$
```

when I need to indicate a command prompt. The commands you type will appear to the right of the `$`.

### Paths and Directories

The Linux file system is organized as a tree. The top level directory is called the *root directory* and denoted by `/`.

Every file and directory on the system has a *path* that describes its place in the file system tree. An *absolute path* gives the 
position of the object relative to the root. For example, the path

```
/home/dmyers/workspace/01b-Linux_and_the_Shell.md
```

identifies a file named `01b-Linux_and_the_Shell.md`, which resides in a directory called `workspace`, which is itself in a directory 
called `dmyers`. The `dmyers` directory is located in the `home` directory under the root, `/`. Here's a picture; I've added a few more directories at each level to illustrate the tree structure.

```                          
                          / (the root dir)
                             |
                             |
              -----------------------------------
              |     |      |       |      |     |
              |     |      |       |      |     |
             bin   lib    home  include  etc   usr
                           |
                           |
                  ---------------------------------
                  |                 |             |
                  |                 |             |
                dmyers         jcarrington    jaanderson       
                  |
                  |
           -------------------------
           |            |          |
           |            |          |
        workspace    teaching   research
           |
           |
01b-Linux_and_the_Shell.md
```

The top-level directories right beneath `/` are fairly standard across systems. `home` contains a series of *home directories* for
each system account. The example shows three home directories for three different users. `bin` is short for *binaries* and stores 
common executable programs.

If you're using Cloud9, your user name will always be `ubuntu` and the default location for your files will be `/home/ubuntu/workspace`.

### Moving Around

At any given time, the shell program recognizes one *working directory*. This is the directory that you are currently "in" and all of your commands will be executed with respect to it.

The `pwd` command prints the shell's present working directory.

```
prompt$ pwd
/home/ubuntu/workspace
prompt$
```

You can list the contents of the current directory using `ls`. Your Cloud9 directory is initialized with some example C and C++ files.

```
prompt$ ls
Makefile  hello-c-world.c  hello-cpp-world.cc
prompt$
```



### Unix Philosophy

In his book *The Art of Unix Programming*, Eric S. Raymond sums up several key ideas that have informed the design of Unix throughout 
its history.





### Useful Commands
