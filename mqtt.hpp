
#ifndef MQTT_HPP_INCLUDED
#define MQTT_HPP_INCLUDED


int mqtt_create();
int mqtt_loop();
int mqtt_publish(const char * topic, const char * message);
int mqtt_close();

#endif // end of MQTT_HPP_INCLUDED
