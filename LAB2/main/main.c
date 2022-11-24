/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

/* Link to FreeRTOSconfig.h = C:\Espressif\frameworks\esp-idf-v4.4.2\components\freertos\include\esp_additions\freertos
    Link git for overide.h = https://github.com/espressif/esp-idf/issues/8345
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "freertos/FreeRTOSConfig.h"



TaskHandle_t Sender = NULL;
TaskHandle_t Receiver1 = NULL;
TaskHandle_t Receiver2 = NULL;
QueueHandle_t queue1,queue2;
typedef struct
{
int eDataID;
int lDataValue;
} Data_t;
void SendTask(void *arg)
{	srand(time(NULL));

    Data_t sendData;
    queue1 = xQueueCreate(5, sizeof(Data_t));
    queue2 = xQueueCreate(5, sizeof(Data_t));
    int r;

    if (queue1 == 0)
    {
     printf("Failed to create queue= %s\n", "queue1");
    }

    if (queue2 == 0)
    {
     printf("Failed to create queue= %s\n", "queue2");
    }

    for(;;){
    	r = rand()% 3;
    	printf("r is %d:  ",r);
		sendData.eDataID = rand()%5;
		sendData.lDataValue= rand()%10;
    	if(r == 1){
    		xQueueSend(queue1, &sendData, (TickType_t)0);
    	}
		else if(r == 2){
			xQueueSend(queue2, &sendData, (TickType_t)0);
    	}
    	else{
    		printf ("%s \n", "Error");
    	}
        vTaskDelay(1000/ portTICK_RATE_MS);
    }
}

void ReceiveTask1(void *arg)
{
    Data_t rxData;
    while(1){
     if( xQueueReceive(queue1, &rxData, (TickType_t)5))
     {
      printf("Received data from queue1 == %d\n", rxData.lDataValue);
      vTaskDelay(1000/ portTICK_RATE_MS);
     }
    }
}
void ReceiveTask2(void *arg)
{
    Data_t rxData ;
    while(1){
     if( xQueueReceive(queue2, &rxData, (TickType_t)5))
     {
	  printf("Received data from queue2 == %d\n", rxData.lDataValue);
      vTaskDelay(1000/ portTICK_RATE_MS);
     }
    }
}
void app_main(void)
{
   xTaskCreate(SendTask, "SendTask", 4096, NULL, 10, &Sender);
   xTaskCreatePinnedToCore(ReceiveTask1, "ReceiveTask1", 4096, NULL,10, &Receiver1, 1);
   xTaskCreatePinnedToCore(ReceiveTask2, "ReceiveTask2", 4096, NULL,10, &Receiver2, 1);

}
