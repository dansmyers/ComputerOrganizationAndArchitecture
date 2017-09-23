# Lab 1: Framboise

### Goals

This lab will let you practice logging into and working with the Raspberry Pi. Along the way, you'll get some practice with several important Linux sysadmin concepts, including

  - copying the operating system onto an SD card
  - logging in to a remote computer using SSH
  - editing files in the terminal
  - superuser acccounts and `sudo`
  - installing packages with `apt-get`
  - the `man` command
  - connecting programs with pipes
  - talking cows
  
### Getting an OS onto the SD Card

The Raspberry Pi uses its micro-SD card to provide all permanent storage, including the operating system files. Therefore, our first
step is to burn a copy of the OS onto your SD card.

**Perform these steps on a Windows computer**. Team up with someone who has a Windows laptop if you're a Mac user.

**Read these warnings before continuing.**
  - You are going to overwrite a destination drive with a new OS. **Make sure you overwrite the SD card and not your computer's regular hard drive**.
  - Windows may pop up messages about "reformatting" a drive. **Do not reformat any drives***. Click cancel on any messages about reformatting that you see.

If you have not done so already, download the [Etcher image burning software](https://etcher.io/). Windows users should have already downloaded the Raspbian OS image as a ZIP file from the Raspberry Pi Foundation's website.

Open Etcher and insert your SD card into the laptop. The Etcher software should automatically recognize that you have inserted a removable storage device and automatically select it as the destination drive for the burn. Select your Raspbian ZIP file as the image, then click "Flash" to perform the burn.

The burn process taks 2-3 minutes, followed by another 2-3 minutes for validation. Don't do anything to disrupt the process until the entire operation is complete.

Once your burn is completely finished, remove your SD card from the laptop, then reinsert it. Look in Windows Explorer and you should see a removable drived named `boot`.

To log in to the Raspberry Pi, you need to enable the SSH ("Secure Shell") encrypted log-in protocol. This is disabled by default on current versions of the Raspbian OS.
  - Open Notepad
  - Go to File --> Save As...
  - Save a blank file with the name `ssh` (just `ssh` with no extension, **not** `ssh.txt`) to the main directory on the `boot` drive. When I have done this before, I selected "Save as type: All files" rather than "Text file" on the Save As... dialog box; I'm not sure if this matters or not.
  - When the Raspbian OS boots, it uses the presence of the `ssh` file as a signal to enable the SSH protocol.
  - Right click on the `boot` drive and choose "Eject" from the menu before you remove it from the laptop.

### Start Up the Raspberry Pi

Insert the micro-SD card into the slot on the bottom of the Pi. Connect the ethernet cable between the Pi and your laptop, then attach the power supply to its connector on the Pi.

You should see a solid red light and a blinking green light. Wait about a minute until the green light stops blinking.

### Logging in for Windows Users

Windows users need to download two additional programs.

First, download PuTTY, a program for making remote connections with a terminal interface on Windows computers. Go to [the PuTTY download page](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html), scroll down to the "Alternative Binary Files" section, and download the 64-bit Windows version of `putty.exe`. Save it in a location that's easy to access, like your Desktop.

Note that `putty.exe` is simply an exectuable file, not an installer.

Next, download and install [Bonjour Print Services](https://support.apple.com/kb/dl999?locale=en_US) from Apple. This program will allow your computer to recognize the Raspberry Pi's name over your direct ethernet connection. If you have iTunes installed you may already have the necessary protocol.

Run PuTTY. In the "Host name" field, enter `pi@raspberrypi.local`, then press the "Open" button. You should see a terminal window pop up.

You will see message saying "the authenticity of host 'raspberrypi.local' can't be established". This is because it's your first time establishing an encrypted connection to that host. You're not being hacked right now, so select "yes" to continue connecting.

The default password is `raspberry`. Remember that the system does not display the password as you type it.

### Logging in for Mac Users

Open the terminal application by going to Finder --> Applications --> Utilities --> Terminal
    
In the terminal window, type
```
prompt$ ssh pi@raspberrypi.local
```
`ssh` is a program that establishes an encrypted, authenticated connection to a remote computer using the SSH protocol. `pi` is the default user account and `raspberrypi.local` is the hostname, which is automatically established when you connect the Pi to a Mac via ethernet.

You will see message saying "the authenticity of host 'raspberrypi.local' can't be established". This is because it's your first time establishing an encrypted connection to that host. You're not being hacked right now, so enter "yes" to continue connecting.

The default password is `raspberry`. Remember that the system does not display the password as you type it.

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

`sudo` is `substitute user do`&mdash;it's a way to run individual commands with superuser-level privileges without actually logging in as the root account.

![xkcd #149](https://imgs.xkcd.com/comics/sandwich.png)

The `wpa_supplicant.conf` file can only be edited by root, so you need to use `sudo` when you open it.

Edit the file so that it looks like the following. There may be an additional country line in the header: that's okay. Put your own
Rollins username and password in the `identity` and `password` fields.

**THE FILE HAS TO LOOK LIKE THE ONE SHOWN BELOW. CHECK THE SPACING AND SPELLING OF EVERY ITEM.**

You can copy the `network` block and paste it into the terminal window. Mac users can probably use the regular `COMMAND + v` paste command; Windows users can paste by right-clicking in the PuTTY window.

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
Press `CTRL + o` to save ("write out") the file.

Press `CTRL + x` to exit the nano editor.

After you have saved the file, reboot your Pi to make the changes take effect.
```
prompt$ sudo reboot
```
It will take about a minute for your Pi to reboot. After that, repeat the log-in process. The target server is `pi@raspberrypi.local` and the password is `raspberry`.

Test by pinging a remote server. `ping` is a command that sends small message packets to a server and measures the response times.
```
prompt$ ping 8.8.8.8
```    
8.8.8.8 is the IP address of the public Google DNS server. If your Pi is connected to FoxNet, you should see lines reporting the response times of each `ping` packet. If you get a message saying that the network is unreachable, or another error, double-check the contents of the `wpa_supplicant.conf` file.

### Cowsay?

Let's install a new program.
```
prompt$ sudo apt-get install cowsay
```
`apt-get` is a standard command for managing packages and installing programs on many Linux distros. It has to be run as root to make
system changes, so it's prefixed by `sudo`.

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

To get more information on a system command, consult its manual page using the `man` command.
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

### One More Thing...
Telnet is a program for establishing a remote connection to another server.

```
prompt$ sudo apt-get install telnet
prompt telnet towel.blinkenlights.nl
```

Close the terminal window to quit.

