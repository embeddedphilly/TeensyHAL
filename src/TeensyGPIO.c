/************************************************************************//**
 *
 * \file TeensyGPIO.c
 *
 *
 * \brief
 *
 * \note
 *
 * \author gtrotter
 * \date Oct 25, 2015
 *
 ****************************************************************************/

/****************************************************************************
 *                              INCLUDE FILES                               *
 ****************************************************************************/
#include "TeensyGPIO.h"
#include <avr/io.h>

/****************************************************************************
 *                      PRIVATE TYPES and DEFINITIONS                       *
 ****************************************************************************/

/****************************************************************************
 *                              PRIVATE DATA                                *
 ****************************************************************************/

/****************************************************************************
 *                             EXTERNAL DATA                                *
 ****************************************************************************/

/****************************************************************************
 *                     PRIVATE FUNCTION DECLARATIONS                        *
 ****************************************************************************/

/****************************************************************************
 *                     EXPORTED FUNCTION DEFINITIONS                        *
 ****************************************************************************/

/************************************************************************//**
 * \brief Initialize an input GPIO Pin
 * \param config - Input configuration (pullup, pulldown, etc)
 *        handle - GPIO handle struct pointer
 * \return GPIO_STATUS indicating success or failure
 ****************************************************************************/
GPIO_STATUS GPIO_InitInputPin(GPIO_INPUT_CONFIG config, GPIO_HANDLE* handle)
{
    switch(handle->port)
    {
        case GPIO_PORTA:
            DDRA &= ~(handle->pin);
            break;
        case GPIO_PORTB:
            DDRB &= ~(handle->pin);
            break;
        case GPIO_PORTC:
            DDRC |= handle->pin;
            break;
        case GPIO_PORTD:
            DDRD |= handle->pin;
            break;
        case GPIO_PORTE:
            DDRE |= handle->pin;
            break;
        case GPIO_PORTF:
            DDRF |= handle->pin;
            break;
        default:
            return GPIO_STATUS_FAILURE;
    }

    return GPIO_STATUS_SUCCESS;}

/************************************************************************//**
 * \brief Initialize an output GPIO pin
 * \param config - Output configuration (on teensy, only default)
 *        handle - GPIO handle struct pointer
 * \return GPIO_STATUS indicating success or failure
 ****************************************************************************/
GPIO_STATUS GPIO_InitOutputPin(GPIO_OUTPUT_CONFIG config, GPIO_HANDLE* handle)
{
    switch(handle->port)
    {
        case GPIO_PORTA:
            DDRA |= handle->pin;
            break;
        case GPIO_PORTB:
            DDRB |= handle->pin;
            break;
        case GPIO_PORTC:
            DDRC |= handle->pin;
            break;
        case GPIO_PORTD:
            DDRD |= handle->pin;
            break;
        case GPIO_PORTE:
            DDRE |= handle->pin;
            break;
        case GPIO_PORTF:
            DDRF |= handle->pin;
            break;
        default:
            return GPIO_STATUS_FAILURE;
    }

    return GPIO_STATUS_SUCCESS;
}

/************************************************************************//**
 * \brief Set the value of an output pin (must initialize first)
 * \param val - set value for pin
 *        handle - GPIO handle struct pointer
 * \return GPIO_STATUS indicating success or failure
 ****************************************************************************/
