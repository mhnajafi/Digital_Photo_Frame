################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/bsp_driver_sd.c \
../Src/fatfs.c \
../Src/main.c \
../Src/sd_diskio.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/bsp_driver_sd.o \
./Src/fatfs.o \
./Src/main.o \
./Src/sd_diskio.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/bsp_driver_sd.d \
./Src/fatfs.d \
./Src/main.d \
./Src/sd_diskio.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/bsp_driver_sd.o: ../Src/bsp_driver_sd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/bsp_driver_sd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/fatfs.o: ../Src/fatfs.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/fatfs.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sd_diskio.o: ../Src/sd_diskio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sd_diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/stm32f4xx_hal_msp.o: ../Src/stm32f4xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/stm32f4xx_it.o: ../Src/stm32f4xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/system_stm32f4xx.o: ../Src/system_stm32f4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/LibJPEG/include -I../Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/mhn/.stm32cubeide/Firmware/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

