# IR-Remote-Controlled-RGB-LED
An infrared home-automation project that decodes unique IR remote control pulse signals to dynamically change colors and scale the active brightness multiplier of a common-cathode RGB LED.

---
## Demo
![Project Demo](RGB_IR.gif)

---
## Component List
* 1x Arduino Uno (or compatible microcontroller)

* 1x RGB LED (Common Cathode)

* 1x VS1838B Infrared (IR) Receiver Module

* 1x IR Remote Controller (NEC Protocol)

* 3x 330Ω Resistors (one for each color channel)

* Bread Board & Jumper Wires

---
## How It Works
The system relies on the `IRremote.hpp` library to sample and translate optical pulses into data packets. The code locks into an idle loop until a packet drops, using `IrReceiver.decode() == 0`.

Inside the execution `loop()`:

* The raw address signal is isolated via `IrReceiver.decodedIRData.decodedRawData` and stored inside a hex-formatted tracking variable (`myCode`).

* Conditional blocks check the code against known key assignments (e.g., `0xB946FF00` for Red).

* Color profiles are loaded as raw brightness bounds (`0` to `255`), while volume buttons modify a floating-point dimming scaling multiplier variable (`dFact`).

* The final mixed color values are mathematically adjusted and emitted to the pins using `analogWrite(pin, rBright * dFact)`. `IrReceiver.resume()` is then called to handle the next button press.

---
## Concepts Covered
* **Infrared Protocol Demodulation:** Tracking modulated $38\text{ kHz}$ optical pulse structures and converting them into hexadecimal command variables.

* **Hexadecimal Communication Mapping:** Processing complex 32-bit hardware addresses (`0x...`) directly within standard control flows.

* **Proportional Scaling Adjustments:** Applying floating-point coefficient modifiers (`dFact`) to adjust mixed color outputs evenly.

* **Receiver State Buffering:** Safely halting hardware state registers and clearing internal storage arrays using library commands like `resume()`.

---
## Skills
`Wireless Packet Capturing` `Hexadecimal Address Parsing` `Mathematical Value Factoring` `Library Buffer Resets`
