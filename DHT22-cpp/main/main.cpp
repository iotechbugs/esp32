#include <esp_log.h>
#include <string>
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "rom/ets_sys.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#include "DHT.h"

extern "C" {
	void app_main(void);
}

void DHT_task(void *pvParameter)
{

	DHT dht;
	dht.setDHTgpio( (gpio_num_t)4 );
		printf( "Starting DHT Task\n\n");

		while(1) {

			printf("=== Reading DHT ===\n" );
			int ret = dht.readDHT();

			dht.errorHandler(ret);

			printf( "Hum %.1f\n", dht.getHumidity() );
			printf( "Tmp %.1f\n", dht.getTemperature() );

			// -- wait at least 2 sec before reading again ------------
			// The interval of whole process must be beyond 2 seconds !!
			vTaskDelay( 3000 / portTICK_RATE_MS );
		}
}

void app_main()
{
	nvs_flash_init();
	vTaskDelay( 1000 / portTICK_RATE_MS );
	xTaskCreate( &DHT_task, "DHT_task", 2048, NULL, 5, NULL );
}


