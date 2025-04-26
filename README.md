---

# Smart Parking System

A real-time parking management system designed using **Arduino UNO**, **IR sensors**, **LCD Display with I2C module**, and **Servo motor**. It detects parking slot occupancy, automates gate control, and displays availability status, helping drivers find parking slots faster and reducing urban traffic congestion.

---

## 📜 Project Overview

The **Smart Parking System** addresses common parking challenges such as traffic congestion, inefficient parking space usage, and user frustration.  
This system automates:
- Real-time slot detection
- Automated gate access
- Slot status updates on LCD display

It is ideal for **small to medium-scale** parking facilities like shopping malls, offices, and urban centers.

---

## 🎯 Objectives

- Minimize the time taken to find available parking slots
- Optimize parking space utilization
- Reduce urban congestion and carbon emissions
- Improve user parking experience through automation

---

## 🛠️ Technology Stack

- Microcontroller: Arduino UNO
- Sensors: IR Sensors (Entry, Exit, and Slot Detection)
- Display: 20x4 LCD with I2C Module
- Motor: Mini Servo Motor SG-90
- Power: 5V, 2A Adapter (from 220V AC Source)
- Software: Arduino IDE (Embedded C/C++)

---

## 📦 Hardware Components

- Component       |        Purpose 
- Arduino UNO             Controls the entire system 
-IR Sensors              Detect vehicles at entry, exit, and parking slots 
- LCD Display (20x4)      Shows real-time slot availability 
- I2C Module              Simplifies LCD wiring 
- Servo Motor (SG-90)     Opens and closes the barrier gate 
- 5V 2A Adapter           Powers Arduino and modules 
- Breadboard & Wires      Assembly and prototyping 

---

## 📈 System Architecture

- Entry/Exit Detection: IR sensors detect incoming and outgoing vehicles.
- Slot Monitoring: Each parking slot monitored via dedicated IR sensors.
- Real-Time Display: LCD shows available parking slots dynamically.
- Barrier Control: Servo motor opens or closes gate based on availability.
- Power Management: Stable 5V supply ensures reliability.

---

## 🧩 Features

- Real-time parking slot monitoring
- Automated gate opening/closing
- LCD status display
- Low-cost and scalable design
- Expandable for more slots and mobile app integration

---

## 📋 Installation Instructions

1. Wiring:
    - Connect IR sensors to Digital Pins 2, 4, 5–10.
    - Connect Servo Motor signal wire to Digital Pin 3.
    - Connect LCD via I2C (SDA → A4, SCL → A5).
2. Power Setup:
    - Power Arduino using a 5V, 2A adapter.
3. Upload Code:
    - Use Arduino IDE.
    - Install libraries:
        - `Wire.h`
        - `LiquidCrystal_I2C.h`
        - `Servo.h`
4. Run:
    - The system will auto-detect parking availability and display it.

---

## 🚀 Future Enhancements

- Mobile application integration (slot booking & navigation)
- RFID authentication for users
- EV charging station support
- Advanced analytics & reporting

---

## 📑 License
  
© 2025 Ritesh Kashyap

---

## 📞 Contact
Email: riteshkashyap2525@gmail.com 

---

# ⭐ Thank you for visiting!  
If you find this useful, feel free to ⭐ star the repository!
