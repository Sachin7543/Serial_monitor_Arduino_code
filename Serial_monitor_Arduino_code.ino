#define led_Pin1 7
#define led_Pin2 6
#define led_Pin3 5
#define led_Pin4 4
#define LED1 1
#define LED2 2
#define LED3 3
#define LED4 4
#define OFF    0
#define Start 7
#define Stop 4
#define UP_arrow 1
#define Down_arrow 2
int ledState = LOW;
unsigned long previous_value = 0;
long interval = 0;
int value = 0;
String s1;
int LED_select = 0;
void LED_state(void);
void turnOffLed(int led_pin);
int LED_intial = 0;
void setup() {

  for ( LED_intial = Start; LED_intial >= Stop ; LED_intial--)
  {
    pinMode(LED_intial, OUTPUT);
    digitalWrite(LED_intial, LOW);
  }
  Serial.begin(9600);
  Serial.println("<===============**********************============>");
  Serial.println("Author:- Sachin Patil\nTitle:- Controlling LED blinking Without using delay and For LOOP interface With USB keyborad");
  Serial.println("NOTE:- USE SERIAL MONITOR TO OPRATE THIS");
  Serial.println("<===========Welcome to LED Application============>");
  Serial.println("Please Follow below commands:\nSend 1 to glow 1st LED\nSend 2 to glow 2nd LED\nSend 3 to glow 3rd LED\nSend 4 to glow 4th LED");
  Serial.println("Send 0 to stop recently glowing LED\nSend \"delete\" to Stop all LED's\nSend \"up_arrow\" to increase blinking speed\nSend \"down_arrow\" to decrease blinking speed ");
  Serial.println("<=================================================>");

}


void loop() {
  unsigned long current_value = millis();
  if ( Serial.available() > 0)
  {
    //value = Serial.parseInt();
    s1 = Serial.readString();
    if (s1 == "1" || s1 == "2" || s1 == "3" || s1 == "4" || s1 == "0") {
      value = s1.toInt();
    }

    s1.toLowerCase();

    Serial.println("You entered : " + s1);

    if ( value == LED1 || value == LED2 || value == LED3 || value == LED4)
    {
      LED_select = value;
      Serial.println("Selected Led: " + (String)LED_select);
    }
    if  ( s1 == "delete")
    {
      for ( LED_intial = Start; LED_intial >= Stop ; LED_intial--)
      {
        digitalWrite(LED_intial, LOW);
        LED_select = 0;
      }
       Serial.println("Turned off all LED's");
    }
  }
  if ( s1 == "up_arrow" )
  {
    interval = interval + 40;
    Serial.println("Led " + (String)LED_select + " running at speed" + (String)interval);
    s1 = "";
  }
  else if ( s1 == "down_arrow")
  {
    interval = interval - 40;
    Serial.println("Led " + (String)LED_select + " running at speed" + (String)interval);
    s1 = "";
  }

  if (current_value - previous_value >= interval)
  {
    previous_value = current_value;
    switch (LED_select)
    {
      case LED1:
        LED_state();
        digitalWrite(led_Pin1, ledState);
        if ( value == OFF) {
          turnOffLed(led_Pin1);
        }
        break;
      case LED2:
        LED_state();
        digitalWrite(led_Pin2, ledState);
        if ( value == OFF) {
          turnOffLed(led_Pin2);
        }

        break;
      case LED3:
        LED_state();
        digitalWrite(led_Pin3, ledState);
        if ( value == OFF) {
          turnOffLed(led_Pin3);
        }
        break;
      case LED4:
        LED_state();
        digitalWrite(led_Pin4, ledState);
        if ( value == OFF) {
          turnOffLed(led_Pin4);
        }
        break;
    }
  }
}
void LED_state(void)
{
  if (ledState == LOW)
  {
    ledState = HIGH;
  }
  else
  {
    ledState = LOW;
  }
}

void turnOffLed(int led_pin)
{
  digitalWrite(led_pin, LOW);
  Serial.println("turned off LED: " + (String)LED_select);
  LED_select = 0;

}

