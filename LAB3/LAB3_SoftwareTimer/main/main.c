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
#include "freertos/timers.h"
#include "freertos/FreeRTOSConfig.h"


// Globals
//static TimerHandle_t one_shot_timer = NULL;
static TimerHandle_t auto_reload_timer1 = NULL;
static TimerHandle_t auto_reload_timer2 = NULL;
int count_timer1 = 0;
int count_timer2 = 0;
//*****************************************************************************
// Callbacks

// Called when one of the timers expires
void myTimerCallback(TimerHandle_t xTimer) {

  // Print message if timer 1 expired
  if ((uint32_t)pvTimerGetTimerID(xTimer) == 1) {
    printf("ahihi, %d \n",count_timer1);
    count_timer1++;
    if(count_timer1 >= 10){
        xTimerStop(xTimer,0);
    }
  }

  // Print message if timer 2 expired
  if ((uint32_t)pvTimerGetTimerID(xTimer) == 2) {
    printf("ihaha, %d \n",count_timer2);
    count_timer2++;
    if(count_timer2 >= 5){
        xTimerStop(xTimer,0);
    }
  }
}


void app_main(void)
{
// Wait a moment to start
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  printf("\n");
  printf("---FreeRTOS Software Timer ---\n");

/*Create one-shot timer

    one_shot_timer = xTimerCreate(
        "One-shot timer",           //Name of timer
        2000 /portTICK_PERIOD_MS,   //Period of timer ( in ticks)
        pdFALSE,                    //Auto reload 
        (void*)0,                   //Timer ID
        myTimerCallback);           // Callback function
*/

//Create auto-reload timer1 - print "ahihi" every 2 second 
//after 10 time printing then stop
    auto_reload_timer1 = xTimerCreate(
       "Auto-reload timer 1",           //Name of timer
        2000 /portTICK_PERIOD_MS,   //Period of timer ( in ticks)
        pdTRUE,                    //Auto reload 
        (void*) 1,                   //Timer ID
        myTimerCallback);           // Callback function

//Create auto-reload timer2 - print "ihaha" every 3 second 
//after 5 time printing then stop
    auto_reload_timer2 = xTimerCreate(
       "Auto-reload timer 2",           //Name of timer
        3000 /portTICK_PERIOD_MS,   //Period of timer ( in ticks)
        pdTRUE,                    //Auto reload 
        (void*) 2,                   //Timer ID
        myTimerCallback);           // Callback function

  // Check to make sure timers were created
  if (auto_reload_timer1 == NULL || auto_reload_timer2 == NULL) {
    printf("Could not create one of the timers\n");
  } else {
    
    // Wait and then print out a message that we're starting the timers
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    printf("Starting timers...\n");

    // Start timers (max block time if command queue is full)
    xTimerStart(auto_reload_timer1, portMAX_DELAY);
    xTimerStart(auto_reload_timer2, portMAX_DELAY);
  }

  // Delete self task to show that timers will work with no user tasks
  //vTaskDelete(NULL);




    // printf("Hello world!\n");

    // /* Print chip information */
    // esp_chip_info_t chip_info;
    // esp_chip_info(&chip_info);
    // printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
    //         CONFIG_IDF_TARGET,
    //         chip_info.cores,
    //         (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
    //         (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    // printf("silicon revision %d, ", chip_info.revision);

    // printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
    //         (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    // printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());

    // for (int i = 10; i >= 0; i--) {
    //     printf("Restarting in %d seconds...\n", i);
    //     vTaskDelay(1000 / portTICK_PERIOD_MS);
    // }
    // printf("Restarting now.\n");
    // fflush(stdout);
    // esp_restart();

    
}
