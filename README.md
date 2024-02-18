# SOCCER BOT

### Specifications

- Board: Arduino Uno
- Bluetooth module: HC-05
- motor driver: L298n
- led

### Circuit:

Two positive end of each side's two motor is shorted to form one single positive end. Same approach is made for negative ends. and two connection for speed control. Pinout Table:

| Motor | Motor Driver | Arduino pin |
| ---- | ---- | ---- |
| Right Positive End | OUT1 | 4 |
| Right Negative End | OUT2 | 3 |
| Left Positive End | OUT4 | 6 |
| Left Negative End | OUT3 | 5 |
| Left Motor Speed | ENA | 9 |
| Right Motor Speed | ENB | 10 |
| Front LED | - | 7 |
| Back LED | - | 8 |

### Diagram
![Circuit diagram](https://github.com/FidaZaman/RECURSION-SoccerBot/assets/88763525/c0edbad6-573e-40bc-a5a3-611c5eb5c94d)


### Movement Logic
|Direction|Right side motors|left side motor|
|---|---|---|
|Forward|On|On|
|Backward|On(reverse)|On(reverse)|
|Turn Left|On|On(reverse)|
|Turn Right|On(reverse)|On|
|Forward Left|On|Off|
|Forward Right|Off|On|


|Backward Left|On(reverse)|Off|
|Backward Right|Off|On(reverse)|

### speed table
| speed {0-q} | analog outout |
| ---- | ---- |
| 0 | 50 |
| 1 | 70 |
| 2 | 90 |
| 3 | 110 |
| 4 | 130 |
| 5 | 150 |
| 6 | 170 |
| 7 | 190 |
| 8 | 210 |
| 9 | 230 |
| q | 255 |

To customize, follow the instructions written in code comments.
