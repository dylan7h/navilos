cmake_minimum_required(VERSION 3.15)

# =========================================
# Set Toolchain & Option
# =========================================
set(CMAKE_TOOLCHAIN_FILE            "CMake/toolchain.cmake")
set(CMAKE_USER_MAKE_RULES_OVERRIDE  "CMake/toolchain.cmake")

# =========================================
# Display Makefile Message
# =========================================
set(CMAKE_VERBOSE_MAKEFILE          ON)

# =========================================
# Set Target Board Inforamtion
# =========================================
set(TARGET_BOARD    "rvpb")

# =========================================
# Describe project information.
# =========================================
project(
    # Project Name
    navilos
    # Version <Major>.<Minor>.<Patch>.<Tweak>
    VERSION         0.0.0.1
    # Language Information
    LANGUAGES       ASM C
)
set(CMAKE_EXE_LINKER_FLAGS "")

# =========================================
# Export Compile Commands
# =========================================
set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)

# =========================================
# Change Default Build Result Path
# =========================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY          "${CMAKE_HOME_DIRECTORY}/build/DebugRel")    # *.exe | *.out | *.elf | *.axf | *.dll | *.so
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY          "${CMAKE_HOME_DIRECTORY}/build/DebugRel")    # *.dll.a | *.so.a
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY          "${CMAKE_HOME_DIRECTORY}/build/DebugRel")    # *.lib | *.a

# =========================================
# Compile Option
# =========================================
list(APPEND CFLAGS  -std=c11)
list(APPEND CFLAGS  -Wall)

# =========================================
# Linker Option
# =========================================
list(APPEND LDFLAGS -nostartfiles)
list(APPEND LDFLAGS -nostdlib)
list(APPEND LDFLAGS -nodefaultlibs)
list(APPEND LDFLAGS -static)

# =========================================
# Library Link Option
# =========================================
list(APPEND LIBS -lgcc)

# =========================================
# Include Path Lists
# =========================================
list(APPEND INC_DIRS "include")
list(APPEND INC_DIRS "hal")
list(APPEND INC_DIRS "hal/${TARGET_BOARD}")
list(APPEND INC_DIRS "lib")

# =========================================
# Linker Script Path
# =========================================
set(LINKER_SCRIPT   "${CMAKE_HOME_DIRECTORY}/navilos.ld")

# =========================================
# Map file Path
# =========================================
set(MAP_FILE        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/navilos.map")

# =========================================
# ASM Source Lists
# =========================================
# boot
list(APPEND ASM_SRCS "boot/Entry.S")

# =========================================
# C Source Lists
# =========================================
# boot
list(APPEND C_SRC    "boot/Main.c")
# hal/rvpb
list(APPEND C_SRC    "hal/rvpb/Regs.c")
list(APPEND C_SRC    "hal/rvpb/Uart.c")
# lib
list(APPEND C_SRC    "lib/stdio.c")

# =========================================
# Set Executable Target
# =========================================
# AXF File
add_executable(${CMAKE_PROJECT_NAME} ${ASM_SRCS} ${C_SRC})
# Extract Binary From AXF File
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND ${CMAKE_OBJCOPY} -O binary ${CMAKE_PROJECT_NAME}.axf ${CMAKE_PROJECT_NAME}.bin
)

# =========================================
# Include Path
# =========================================
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${INC_DIRS})

# =========================================
# Compiler Option
# =========================================
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
    -mcpu=${CMAKE_SYSTEM_PROCESSOR}
    ${CFLAGS}
)

# =========================================
# Linker Option
# =========================================
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    -n -T ${LINKER_SCRIPT}
    -Wl,-Map=${MAP_FILE} ${LDFLAGS}
)

# =========================================
# Library Link
# =========================================
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LIBS})

# =========================================
# Set debug Target
# =========================================
add_custom_target(debug DEPENDS ${CMAKE_PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND qemu-system-arm -M realview-pb-a8 -kernel ${CMAKE_PROJECT_NAME}.axf -S -gdb tcp::9200,ipv4
)

# =========================================
# Set run Target
# =========================================
add_custom_target(run DEPENDS ${CMAKE_PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND qemu-system-arm -M realview-pb-a8 -kernel ${CMAKE_PROJECT_NAME}.axf -nographic
)

# =========================================
# Set gdb Target
# =========================================
add_custom_target(gdb DEPENDS ${CMAKE_PROJECT_NAME}
    COMMAND ${CMAKE_GDB}
)
