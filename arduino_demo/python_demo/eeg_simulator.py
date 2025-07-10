"""
Title: EEG Signal Threshold Simulation (Demo)
Description:
    This is a demo Python script to simulate EEG signal classification
    for robotic movement based on threshold values. This simulates 
    reading real-time EEG values and making directional decisions.
    
Note:
    - This is a demo without real EEG or classifier.
    - Can be connected to Arduino via Serial or Bluetooth for control.
"""

import random
import time

# Default EEG threshold (simulate baseline brainwave)
THRESHOLD = 520
TOLERANCE = 20  # Margin of variation to avoid false triggers

def read_eeg_signal():
    """
    Simulate EEG signal:
    Random value to mimic brainwave fluctuation.
    """
    return random.randint(480, 560)

def interpret_signal(value):
    """
    Decide direction based on EEG signal value.
    """
    if value > THRESHOLD + TOLERANCE:
        return "RIGHT"
    elif value < THRESHOLD - TOLERANCE:
        return "LEFT"
    else:
        return "IDLE"

def move_robot(direction):
    """
    Simulate or print robot movement.
    In real case, this would send signal via serial/Bluetooth to Arduino.
    """
    if direction == "LEFT":
        print("← Robot moving LEFT")
    elif direction == "RIGHT":
        print("→ Robot moving RIGHT")
    else:
        print("⏸ Robot IDLE / No action")

print("🧠 Starting EEG Threshold Simulation...\n")

while True:
    eeg = read_eeg_signal()
    print(f"EEG Reading: {eeg}")
    
    decision = interpret_signal(eeg)
    move_robot(decision)

    time.sleep(1)

