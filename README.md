# TwinkleToes

Welcome to the documentation for Twinkle Toes, a DIY audio effects pedal based on the [Daisy Seed.](https://electro-smith.com/products/daisy-seed?variant=45234245108004z) 

# Bill of Materials
| Item              | Quantity |
|-------------------|----------|
| Daisy Seed        | 1        |
| Foot Shaped PCB   | 1        |
| Potentiometer     | 1        |
| Toggle Switch     | 1        |
| LED               | 5        |
| 1kΩ Resistor      | 5        |
| 1000 uF Capacitor | 1        |
| .1 uF Capacitor   | 1        |
| 3.5mm Audio Jack  | 2        |

# Hardware

![diagram of twinkle toes](https://github.com/EinsteinUnicorn/TwinkleToes/blob/main/diagram.png)

The resistors are just current limiting resistors. You can be way more picky about choosing values to optimize for LED brightness, or you can just use a 1k resitor. 
There is a 1000uF cap at C2, and a 220uF cap at C3. The other capacitor slots are there in case you want to do additional filtering specific to your audio set up. The board works without them ;)

There are some places where the direction of the component matters. Namely the direction of the LEDs and the capacitors go. I have circles the holes where the Cathodes of the devices go. When assembling, please make sure that the short lead goes through the holes circled in Purple. 
![picture showing cathode placement](https://github.com/EinsteinUnicorn/TwinkleToes/blob/main/negatives.jpg)

Also important to note, Pin 1 on the Daisy Seed should go in the hole marked pin one. If the Daisy Seed is not aligned this was it will not work :(
![picture of pin 1](https://github.com/EinsteinUnicorn/TwinkleToes/blob/main/pin1.jpg)


# Setting up a Development Environment for the TwinkleToes

To program the TwinkleToes, you will need to set up a development environment for developing on the Daisy eed. You can find documentation on how to do that [here.](https://github.com/electro-smith/DaisyWiki/wiki/1.-Setting-Up-Your-Development-Environment)

After you set up the development environment, you can create a new project to write your own hacky software to run on the board. There is some great documentation [here](https://github.com/electro-smith/DaisyWiki/wiki/1.-Setting-Up-Your-Development-Environment#to-make-your-own-daisy-project-checkout-the-create-a-new-project-wiki-page) on how to do this. 

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
| Potentiometer   | A0  |

# Effects

This board is capable of leveraging the many different DSP techniques in the [Daisy Seed DSP library.](https://electro-smith.github.io/DaisySP/index.html) I urge anyone with this board to go through the Daisy Seed examples, and play around with what effects the board uses, and how they are used. 

