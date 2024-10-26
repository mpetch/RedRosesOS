#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <include/constants.h>
#include <drivers/disk/fat.h>
#include <memory_management/pmm.h>
#include <c_programs/shell.h>
#include <drivers/keyboard.h>
#include <multitasking/multitasking.h>
#include <sprint.h>

extern Task other_task;
extern void task_create(Task *task, void (*main)());
void wrapper_function(void (*entry_point)()) {
    entry_point();
    come_back();
}

void execute_flat_binary(const char* path) {
    char* the_binary = readfile_into_buffer(path);
    __asm__ volatile(
        "movq %0, %%rax\n"
        "call *%%rax\n"
        :
        : "r"(the_binary)
        : "%rax"
    );
}



