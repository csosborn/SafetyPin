SafetyPin
=========

High level type-safe handling of Arduino pins

What is it?
-----------

The SafetyPin library is a set of classes that wrap Arduino pins and provide easy read/write methods. Their purpose is twofold:

 * **syntactic sugar**: The basic Arduino API is just a step above the bare metal, and leaves ample room for useful abstraction. Why do this:

    ```Cpp
    const int ledPinNum = 5;
    setPinMode(ledPinNum, output);
    digitalWrite(ledPinNum, true);
    ```    
    ... when you could do this instead?
    
    ```Cpp 
    DigitalOut ledPin(5);
    ledPin.high();
    ```

 * **type safety**: Pins aren't all created equal. In the physical world of your circuit pins tend to be either inputs or outputs, and mixing them up can be electrically unpleasant. Likewise, most Arduino libraries which use pins in some form don't just want any old generic pins. They want pins configured in specific ways and hopefully hooked up to things that won't emit blue smoke when the power comes on. By taking SafetyPin references rather than integers (the more common practice), a library can be explicit about how it intends to use the pin. This makes it much less likely that you will accidentally get your integers mixed up and damage your Arduino. If you accidentally provide an input pin where an output is expected your sketch simply won't compile. Try the same mistake with raw integers and you may burn out a chip.


Classes
-------

### Pin

Abstract base class from which all concrete SafetyPin classes inherit. It stores the actual wrapped pin number and provides an ```(int)``` cast operator for backwards compatibility. 

Since ```Pin``` instances represent real physical world objects that can't just be cloned, there is no good reason to copy pins or pass them by value. ```Pin``` thus declares private copy constructor and assignment operator methods to prevent inadvertent proliferation.

### DigitalOut

Wraps a pin configured for output and provides digital output methods.

**Synopsis:**

```Cpp
DigitalOut(byte pin);   // Constructor

void low();             // Set the pin low    
void high();            // Set the pin high    
void write(bool value); // Set the pin to the given logical value
        
bool read();            // Read the current pin state
```

### PwmOut 

Wraps a pin configured for output and provides a method to set the PWM-encoded output value.

You may reasonably ask why this isn't called "AnalogOut", since it wraps the Arduino's ```analogWrite``` method. The answer is that it isn't an analog voltage output, which is what people normally think of when they think analog, and cannot be used in the same fashion: one could drive a motor with PWM or bias an amplifier with an analog voltage, but not vice versa. It is entirely possible that future Arduino hardware might include true steady-state analog voltage output pins for which the name ```AnalogOut``` would be much more appropriate.

**Synopsis:**

```Cpp
PwmOut(byte pin);       // Constructor

void write(byte value); // Set the pin's analog value, to be approximated using PWM.
```
    
### AnalogIn

Wraps a pin configured for input and provides a method to read its analog input value.

**Synopsis:**

```Cpp
AnalogIn(byte pin);
    
unsigned int read();
```