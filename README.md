#  Smart Digital Battery Voltage and Health Monitoring System

##  Aim
To design and implement a digital instrumentation system that continuously measures battery voltage, estimates battery health, and provides real-time visual and audio alerts using LEDs, a buzzer, and an LCD.

---

##  Project Overview
This project monitors battery voltage using a potentiometer (simulated battery), converts the analog signal into digital form using Arduino’s ADC, processes the data to calculate battery health, and displays:

- Battery Voltage (V)
- Battery Health (%)
- Battery Status (HEALTHY / WARNING / CRITICAL)

Real-time alerts are provided using LEDs and a buzzer.

---

##  Components Used
- Arduino UNO  
- 16×2 LCD Display  
- Potentiometer (battery voltage simulation)  
- 10k Potentiometer (for LCD contrast)  
- LEDs (Green, Yellow, Red)  
- Buzzer  
- 220 Ω Resistors  
- Breadboard and jumper wires  

---

##  Working Principle

### 1. Voltage Sensing
A potentiometer simulates battery voltage from 0–5V.  
The middle pin is connected to Arduino analog pin A0.

---

### 2️. Analog-to-Digital Conversion (ADC)
The Arduino ADC converts the analog voltage into a digital value ranging from 0 to 1023.

**Voltage calculation:**
Voltage = (ADC × 5) / 1023

---

### 3️. Battery Health Calculation
Battery health is calculated as:

Health (%) = (Measured Voltage / 5V) × 100

---

### 4️. Decision Logic (Threshold-Based)

| Voltage Range | Health (%) | Status    | Output            |
|--------------|------------|-----------|-------------------|
| > 3.5 V      | > 60%      | HEALTHY   | Green LED         |
| 2.0–3.5 V    | 30–60%     | WARNING   | Yellow LED        |
| < 2.0 V      | < 30%      | CRITICAL  | Red LED + Buzzer  |

---

### 5️. Display and Alerts
- LCD continuously displays voltage, health percentage, and status
- LEDs indicate battery condition
- Buzzer activates only during critical condition

---

##  Circuit Diagrams
![Schematic Diagram](circuit/schematic.pdf)

![Tinkercad Circuit View](circuit/tinkercad-circuit-view.png)

---

##  Simulation
The project is designed and tested using Tinkercad.  
A potentiometer is used to simulate real battery voltage variations.
---
