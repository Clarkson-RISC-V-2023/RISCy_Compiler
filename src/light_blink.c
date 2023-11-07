#define GPIOA 0xEF0

int delayMs(int ms);

int main() {
    
    // Setting Up the GPIO Register and Storage Value
    int* gpio_a = GPIOA;
    int value = 0;
    *(gpio_a) = 0x55550000;

    while(1)
    {
        // value = *(gpio_a);
        *(gpio_a) = *(gpio_a) ^ 0xFFFF0000;
        delayMs(1000);
    }
}

int delayMs(int ms)
{
    int i, j, k = 0;
    for(i = 0;i < ms;i++){
        for(j=0;j < 1500;j++){
            k = j;
        }}
    return k;
}