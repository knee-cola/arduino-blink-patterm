This is an Arduino sketch (program) which blinks the built-in LED at a given pattern.

Blinking is done with minimal impact on `loop()` performance since it doesn't use `delay`.

This example is based on the official Arduino *Blink* example.

# How to use
Download it, open it in Arduino IDE, upload it to your Arduino (or any compatible board) and run it.

# Customization
Source contains two example patterns: `blinkPattern1` and `blinkPattern2`.

First try editing `loop()` function and making it use the second pattern:
```C
loop() {

//  blinkLed(LED_BUILTIN, blinkPattern1, blinkPattern1Len);
  blinkLed(LED_BUILTIN, blinkPattern2, blinkPattern2Len);
}
```

When you have that working try defining your own pattern.

# License
This code is released into public domain the same way as the original example was.
