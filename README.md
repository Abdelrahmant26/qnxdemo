# QNX Color Cycle Demo

A simple demonstration program for QNX RTOS that cycles through red, green, and blue colors every 6 seconds.

## Description

This program creates a fullscreen window and continuously cycles through colors. It demonstrates basic QNX Screen Graphics Subsystem usage, including window creation, buffer management, and color rendering.

### What It Does

- Creates a fullscreen window using QNX Screen API
- Fills the entire screen with a solid color
- Wait for 2 seconds and cycle to the next color.
- Updates display at ~60 FPS

## Compilation

### Cross-Compilation (from development host)

For ARM 64-bit (Raspberry Pi 4):
```bash
qcc -Vgcc_ntoaarch64le -o color_cycle mydemo.c -lscreen
```
