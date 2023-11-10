# Challenge Project 2: Tales from the `crypt`

<img src="https://www.budsartbooks.com/wp-content/uploads/2021/05/ectfc01-tales-from-the-crypt-book_2.jpg" width="35%" />

## Due 12/4 (last day of class)

## You can work with a partner to complete this project

## Description

In this project, you'll write your own dictionary-based **password cracker** using
the C `crypt` utility.

Your cracking program will take as its input a shadow password file (discussed in detail below) consisting of usernames and their associated password hashes, along with a dictionary of candidate passwords. The program should determine the true password for each user by calculating the hash of each entry in the candidate file, then comparing those hashes to the entries stored in the shadow password file. In addition, your cracker must include some support for mangling the candidate passwords to deal with more potential matches.

## Submission and Testing

Use the workspace on repl.it. It includes starter files, a `words` dictionary that you will use for your program, and a directory of test cases. Run the file `test.py` to test your program against each test case.

```
python3 test.py
```

(You may need to allow repl.it to install `python3` in your workspace. If so, that's fine.)

The description below explains that format of each test file and the features your program needs to support. As always, start with the easiest test case and build up to the more difficult ones. You will need to include a `Makefile` to build your program from source.


## Password Management

### Early password files
Back in the really old days, when the world was young, UNIX systems stored all users' passwords in a special file called `/etc/passwd`. When a user needed to perform an action that required authentication, like logging in, the system would prompt the user to enter a password, then compare what was entered to the true password stored in the `passwd` file.

However, these early systems stored passwords **in cleartext**. That is, they just stored every user's real password in a text file, like this:

```
dmyers:password1234
```

The `passwd` file did have some protections: it was only readable by `root`, the special system superuser account. Despite that, storing cleartext passwords is obviously a big security risk, because any program that *did* gain the ability to read `/etc/passwd` (for example, by performing a *privilege escalation* attack to gain root access) would immediately know every user's real password.

### Shadow password files

Modern systems do not store users' cleartext passwords. Instead, the system stores a ***hash*** of the user's password in a special file named `/etc/shadow`, the *shadow password file*.

Recall that a hash function is any operation that takes an input bit sequence (which may be of arbitrary length) and converts it to a fixed-size output. You can think of the hash function output as being a "summary" for its input data. Hashing is an important concept that occurs throughout computer science: in the implementation of hash table data structures, in verifying the integrity of file transfers, and in digital signatures, among other applications.

There are many different hash functions that operate in different ways. Every Java class has a method called `hashCode` which can be used to compute a hash code from an object's data. The default `hashCode` is based on the object's memory address, but a class can also define its own `hashCode` that's appropriate for its own data ([see here](https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#hashCode()) for the `String` class documentation).

With a shadow file containing password hashes, the basic authentication flow works like this:

- Prompt the user to enter a password
- Compute the hash of the entered password
- Compare to the stored hash in the `shadow` file
- If the two hashes match, the user has entered the correct password with high probability, so allow the action

### Password cracking

<img src="https://imgs.xkcd.com/comics/how_hacking_works_2x.png" width="35%" />

What if the `shadow` file is compromised? This is not great, but it isn't as bad as leaking users' real passwords. An attacker who manages to obtain the `shadow` file would know the **hash** of each user's password, but not the real passwords themselves.

Therefore, the attacker faces a reverse-engineering problem: given the hash of a user's password, find a **real input password** that can be used to generate that hash. This might be easy for simple hash functions, but real password systems use strong **cryptographic hash functions** that are **one-way**.  That is, there's no way to invert a strong hash function to recover the input for a given hash, so the attacker's only choice is to **try many different inputs** until finding one that produces the desired output.

The simplest approach is to launch a **brute-force** attack by generating all possible candidate passwords and testing each one. This is guaranteed to eventually succeed, but is usually impractical. For example, if we consider a 10 character password that may contain uppercase and lowercase letters and the ten digits 0-9, there are

62<sup>10</sup> = 839299365868340224

possible combinations. Therefore, long, truly random passwords are always strong.

However, weak passwords are significantly easier to crack. For example, if we consider eight character passwords using lowercase letters, there are only

26<sup>8</sup> = 208827064576

That's still a lot, but it's possible to **precompute** every hash for those passwords and store them on a disk using a [rainbow table](https://en.wikipedia.org/wiki/Rainbow_table), a special data structure used to efficiently store pre-computed password hashes.

### Dictionary attacks

For the most part, though, attackers don't even need to resort to brute force attacks. Normal users rarely pick complex passwords and the same general passwords tend to show up repeatedly on different systems. The classic, of course, is simply setting your password to `password`, but smarter users still tend to choose passwords that are based on common words, short phrases, or cultural tropes.

For example, you might think that a password like `2Timothy3:16` is strong, because it's relatively long with a mixture of characters, digits, and symbols, but it's actually incredibly weak. Passwords based on Bible verses, popular band names, characters, or movie quotes are easy to crack because users tend to pick from a relatively small number of choices in each category. Popular word combinations like `bluesky` or `pumpkinspice` are also likely to be chosen by many users, so they also make weak passwords.

A **dictionary attack** starts with a list of candidate passwords, which might be based on real passwords leaked from other systems, and then tests each one. In a large `shadow` file, it's likely that many users will have picked passwords that are already in the dictionary.

An attacker can get more passwords for low cost by applying **mangling rules** to the passwords in the dictionary. For example, taking a short phrase and appending a number (e.g., `pumpkinspice1`) is a common heuristic, but it's easy to take each password in the dictionary and generate ten variations with a digit appended. Capitalizing the first letter of a password is an easy mangle (only one character needs to change), as are common substitutions, as shown in this famous xkcd:

<img src="https://imgs.xkcd.com/comics/password_strength.png" width="40%" />


## The Actual Project

Write a program named `crack.c` that can perform dictionary-based password cracking. Your program will use the `words` file included in the project workspace as its dictionary and the built-in C `crypt` function to calculate hashes, which we'll discuss in more detail below. In addition, your program needs to support two mangling options:

- Toggling the case of the first letter in a dictionary word
- Appending each of the digits 0-9 to a word and testing each of the resulting passwords

### Shadow file format

If you look at the files in the testing directory, you'll see shadow password entries similar to the following:

```
user0:$1$$JCsoZ55UHyLk22.lqSA2U0
user1:$1$$eoTG9D5Fx..7iliLQWPBw/
user2:$1$$VD002Iq9ks/wo/H1EXJtJ0
user3:$1$$30qGDaBgnIhhMssqS04JT1
user4:$1$$HORk2MILG8xV3q4OqTHwX0
```

Each line corresponds to one password entry with the following format:

- The user name, e.g. `user0`. These are dummy values and you won't use them at all.

- A colon separating the user name from the hashed password string.
 
- The first part of the password string, which is always `$1$$`. The number identifies the hash function to use for this password, using standard numbers defined by the `crypt` function. Number `1` corresponds to the md5 hash function, which is not the most secure choice, but is fast. A more realistic option is number `6`, which corresponds to SHA-512, one of the main cryptographic hash functions.

- The actual password hash itself, e.g. `JCsoZ55UHyLk22.lqSA2U0` in the first line of the example above.

### The `crypt.c` program

Your program must support the following options:

- `-i`: specifies the input shadow password  file.

- `-o`: specifies the output file that will store the cracked passwords

- `-d`: specifies the dictionary file that stores the list of candidate passwords. The supplied `words` file is a UNIX dictionary with a large number of words intended for spellchecking.

The basic dictionary attack simply calculates the hashes of every word in the
dictionary, checking for matches with the entries in the shadow  file. You should also support two mangling options:

- `-n`: append each of the single digits, 0-9, to the end of the candidate. 
- `-c`: toggle the case of the  first letter of the candidate.

These options can be invoked in any combination. It's acceptable to use zero, only one, or both mangling options, but you can only invoke one combination of options each time the program runs. **You must use `getopt` to process the command-line options**.

Here is an example invocation:

```
./crypt -i tests/shadow_no_mangle -o output -d words -c -n
```

The `test.py` script will automatically invoke your program with the appropriate inputs for each test case.


### Calculating hashes with `crypt`

You will use the C crypt function to calculate password hashes. Take a look at
`example.c` to see how it works.

`crypt` takes two arguments: the string to hash and a "salt" string. **Your salt string will
always be `$1$`**. The salt string serves two purposes:

- It begins with a number that identifies the hash function, as discussed above.

- It can contain additional characters that are added to the input string before the hash operation. Doing this increases the effective length of the password, which defeats attacks based on precomputing hashes for short passwords (read the part about the rainbow table attack above). You do not need to add any additional salt characters to your implementation.

### Strategy

This is a complex project. Think about how to build incrementally and test your work as you go. Here is a general strategy to get you through:

- Look at `example.c` and make sure that you understand it and can compile and run it. Experiment with hashing different strings.

- Start by writing the `main` function and using `getopt` to process arguments. You don't need to do anything with all of the arguments yet, but write code to identify that they're present. Review the Benford's Law project if you need a refresher on `getopt`.

- Next, write code to open the input file and loop through each of its lines. Use `strtok` to extract the hash string from each line.

- This next step is the hardest one. Write a function that takes the hash string and the dictionary file name as inputs. Your function should open the dictionary file and loop through the words in contains, one per line. For each word, calculate its hash using `crypt` and compare to the input hash string. If you find a match, return the dictionary word that generated the correct hash. **Every test has a match in the dictionary**.

- Once you can identify the correct passwords for one of the test files, write code to write them to the output file.

- At this point, you should be able to pass the first test case, which uses the input shadow file with no mangling rules.

- Next, add support for the `-c` option to toggle the first letter of each input word. Note that this doesn't require rewriting the entire flow, just add a flag that checks if case toggling is set, and if it is, flip the first letter. You might want to check for any easy way to do that, or review the midterm.

- Finally, add support for the `-n` option. This one is more complex because it needs to append each digit 0-9 to each candidate word and calculate the hash for each combination.

Happy cracking!
