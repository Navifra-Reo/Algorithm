#define LED1 22
#define LED2 23
#define LED3 24
#define LED4 25
#define btn
void setup()
{
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    attachInterrupt(0, readSerial, RISING);
    Serial.begin(9600);
}
void loop() {}

void _delay(int ms)
{
    int count = 0;
    while (count != ms)
    {
        delayMicroseconds(1000);
        count++;
    }
}
void readSerial()
{
    while (Serial.available() > 0)
    {
        int cmd = Serial.read();
        if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4')
        {
            cmd = cmd - '1' + 22;
            digitalWrite(cmd, HIGH);
            _delay(50);
            digitalWrite(cmd, LOW);
            _delay(50);
            Serial.println(cmd);
        }
    }
}
