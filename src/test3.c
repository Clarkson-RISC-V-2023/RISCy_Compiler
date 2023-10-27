//IEEE754
#define FLOAT_1 0x40490fd0
#define FLOAT_2 0x3f99999a

float get_float(int val);

int main() {
    float x = get_float(FLOAT_1);
    float y = get_float(FLOAT_2);

    float z = x + y;

    return 0;
}

float get_float(int val)
{
    // Getting the Current Value at 0x0
    int* tmp_int = 0;
    float* tmp_float = 0;
    int curr_int = *tmp_int;

    // Setting/Reading the value
    *tmp_int = val;
    float tmp = *(tmp_float);

    // Returning the Memory Configuration
    *tmp_int = curr_int;

    // Returning the constructed float
    return tmp;
}