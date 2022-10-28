#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"


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