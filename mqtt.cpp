
#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "mqtt.hpp"

static struct mosquitto *mosq;

char * host;

int mqtt_create()
{
   host = getenv("MQTT_HOST");

   mosquitto_lib_init();

   mosq = mosquitto_new(NULL, true, NULL);
   if (!mosq)
   {
      fprintf(stderr, "Error creating Mosquitto instance\n");
      exit(EXIT_FAILURE);
   }

   int ret = mosquitto_connect(mosq, host, 1883, 10);
   if (ret != MOSQ_ERR_SUCCESS)
   {
      fprintf(stderr, "Error connectint to broker\n");
      exit(EXIT_FAILURE);
   }


   return 0;
}

int mqtt_loop()
{
   mosquitto_loop(mosq, 0, 1);

   return 0;
}

int mqtt_publish(const char * topic, const char * message)
{
   int ret = mosquitto_publish(mosq, NULL, topic, strlen(message), message, 0, false);
   if (ret != MOSQ_ERR_SUCCESS)
   {
      fprintf(stderr, "Error publishing message\n");
   }

   return 0;
}


int mqtt_close()
{
   mosquitto_disconnect(mosq);
   mosquitto_destroy(mosq);
   mosquitto_lib_cleanup();
   return 0;
}
