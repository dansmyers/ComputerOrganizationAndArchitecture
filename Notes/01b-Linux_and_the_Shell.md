# Linux and the Terminal Environment

### The Terminal and the Shell

If all of your previous experience has been on Windows or Mac OS a Linux system may feel very odd at first.

The most obvious point of departure is the *terminal*, the place where you type commands for the system to execute. Windows and Mac 
systems do have built-in terminals&mdash;Windows calls its terminal the Command Prompt&mdash;but they favor graphical user interfaces
(GUIs) for most tasks.

Linux systems are pretty much the opposite: most modern distributions support GUIs, but it's traditional for all serious work to be 
done in the terminal environment. Many configuration and maintenance tasks (common in the server realm) are actually easier to handle 
with typed commands than they would be with graphical menus.

The program that receives your commands, interprets them, and launches new programs is called the *shell*. The default shell program 
on most Linux systems is called `bash`.

The shell program prints a prompt for your commands, which typically identifies your username and the current working directory. On
Cloud9, my prompt looks like this:

```
dmyers@cms230:~/workspace $
```

For clarity, I will just use

```
prompt$
```

when I need to indicate a command prompt. The commands you type will appear to the right of the `$`.

### Paths and Directories

The Linux file system is organized as a tree. The top level directory is called the *root directory* and is denoted by `/`.

Every file and directory on the system has a *path* that describes its place in the file system tree. An *absolute path* gives the 
position of the object relative to the root. For example, the path

```
/home/dmyers/workspace/01b-Linux_and_the_Shell.md
```

identifies a file named `01b-Linux_and_the_Shell.md`, which resides in a directory called `workspace`, which is itself in a directory 
called `dmyers`. The `dmyers` directory is located in the `home` directory under the root, `/`. Here's a picture&mdash;I've added a
few more directories at each level to illustrate the tree structure:

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

If you're using Cloud9, your username will always be `ubuntu` and the default location for your files will be 
`/home/ubuntu/workspace`.

### Moving Around and Creating Directories

The shell program recognizes one *working directory* at any given time. This is the directory that you are currently "in" and all of 
your commands will be executed with respect to it.

The `pwd` command prints the shell's present working directory.

```
prompt$ pwd
/home/ubuntu/workspace
prompt$
```

You can list the contents of the current directory using `ls`. Your Cloud9 directory is initialized with some example C and C++ files.

```
prompt$ ls
Makefile  README.md  hello-c-world.c  hello-cpp-world.cc
prompt$
```

To make a new directory use `mkdir` and supply the name of the new directory:

```
prompt$ mkdir Project1
prompt$ ls
Makefile  Project1/  README.md  hello-c-world.c  hello-cpp-world.cc
prompt$
```

Note that `mkdir` does not produce any output when it executes: it just creates the new directory, finishes, and then the prompt 
reappears. In the Unix world, *silence is golden*. Programs that run correctly tend to finish and exit without producing unnecessary
output.

Now suppose that you're ready to work on Project 1. First, you need to change to the `Project1` directory. The `cd` command changes 
the working directory to the location you specify. If you don't supply a full absolute path, the shell will treat the path as 
*relative* and resolve it with respect to the current working directory.

```
prompt$ cd Project1
```

Here's a tip: you can use TAB to autocomplete a name once you've typed enough characters.

One way to create a new file is to `touch` it.

```
prompt$ touch hw1.c
prompt$ ls
hw1.c
prompt$
```

### Command-Line Arguments

Most commands can take arguments that control their behavior.

Two useful arguments for the `ls` command are `-l` and `-a`. `-l` specifies the "long" listing format, which gives more information 
about each item. `-a` displays "hidden" files, which have filenames beginning with a a dot and don't appear in a normal listing.

```
prompt$ ls -l -a
total 8
drwxr-xr-x 2 ubuntu ubuntu 4096 May 18 01:53 ./
drwxrwxr-x 4 ubuntu ubuntu 4096 May 15 19:11 ../
-rw-r--r-- 1 ubuntu ubuntu    0 May 18 01:53 hw1.c
prompt$
```

It's possible to combine multiple basic flags into one argument, like`ls -la`.

**The Listing Format**

The first column in the listing shows the permissions for each file, specifying who is allowed to read, write, and execute it. 
The second column specifies the number of "links" to the file. We'll defer discussion of these two items for now.

The third and fourth columns specify the owner of the file and the owner's group. In the Cloud9 environment these will always be
`ubuntu`.

The fifth column is the size of the file in bytes. The other columns list the last time the file was modified.

**The Parent Directory**

There are two special entries in the listing, `.` and `..`. These are considered "hidden" files, so they only appear when you run `ls`
with the `-a` option.

  - `.` is a shorthand reference to the current directory, in this case `/home/ubuntu/workspace/Project1`
  - `..` always references the parent directory, which is `/home/ubuntu/workspace`

If you need to move higher in the directory hierarchy you can do so using `cd ..`:

```
prompt$ cd ..
prompt$ pwd
/home/ubuntu/workspace
prompt$
```

### Removing Files

Use the `rm` command to remove files.

```
prompt$ rm hw1.c
```

You can use `*` as a wildcard to match all files matching a certain patter. For example, to remove all `.c` files in the current
directory,

```
promtp$ rm *.c
```

`rm *` by itself will remove all files in the current directory.

`rm` will refuse to remove diretories. Instead can use either `rmdir` or use the `-f` flag to "force" `rm`to perform
the operation.

```
prompt$ rmdir Example1
prompt rm -f Example2
```

### In the Future

You will get plenty of practice working with the shell throughout this course. For now, refer back to this note for a refresher while 
you're working on the first assignment.

The next note covers compiling and running C program from the command line. After reading it you'll be ready to write your first Linux
programs!
