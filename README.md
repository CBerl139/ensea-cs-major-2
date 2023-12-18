# ensea-cs-major-2
LAB 3 &amp; 4 of Computer Science Major S7 at ENSEA.

[ensea.fr](https://www.ensea.fr/fr)

# How to launch the code
1. Compilation :
When in src directory :
```
& gcc ./gettftp.c -o ./gettftp
& gcc ./puttftp.c -o ./puttftp
```
2. Execution :
When in src directory :
```
& ./gettftp <host> <port> <file>
& ./puttftp <host> <file>
```

# What this code does
gettftp sends a TFTP read request (RRQ) to a host of your choice.
Here is an capture of Wireshark showing the request has been successfully sent :
![IMAGE](https://github.com/CBerl139/ensea-cs-major-2/blob/img/capture.png?raw=true)
