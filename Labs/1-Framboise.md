# Lab 1: Introduction à la Framboise Pi

### Goals

This lab will let you practice logging into and working with the Raspberry Pi. Along the way, you'll get some practice with several important Linux sysadmin concepts, including

  - logging in to a remote computer using SSH
  - editing files in the terminal
  - superuser acccounts and `sudo`
  - password hashing and authentication
  - installing packages with `apt-get`
  - the `man` command
  - connecting programs with pipes
  - X and forwarding
  - talking cows

### Start the Terminal

Log in to the desktop Mac

Open the terminal application
    - Go to Finder --> Applications --> Utilities --> Terminal
    
### Connect the Desktop Mac to FoxNet

Click on Apple logo in the upper-left corner. Go to System Preferences --> Networks and click on "Wi-fi".

Choose "FoxNet" in the "Network Name" dropdown menu and enter your credentials to connect to the network.
    
You may be prompted to update your credential settings. Accept this and enter your password to confirm.

### Start-up the Raspberry Pi        

**Gently** unplug the network cable from the wall and connect it to .the Raspberry Pi's ethernet port

Plug in your power supply. You should see a solid red light and a blinking green light. Wait about a minute until the green light stops blinking.
  
In the terminal window, type
```
prompt$ ssh pi@raspberrypi.local
```
SSH (secure shell) is a program that establishes an encrypted, authenticated connection to a remote computer. `pi` is the default user account and `raspberrypi.local` is the hostname, which is automatically established when you connect the Pi to a Mac via ethernet.

You will see message saying "the authenticity of host 'raspberrypi.local' can't be established". This is because it's your first time establishing an encrypted connection to that host. You're probably not being hacked right now, so enter "yes" to continue connecting.

The default password is `raspberry`.

### Connect the Raspberry Pi to FoxNet

To set up wi-fi, you're going to edit a configuration file called `wpa_supplicant.conf`.

Change to the wpa_supplicant directory:
```
prompt$ cd /etc/wpa_supplicant
``` 

Open the file in a text editor:
```
prompt$ sudo nano wpa_supplicant.conf
```
`nano` is a basic text editor that runs in the terminal window.

Linux systems have the notion of privilege levels and access control. The top level account on any system is the **superuser** or **root** account, which has the ability to make any change to anything. Regular users always run with privileges below that of root.

`sudo` is `substitute user do`&mdash;it's a way to run individual commands with superuser-level privileges without actually logging in as the root account. The `wpa_supplicant.conf` file can only be edited by root, so you need to use `sudo` when you open it.

Edit the file so that it looks like the following. There may be an additional country line in the header: that's okay. Put your own
Rollins username and password in the `identity` and `password` fields.
```
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1

network={
	ssid="FoxNet"
	proto=RSN
	key_mgmt=WPA-EAP
	pairwise=CCMP
	auth_alg=OPEN
	eap=PEAP
	identity="dmyers"
	password="ItsASecretToEveryone"
	phase1="peapver=0"
	phase2="MSCHAPV2"
}
```
Press CTRL + o to save ("write out") the file.

Press CTRL + x to exit the nano editor.

Cycle the wi-fi to connect to the network.
```
prompt$ sudo ifdown wlan0
prompt$ sudo ifup wlan0
```

Test by pinging a remote server. `ping` is a command that sends small message packets to a server and measures the response times.
```
prompt$ ping 8.8.8.8
```    
8.8.8.8 is the IP address of the public Google DNS server. If your Pi is connected to FoxNet, you should see lines reporting the results of each `ping` packet.

### Let's At Least Pretend to Care About Security

On second thought, storing your real password in plain text is not really a smart thing to do.

The server doesn't actually store your plain text password; instead, it stores a **hash** of your password. When you log in, the server calculates the hash of the password you provide, then checks it against the stored hash. If there's a match, it accepts the supplied password and allows you to authenticate to the network.

Therefore, you can get around the problem of storing a password in plain text by storing the **hash** of your password. Assuming that you're using a strong cryptographic hash function, recovering your real password from the hash is prohibitively difficult.

First, generate the hash:
```
prompt$ echo -n YourRealPasswordGoesHere | iconv -t utf16le | openssl md4
```
This will print something like
```
(stdin)= e1daee0c568764db0123456789abcdef
```
The hex string to the right of `=` is the hash of your password. Highlight it and press COMMAND + c to copy.

Now reopen `wpa_supplicant.conf` using `sudo nano`. Edit the `password` line:
```
password=hash:e1daee0c568764db0123456789abcdef
```
The hex string will be the string that you generated in the previous step. Paste it using COMMAND + v.

