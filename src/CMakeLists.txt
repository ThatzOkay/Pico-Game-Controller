add_executable(Pico_Game_Controller
        pico_game_controller.c
        usb_descriptors.c
        led_strip.cpp)

target_include_directories(Pico_Game_Controller PRIVATE ${CMAKE_CURRENT_LIST_DIR})

pico_generate_pio_header(Pico_Game_Controller ${CMAKE_CURRENT_LIST_DIR}/encoders.pio)
target_sources(Pico_Game_Controller PRIVATE pico_game_controller.c)

target_link_libraries(Pico_Game_Controller PRIVATE
        pico_multicore
        pico_stdlib
        tinyusb_device
        tinyusb_board
        hardware_pio
        hardware_dma
        hardware_irq
        PicoLed)

pico_add_extra_outputs(Pico_Game_Controller)

if(PICO_BOARD STREQUAL "pico2")
    set(UF2_OUTPUT_NAME "Pico_Game_Controller_Pico2.uf2")
else()
    set(UF2_OUTPUT_NAME "Pico_Game_Controller.uf2")
endif()

add_custom_command(TARGET Pico_Game_Controller
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/src/Pico_Game_Controller.uf2 ${PROJECT_SOURCE_DIR}/build_uf2/${UF2_OUTPUT_NAME}
)
