#include "sys.h"

#if 1
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
//  RCC_OscInitStruct.PLL.PLLMUL = plln;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    while(1);
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    while(1);
  }
}
#endif

#if 0
void stm32_clock_init(uint32_t plln)
{
    HAL_StatusTypeDef ret = HAL_ERROR;
    RCC_OscInitTypeDef rcc_osc_init = {0};
    RCC_ClkInitTypeDef rcc_clk_init = {0};

    rcc_osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    rcc_osc_init.HSEState = RCC_HSE_ON;
    rcc_osc_init.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    rcc_osc_init.PLL.PLLState = RCC_PLL_ON;
    rcc_osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    rcc_osc_init.PLL.PLLMUL = plln;
    ret = HAL_RCC_OscConfig(&rcc_osc_init);
    
    if (ret != HAL_OK)
    {
        while(1);
    }
    
    rcc_clk_init.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    rcc_clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    rcc_clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
    rcc_clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
    rcc_clk_init.APB2CLKDivider = RCC_HCLK_DIV1;
    ret = HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_2);
    if (ret != HAL_OK)
    {
        while(1);
    }
}
#endif

#if 0
void stm32_clock_init(uint32_t plln)
{
    HAL_StatusTypeDef ret = HAL_ERROR;
    RCC_OscInitTypeDef rcc_osc_init = {
        .OscillatorType = RCC_OSCILLATORTYPE_HSE,   // 选择时钟源--外部高速时钟
        .HSEState = RCC_HSE_ON,                     // 状态--开启时钟
        .HSEPredivValue = RCC_HSE_PREDIV_DIV1,      // 预分频系数选择  1分频
        .PLL.PLLState = RCC_PLL_ON,                 // 锁相环状态--开启
        .PLL.PLLSource = RCC_PLLSOURCE_HSE,         // 锁相环来源--外部高速时钟
        .PLL.PLLMUL = plln                          // 锁相环倍频--函数传参--也可以直接赋值
    };
    ret = HAL_RCC_OscConfig(&rcc_osc_init);
    if (ret != HAL_OK)
    {
        while(1);
    }
    RCC_ClkInitTypeDef rcc_clk_init = {
        .ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2),          // 时钟源选择,配置多个时钟
        .SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK,        // 时钟来源
        .AHBCLKDivider = RCC_SYSCLK_DIV1,               // AHB预分频系数
        .APB1CLKDivider = RCC_HCLK_DIV2,                // APB1预分频系数
        .APB2CLKDivider = RCC_HCLK_DIV1                 // APB2预分频系数
    };
    ret = HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_2);        // uint32_t FLatency    FLASH_LATENCY_2   flash速度比芯片速度慢，所以需要等待，两个周期去一个数
    if (ret != HAL_OK)
    {
        while(1);
    }
}
#endif
