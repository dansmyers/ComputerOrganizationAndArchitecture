# Challenge Project 3: Tales from the `crypt`

<img src="https://www.budsartbooks.com/wp-content/uploads/2021/05/ectfc01-tales-from-the-crypt-book_2.jpg" width="35%" />

## STILL UNDER DEVELOPMENT -- DON'T WORK ON THIS YET

## Due

## You can work with a partner to complete this project

## Description

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

What if the shadow file is compromised? This is not great, but 
