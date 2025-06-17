<!--
# Button-Debouncing

## Overview

Button debouncing is a crucial technique in embedded systems and hardware interfacing to ensure reliable detection of button presses. Mechanical buttons often generate noisy signals due to physical bouncing, resulting in multiple unwanted transitions (false triggers) when a button is pressed or released. This project provides a simple and effective software-based solution for debouncing button inputs using C++.

## Features

- **Software Debouncing:** Implements a robust algorithm to filter out noise from mechanical button presses.
- **C++ Implementation:** Written in standard C++ for portability and ease of integration.
- **Customizable Parameters:** Allows adjustment of debounce timing to suit different hardware and application requirements.
- **Lightweight:** Minimal resource usage, suitable for micro-controllers and embedded systems.

## How It Works

The debouncing algorithm samples the button state at regular intervals. It only registers a button press or release after the input has remained stable for a specified debounce period. This prevents false triggers caused by rapid, unintended transitions.

## Usage

1. **Integrate the Debounce Logic:** Include the debounce code in your project.
2. **Configure Timing:** Set the debounce interval according to your hardware's characteristics (typically 10-50ms).
3. **Read Button State:** Use the provided interface to check for debounced button events in your main loop or interrupt handler.

## Example

This is a simple button debouncing software implementation using C++ to noisy button presses.
