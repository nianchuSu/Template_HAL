#include "sys.h"
#include "delay.h"

/*
模板工程已创建完成   1-2步骤必须配置
1.还需要初始化HAL库
2.设置时钟--直接调用sys.c文件函数
3.开启对应的总线时钟使能，设置IO口的属性/参数
*/
int main(void)
{
    HAL_Init();     /*初始化HAL库*/
    SystemClock_Config();   /*72MHz*/
    
    __HAL_RCC_GPIOA_CLK_ENABLE();   /*GPIOA时钟使能     再rcc.h的500行附件宏函数*/
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    /*GPIO_InitTypeDef 在gpio.c里面找*/
    GPIO_InitTypeDef gpio_pa4 = {       /*设置IO参数*/
        .Pin = GPIO_PIN_4,              /*Pin4*/
        .Mode = GPIO_MODE_OUTPUT_PP,    /*推挽输出*/
        .Pull = GPIO_NOPULL,            /*输出可以不设置这项参数，输入才需要设置*/
        .Speed = GPIO_SPEED_FREQ_HIGH   /*高速，输入不需要设置这个参数*/
    };
    HAL_GPIO_Init(GPIOA, &gpio_pa4);    /*初始化PA4引脚*/
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);     // 设置PA4输出低电平
    
    GPIO_InitTypeDef gpio_pb9 = {0};
    gpio_pb9.Pin = GPIO_PIN_9;              /*Pin9*/
    gpio_pb9.Mode = GPIO_MODE_OUTPUT_OD;    /*开漏输出*/
    gpio_pb9.Pull = GPIO_NOPULL;            /*输出可以不设置这项参数，输入才需要设置*/
    gpio_pb9.Speed = GPIO_SPEED_FREQ_LOW;   /*低速，输入不需要设置这个参数*/
    HAL_GPIO_Init(GPIOB, &gpio_pb9);    /*初始化PB9引脚*/
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);     // 设置PB9输出高电平
    
    while(1)
    {
        delay_ms(500);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);  // 翻转状态
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
        delay_ms(1000);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
    }
}
