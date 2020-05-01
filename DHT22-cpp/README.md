# DHT22 / AM2302 cpp library for ESP32 (ESP-IDF)

This is an ESP32 cpp (esp-idf) library for the DHT22 low cost temperature/humidity sensors.

Jun 2017: Ricardo Timmermann, new for DHT22. 

This lib is the cpp version of one in the DHT22 repo.

*Running DHT22*

Create folder called DTH22. In this folder run:

```
$ git clone https://github.com/gosouth/DHT22-cpp.git

$ make menuconfig and make sure to set Component config->LWIP->recv_bufsize
$ make
$ make flash monitor
```

**USE**

See main.cpp

```C
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
```


