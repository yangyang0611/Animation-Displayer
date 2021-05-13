# Animation-Controller
## A. System function and principle explanation
The system function is to play the story content.
The dot matrix is used as the screen of the story book, the UART is used as the text of the story, and the ADC is used to control the number of pages.

## B. System Environment and Target
- Environment: MPLAB
- Target: xc8

## C. Demo video: https://youtu.be/1ZEaAyQWCzQ

## D. Appearance:
![](https://i.imgur.com/73gXQOJ.jpg)
<img src="https://i.imgur.com/73gXQOJ.jpg" width="800" height="600"/>

![](https://i.imgur.com/Aeak4lX.jpg)

![](https://i.imgur.com/h9vgquR.jpg)

## E. Circuit Diagram:
![](https://i.imgur.com/jNgUHhG.png)

![](https://i.imgur.com/AGMBnX1.png)

## F. Flow Chat:
![](https://i.imgur.com/1QwORoL.jpg)

## G. System development tools, materials and techniques
- Tools: MPLAB, Pickit4 burner, PIC18f4520 chip, 8x8 point matrix, variable resistor, 
- TTL line, breadboard
- Technique: Interrupt is generated by rotating the variable resistor, and in the interrupt service routine, the ADRES value is used to change the graphical position. By calculating the rotation range of the variable resistor, the pattern generated by the matrix in that range is matched with the UART to generate the corresponding text description on the screen.

## H. Peripheral Interface or Library and API Usage Description
- Interrupt: UART CCP
- UART: Use UART to output text.
- ADC: Use the interval from 0 to 255 to control the story picture flow f. Actual team members' division of work

## I. Difficulties encountered and how to solve them
### 1. Sound synchronization problem
The original intention was to play the sound effect synchronously with the animation movement by connecting the external speaker, but due to the sound
sound in the playback will encounter a lot of delay problems, it cannot keep up with the synchronization signal. The attempts are failed

### 2. PORT sharing problem
The dot matrix has two pin pins connected to another PORT

### 3. ADC and UART interrupt conflict with each other
Direct fusion reads the ADC value, then determines and outputs it to the UART.

### 4. Pushbuttons
At the beginning of the design concept, we intend to use the button to trigger the Interrupt generation. We try to connect  the button to the interrupt pin (RB0), we couldn't get the program to enter the interrupt service routine. Therefore, we use an ad converter to replace the button. 

### 5.The dot matrix screen flashes.
While each picture is in the matrix switching process, we use delay function to control the time differences. Since the switching operation is wrapped in a while loop, the while loop will continue until the next picture is transferred. We tried to extend the delay rate or shorten the frequency, still couldn't solve the problem. Finally the screen stopped blinking when pair with UART.

### 6. Unable to generate random numbers
Since C++ cannot randomize the numbers in MPLAB, the only solution is to write a very large array to access random variables.

### 7. Damaged pin and socket cables
When connecting to an external device, it is common that the device fails to operate successfully. In order to catch the problem,  we often use a multimeter(三用電表) to determine the power on each wire.
