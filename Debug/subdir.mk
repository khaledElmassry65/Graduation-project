################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../App.c \
../DIO.c \
../EXT_INT.c \
../InOut.c \
../KEYPAD.c \
../LCD.c \
../LED.c \
../MOTOR.c \
../SPI.c \
../TIMER0.c \
../UART.c 

OBJS += \
./ADC.o \
./App.o \
./DIO.o \
./EXT_INT.o \
./InOut.o \
./KEYPAD.o \
./LCD.o \
./LED.o \
./MOTOR.o \
./SPI.o \
./TIMER0.o \
./UART.o 

C_DEPS += \
./ADC.d \
./App.d \
./DIO.d \
./EXT_INT.d \
./InOut.d \
./KEYPAD.d \
./LCD.d \
./LED.d \
./MOTOR.d \
./SPI.d \
./TIMER0.d \
./UART.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


