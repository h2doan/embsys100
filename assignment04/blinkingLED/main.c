#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))

#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA (1<<5)

// bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number x 4)
//               = 0x42000000 + (0x20014 x 32) + (5 x 4)
#define GPIOA_ODR_BB (*(unsigned int*)(0x42000000 + (0x20014 * 32) + (5 * 4)))

int counter = 0;
int main()
{
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Write: 0x1
    // 1. Enable clock to Peripheral
    //RCC_AHB1ENR |= 0x1;
   (*(unsigned int*)(0x42000000 + (0x23830 * 32) + (0 * 4))) = 0x1;
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Write: 0x400
  // 2. Set GPIO5 to Output
  GPIOA_MODER |= 0x400;

// GPIOA Base Address: 0x40020000
// GPIO port output data register (GPIOx_ODR) (x = A..E and H)
// Address offset: 0x14
// Write: 0x20
  // 3. Write 1 or 0 to turn ON/OFF LED
  
  volatile int counter;
  
  while(1)
  {
    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
//    GPIOA_ODR |= 0x00000020;
//    GPIOA_ODR |= GPIOA;
    GPIOA_ODR_BB = 0x1;

    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
//    GPIOA_ODR &= 0xFFFFFFDF;
//    GPIOA_ODR &= ~GPIOA;
    GPIOA_ODR_BB = 0x0;
  }
  return 0;
}
