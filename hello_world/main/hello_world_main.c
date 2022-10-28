/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

// void app_main(void)
// {
//     printf("Hello world!\n");

//     /* Print chip information */
//     esp_chip_info_t chip_info;
//     esp_chip_info(&chip_info);
//     printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
//             CONFIG_IDF_TARGET,
//             chip_info.cores,
//             (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
//             (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

//     printf("silicon revision %d, ", chip_info.revision);

//     printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
//             (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

//     printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());

//     for (int i = 10; i >= 0; i--) {
//         printf("Restarting in %d seconds...\n", i);
//         vTaskDelay(1000 / portTICK_PERIOD_MS);
//     }
//     printf("Restarting now.\n");
//     fflush(stdout);
//     esp_restart();
// }

TaskHandle_t handler;
void print_id(void *pvParameter){
    while(1){
        printf("DUONG GIA AN : %d \n",1952163);
        vTaskDelay(1000/portTICK_PERIOD_MS);

    }
    vTaskDelete(NULL);

}

void blinky(void *pvParameter){
    while(1){
        printf("Press Button\n");
        int  rd = rand() % (5000 + 1 - 0) + 0;
        vTaskDelay(rd /portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}


void app_main(){
    xTaskCreate(&print_id, "print_id", 2048, NULL, 5, NULL);
    xTaskCreate(&blinky, "blinky", 2048,NULL,0,NULL );
    
    for (int i = 20; i >= 0; i--) {
        printf("Remaing %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    fflush(stdout);
    esp_restart();
}