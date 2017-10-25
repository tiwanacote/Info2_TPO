################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TPO-Primitivas/cinematica.c 

OBJS += \
./TPO-Primitivas/cinematica.o 

C_DEPS += \
./TPO-Primitivas/cinematica.d 


# Each subdirectory must supply rules for building sources it contributes
TPO-Primitivas/%.o: ../TPO-Primitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/maximilano/LPCXpresso/workspace/TPO_semihosted/TPO-Headers" -I"/home/maximilano/LPCXpresso/workspace/TPO_semihosted/TPO-Headers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


