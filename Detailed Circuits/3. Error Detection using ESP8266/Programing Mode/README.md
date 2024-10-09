While Programming ESP8266 Board, Make sure to use a Logic Level Shifter for UART Communication

Arduino        Something to translate logic levels      ESP8266

Rx (5v)                      <--->                     Tx (3.3v)
Tx (5v)                      <--->                     Rx (3.3v)

Not having a shifter to convert the voltage levels might fry the ESP8266 Board. Simple shifter can be made with a BJT and 2 Resistors. For More Info, please refer : [Digikey - Logic Level Shifter Basics](https://www.digikey.in/en/blog/logic-level-shifting-basics)