################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/api_lib.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/api_msg.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/err.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/netbuf.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/netdb.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/netifapi.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/sockets.c \
/home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/tcpip.c 

OBJS += \
./Middlewares/LwIP/Api/api_lib.o \
./Middlewares/LwIP/Api/api_msg.o \
./Middlewares/LwIP/Api/err.o \
./Middlewares/LwIP/Api/netbuf.o \
./Middlewares/LwIP/Api/netdb.o \
./Middlewares/LwIP/Api/netifapi.o \
./Middlewares/LwIP/Api/sockets.o \
./Middlewares/LwIP/Api/tcpip.o 

C_DEPS += \
./Middlewares/LwIP/Api/api_lib.d \
./Middlewares/LwIP/Api/api_msg.d \
./Middlewares/LwIP/Api/err.d \
./Middlewares/LwIP/Api/netbuf.d \
./Middlewares/LwIP/Api/netdb.d \
./Middlewares/LwIP/Api/netifapi.d \
./Middlewares/LwIP/Api/sockets.d \
./Middlewares/LwIP/Api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LwIP/Api/api_lib.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/api_lib.c Middlewares/LwIP/Api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Api/api_msg.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/api_msg.c Middlewares/LwIP/Api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Api/err.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/err.c Middlewares/LwIP/Api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Api/netbuf.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/netbuf.c Middlewares/LwIP/Api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Api/netdb.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/netdb.c Middlewares/LwIP/Api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Api/netifapi.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/netifapi.c Middlewares/LwIP/Api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Api/sockets.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/sockets.c Middlewares/LwIP/Api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LwIP/Api/tcpip.o: /home/adivanced/Documents/STM32Projects/LwIP_HTTP_Server_Netconn_RTOS/Middlewares/Third_Party/LwIP/src/api/tcpip.c Middlewares/LwIP/Api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCOVERY -c -I../../../Inc -I../../../Src -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/Components -I../../../Middlewares/Third_Party/LwIP/src/include -I../../../Middlewares/Third_Party/LwIP/system -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Middlewares/Third_Party/FreeRTOS/Source -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Utilities -I../../../Utilities/Log -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-LwIP-2f-Api

clean-Middlewares-2f-LwIP-2f-Api:
	-$(RM) ./Middlewares/LwIP/Api/api_lib.cyclo ./Middlewares/LwIP/Api/api_lib.d ./Middlewares/LwIP/Api/api_lib.o ./Middlewares/LwIP/Api/api_lib.su ./Middlewares/LwIP/Api/api_msg.cyclo ./Middlewares/LwIP/Api/api_msg.d ./Middlewares/LwIP/Api/api_msg.o ./Middlewares/LwIP/Api/api_msg.su ./Middlewares/LwIP/Api/err.cyclo ./Middlewares/LwIP/Api/err.d ./Middlewares/LwIP/Api/err.o ./Middlewares/LwIP/Api/err.su ./Middlewares/LwIP/Api/netbuf.cyclo ./Middlewares/LwIP/Api/netbuf.d ./Middlewares/LwIP/Api/netbuf.o ./Middlewares/LwIP/Api/netbuf.su ./Middlewares/LwIP/Api/netdb.cyclo ./Middlewares/LwIP/Api/netdb.d ./Middlewares/LwIP/Api/netdb.o ./Middlewares/LwIP/Api/netdb.su ./Middlewares/LwIP/Api/netifapi.cyclo ./Middlewares/LwIP/Api/netifapi.d ./Middlewares/LwIP/Api/netifapi.o ./Middlewares/LwIP/Api/netifapi.su ./Middlewares/LwIP/Api/sockets.cyclo ./Middlewares/LwIP/Api/sockets.d ./Middlewares/LwIP/Api/sockets.o ./Middlewares/LwIP/Api/sockets.su ./Middlewares/LwIP/Api/tcpip.cyclo ./Middlewares/LwIP/Api/tcpip.d ./Middlewares/LwIP/Api/tcpip.o ./Middlewares/LwIP/Api/tcpip.su

.PHONY: clean-Middlewares-2f-LwIP-2f-Api

