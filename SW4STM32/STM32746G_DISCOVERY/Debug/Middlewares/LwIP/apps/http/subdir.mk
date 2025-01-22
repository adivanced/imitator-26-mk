################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/apps/http/fs.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/apps/http/httpd.c 

OBJS += \
./Middlewares/LwIP/apps/http/fs.o \
./Middlewares/LwIP/apps/http/httpd.o 

C_DEPS += \
./Middlewares/LwIP/apps/http/fs.d \
./Middlewares/LwIP/apps/http/httpd.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LwIP/apps/http/fs.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/apps/http/fs.c Middlewares/LwIP/apps/http/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/apps/http/httpd.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/apps/http/httpd.c Middlewares/LwIP/apps/http/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-LwIP-2f-apps-2f-http

clean-Middlewares-2f-LwIP-2f-apps-2f-http:
	-$(RM) ./Middlewares/LwIP/apps/http/fs.cyclo ./Middlewares/LwIP/apps/http/fs.d ./Middlewares/LwIP/apps/http/fs.o ./Middlewares/LwIP/apps/http/fs.su ./Middlewares/LwIP/apps/http/httpd.cyclo ./Middlewares/LwIP/apps/http/httpd.d ./Middlewares/LwIP/apps/http/httpd.o ./Middlewares/LwIP/apps/http/httpd.su

.PHONY: clean-Middlewares-2f-LwIP-2f-apps-2f-http

