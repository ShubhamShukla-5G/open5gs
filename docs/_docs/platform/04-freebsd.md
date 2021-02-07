---
title: FreeBSD
head_inline: "<style> .blue { color: blue; } </style>"
---

This guide is based on **FreeBSD-12.2-STABLE**.
{: .blue}

### Getting MongoDB
---

Install MongoDB with package manager.
```bash
$ sudo pkg install mongodb44
```

Run MongoDB server.
```bash
$ mkdir -p ./data/db
$ mongod --dbpath ./data/db
```

### Setting up network (No persistent after rebooting)
---

Configure the loopback interface.
```bash
$ sudo ifconfig lo0 alias 127.0.0.2 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.3 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.4 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.5 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.5 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.6 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.7 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.8 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.9 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.10 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.11 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.12 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.13 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.14 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.15 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.16 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.17 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.18 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.19 netmask 255.255.255.255
$ sudo ifconfig lo0 alias 127.0.0.20 netmask 255.255.255.255
```

Enable IP forwarding
```bash
$ sudo sysctl -w net.inet.ip.forwarding=1
$ sudo sysctl -w net.inet6.ip6.forwarding=1
```

**Tip:** The script provided in [$GIT_REPO/misc/netconf.sh](https://github.com/{{ site.github_username }}/open5gs/blob/master/misc/netconf.sh) makes it easy to configure the TUN device as follows:
`$ sudo ./misc/netconf.sh`
{: .notice--info}

### Building Open5GS
---

Install the depedencies for building the source code.
```bash
$ sudo pkg install meson ninja gcc bison gsed pkgconf git mongo-c-driver gnutls libgcrypt libidn libyaml libmicrohttpd nghttp2
```

Configure GCC PATH
```bash
$ setenv LIBRARY_PATH /usr/local/lib
$ setenv C_INCLUDE_PATH /usr/local/include

OR

$ export LIBRARY_PATH=/usr/local/lib
$ export C_INCLUDE_PATH=/usr/local/include
```

Git clone.

```bash
$ git clone https://github.com/{{ site.github_username }}/open5gs
```

To compile with meson:

```bash
$ cd open5gs
$ meson build --prefix=`pwd`/install
$ ninja -C build
```

Check whether the compilation is correct.

**Note:** This should require *sudo* due to access `/dev/tun0`.
{: .notice--danger}

```bash
$ sudo ./build/tests/attach/attach ## EPC Only
$ sudo ./build/tests/registration/registration ## 5G Core Only
```

Run all test programs as below.

**Note:** This should require *sudo* due to access `/dev/tun0`.
{: .notice--danger}

```bash
$ cd build
$ sudo meson test -v
```

**Tip:** You can also check the result of `ninja -C build test` with a tool that captures packets. If you are running `wireshark`, select the `loopback` interface and set FILTER to `s1ap || gtpv2 || pfcp || diameter || gtp || ngap || http2.data.data || http2.headers`.  You can see the virtually created packets. [testattach.pcapng]({{ site.url }}{{ site.baseurl }}/assets/pcapng/testattach.pcapng)/[testregistration.pcapng]({{ site.url }}{{ site.baseurl }}/assets/pcapng/testregistration.pcapng)
{: .notice--info}

You need to perform the **installation process**.
```bash
$ cd build
$ ninja install
$ cd ../
```

### Building WebUI of Open5GS
---

[Node.js](https://nodejs.org/) is required to build WebUI of Open5GS

```bash
$ sudo pkg install node
```

Install the dependencies to run WebUI

```bash
$ cd webui
$ npm install
```

The WebUI runs as an [npm](https://www.npmjs.com/) script.

```bash
$ npm run dev
```
