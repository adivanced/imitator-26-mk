################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c 

OBJS += \
./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery.o \
./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_lcd.o \
./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_sdram.o 

C_DEPS += \
./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery.d \
./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_lcd.d \
./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_sdram.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32746G_Discovery/stm32746g_discovery.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c Drivers/BSP/STM32746G_Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_lcd.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.c Drivers/BSP/STM32746G_Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_sdram.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c Drivers/BSP/STM32746G_Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32746G_Discovery

clean-Drivers-2f-BSP-2f-STM32746G_Discovery:
	-$(RM) ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery.cyclo ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery.d ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery.o ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery.su ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_lcd.cyclo ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_lcd.d ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_lcd.o ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_lcd.su ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_sdram.cyclo ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_sdram.d ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_sdram.o ./Drivers/BSP/STM32746G_Discovery/stm32746g_discovery_sdram.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32746G_Discovery

