# BeepyBoi

A low-level alarm for a granule hopper. A proximity sensor mounted on a resin bin triggers a horn to alert workers when the hopper is running low, and a push button lets them silence the horn for 5 minutes while they deal with it.

Built for Barrett Plastics. Project started 7/1/2022; code written 7/14/2022. Current version: **alpha v0.1**.

## How it works

- A **Pepperl+Fuchs proximity sensor** is mounted on the bin (a 3D-printed housing uses the sensor as its mount) and monitors the material level.
- A **horn** sounds to signal a low hopper condition.
- An **Arduino** controls the horn through a **5 V relay wired normally closed (NC)**:
  - **Relay off (default):** the NC contact stays closed, so the alarm path is live and the horn can sound.
  - **Button pressed:** the Arduino energizes the relay, which opens the contact and silences the horn. After **5 minutes**, it returns to normal.

The sketch itself never reads the sensor. It only handles the mute button and the relay.

## Parts

| Part | Notes |
|---|---|
| Arduino Uno, Nano, or Mega (ATmega2560) | Any of the three works; the schematic draws a Mega |
| Pepperl+Fuchs 210621 proximity sensor | 10-36 V DC, load output < 100 mA |
| Pepperl+Fuchs VAZ-HORN-70MM-85dBa | 85 dB horn |
| 5 V relay (NC/NO) | The NC contact is used |
| Momentary push button | Mutes the horn |
| 3D-printed housing | Mounted using the sensor |

## Wiring

**Arduino pins**

| Pin | Connected to |
|---|---|
| D7 | Push button (other side to GND; uses the internal pull-up) |
| D3 | Relay input |
| `LED_BUILTIN` | Lights while the button is pressed |

**Sensor connector pinout**

| Pin | Function | Wire |
|---|---|---|
| 1 | 10-36 V DC | Brown |
| 2 | Not connected | White |
| 3 | GND | Blue |
| 4 | Load output (< 100 mA) | Black |

The full wiring is in the included TinyCAD schematic, `ATMEGA2560 Control.dsn`, which opens with [TinyCAD](https://www.tinycad.net).

## Building and uploading

`main.cpp` is plain Arduino-framework C++. Either:

- **PlatformIO:** place it in `src/main.cpp` of a project targeting your board, or
- **Arduino IDE:** copy the contents into a new sketch (a `.ino` file) and upload.

No external libraries are needed.

## Behavior

| Button | Relay | Result |
|---|---|---|
| Not pressed | Off (NC contact closed) | Alarm path live |
| Pressed | On (NC contact open) | Horn muted, LED on, 5-minute hold |

The mute is a blocking `delay(300000)`, so the Arduino does nothing else for those 5 minutes. A serial log at 9600 baud reports the button state.

## References

- [Arduino Getting Started: button and relay](https://arduinogetstarted.com/tutorials/arduino-button-relay)
- [Arduino Getting Started: LED blink (relay time hold)](https://arduinogetstarted.com/tutorials/arduino-led-blink)

## Author

Spenser Fenton ([@rotarybean](https://github.com/rotarybean))
