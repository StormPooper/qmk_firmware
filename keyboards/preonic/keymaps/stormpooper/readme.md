# Custom keymap for Preonic

Press button on PCB (hard mode) or hold Esc when plugging in to boot into DFU mode.

For building on Linux, add these udev rules:

```bash
# /etc/udev/rules.d/50-atmel-dfu.rules
# Atmel ATMega32U4
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ff4", TAG+="uaccess", RUN{builtin}+="uaccess"
# Atmel USBKEY AT90USB1287
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ffb", TAG+="uaccess", RUN{builtin}+="uaccess"
# Atmel ATMega32U2
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ff0", TAG+="uaccess", RUN{builtin}+="uaccess"
```

Afterwards, run the following to reload:

```bash
sudo udevadm control --reload-rules
sudo udevadm trigger
```

It should be picked up by `qmk flash` after that.
