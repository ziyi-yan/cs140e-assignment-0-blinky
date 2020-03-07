#define GPIO_BASE (0x3F000000 + 0x200000)

volatile unsigned *GPIO_FSEL1 = (volatile unsigned *)(GPIO_BASE + 0x04);
volatile unsigned *GPIO_SET0 = (volatile unsigned *)(GPIO_BASE + 0x1C);
volatile unsigned *GPIO_CLR0 = (volatile unsigned *)(GPIO_BASE + 0x28);

static void spin_sleep_us(unsigned int us)
{
  for (unsigned int i = 0; i < us * 6; i++)
  {
    asm volatile("nop");
  }
}

static void spin_sleep_ms(unsigned int ms)
{
  spin_sleep_us(ms * 1000);
}

int main(void)
{
  // STEP 1: Set GPIO Pin 16 as output.
  *GPIO_FSEL1 = (1 << (6 * 3)); // set FSEL16 as 0b001

  // STEP 2: Continuously set and clear GPIO 16.
  for (;;)
  {
    *GPIO_SET0 = (1 << 16); // set GPIO 16
    spin_sleep_ms(100);
    *GPIO_CLR0 = (1 << 16); // clear GPIO 16
    spin_sleep_ms(100);
  }
}
