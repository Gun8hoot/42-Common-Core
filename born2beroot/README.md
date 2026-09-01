<div align="center">
    <h1>Born2beroot</h1>
</div>

<div align="center">
    <h2>DESCRIPTION :</h2>
</div>

The purpose of this project is to setup a server on a virtual machine without using any graphical interface. For this project ive taken a lot of [notes](https://github.com/Gun8hoot/42-Common-Core/blob/main/born2beroot/notes.md) who are on ./notes.md

<div align="center">
    <h2>CONFIGURATION DONE :</h2>
</div>

- Being on the minimal version of Debian or Rocky Linux
- Create at least 2 encrypted LVM partition
- Setup a SSH server who listen on port 4242
    - Not being possible to connect from root in SSH
- Configure a firewall with ufw on Debian or firewalld on Rocky
- The hostname of our VM should be our 42 login ending with 42 (mine is nclavel42)
- Have a strong password policy
    - The password should expire every 30 days
    - It should be possible only if the password have been change two ago or more
    - The user should get a warning 7 days before the expiration of his password
    - The password should contain more that 10 character, contain a uppercase character, a lowercase, a number and should not contain more that 3 time consecutive the same character
    - The password should not contain the name of the user
    - The password policy should also work with root user
    - The new password should not contain 7 consecutive character from the old password (root is exclude)
- Install and configure sudo
- Having a user with our 42 login as username
    - The user should be on the group sudo and user42
- The max try to sudo should be on limited to 3 attempts
- A custom message of our choise should be display if its the wrong password
- Each action done by sudo should be logged in /var/log/sudo
- The TTY should be enable 
- The $PATH of sudo should be limited to /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
- Having a bash script that display when launching the server and every 10 minutes (WILL ONLY WORK ON THE VM SCREEN, SSH CONNECTION WILL NOT HAVE THE MESSAGE)

<div align="center">
    <h2>SKILL GAIN :</h2>
</div>

- Learned how to install and configure an Linux distribution
