#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA (1<<5)

void mcDelay(int length);
void xmit_H_char();
void xmit_U_char();
void xmit_A_char();
void xmit_N_char();
void xmit_space_btwn_chars();

//int counter = 0;

/*==============================================================
Name: mcDelay
Parameter: length - delay length. This is a multiple of 1000000.
           For example, length = 2 means a delay of 2000000.
Return: None
================================================================*/
void mcDelay(int length) {
  int len = length > 0 ? length : 1;
  int period = 1000000 * len;
  volatile int counter = 0;
  while (counter < period) {
    counter++;
  }
}

/*==============================================================
Name: xmit_H_char - Display Morse Code of the letter "H".
      H: on off on off on off on off
Parameter: None
Return: None
================================================================*/
void xmit_H_char() {
  int num_xmit;
  
  for (num_xmit = 0; num_xmit < 4; num_xmit++) {
    // GPIOA_ODR |= 0x00000020;
    GPIOA_ODR |= GPIOA;
    mcDelay(1);
    
    // GPIOA_ODR &= 0xFFFFFFDF;
    GPIOA_ODR &= ~GPIOA;
    mcDelay(1);
  }
}

/*==============================================================
Name: xmit_U_char - Display Morse Code of the letter "U".
      U: on off on off on on on off
Parameter: None
Return: None
================================================================*/
void xmit_U_char() {
  int num_xmit;
  
  for (num_xmit = 0; num_xmit < 3; num_xmit++) {
    // GPIOA_ODR |= 0x00000020;
    GPIOA_ODR |= GPIOA;
    
    if (num_xmit < 2) {
      mcDelay(1);
    } else {
      mcDelay(3);
    }
    
    // GPIOA_ODR &= 0xFFFFFFDF;
    GPIOA_ODR &= ~GPIOA;
    mcDelay(1);
  }
}

/*==============================================================
Name: xmit_A_char - Display Morse Code of the letter "A".
      A: on off on on on off
Parameter: None
Return: None
================================================================*/
void xmit_A_char() {
  int num_xmit;
  
  for (num_xmit = 0; num_xmit < 2; num_xmit++) {
    // GPIOA_ODR |= 0x00000020;
    GPIOA_ODR |= GPIOA;
    
    if (num_xmit < 1) {
      mcDelay(1);
    } else {
      mcDelay(3);
    }
    
    // GPIOA_ODR &= 0xFFFFFFDF;
    GPIOA_ODR &= ~GPIOA;
    mcDelay(1);
  }
}

/*==============================================================
Name: xmit_N_char - Display Morse Code of the letter "N".
      N: on on on off on off
Parameter: None
Return: None
================================================================*/
void xmit_N_char() {
  int num_xmit;
  
  for (num_xmit = 0; num_xmit < 2; num_xmit++) {
    // GPIOA_ODR |= 0x00000020;
    GPIOA_ODR |= GPIOA;
    
    if (num_xmit < 1) {
      mcDelay(3);
    } else {
      mcDelay(1);
    }
    
    // GPIOA_ODR &= 0xFFFFFFDF;
    GPIOA_ODR &= ~GPIOA;
    mcDelay(1);
  }
}

/*==============================================================
Name: xmit_space_btwn_chars - Display Morse Code of the space
      between two characters.
      space: off off off
Parameter: None
Return: None
================================================================*/
void xmit_space_btwn_chars() {
  // GPIOA_ODR &= 0xFFFFFFDF;
  GPIOA_ODR &= ~GPIOA;
  mcDelay(3);
}

int main()
{
   // RCC Base Address: 0x40023800
   // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
   // Address offset: 0x30
   // Write: 0x1
   // 1. Enable clock to Peripheral
   RCC_AHB1ENR |= 0x1;
  
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
  
   //volatile int counter;
   
   int xmit_times = 3;
   /* -------------------
      H: dot dot dot dot
      space: dot dot dot
      U: dot dot dash
      space: dot dot dot
      A: dot dash
      space: dot dot dot
      N: dash dot

      H: on off on off on off on off
      space: off off off
      U: on off on off on on on off
      space: off off off
      A: on off on on on off
      space: off off off
      N: on on on off on off
    */
   
   while (xmit_times > 0) {
     mcDelay(1);
     xmit_H_char();
     xmit_space_btwn_chars();
     xmit_U_char();
     xmit_space_btwn_chars();
     xmit_A_char();
     xmit_space_btwn_chars();
     xmit_N_char();
     xmit_times--;
     mcDelay(6);
   }
   
   return 0;
}
