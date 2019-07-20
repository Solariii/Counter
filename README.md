In this project it is required to implement a counter system. The counter system main components
are:
1. Tiva C board
2. 3 seven-segment displays (count from 000 to 999)
3. 3 push buttons (increment by 1, decrement by 1, reset to 000)
4. Battery to power all components
5. Power switch (on/off) to enable/disable power of the entire system including Tiva C


The operation mode of push buttons should follow these rules:



|  operation| event| description|
| ----------|:-----| -----:|
|Increment|While pressing|If the user is pressing the push button, the number on the display should increase but with a delay of 0.2 seconds. So, you need to check every 0.2 seconds if the user is still pressing the switch then increment by 1|
|Decrement|On press event|If the user presses the button, the number displayed is decremented by 1 only and no matter how long the user keeps pressing the push button nothing should happen|
|Reset|On release event|If the user presses the button and no matter how long the button is pressed, nothing should happen until the button is released then the display isreset to 000|

