# Spider3DSTools printing
=========================
A collection of easy to use functions to print various data from your [Spider3DSTools](https://github.com/dukesrg/Spider3DSTools) code on the bottom screen of a 3DS.

## Features
- Emulates 40x30 truecolor text mode with transparency
- Build-in 8x8 font for ASCII range 0x20-0x7F

## Limitations
- May require memory relocation in your code
- Printing a dynamically changed data requires to print all the needed data every time because Spider services refreshes screen too. Flicker may be visible in that case.

## How to integrate into my code

- Include print.h
- Set optimisation flag to O2 (instead of O3 used in Spider3DSTools)
- Relocate all used memory in your code from 0x18410000 above 0x18412000 if printing can interfere with another data processing
- Use print* functions as you like

## How to use
For now those print functions are included:
- print - string
- printw - wide char string
- printint - long int in 0X08 format
String printing functions also support escape control characters:
- \b - backspace, move cursor one character back
- \t - tab, move cursor 8 characters forward
- \n - new line, move cursor to the next line
- \v - vertical tab, move cursor 6 lines down
- \f - form feed, move cursor to the top left corner, clear screen with the color
- \r - carriage return, move cursor to the start of the line
Any color in range 0x01000000-0xFF000000 treated as a transparent which can be used for several tricks:
- *print("Hello World!", 0x000000FF, COLOR_TRANS);* - print blue "Hello World!" with transparent background color, resulting the string is printed on the existing Spider ROP loader page background
- *print("\f", COLOR_TRANS);* - fast form feed, just move cursor to the top left corner to use for the for the next iteration data output, which should avoid using transparent color because it may overlay previously printed data.
