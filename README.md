# TwinkleToes

Welcome to the documentation for Twinkle Toes, a DIY audio effects pedal based on the [Daisy Seed.](https://electro-smith.com/products/daisy-seed?variant=45234245108004z) 

# Hardware
Here is a diagram of the board:

![diagram of twinkle toes](https://github.com/EinsteinUnicorn/TwinkleToes/blob/main/diagram.png)

The resistors are just current limiting resistors. You can be way more picky about choosing values to optimize for LED brightness, or you can just use a 1k resitor. 
There is a 1000uF cap at C1, and a .1uF cap at C3. 

# Setting up a Development Environment for the TwinkleToes

To program the TwinkleToes, you will need to set up a development environment for developing on the Daisy eed. You can find documentation on how to do that [here.](https://github.com/electro-smith/DaisyWiki/wiki/1.-Setting-Up-Your-Development-Environment)

After you set up the development environment, you can create a new project to write your own hacky software to run on the board. There is some great documentation [here] (https://github.com/electro-smith/DaisyWiki/wiki/1.-Setting-Up-Your-Development-Environment#to-make-your-own-daisy-project-checkout-the-create-a-new-project-wiki-page) on how to do this. 

You can now program Twinkle Toes just like you would a Daisy Seed, with some hardware already wired to certain pins. There is also space for you to access the Daisy Seed I/O should you want to repurpose the board 😙

# Hardware Map

|                 | Pin |
|-----------------|-----|
| Toggle Switch   | D25 |
| Big Toe LED     | D20 |
| Index Toe LED   | D21 |
| Middle Toe LED  | D22 |
| Ring Toe LED    | D23 |
| Pinky Toe LED   | D24 |
| Potentiometer   |     |

# Effects

This board is capable of leveraging the many different DSP techniques in the [Daisy Seed DSP library.](https://electro-smith.github.io/DaisySP/index.html) I urge anyone with this board to go through the Daisy Seed examples, and play around with what effects the board uses, and how they are used. 

# Thank You's

There are many people who helped make this project possible. I would like to thank them all here. 

Thank you to Dave Darko who introduced me to xhain, the community where this project spawned from.
Thank you to Winny Li for designing the graphic for this board. 
Thank you to Aisler for sponsoring the initial run of this board 🟢
Thank you to Jason Garwood for designing the diagram, and co-creating the previous iterations of this project with me. 
Thank you to Rowan Dunlop for introducing me to the Pittsburgh Sound Preserve, where the initial testing of previous iterations of this project happened, and for helping with prior iteratons of the board. 
Thank you to the folks at Carnegie Mellon University for supporting the initial research on music effects, including my research advisor Tom Zajdel, and my mentor Jesse Styles. 
