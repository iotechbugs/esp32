#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "string.h"

QueueHandle_t q = NULL;

typedef struct {
	int counter;
	char value[10];
	bool status;
} sample_type;

void consumer_task(void *pvParameter) {
	if (q == NULL) {
		printf("Queue is not ready");
		return;
	}
	sample_type received_holder = { };
	while (1) {
		xQueueReceive(q, &received_holder,
				(TickType_t )(1000/portTICK_PERIOD_MS));
		printf("<<RCVD :: \t COUNTER {%d}, VALUE {%s}, STATUS {%s} \n",
				received_holder.counter, received_holder.value,
				received_holder.status ? "TRUE" : "FALSE");
		vTaskDelay(500 / portTICK_PERIOD_MS); //wait for 500 ms
	}
}

void producer_task(void *pvParameter) {
	sample_type data_holder = { };
	data_holder.counter = 0;
	strcpy(data_holder.value, "hello");
	if (q == NULL) {
		printf("Queue is not ready \n");
		return;
	}
	while (1) {
		printf("=================\n");
		printf(">>SENT ::  \t COUNTER {%d}, VALUE {%s}, STATUS {%s} \n",
				data_holder.counter, data_holder.value,
				data_holder.status ? "TRUE" : "FALSE");
		xQueueSend(q, (void* )&data_holder, (TickType_t )0); // add the counter value to the queue
		data_holder.counter++;
		data_holder.status = !data_holder.status;
		vTaskDelay(1000 / portTICK_PERIOD_MS); //wait for a second
	}
}

void app_main() {
	q = xQueueCreate(20, sizeof(sample_type));
	if (q != NULL) {
		printf("Queue is created\n");
		vTaskDelay(1000 / portTICK_PERIOD_MS); //wait for a second
		xTaskCreate(&producer_task, "producer_task", 2048, NULL, 5, NULL);
		printf("producer task  started\n");
		xTaskCreate(&consumer_task, "consumer_task", 2048, NULL, 5, NULL);
		printf("consumer task  started\n");
	} else {
		printf("Queue creation failed");
	}
}
