# Multi-purpose IoT-Crate
The crate (printed in PLA, prototyped in cardboard) features:
 - A Digital Clock;
 - A Bluetooth Speaker¹;
 - Wireless communication between 2 Crates²;
 - Pomodoro Timer and Alarm;


### Speaker¹:
The speaker is an 8Ω 32w SAMCO, but it can be any 8Ω speaker. It is connected to the 13th digital pin in the Arduino and to the bluetooth module as shown in /Speaker/circuit.png.
### Wireless Communication²:
This a feature requested by my mother so she can communicate with me while I'm at my office. The communication is currently made between 2 NRF24L01 radio modules and the speaker¹ can play a music (and, in the future, live mic sounds)
to warn something to one side of the communications that can send other signal to stabilish conection.


## 📍
In this repository you'll find the codes for each feauture plus the hole integrated code for the Arduino UNO R3;
