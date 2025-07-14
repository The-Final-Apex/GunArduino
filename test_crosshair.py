import serial
import pyautogui

ser = serial.Serial('COM4', 9600)  # Change to your Arduino port

center_x, center_y = pyautogui.size()
x, y = center_x // 2, center_y // 2

pyautogui.FAILSAFE = False  # allows full-screen movement

while True:
    line = ser.readline().decode().strip()
    if not line:
        continue

    try:
        action, tilt_x, tilt_y = line.split(",")
        tilt_x = float(tilt_x)
        tilt_y = float(tilt_y)

        # sensitivity
        dx = int(tilt_x * 0.5)
        dy = int(tilt_y * 0.5)

        x += dx
        y += dy
        pyautogui.moveTo(x, y)

        if action == "SHOOT":
            pyautogui.click(button='left')
        elif action == "RELOAD":
            pyautogui.press('r')

    except Exception as e:
        print("Error:", e)

