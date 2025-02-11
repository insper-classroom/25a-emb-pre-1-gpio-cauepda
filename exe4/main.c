#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int led_R = 5;
const int led_P = 8;
const int led_B = 11;
const int led_Y = 15;
const int BTN = 28;

int main() {
  stdio_init_all();

  gpio_init(led_R);
  gpio_init(led_P);
  gpio_init(led_B);
  gpio_init(led_Y);
  gpio_init(BTN);

  gpio_set_dir(led_R, GPIO_OUT);
  gpio_set_dir(led_P, GPIO_OUT);
  gpio_set_dir(led_B, GPIO_OUT);
  gpio_set_dir(led_Y, GPIO_OUT);
  gpio_set_dir(BTN, GPIO_IN);

  gpio_pull_up(BTN);

  while (true) {
    if (!gpio_get(BTN)) {
      gpio_put(led_R, 1);
      sleep_ms(300);
      gpio_put(led_R, 0);
      gpio_put(led_P, 1);
      sleep_ms(300);
      gpio_put(led_P, 0);
      gpio_put(led_B, 1);
      sleep_ms(300);
      gpio_put(led_B, 0);
      gpio_put(led_Y, 1);
      sleep_ms(300);
      gpio_put(led_Y, 0);
      while (!gpio_get(BTN)) {};
    }

  }
}
