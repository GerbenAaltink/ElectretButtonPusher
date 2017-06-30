#include <Servo.h>
Servo motor;

int servo_pin = 9;
int button_pin = 2;
int led_pin = 13;

int servo_release_value = 70;
int servo_push_value = 95;

int electred_port = A0;
int volume_level = 620;
int sound_duration = 150;

int delay_before_press = 4000;
int delay_press = 1000;
int delay_after_press = 5000;

void setup() {
  motor.attach(servo_pin);

  // Make sure in idle mode (so not pressing a button)
  servo_release();

  // Show the world the device is on
  digitalWrite(led_pin, HIGH);
}

void servo_release()
{
  motor.write(servo_release_value);
}
void servo_push()
{
  motor.write(servo_push_value);
}

void loop() {
  int value = analogRead(electred_port);
  if(value > volume_level)
  {
      // Wait for while (to avoid trigger on short peak sound)
      delay(sound_duration);
      if(value > volume_level)
      {
        
        // Device where this script was intended for does not like direct pushes..
        delay(delay_before_press);
        servo_push();
        
        // Hold the button for a while
        delay(delay_press);
        
        // Release button and wait a while
        servo_release();
        delay(delay_after_press);
      }
   }
}
