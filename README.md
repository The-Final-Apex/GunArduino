🧰 Hardware Checklist
🧠 1. Arduino Board

    ✅ Recommended: Arduino Micro or Leonardo

        These support HID (keyboard/mouse emulation)

    ❌ Uno is fine for serial testing, but can’t act as a real controller without help

🎮 2. MPU-6050 Module

    Purpose: Measures tilt/rotation (gyroscope + accelerometer)

    Comes with: 6 pins (VCC, GND, SCL, SDA, XDA, XCL)

    Needed for aiming

🔘 3. Push Buttons (x2 or more)

    One for trigger (shoot)

    One for reload

    Optional: Add more for other features like “zoom” or “melee”

⚡ 4. Resistors (optional for buttons)

    Pull-up resistors (10kΩ) if not using INPUT_PULLUP mode

🔌 5. Jumper Wires

    To connect MPU and buttons to Arduino

🔋 6. Breadboard (optional, for prototyping)

    Helps avoid soldering during testing

🌌 7. Power Supply / USB Cable

    Just connect Arduino to PC via USB

🧩 Optional:
Component	Use
Laser diode (low power)	Pointing dot (cool factor)
Vibration motor	Haptic feedback on shoot
Small speaker/buzzer	Play gun sounds
3D printed gun shell	Mount everything inside
🖥️ Software Requirements
🧱 On the Arduino:

    Arduino IDE

    Libraries:

        MPU6050 (by Jeff Rowberg)

        [Wire] (included in Arduino IDE)

🧪 On the PC (Windows/Linux/Mac):

    Python 3.x

    Install:

pip install pyserial pyautogui

These Python packages allow the PC to:

    Read data from Arduino

    Move the mouse based on aiming

    Simulate clicks and key presses (like reload)

🔧 Wiring Diagram Summary
Arduino Pin	Connect To
3.3V or 5V	VCC on MPU6050
GND	GND on MPU6050
A4	SDA (MPU6050)
A5	SCL (MPU6050)
D2	Trigger button
D3	Reload button

    Use INPUT_PULLUP in code to simplify wiring (button connects to GND on press).

🧠 What This Setup Does
Action	How it's Done
Aim crosshair	Move the gun (gyro/tilt)
Shoot	Press trigger button
Reload	Press reload button
Game response	Python script moves mouse / presses keys
