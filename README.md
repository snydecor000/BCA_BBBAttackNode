# BCA_BBBAttackNode
Rose-Hulman ECE Senior Design Project: Broadcast Confusion Attack. This repo contains the code and scripts for the BeagleBone Black (BBB) attack device.  The C code runs on the BBB's Programmable Realtime Unit (PRU)

In order to run a program on the PRU, there are a couple steps:

1. Config the input/output pins so that they are accessible by the pru.
   Do this by using the command: sudo config-pin P9.31 pruout
                             or: sudo config-pin p9.31 pruin

   In this src folder, there is a setup.sh script that should be run every
   time the BeagleBone is rebooted. It contains these setup commands

2. The program needs to be loaded into the PRU. This can be done with the
   command: make TARGET=bitBang.pru0

The program should now be running on PRU0!