GPIO_STATUS GPIO_SetOutput(GPIO_VALUE val, GPIO_HANDLE* handle)
{
    switch(handle->port)
    {
        case GPIO_PORTA:
        {
            //check if set as ouput
            if (DDRA & handle->pin)
            {
                if(val == GPIO_HIGH)
                {
                    PORTA |= handle->pin;
                }
                else if(val == GPIO_LOW)
                {
                    PORTA &= ~(handle->pin);
                }
                return GPIO_STATUS_SUCCESS;
            }
            else
            {
                return GPIO_STATUS_FAILURE;
            }
        }
        case GPIO_PORTB:
        {
            //check if set as ouput
            if (DDRB & handle->pin)
            {
                if(val == GPIO_HIGH)
                {
                    PORTB |= handle->pin;
                }
                else if(val == GPIO_LOW)
                {
                    PORTB &= ~(handle->pin);
                }
                return GPIO_STATUS_SUCCESS;
            }
            else
            {
                return GPIO_STATUS_FAILURE;
            }
        }
        case GPIO_PORTC:
        {
            //check if set as ouput
            if (DDRC & handle->pin)
            {
                if(val == GPIO_HIGH)
                {
                    PORTC |= handle->pin;
                }
                else if(val == GPIO_LOW)
                {
                    PORTC &= ~(handle->pin);
                }
                return GPIO_STATUS_SUCCESS;
            }
            else
            {
                return GPIO_STATUS_FAILURE;
            }
        }


        case GPIO_PORTD:
        {
            //check if set as
            if (DDRD & handle->pin)
            {
                if(val == GPIO_HIGH)
                {
                    PORTD |= handle->pin;
                }
                else if(val == GPIO_LOW)
                {
                    PORTD &= ~(handle->pin);
                }
                return GPIO_STATUS_SUCCESS;
            }
            else
            {
                return GPIO_STATUS_FAILURE;
            }
        }
        case GPIO_PORTE:
        {
            //check if set as ouput
            if (DDRE & handle->pin)
            {
                if(val == GPIO_HIGH)
                {
                    PORTE |= handle->pin;
                }
                else if(val == GPIO_LOW)
                {
                    PORTE &= ~(handle->pin);
                }
                return GPIO_STATUS_SUCCESS;
            }
            else
            {
                return GPIO_STATUS_FAILURE;
            }
        }
        case GPIO_PORTF:
        {
            //check if set as ouput
            if (DDRF & handle->pin)
            {
                if(val == GPIO_HIGH)
                {
                    PORTF |= handle->pin;
                }
                else if(val == GPIO_LOW)
                {
                    PORTF &= ~(handle->pin);
                }
                return GPIO_STATUS_SUCCESS;
            }
            else
            {
                return GPIO_STATUS_FAILURE;
            }
        }
        default:
            break;
    }
    return GPIO_STATUS_FAILURE;
}

/************************************************************************//**
 * \brief Get value of an input pin (must be initialized first)
 * \param handle - GPIO handle struct pointer
 * \return GPIO_VALUE indicating current level of input pin
 ****************************************************************************/
GPIO_VALUE GPIO_GetValue(GPIO_HANDLE* handle)
{
    switch(handle->port)
    {
        case GPIO_PORTA:
        {
            //check direction
            if (DDRA & handle->pin)
            {
                return PORTA & handle->pin ? GPIO_HIGH: GPIO_LOW;
            }
            else
            {
                return PINA & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
        }
        case GPIO_PORTB:
        {
            //check direction
            if (DDRB & handle->pin)
            {
                return PORTB & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
            else
            {
                return PINB & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
        }
        case GPIO_PORTC:
        {
            //check direction
            if (DDRC & handle->pin)
            {
                return PORTC & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
            else
            {
                return PINC & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
        }
        case GPIO_PORTD:
        {
            //check direction
            if (DDRD & handle->pin)
            {
                return PORTD & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
            else
            {
                return PIND & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
        }
        case GPIO_PORTE:
        {
            //check direction
            if (DDRE & handle->pin)
            {
                return PORTE & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
            else
            {
                return PINE & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
        }
        case GPIO_PORTF:
        {
            //check direction
            if (DDRF & handle->pin)
            {
                return PORTF & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
            else
            {
                return PINF & handle->pin? GPIO_HIGH: GPIO_LOW;
            }
        }
        default:
            break;
    }
    return GPIO_LOW;
}

/************************************************************************//**
 * \brief Configure an interrupt pin
 * \param config - when does this interrupt occur (rising edge, falliing edge, etc)
 *        cb - a function pointer that will get called when the interrupt occurs
 *        params - any necessary parameters to this function (NULL for no params)
 *        handle - a GPIO handle struct pointer
 * \return GPIO_STATUS indicating success or failure
 ****************************************************************************/
GPIO_STATUS GPIO_ConfigureInterrupt(GPIO_INTERRUPT_CONFIG config, InterruptCallback cb,
    void * params, GPIO_HANDLE * handle)
{
    return GPIO_STATUS_FAILURE;
}

/****************************************************************************
 *                     PRIVATE FUNCTION DEFINITIONS                         *
 ****************************************************************************/

/************************************************************************//**
 * \brief
 * \param
 * \return
 ****************************************************************************/

/** \}*/
