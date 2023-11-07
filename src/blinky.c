#define GPIOA 0xEF0
#define GPIOB 0xEF4

int delayMs(int ms);
int write_digit(int digit, int position);
int mod(int a, int b);
int div(int a, int b);
int mult(int a, int b);
int display_number(int number);

int main() {
    int value = 0;
    int* gpio_a = GPIOA;
    *(gpio_a) = 0x0000FF00;

    while(1)
    {
        for(int k = 0;k < 1000;k++)
        {
            for(int i = 0;i < 1500;i++)
            {
                display_number(k);
            }
        }
        
    }
}

int mod(int a, int b)
{
    return a - mult(b, div(a,b));
}

int mult(int a, int b)
{
    int value = 0;
    for(int i = 0;i < b;i++)
    {
        value += a;
    }
    return value;
}

int div(int a, int b)
{
    int value = 0;
    while(a >= b)
    {
        a -= b;
        value++;
    }
    return value;
}

int write_digit(int digit, int position)
{
    // Determining which Cathodes Should Be Set
    int value = 0;
    int anode = 0;
    
    // Determining Position
    if(position == 0)       anode = 0b00000000000000001111111000000000;
    else if(position == 1)  anode = 0b00000000000000001111110100000000;
    else if(position == 2)  anode = 0b00000000000000001111101100000000;
    else if(position == 3)  anode = 0b00000000000000001111011100000000;
    else if(position == 4)  anode = 0b00000000000000001110111100000000;
    else if(position == 5)  anode = 0b00000000000000001101111100000000;
    else if(position == 6)  anode = 0b00000000000000001011111100000000;
    else                    anode = 0b00000000000000000111111100000000;

    // Determining Digit
    if(digit == 0)          value = 0b00000000000000000000000011000000;
    else if(digit == 1)     value = 0b00000000000000000000000011111001;
    else if(digit == 2)     value = 0b00000000000000000000000010100100;
    else if(digit == 3)     value = 0b00000000000000000000000010110000;
    else if(digit == 4)     value = 0b00000000000000000000000010011001;
    else if(digit == 5)     value = 0b00000000000000000000000010010010;
    else if(digit == 6)     value = 0b00000000000000000000000010000010;
    else if(digit == 7)     value = 0b00000000000000000000000011111000;
    else if(digit == 8)     value = 0b00000000000000000000000010000000;
    else                    value = 0b00000000000000000000000010011000;

    // Determining Return Value
    int return_value = anode | value;

    // Returning
    return return_value;
}

int delayMs(int ms)
{
    int i, j, k = 0;
    for(i = 0;i < ms;i++){
        for(j=0;j < 3;j++){
            k = j;
        }}
    return k;
}

int display_number(int number)
{
    int* gpio_a = GPIOA;
    int current_num = number;
    for(int i = 0;i < 8;i++)
    {
        *(gpio_a) = write_digit(mod(current_num, 10), i);
        current_num = div(current_num, 10);
        delayMs(1);
    }
}