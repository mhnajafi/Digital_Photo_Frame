################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src/diskio.c \
C:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src/ff.c \
C:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
C:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src/option/syscall.c 

OBJS += \
./Middlewares/FatFs/diskio.o \
./Middlewares/FatFs/ff.o \
./Middlewares/FatFs/ff_gen_drv.o \
./Middlewares/FatFs/syscall.o 

C_DEPS += \
./Middlewares/FatFs/diskio.d \
./Middlewares/FatFs/ff.d \
./Middlewares/FatFs/ff_gen_drv.d \
./Middlewares/FatFs/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FatFs/diskio.o: C:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src/diskio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/FatFs/diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/ff.o: C:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src/ff.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/FatFs/ff.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/ff_gen_drv.o: C:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/FatFs/ff_gen_drv.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/syscall.o: C:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src/option/syscall.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/FatFs/syscall.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

