idf_component_register(
    SRCS 
        "lcd.c"
        "touch.c"
        "demo.c"
        "mqtt_relay_client.c"  # Add this line
    INCLUDE_DIRS "."
)
