################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TPO-Drivers/Oscilador.c \
../TPO-Drivers/TPO-CONFIG.c \
../TPO-Drivers/TPO-GPIO.c \
../TPO-Drivers/TPO-INIC.c \
../TPO-Drivers/TPO_TIMER.c \
../TPO-Drivers/cr_startup_lpc176x.c \
../TPO-Drivers/crp.c 

OBJS += \
./TPO-Drivers/Oscilador.o \
./TPO-Drivers/TPO-CONFIG.o \
./TPO-Drivers/TPO-GPIO.o \
./TPO-Drivers/TPO-INIC.o \
./TPO-Drivers/TPO_TIMER.o \
./TPO-Drivers/cr_startup_lpc176x.o \
./TPO-Drivers/crp.o 

C_DEPS += \
./TPO-Drivers/Oscilador.d \
./TPO-Drivers/TPO-CONFIG.d \
./TPO-Drivers/TPO-GPIO.d \
./TPO-Drivers/TPO-INIC.d \
./TPO-Drivers/TPO_TIMER.d \
./TPO-Drivers/cr_startup_lpc176x.d \
./TPO-Drivers/crp.d 


# Each subdirectory must supply rules for building sources it contributes
TPO-Drivers/%.o: ../TPO-Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/maximilano/Documents/Facultad/informatica_2/Info2_TPO/TPO-Headers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


