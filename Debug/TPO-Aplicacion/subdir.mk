################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TPO-Aplicacion/TPO-Aplicacion.c 

OBJS += \
./TPO-Aplicacion/TPO-Aplicacion.o 

C_DEPS += \
./TPO-Aplicacion/TPO-Aplicacion.d 


# Each subdirectory must supply rules for building sources it contributes
TPO-Aplicacion/%.o: ../TPO-Aplicacion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/maximiliano/Documents/Info_II/Info2_TPO/TPO-Headers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


