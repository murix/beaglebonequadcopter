bbb-scripts
===========

Tested in xUbuntu 14.04 64-bit

Official Lastest images
=======================
http://beagleboard.org/latest-images/

Create custom images (advanced)
===============================

git clone https://github.com/RobertCNelson/omap-image-builder

git checkout -b v2014.07

./RootStock-NG.sh -c bb.org-console-debian-stable

./setup_sdcard.sh --img-1gb debian --dtb beaglebone --bbb-flasher --enable-systemd --offline

xz -v debian-1gb.img


Install official or custom images
=================================

0. xzcat debian-1gb.img.xz > /dev/sdx
1. Power down BBB
2. Insert SD Card in BBB with S2 button pressed
3. Wait all users leds to be active ( wait 15 minutes or more )
4. Power cycle BBB without SD Card


Setup PC as internet USB router
===============================

sysctl -w net.ipv4.ip_forward=1

iptables -t nat -A POSTROUTING -j MASQUERADE

ifconfig usb0 192.168.7.1

Connect BBB serial TTL - J1 header
==================================

minicom -c on -o -D /dev/ttyACM0


Connect BBB to internet via USB
===============================

ifconfig usb0 192.168.7.2

route add default gw 192.168.7.1

echo nameserver 8.8.8.8 > /etc/resolv.conf

Cleanup/Upgrade BBB Debian
==========================

git clone git@github.com:murix/bbb-scripts.git

./bbb-scripts/bbb-packages.sh


SSH & GIT setup
===============

./git-config.sh






