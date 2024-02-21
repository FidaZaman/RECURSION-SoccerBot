// RECURSIONr-SoccerBot © 2024

//========================================
// Pinout Declarations
// -=-
// Change it according to your circuit.
// IN1 = OUT1. Same logic for other pins.
//========================================
uint8_t out1 = 4;
uint8_t out2 = 3;
uint8_t out3 = 5;
uint8_t out4 = 6;
uint8_t front_led = 7;
uint8_t back_led = 8;
uint8_t speed_left = 9;
uint8_t speed_right = 10;
uint8_t speed[11] = {50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 255}; // speed slider
//==------------------------------------==

//===================================================
// MAIN CODE
// -=-
// No changes required unless explicitely mentioned.
//===================================================
void setup()
{
    Serial.begin(9600); // By Default, HC-05 Recieves Signals in 9600 baud rate channel. Changes needed if your module uses aother channel.
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(out3, OUTPUT);
    pinMode(out4, OUTPUT);
    pinMode(front_led, OUTPUT);
    pinMode(back_led, OUTPUT);
    pinMode(speed_left, OUTPUT);
    pinMode(speed_right, OUTPUT);
}

char btSignal = 0;
void loop()
{
    if (Serial.available())
    {
        btSignal = Serial.read();
        if (btSignal != 'S')
        {
            Serial.println(btSignal);
        }
        if (btSignal == 'F')
        {
            moveForward();
        }
        else if (btSignal == 'B')
        {
            moveBackward();
        }
        else if (btSignal == 'R')
        {
            turnRight();
        }
        else if (btSignal == 'L')
        {
            turnLeft();
        }
        else if (btSignal == 'G')
        {
            moveForwardLeft();
        }
        else if (btSignal == 'I')
        {
            moveForwardRight();
        }
        else if (btSignal == 'H')
        {
            moveBackwardLeft();
        }
        else if (btSignal == 'J')
        {
            moveBackwardRight();
        }
        else if (btSignal == 'S')
        {
            stopAllMotors();
        }
        else if (btSignal == 'W')
        {
            front_led_ON();
        }
        else if (btSignal == 'w')
        {
            front_led_OFF();
        }
        else if (btSignal == 'V')
        {
            back_led_ON();
        }
        else if (btSignal == 'v')
        {
            back_led_OFF();
        }
        else if (btSignal == '0'){
            sp_0();
        }
        else if (btSignal == '1') {
            sp_1();
        }
        else if (btSignal == '2') {
            sp_2();
        }
        else if (btSignal == '3') {
            sp_3();
        }
        else if (btSignal == '4') {
            sp_4();
        }
        else if (btSignal == '5') {
            sp_5();
        }
        else if (btSignal == '6') {
            sp_6();
        }
        else if (btSignal == '7') {
            sp_7();
        }
        else if (btSignal == '8') {
            sp_8();
        }
        else if (btSignal == '9') {
            sp_9();
        }
        else if (btSignal == 'q') {
            sp_q();
        }
        else { stop(); } // Remove this if you want to stop.
    }
}
//==------------------------------------==

//=======================================================
// Motor Spin Directions
// -=-
// Test if these 6 functions works as expected.
// HIGH-LOW can be completely opposite for your circuit.
//=======================================================
void spin_right_motors()
{
    digitalWrite(out1, LOW);
    digitalWrite(out2, HIGH);
}

void reverse_spin_right_motors()
{
    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
}

void stop_right_motors()
{
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
}

void spin_left_motors()
{
    digitalWrite(out3, HIGH);
    digitalWrite(out4, LOW);
}

void reverse_spin_left_motors()
{
    digitalWrite(out3, LOW);
    digitalWrite(out4, HIGH);
}

void stop_left_motors()
{
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);
}
//==---------------------------------==

//===============================
// Moving Directions
// -=-
// No Changes required
//===============================
void moveForward()
{
    spin_right_motors();
    spin_left_motors();
}

void moveBackward()
{
    reverse_spin_right_motors();
    reverse_spin_left_motors();
}

void turnRight()
{
    reverse_spin_right_motors();
    spin_left_motors();
}

void turnLeft()
{
    spin_right_motors();
    reverse_spin_left_motors();
}

void moveForwardLeft()
{
    spin_right_motors();
    stop_left_motors();
}

void moveForwardRight()
{
    spin_left_motors();
    stop_right_motors();
}

void moveBackwardRight()
{
    reverse_spin_left_motors();
    stop_right_motors();
}

void moveBackwardLeft()
{
    reverse_spin_right_motors();
    stop_left_motors();
}

void stopAllMotors()
{
    stop_right_motors();
    stop_left_motors();
}
//==-----------------------------==


//===============================
// motor speed
// -=-
// No Changes required
//===============================
void sp_0()
{
    analogWrite(speed_left, speed[0]);
    analogWrite(speed_right, speed[0]);
}

void sp_1()
{
    analogWrite(speed_left, speed[1]);
    analogWrite(speed_right, speed[1]);
}

void sp_2()
{
    analogWrite(speed_left, speed[2]);
    analogWrite(speed_right, speed[2]);
}

void sp_3()
{
    analogWrite(speed_left, speed[3]);
    analogWrite(speed_right, speed[3]);
}

void sp_4()
{
    analogWrite(speed_left, speed[4]);
    analogWrite(speed_right, speed[4]);
}

void sp_5()
{
    analogWrite(speed_left, speed[5]);
    analogWrite(speed_right, speed[5]);
}

void sp_6()
{
    analogWrite(speed_left, speed[6]);
    analogWrite(speed_right, speed[6]);
}

void sp_7()
{
    analogWrite(speed_left, speed[7]);
    analogWrite(speed_right, speed[7]);
}

void sp_8()
{
    analogWrite(speed_left, speed[8]);
    analogWrite(speed_right, speed[8]);
}

void sp_9()
{
    analogWrite(speed_left, speed[9]);
    analogWrite(speed_right, speed[9]);
}

void sp_q()
{
    analogWrite(speed_left, speed[0]);
    analogWrite(speed_right, speed[0]);
}

void stop(){
    analogWrite(speed_left,0);
    analogWrite(speed_right, 0);
}


//==-----------------------------==

//===============================
// Utilities
// -=-
// No Changes required
//===============================
void front_led_ON()
{
    digitalWrite(front_led, HIGH);
}

void front_led_OFF()
{
    digitalWrite(front_led, LOW);
}

void back_led_ON()
{
    digitalWrite(back_led, HIGH);
}

void back_led_OFF()
{
    digitalWrite(back_led, LOW);
}

//==-----------------------------==
