#include "adc.h"

void adc_init()
{
    /*AVcc = +5V = Vref*/
    ADMUX = 1<<REFS0;   

    /* Enable ADC and set Prescalr to 2 */
    ADCSRA = (1<<ADEN)|(7<<ADPS0);
}

uint16_t adc_read(uint8_t channel)
{
    /*Select ADC Channel: must be 0-7*/
  //  ADMUX &= 0xF8;
    channel = channel & 0b00000111;
    ADMUX |= channel;

    /*start single Conversion*/
    ADCSRA |= 1<<ADSC;

    /*wait for conversion to complete*/
    while(!(ADCSRA & (1<<ADIF)));

    /*Clear ADIF by writing one to it*/
    ADCSRA |= (1<<ADIF);

    return(ADC);
}