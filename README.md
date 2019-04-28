# inputShieldProtection
This is shield for the Arduino Nano meant to provide automatic level shifting and DUT protection and the main purpose is to use this in conjunction with the [JTAGENUM](https://github.com/cyphunk/JTAGenum) project.  
The idea and basic are taken from the Input Shield protection found [here](https://github.com/dxa4481/inputProtectionShield),
but it's been updated to use available components.  

As the version from dxa4481 the capabilities are: 
- Input level conversion, including a range from 1.8-5v logic
- Input protection with current limiting and schottky diode array

To use the shield all you have to do is to connect the GND of the arduino to a common ground with the DUT and the REF to the voltage reference of the DUT.
The boards levels the ardiono's pins from 2 to 9 and the pin are marked on the pcb.


# Folder Structure
- **schematics**: contains the Eagle project files
- **exports**: contains the schematics in pdf and the top/bottom of the board
- **boms**: contains the long and short bill of material, the first one is useful during assembly, the second to order the parts

# Short bom

|   Part   |     Value     | Count |       Device       |     Package      |
|----------|---------------|-------|--------------------|------------------|
| IC       | NUP4304MR6T1G |     2 | NUP4304MR6T1G      | SOT95P275X110-6N |
| Mosfet   | BSS138        |     8 | MOSFET-NCHANNELSMD | SOT23-3          |
| Resistor | 1k            |     8 | R-US_R0402         | R0402            |
| Resistor | 10k           |    16 | R-US_R0402         | R0402            |


# Board Layers
| Top Layer                   | Bottom Layer                  |
| :-------------------------: | :-------------------------: |
| ![](exports/board-top.png)   | ![](exports/board-bottom.png) |


# Building the board
I've ordered the boards from OSHPARK, you can find the link to the project [here](https://oshpark.com/shared_projects/XDcR2eJg).  
The cost of a single unit should be around 6 euro, but consider that given the shipping cost of the component, 
the fact that oshpark as a minimum order quantity of 3, I ended up building 3 of this.  
For the Reference Voltage connector (REF) I suggest to use right angle strip connector, at least it is working well for me.  

# Testing the board
You can test the board by flashing the Arduino Sketch test_shield.ino in this repository and connecting the REF to the 3.3v of the Arduino.  
The sketch will allow you to cycle the pins and will read the voltage value from the pin A2 , or you can use a multimeter since all the pins are in a HIGH state.  
