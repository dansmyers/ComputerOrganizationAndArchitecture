# Server

A web server is a program that receives and processes HTTP requests. HTTP (the "Hypertext Transfer Protocol") is the main protocol used to request and transmit web pages over the global Internet.

In this lab, you'll turn your Raspberry Pi into a web server, create a basic web page, and experiment with a few of Linux's basic security features. This will give you practice:
  
  - Installing and configuring the nginx web server
  - Connecting to the server using its IP address and HTTP
  - Creating and styling a basic HTML web page
  - Working with file permissions using the `chmod` command
  - Setting up a shadow password file and basic HTTP authentication

## Initial Setup

Repeat the basic setup process from the last lab:

  1. Log in to the dekstop Mac.
  
  2. Open the terminal application.
  
  3. Once the terminal is open, **gently** disconnect the network cable from the wall and connect it to the ethernet port of your Raspberry Pi.
  
  4. Connect the power supply to the Pi and wait about a minute
  
  5. Log in to the pi using ssh:
  
  ```
  prompt$ ssh pi@raspberrypi.local
  ```
  
  The default password is `raspberry`.
  
  You may get a fearsome error saying `REMOTE HOST IDENTIFICATION HAS CHANGED!`. This can be caused by logging into a desktop computer that previously hosted a different Pi under the name `raspberrypi.local`. You can make the desktop forget the old Pi using
  
  ```
  prompt$ ssh-keygen -R raspberrypi.local
  ```
  
  6. Connect the desktop computer to FoxNet and verify that you're connected by opening a browser.
  
Once you're logged in to the Pi, verify that your wi-if is working:

```
prompt$ ping 8.8.8.8
```

## Install nginx

nginx is one the two main web server programs widely used in the modern Internet. The other is Apache.

Install nginx using `apt-get`.

```
prompt$ sudo apt-get install nginx
```

**Question**: what does the `sudo` command do?

nginx is automatically configured to start as soon as its host boots. This makes sense for a production web server, which should start up as quickly as possible after any downtime, but it isn't necessary for our Pi. As a general rule, never keep a server open on your machine when you aren't actively using it for something. To disable autorun:

```
prompt$ sudo update-rc.d -f nginx disable
```

Start nginx:

```
prompt$ sudo nginx
```

Your server is now up and sending a default page in response to HTTP requests. Later, when you're ready to stop it, use

```
prompt$ sudo nginx -s quit
```

A web server needs access to the system's low-level network resources, so interacting with nginx requires the `sudo` command.

## Test

Get your Pi's IP address:

```
prompt$ ifconfig
```

Look to the portion of the output labeled `wlan0`. It will look similar to this:

```
wlan0     Link encap:Ethernet  HWaddr b8:27:eb:7d:98:e8  
          inet addr:172.23.17.102  Bcast:172.23.31.255  Mask:255.255.240.0
          inet6 addr: fe80::3a58:e6c:c5e6:140c/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:401 errors:0 dropped:354 overruns:0 frame:0
          TX packets:88 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:86595 (84.5 KiB)  TX bytes:16455 (16.0 KiB)```
```

Look at the `inet addr` field. This is your Pi's IP address, a unique identifier that browsers and other systems can use to reach your machine over the Internet. The IP address is a 32-bit value, but is conventionally written in "dot notation," showing the integer values of each of its four bytes.

Open up a web browser and type `http://172.23.17.102` in the browser's address bar&mdash;replace my example IP address with your Pi's own IP address printed by `ifconfig`. The default nginx web page will load in your browser.

The default page is located at `/var/www/html/index.nginx-debian.html`. Edit it using `nano`:

```
prompt$ sudo nano /var/www/html/index.nginx-debian.html
```

The HTML ("Hypertext Markup Language") file shows the text content of the web page, together with **tags** that describe how it should be structured and formatted. For example, the `<h1>` indicates a top-level header that appears large and bold when the page is displayed. Tags are usually grouped in matched pairs, with closing tags denoted by a `/`, e.g. `</h1>`.
  
Make a change to the file by adding

```
<h1>OHAI DERE</h1>
```

to the existing `<body>` section. Save with CTRL + o and exit with CTRL + x. Reload the page in the web browser and you should see your changes in the page's text.

## Configure and Serve a New File

Now we'll create a new web page in a new location and configure nginx to serve that page instead of the default one.

Change back to your home directory and make a new directory called `web`.

