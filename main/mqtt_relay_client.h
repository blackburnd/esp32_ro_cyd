#ifndef MQTT_RELAY_CLIENT_H
#define MQTT_RELAY_CLIENT_H

#include <stdbool.h>
#include <stdint.h>

// We don't need to include the full ESP-IDF MQTT header in our interface
// Just forward declare the essential types we need
typedef struct esp_mqtt_client* esp_mqtt_client_handle_t;
typedef struct esp_mqtt_event_t* esp_mqtt_event_handle_t;

/**
 * @brief Initialize the MQTT client
 * 
 * @return true if initialization was successful, false otherwise
 */
bool mqtt_init(void);

/**
 * @brief Check if MQTT client is connected
 * 
 * @return true if connected, false otherwise
 */
bool mqtt_is_connected(void);

/**
 * @brief Publish the state of a relay to MQTT
 * 
 * @param relay_num Relay number (1-6)
 * @param state Relay state (true = ON, false = OFF)
 */
void mqtt_publish_relay_state(uint8_t relay_num, bool state);

/**
 * @brief Publish the state of all relays
 */
void mqtt_publish_all_relay_states(void);

// Callback for external state changes (e.g. from Home Assistant)
typedef void (*mqtt_state_change_callback_t)(uint8_t relay_num, bool state);

// Function to register a state change callback
void mqtt_register_state_change_callback(mqtt_state_change_callback_t callback);

#endif /* MQTT_RELAY_CLIENT_H */