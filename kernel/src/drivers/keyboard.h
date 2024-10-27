#ifndef KEYBOARD_H
#define KEYBOARD_H
#pragma once
#include <interrupts/idt.h>

InterruptRegisters* keyboard_handler(InterruptRegisters* regs);
void keyboard_init();
#endif