Save the file using CTRL + o and exit using CTRL + x.

To reauthenticate to the network, you must reboot:
```
prompt$ sudo reboot
```
`reboot` will log you out of the terminal connection as it reboots your Pi. Wait about a minute, then log back in using SSH. Pro tip: you can press the up arrow in the terminal to cycle through your previous commands.

Once you're back in, try
```
prompt$ ping 8.8.8.8
```
If it works, you've authenticated to the wireless network without using your plain text password.

The final step is to clear your Pi's command history so no nefarious person can recover your password by looking back to the hash generation command.
```
prompt$ history -c
prompt$ history -n
```

### Update and Upgrade

Run four commands:

    prompt$ sudo apt-get update
    prompt$ sudo apt-get upgrade
    prompt$ sudo rpi-update
    prompt$ sudo reboot
    
`apt-get` is a standard command for managing packages and installing programs on many Linux distros. It has to be run as root to make
system changes, so it's prefixed by `sudo`.

These will bring your Pi's OS and utilities up to the latest versions. The upgrade will take several minutes, but you only have to do it once.



### Cowsay?

Let's install a new program.
```
prompt$ sudo apt-get install cowsay
```
Run the program:
```
prompt$ cowsay "Hello, Raspberry Pi!"
  ____________________
< Hello, Raspberry Pi! >
  --------------------
       \   ^__^ 
        \  (oo)\_______
           (__)\       )\/\
               ||----w |
               ||     ||
```               
Make the cow say a few different things.

### The Man Pages (Not a Dating Site)

To get more information on a system command, consult its manual page using the `man` command. For example,
```
prompt$ man cowsay
```    
This brings up a description of the `cowsay` command, including discussion of its optional flags and arguments.

Use the arrow keys to scroll and press `q` to quit the viewer.

Using the information in the man page, make the cow take on the following qualities:
  - dead
  - tired
  - youthful
  - Borg
    
You can also use a different image file with the -f flag:
```
prompt$ cowsay -f dragon "Extra crispy!"
```

### Fortunate Cows

Install another silly program:
```
prompt$ sudo apt-get install fortune
```
`fortune` prints sayings&mdash;some profound, some not&mdash;to the console. You can have some fun by **piping** the output of `fortune` to the input of `cowsay`.
```
prompt$ fortune | cowsay
```

A **pipe** is a connection between two processes. The output of one end of the pipe becomes the input to the other end. In this example, the output of `fortune`, which would ordinarily go to the console, is redirected to the `cowsay` program instead, which then uses it as input and prints an oracular cow.

Pipes are a common tool in the Unix world: they allow you to chain small, simple programs together to accomplish complex feats of text processing.

### Graphics

Logout from your Raspberry Pi.
```
prompt$ exit
```
Now log back in, but with a slightly different command:
```
prompt$ ssh -X pi@raspberrypi.local
```
The `-X` flag to `ssh` enables **X11 forwarding**. X is the default windowing system on Linux. "Forwarding" X allows graphical windows that you open on the Raspberry Pi to appear on your local Mac desktop.

Navigate to the `~/python_games` directory (hint: use `pwd`, `ls`, and `cd` to check where you are in the hierarchy and move around; you can use `cd ..` to move up to a parent directory).

All of the games are Python files with a `.py` extension. To list all files ending in `.py`:
```
prompt$ ls *.py
```
Run a game:
```
prompt$ python squirrel.py
```
I like Squirrel Eat Squirrel and Inkspill. Starpusher is pretty hard.

### Get Back to Work

Write a simple C program that declares three integers, assigns them values, adds them into a fourth integer, then prints their sum.

Use the `nano` editor and compile your program with `gcc`:
```
prompt$ cd ~
prompt$ mkdir labs
prompt$ nano add.c
prompt$ gcc -o add add.c
prompt$ ./add
```

You can modify the output of `gcc` using different flags. The `-S` flag instructs `gcc` to stop the compilation process after producing an assembly language file.
```
prompt$ gcc -S add.c
```
Take a look at the assembly file:
```
prompt$ nano add.s
```
There will be several things that are unclear at this point, but take a close look at the sequence of basic language instructions in the file. Can you decipher the basic steps in the program's execution?

### One More Thing...
Telnet is a program for establishing a remote connection to another server.

```
prompt$ sudo apt-get install telnet
prompt telnet towel.blinkenlights.nl
```

Close the terminal window to quit.

