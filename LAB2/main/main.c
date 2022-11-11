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
void vTaskFunction(void *pvParameters)
{
    char *pcTaskName;
    const TickType_t xDelay250ms = pdMS_TO_TICKS(250);

    /* The string to print out is passed in via the parameter .
    Cast this to a character pointer . */
    pcTaskName = (char *)pvParameters;
    /* As per most tasks , this task is implemented in
    an infinite loop . */
    for (;;)
    {
        /* Print out the name of this task . */
        printf(pcTaskName);
        //printf("Hello");

        /* Delay for a period . This time a call to vTaskDelay ()
         is used which places the task into the Blocked state
         until the delay period has expired . The parameter takes
         a time specified in " ticks " , and the pdMS_TO_TICKS () macro
         is used ( where the xDelay250ms constant is declared ) to
        convert 250 milliseconds into an equivalent time in ticks .*/
        vTaskDelay(xDelay250ms);
    }
    vTaskDelete(NULL);
}

void vTaskFunction1(void *pvParameters)
{
    char *pcTaskName;
    const TickType_t xDelay500ms = pdMS_TO_TICKS(500);

    /* The string to print out is passed in via the parameter .
    Cast this to a character pointer . */
    pcTaskName = (char *)pvParameters;
    /* As per most tasks , this task is implemented in
    an infinite loop . */
    for (;;)
    {
        /* Print out the name of this task . */
        printf(pcTaskName);
        //printf("Hello");

        /* Delay for a period . This time a call to vTaskDelay ()
         is used which places the task into the Blocked state
         until the delay period has expired . The parameter takes
         a time specified in " ticks " , and the pdMS_TO_TICKS () macro
         is used ( where the xDelay250ms constant is declared ) to
        convert 250 milliseconds into an equivalent time in ticks .*/
        vTaskDelay(xDelay500ms);
    }
    vTaskDelete(NULL);
}
static const char *pcTextForTask1 = "Task 1 is running \r\n";
static const char *pcTextForTask2 = "Task 2 is running \r\n";
static const char *pcTextForTask0 = "Task 0 is running \r\n";

void app_main(void)
{
    // printf("Hello world!\n");

    // /* Print chip information */
    // esp_chip_info_t chip_info;
    // esp_chip_info(&chip_info);
    // printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
    //        CONFIG_IDF_TARGET,
    //        chip_info.cores,
    //        (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
    //        (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    // printf("silicon revision %d, ", chip_info.revision);

    // printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
    //        (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    // printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());

    // // for (int i = 10; i >= 0; i--) {
    // //     printf("Restarting in %d seconds...\n", i);
    // //     vTaskDelay(1000 / portTICK_PERIOD_MS);
    // // }
    // // printf("Restarting now.\n");
    // // fflush(stdout);
    // // esp_restart();

    printf("===============\n");

    /* Create the first task at priority 1.
 The priority is the second to last parameter . */
    xTaskCreate(vTaskFunction1, " Task 1", 2048,
                (void *)pcTextForTask1, 1, NULL);

    /* Create the second task at priority 2 ,
     which is higher than a priority of 1.
     The priority is the second to last parameter . */
    xTaskCreate(vTaskFunction, " Task 2", 2048,
                (void *)pcTextForTask2, 0, NULL);

    xTaskCreate(vTaskFunction, " Task 0 Ilde", 2048,
                (void *)pcTextForTask0, 0, NULL);
    /* Start the scheduler so the tasks start executing . */
    //vTaskStartScheduler();

    /* Will not reach here . */
}
