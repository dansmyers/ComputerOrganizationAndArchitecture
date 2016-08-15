# Raspberry Pi Shopping Guide

### About the Raspberry Pi


### Things You Have to Buy

You will need to purchase the following items:

  - A Raspberry Pi 3 Model B ($35)
  
  - A power supply for the Raspberry Pi (less than $10)
  
  -  A micro SD card with at least 16 GB of space (less than $15)

All of these items are available from Amazon or other online retailers. AdaFruit and the PiHut are speciality vendors that focus specifically on the Raspberry Pi.

Make sure you purchase the Model 3B! There are still old Model 2's around as well as the Model 0, which is intended for lower-cost embedded projects. Neither of those will work for this course.

**SD Cards, NOOBS, and Raspbian**

If you search for Raspberry Pi SD cards, you will come across references to cards that come "pre-loaded with NOOBS." NOOBS ("New Out-of-the-Box System") is a program that can boot your Pi and install the Raspbian OS with minimal effort on your part. This is great, but you need an HDMI monitor or TV and a USB keyboard to interact with NOOBS and perform the setup. We don't have that many monitors, so we can't use it to perform the initial set-up and OS install in class. Therefore, you **don't** need to purchase an SD card with NOOBS.

I will collect everyone's blank SD cards and format them to install the Raspbian OS. We'll then be able to boot all the Pis directly to Raspbian in class without connecting to a monitor.

**Kits**

You can purchase kits that include the Raspberry Pi, power supply, SD card, a case, and a few other peripherals for about $70. I did not have good luck with the kits sold by Canakit and I don't recommend them&mdash;among other issues, the SD card was not properly formatted. If you choose to purchase a kit, read the reviews before committing.

**Sensors**

We will do a little Internet of Things work at the end of the course, using the Raspberry Pi to create a small platform that can create and share data on its environment. This project may require you to purchase a few additional inexpensive sensor components.

### Things You Might Want to Buy

  - An additional ethernet cable to connect your Pi to a laptop or desktop when you aren't in the computer lab
  
  - An adaptor to connect an ethernet cable to your laptop if it doesn't have a dedicated ethernet port
  
  - A case for your Pi
  
  - A toolbox, shoebox, or other container to store all your equipment

### Connecting to the Raspberry Pi

During class, we'll use the Mac desktops in room 310 for our labs. Each desktop has an ethernet cable that we'll connect to the Pi's ethernet port: this creates a local network connection between the Pi and the Mac and you'll be able to log in to the Pi from the Mac's terminal application. We'll set up a Wi-fi connection to FoxNet in our first lab, so you'll also be able to access the Internet from the Pi and log into it over the wireless network.

If you want to work with your Pi outside of the computer lab, you have a few options. Read the list below and think about which setup will work best for you.

  - If you have a monitor or TV with HDMI input (most TVs have this) and a USB keyboard and mouse, you can connect your Pi to the devices and use it like a desktop computer. The Raspberry Pi's designers intended for it to be used this way.
  
  - You can connect your Pi to another laptop or desktop with an ethernet cable and log in to it, like in the labs. You'll need an adaptor if your computer does not have an ethernet port. If you are using a Windows computer, you'll need a program called PuTTY to open a terminal connection&mdash;I'll demonstrate this later.
  
  - Once we've set up a Wi-fi connection for FoxNet, you'll be able to log into the Pi wirelessly whenever it's powered and connected to the network. You can log into the Pi over a home network by either connecting it your router with an ethernet cable or configuring it to automatically connect to your network over Wi-fi. 

