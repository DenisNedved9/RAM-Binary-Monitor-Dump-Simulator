A lightweight C application that simulates real-time memory allocation, random data population, and concurrent binary and formatted text memory logging.

Problem & Purpose

In embedded systems and low-level debugging, monitoring raw system RAM states requires exporting binary memory dumps alongside human-readable text logs. Reading hex or raw byte buffers directly from memory and persisting them efficiently to storage is a core task in real-time embedded diagnostics.

This tool solves this challenge by providing:

Dynamic Memory Allocation: Allocates a 1 KB simulated RAM block using malloc on the heap.

Periodic RAM Dumps: Generates pseudo-random byte data and flushes the buffer state every 500ms.

Dual Output Logging: Writes raw byte streams directly to a binary file (ram_data.bin) via fwrite() while formatting a readable 16-byte-wide grid in Ram_data.txt.

File Overview

RAM.c — Main simulator program managing heap memory allocation, random byte generation, and file dumping loops.

Ram_data.txt — Human-readable text log containing formatted 16-byte row memory dumps.

ram_data.bin — Raw binary file output representing the live memory dump.
