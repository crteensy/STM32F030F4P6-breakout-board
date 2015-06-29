# STM32F030F4P6-breakout-board
STM32F030F4P6 breakout board pcb files and example code

Hackaday.io project: https://hackaday.io/project/4277-stm32f030f4p6-breakout-board  
(includes link to OSH Park for bare PCBs)

## Code::Blocks project
This repo includes a Code::Blocks project file which is pre-configured. However, it needs some adjustments to your own environment. These are the necessary steps:
* make sure then libopencm3 has been compiled as per their instructions
* correctly configure your compiler. The project looks for a compiler named "gcc-arm-none-eabi 4.9 2015q2". If you want to use a different one, change the project's top-level compiler to that.
* in the project's "Build Settings"->"Custom Variables": update the variable opencm3root to point at your libopencm3 root directory. Compiler and linker search paths use that variable.
* (optional) create a template: "File"->"Save Project as Template..."

The template (if you have created one; see the last step above) can then reused from within C::B's project wizard: "File"->"New"->"From Template" or "File"->"New"->"Project"->"User Templates"