```
prompt$ cd ~
prompt$ mkdir web
prompt$ cd web
```

The name `web` is not significant; it's just easy to remember.

Let's make a basic web page. It needs to be named `index.html`.

```
prompt$ nano index.html
```

```
<!DOCTYPE html>
<html>
    <!-- This is an HTML comment -->
    <!-- 
      --  The basic HTML file has two sections:
      --    <head> contains metainformation on the whole page
      --    <body> contains page content
      -->

    <head>
        <title>This appears at the top of the browser.</title>
    </head>
    <body>
        <h1>This is a Website.</h1>
        
        <p>This is a paragraph of text on a website.
        
        <p>Here's another paragraph.
        
        <p>That's all.
    </body>
</html>
```

Save the file using CTRL + o and exit the editor using CTRL + x.

Next, edit the nginx configuration to serve your new page. Get the full path of the `web` directory.

```
prompt$ pwd
/home/pi/web
```

The default nginx config file is located at `/etc/nginx/sites-available/default`.

```
prompt$ sudo nano /etc/nginx/sites-available/default
```

Look for a block close to the top of the file that starts with `server`:

```
# Default server configuration
#
server {
        listen 80 default_server;
        listen [::]:80 default_server;

        # SSL configuration
        #
        # listen 443 ssl default_server;
        # listen [::]:443 ssl default_server;
        #
        # Self signed certs generated by the ssl-cert package
        # Don't use them in a production server!
        #
        # include snippets/snakeoil.conf;

        root /var/www/html;
```

Lines beginning with `#` are comments. The SSL block, used for secure authentication, is commented out.

The `root` line specifies the location of the directory holding the index page. Change it to

```
    root /home/pi/web;
```

Save the file, then reload nginx to make it use the new configuration.

```
prompt$ sudo nginx -s reload
```

Refresh the page in the browser one more time to see your new page.

## Interior Decoration

cURL is a useful tool that let's you interact with a remote server from the command line. Among its MANY uses is grabbing files from a remote location. From your `/home/pi/web` directory, run

```
prompt$ curl -O https://upload.wikimedia.org/wikipedia/commons/0/0a/The_Great_Wave_off_Kanagawa.jpg
```

The `-O` flag saves the file locally.

Open your `index.html` file and add an image tag to its body.

```
<p>
<img src="The_Great_Wave_off_Kanagawa.jpg"/>
```

Reload the page and check out your picture.

Yikes. That's large. You can add style to the tag to scale the image to a percentage of the display width:

```
<p>
<img src="The_Great_Wave_off_Kanagawa.jpg" style="width:100%"/>
```

You can also set an absolute size in pixels, e.g. `"width:200px"`.

This method of styling elements was common in the old-school web, but modern practice favors separating page content from styling.

Move the `<style>` information up to the `<head>` block of your page:

```
<head>
    <title>This appears at the top of the browser.</title>

    <style>
        img {
            width: 100%;
        }
    </style>
</head>
```

The style rule specifies that the contents of all `<img>` tags should have their width set to 50% of the page size.

You can add elements to the style block to control the presentation of other parts of the page. For example, to style the contents of  the entire body:

```
<head>
    <title>This appears at the top of the browser.</title>

    <style>
        img {
            width: 200px;
        }

        body {
            font-family: "Helvetica", "Arial", sans-serif;
            font-size: 18pt;
            background-color: #FAFAFA;
        }
    </style>
</head>
```

The `font-family` parameter takes a list of fonts and uses the first one that's available on the system, with the last choice being the default system sans-serif font.

Colors are specified as three hex values, denoting the R, G, and B components of the color. Play around with some color parameters and see what you can generate.

You can also set `color` to control the color of the text.

Here's one last style block that makes things a little more readable by bringing the page contents to the center.

```
<style>
    img {
        width: 100%;
    }

    body {
        font-family: "Helvetica", "Arial", sans-serif;
        font-size: 18pt;
        color: #333333;
        background-color: #FCFCFC;
        margin: 40px auto;
        max-width: 640px;
    }
</style>
```

`max-width` controls the size of the display region in the browser.

`margin` sets a padding of 40px around all sides of the page content; `auto` centers the display region inside the browser frame, pulling everything to the middle. Note that this is centering the display region, not the content itself.

The background and text are softened a little away from strict white and black.

## Authentication

