# justsock -- just some sockets :]

Litte lib for basic using sockets. It's annoying to do all this work every time, so I put here some of this operations by template and use it as lib.

> This little repo is Linux-only compatibility.

## Build 

To build **executable** test file (which `main` you can read from *src/common/_main/main.c*):
```
$ make 
```
To build **dynamic lib** file:
```
$ make so
```
To **install** lib in `LIBPATH` (default: */usr/local/lib*) and header in `INCPATH` (default: */usr/local/include*):
```
# make install                  ;; pay attention: root privileges
```
To **uninstall** lib and header (if you didn't change `LIBPATH` and `INCPATH` in a Makefiles):
```
# make uninstall                ;; pay attention: root privileges
```

## Interface

Now it's only 2 functions to use:
1. Get and connect socket to this hostname:
```
int get_socket_by_hostname (unsigned char*);
```
This function get string **hostname**, such as `"google.com"`, or string **service://hostname**, such as `"http://google.com"`. Then it redirect query to `getaddrinfo()` function, create socket by gotten info and connect it to addr from `struct addrinfo`. After all, it returns already connected socket descriptor on requested host or -1 if there's no connection. Text is long, but it's easy

2. Get and connect socket to this address:
```
int get_socket_by_str_ipv4 (unsigned char*);
```
This function get string **ipv4_addr:port**, such as `"127.0.0.1:80"`, and parse it. Then it create socket and connect it to parsed address. After all, it return already connected socket descriptor on requested address or -1 if there's no connection. Same

## Other abilities

Not much, really. It's just 1 action yet, no more. But I not going to strip symbols, so you free to use `nm` or `objdump` -- this lib has not any precious.
