# Self Balancing Cube
Embedded code for a self balancing cube using reaction wheels.

## TODOs
- Add liscence
- Add CMSIS drivers as a submodule
- Add debugging conveinence scripts

## Design
For the project structure I chose to do keep things fairly bare metal. I really dislike the amount of code that the STM32CubeMX generates. As I understand, it's mostly for portability and robustness, but I'd rather know exactly what my code is doing, and keep things minimal. Hence you will see a lot of hand rolled functions resembling a HAL. This is to keep things simple, lean and easy to keep track of. It also means that I can comfortably develop in my own enviroments. Jumping between VSCode for debugging and Neovim for writing code. I don't expect this code to be on any boards except for the STM32F411 (Black Pill) so its another reason for me not to rely on that bloated ass HAL from ST. 
