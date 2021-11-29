/**
 * @file project_main.c
 * @author Bharath.G ()
 * @brief Project to Blink an LED at 1000ms ON and 500 ms OFF Interval
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"

#include "user_utils.h"
#include "blinky.h"
#include "adc.h"

static void gpio_config()
{
	/* Configure LED Pin */
	DDRB |= (1 << DDB1);

}

/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void)
{
	gpio_config();
	adc_init();
}

void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}


/**
 * @brief Main function where the code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 */
int main(void)
{
	/* Initialize Peripherals */
	peripheral_init();
	
	int adc_val = adc_read(0);
	int delay = 1;
	
	for(;;) // while(1)
	{
		adc_val = adc_read(0);

		if(adc_val >= 100)
			delay = 4;
		else
			delay = 1;
		
        change_led_state(LED_ON);
		delay_ms(LED_ON_TIME/delay);
		
        change_led_state(LED_OFF);
		delay_ms(LED_OFF_TIME/delay);	
	}
	return 0;
}
