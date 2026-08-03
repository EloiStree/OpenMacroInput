# .fasttyping

Fast typing allows you to detect predefined text sequences that are entered as rapid keystrokes.

Typical devices that generate this kind of fast keyboard input include:
* QR code readers
* Barcode readers
* RFID readers
* Other keyboard-emulating input devices

You can also type the keyword manually, provided it is entered quickly enough.

You can attach events to a text sequence:
* **enter**: the text sequence has been detected.
* **exit**: the text sequence was detected, but another character was typed afterward.
* **submit**: the user stopped typing, and the text sequence was successfully detected.

This system listens to text produced by keyboard input rather than to a specific input field.

If you want similar behavior with gamepads or other non-keyboard devices, you can map their inputs to text sequences in a separate configuration file. For example:

```text
gamepad a: BA
gamepad y: BY
gamepad left: JLL
```

This file format, however, only handles keyboard-generated text sequences and does not define mappings for other input devices.


Example of NFC used in this case:    
https://github.com/eloistree/guid/9PuzTgJ89XkgFGfBZRsBVHMaDzHF1iLswWfG2wjeJMMb   


##  Keylogger

Outside of the Godot app, you need to run a keylogger to enjoy this functionality.

Find information and download here:   
https://github.com/EloiStree?tab=repositories&q=key_logger&type=&language=&sort=


