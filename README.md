# Hybrid Solar Converter with LDR Automation and IoT-based Automated Error Detection

![Final Assembly](https://github.com/roshanyadav29/Hybrid-Solar-Tracker/blob/main/Final%20Assembly.jpg)

## Overview
This project involves the development of a Hybrid Solar Converter system with sun-tracking, automated error detection, and seamless power source transition capabilities. It addresses challenges in solar power systems, ensuring efficient energy generation and reliable performance in various weather conditions.

The system optimizes energy generation by seamlessly switching between solar and AC power sources. It employs a sun-tracking mechanism that adjusts the solar panel's position based on the intensity of sunlight detected by Light Dependent Resistors (LDRs) placed around the panel.

To ensure reliable performance, an automated error detection system continuously monitors the solar panel's power output. It compares the generated power with the required load and triggers a swift transition from solar to AC power if insufficient power is detected. Users are notified of this transition via phone or email.

Real-time alerts and notifications are facilitated by an ESP8266 Wi-Fi module integrated with the IFTTT platform. When an error in the solar panel's output voltage is detected, the module communicates with IFTTT to send notifications to designated devices.

During adverse weather conditions, the system seamlessly switches to AC power, ensuring uninterrupted operation. Integration of the ESP8266 module and IFTTT platform enables remote monitoring and real-time notifications, empowering users to stay informed about system performance.

This project contributes to sustainable and technologically advanced clean energy solutions. It showcases the potential to enhance efficiency, reliability, and usability in solar power applications.

## Getting Started

### Prerequisites
Before you begin, ensure you have met the following requirements:
* You have a Windows machine. 
* You have installed the latest version of Arduino IDE.
* You have basic knowledge of Arduino programming and circuit assembly.

### Installing Hybrid Solar Converter
To install Hybrid Solar Converter, follow these steps:

1. Clone the repo:
```bash
git clone https://github.com/roshanyadav29/Hybrid-Solar-Converter.git
```
2. Navigate into the project directory:
```bash
cd Hybrid-Solar-Converter
```

## How it Works
The system works by continuously monitoring the output of the solar panel and the required load. If the solar panel's output is insufficient, the system seamlessly switches to AC power. The system also tracks the sun's position using LDRs and adjusts the solar panel's position for maximum efficiency. If an error is detected, the system sends a notification via the ESP8266 Wi-Fi module and IFTTT platform.

## Features

### 1. Solar Hybrid Converter
The efficiency of a solar converting system is largely dependent on weather conditions. On average, a solar panel receives four to five hours of bright sunlight in a day. Cloudy or rainy weather can hinder the charging process, preventing the battery from attaining a full charge. This hybrid solar converter addresses this issue by charging the battery or load using both solar power and AC mains supply. When the output from the solar panel exceeds 12 volts, the battery charges using solar power. When the output falls below 12 volts, the battery charges through the AC mains supply.

### 2. Dual Axis Sun Tracking System
The system includes an ATmega328 microcontroller, a solar panel, Light Dependent Resistors (LDRs), and a Servo Motor. Due to the Earth's rotation, the sun's position relative to the solar panel is not fixed. For efficient use of solar energy, the solar panels should absorb as much energy as possible, which can be achieved if the panels continuously face the sun. Therefore, the solar panel should continuously rotate in the direction of the sun.

### 3. Automated Error Detection
This feature involves an Ex-or gate, an ESP8266 Wi-Fi module, and a Voltage Regulator. The inputs to the Ex-or gate come from the Arduino Uno, and the output of the Ex-or gate is connected to the input terminal of the voltage regulator ASM1117. The ESP8266's GND pin is grounded along with the Arduino board's GND. The output of the Voltage Regulator (3.3V) is connected to the CH_PD and Vcc terminals of the ESP8266 Wi-Fi Module. When an error is detected, a message is sent to a registered mobile number via the open-source website Ifttt.com

## Advantages, Disadvantages and Future Work

### Advantages:

1. **Continuous Operation:** The load remains continuously ON, ensuring uninterrupted service.
2. **Smooth Transition:** The system seamlessly switches between solar power and AC supply, preventing any visible fluctuations.
3. **Automated Error Detection:** The system promptly identifies and resolves power generation issues.
4. **Optimized Efficiency:** Maximum efficiency is achieved when the solar panel is perpendicular to sun rays.
5. **Real-Time Feedback:** The ESP8266 module provides real-time system performance updates.
6. **Automated Control:** The system requires no manual monitoring or control, saving manpower.
7. **Renewable Energy Utilization:** The system harnesses solar energy, a renewable and environmentally friendly resource.
8. **Cost-Effective:** After the initial setup cost, the system operates at no additional energy cost.
9. **Maximized Solar Absorption:** The Dual Axis Sun Tracker ensures maximum solar energy absorption by continuously tracking the sun.

### Disadvantages:

1. **Transformer Heating:** Continuous operation may lead to transformer overheating over time.
2. **Initial Cost:** The system has a high one-time setup cost.
3. **Weather Dependence:** While the system maximizes solar energy utilization, its effectiveness may be reduced during the rainy season.
4. **Battery Limitations:** Although solar energy can be stored in batteries, they are bulky, occupy more space, and need to be replaced periodically.

### Future Work:

The current limitations of the system present opportunities for future improvements. Research could be conducted to find solutions for transformer overheating and to develop more efficient and compact battery storage systems. Additionally, exploring ways to optimize the system's performance during adverse weather conditions could further enhance its reliability and efficiency.

## Contributing to Hybrid Solar Converter
To contribute to Hybrid Solar Converter, follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b <branch_name>`.
3. Make your changes and commit them: `git commit -m '<commit_message>'`
4. Push to the original branch: `git push origin <project_name>/<location>`
5. Create the pull request.

Alternatively, see the GitHub documentation on [creating a pull request](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request).

## Contact
If you want to contact me, you can reach me at `30005500@iitb.ac.in`.

## License
This project uses the following license: `<MIT License>`.