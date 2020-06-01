//#define configUSE_IDLE_HOOK   0
#include <Arduino_FreeRTOS.h>

#include <avr/io.h>
#include <util/delay.h>

#define MS_DELAY 3000


// define two tasks for Blink & AnalogRead
void TaskOn( void *pvParameters );
void TaskNoop( void *pvParameters );



int main (void) {
    /*Set to one the fifth bit of DDRB to one
    **Set digital pin 13 to output mode */    
    DDRB |= _BV(DDB5);

  xTaskCreate(
    TaskOn
    ,  "TaskOn"   // A name just for humans
    ,  100  //Stack size ... This was adjusted according to the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  xTaskCreate(
    TaskNoop
    ,  "TaskNoop"
    ,  100// This was adjusted according to the Stack Highwater
    ,  NULL
    ,  0  // Priority
    ,  NULL );

    vTaskStartScheduler();
    while(1) {

    }
}

void loop() {}

void TaskOn(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  for (;;) // A Task shall never return or exit.
  {
            /*Set to one the fifth bit of PORTB to one
        **Set to HIGH the pin 13 */
        PORTB |= _BV(PORTB5);

        /*Wait 3000 ms */
        _delay_ms(MS_DELAY);

        /*Set to zero the fifth bit of PORTB
        **Set to LOW the pin 13 */
        PORTB &= ~_BV(PORTB5);

        /*Wait 3000 ms */
        _delay_ms(MS_DELAY);
    
  }
}

void TaskNoop(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  for (;;) // A Task shall never return or exit.
  {
            /*Set to one the fifth bit of PORTB to one
        **Set to HIGH the pin 13 */
//        PORTB |= _BV(PORTB5);
//
//        /*Wait 3000 ms */
//        _delay_ms(MS_DELAY);
//
//        /*Set to zero the fifth bit of PORTB
//        **Set to LOW the pin 13 */
//        PORTB &= ~_BV(PORTB5);
//
//        /*Wait 3000 ms */
//        _delay_ms(MS_DELAY);
    
  }
}