Let's modify our site so that it restricts access using basic HTTP authentication. This is not the most sophisticated setup possible. In particular, it doesn't protect user passwords from anyone that might be sniffing traffic on the wi-fi network. Nonetheless, it helps illustrate some important Linux password-management concepts.

### How does a Linux system store your password?

Old systems actually stored users' passwords in a cleartext file called `/etc/passwd`. Unfortunately, this meant that anyone gaining access to that file would have every system users' real password.

Modern systems use a **shadow** password file, stored in `/etc/shadow`. The shadow file doesn't store user's real passwords. Instead, it stores **hashes** of each password.

Recall: **what's a hash function**?

When a user logs in, the system can calculate the hash of the user password and compares it to the stored hash in the shadow file. If the hashes match, then the system assumes that the submitted password is the real password and accept the user's credentials.

Note that for this to be secure, it must be **impossible** to recover the real password given only the hash in the shadow file. Strong cryptographic hash functions have this property. In practice, however, weak passwords may still be easy to crack.

### Who Knows What Secrets Lurk in the Hearts of Men? The Shadow Knows

Try to dump the contents of `/etc/shadow/` to the screen using the `cat` command.

```
prompt$ cat /etc/shadow
```

You'll get `Permission denied` as a result.

Every Linux file has a set of **permissions**, describing which users are allowed to read, write, and execute the file. You can view the permissions with `ls -l`:

```
prompt$ ls -l /etc/shadow
```

Every file has an owner and an associated group. The owner of the `shadow` file is root and its group is `shadow`. The permissions are a string of the form

```
rwxrwxrwx
```

For `shadow`, the permission string is `rw-r------`.

The first `rwx` group indicates the permissions assigned to the owner of the file: `root` can read and write the shadow file, which makes sense.

The second `rwx` group indicates permissions for the file's associated group. The `shadow` group can read, but not write, the file.

The third `rwx` group indicates permissions for any other system user. Other users have no permissions for the `shadow` file. This makes sense: `shadow` contains sensitive information about user passwords, so only sysadmins with root access should be able to interact with it. Regular users should not be able to read or write the `shadow` file.

You can check the permissions for some other files:

```
prompt$ ls -l /home/pi/web/index.html
```

What do the results show?

### Move in the Shadows

You can view the contents of `shadow` with `sudo`.

```
prompt$ sudo cat /etc/shadow
```

Look for a line that begins with `pi:$6$X8NL...`. This is shadow password file entry for user `pi`, the default user that we've used to log in to the Raspberry Pi.

The huge string specifies the hash of Pi's password. In this case, we know the password is `raspberry`, but it would be hard to determine that if all we had was the `shadow` file. The `$6$` at the beginning of the line indicates that the hash was produced by the SHA-512 hash function.

### Adding Authentication to the Web Site

Open up the configuration file.

```
prompt$ sudo nano /etc/nginx/sites-available/default
```

Scroll down and look for a block labeled `location / {`. Add two lines to the `location` block.

```
        auth_basic "Restricted";
        auth_basic_user_file /home/pi/web/.htaccess;
```

The first line is just a message indicating that the site is "Restricted." The second specifies the location of a shadow password file to use for authentication to the site. The shadow file will be called `.htaccess` and live in the same directory as the rest of the site.

The `.` indicates that `.htaccess` is a hidden file and won't show up in normal listings. Use `ls -a` to show hidden files.

The `.htaccess` file will contain a list of user names and their associated password hashes.

To create a hash of a password, use

```
prompt$ openssl passwd -1 "password"
```

This will print a string beginning with `$1$`, which is the MD5 hash of the string `password`.

**Don't use an important password for this activity**. The basic authentication protocol sends your password over the network in cleartext. It's unlikely, but anyone logging traffic on the campus wi-fi system could grab a copy of the password as it's in transmission.

Now, open the `.htaccess` file and enter a username and the password hash you just generated.

```
prompt$ sudo nano .htaccess
```

Copy and paste the password hash string to create a line like

```
pi:$1$JyPDrvsl$cvM7ZKzCiIZmaJqV5nCLY.
```

You must reload nginx to make the changes to the config file take effect:

```
prompt$ sudo nginx -s reload
```

Now reload your page. You should be prompted to enter a name a password. Enter the ones you specified in the `.htaccess` file and watch the page load.


## Last Step

Log out of your Pi by typing `exit` at the prompt. Disconnect it from the ethernet cable and power, and then **plug the network cable back into the wall**.

