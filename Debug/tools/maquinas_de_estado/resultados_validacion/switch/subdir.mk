################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tools/maquinas_de_estado/resultados_validacion/switch/funciones.c \
../tools/maquinas_de_estado/resultados_validacion/switch/main.c 

OBJS += \
./tools/maquinas_de_estado/resultados_validacion/switch/funciones.o \
./tools/maquinas_de_estado/resultados_validacion/switch/main.o 

C_DEPS += \
./tools/maquinas_de_estado/resultados_validacion/switch/funciones.d \
./tools/maquinas_de_estado/resultados_validacion/switch/main.d 


# Each subdirectory must supply rules for building sources it contributes
tools/maquinas_de_estado/resultados_validacion/switch/%.o: ../tools/maquinas_de_estado/resultados_validacion/switch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/maximilano/Documents/Facultad/informatica_2/Info2_TPO/TPO-Headers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


