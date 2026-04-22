#include <stdio.h>

#include <QuadratureDecoder.h>


int main()
{
    stdio_init_all();

    QuadratureDecoder decoder;
    int32_t lastCounter = 0;


    // Configure the pins connected to the encoder to be inputs with no pull-up or pull-down as my encoders already
    // had external pull-ups on the hall effect sensors.
    const uint pinBase = 2;

    // Initialize the PIO to count the quadrature encoder ticks in the background.
    decoder.init(pio0);
    int32_t index = decoder.addQuadratureEncoder(pinBase);

    // Dump the encoder counts encountered during a fixed interval.
    absolute_time_t nextSampleTime = get_absolute_time();
    while (1)
    {
        if (time_reached(nextSampleTime)) {
            nextSampleTime = make_timeout_time_ms(100);
            int32_t currCounter = decoder.getCount(index);
            int32_t deltaCounter = currCounter - lastCounter;
            lastCounter = currCounter;
            printf("curr: %ld, delta: %ld\n", currCounter, deltaCounter);
        }
        sleep_us(0); // yield to pico sdk so printf works
    }
}
