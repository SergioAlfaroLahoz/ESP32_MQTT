#include <Arduino.h>

#include "config.h"
#include "WiFi_client.hpp"
#include "MQTT_client.hpp"

void setup() {
    Serial.begin(115200);

    wifiConnection();

    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
}

void loop() {

    if(!client.connected()){
        reconnect();
    }

    if (client.connected()){
        String str = "counter -> " + String(count);
        str.toCharArray(msg,25);
        client.publish(root_topic_publish,msg);
        count++;
        delay(300);
    }

    delay(300);
    client.loop();
}

