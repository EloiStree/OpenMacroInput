# .typing

This file allows you to hook actions to typed text.

## Examples

* Cut some text to the clipboard, then type `g>p>t`.
  * The tool sends the clipboard content as a request using your ChatGPT API token.
* Cut some text to the clipboard, then type `s>g>p>t`.
  * The tool sends the clipboard content to ChatGPT to correct its spelling.
* Type `ggg`.
  * The tool launches a grenade in a game.
* Type `uv.`.
  * The tool flips the UVs in Blender.

## Modes

* **continue**: Checks the typed characters after every key press.
* **submit**: Checks the typed text only when a submission or validation is requested.

## Related

Similar to `.fasttyping`.

## Boolean Conditions

You can add a boolean condition that must be satisfied for the action to be triggered.


##  Keylogger

Outside of the Godot app, you need to run a keylogger to enjoy this functionality.

Find information and download here:   
https://github.com/EloiStree?tab=repositories&q=key_logger&type=&language=&sort=