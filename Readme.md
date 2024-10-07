# Smart Cane for the Visually Impaired

## Project Overview
This project aims to empower visually impaired individuals by providing a **Smart Cane** that enhances their independence and safety while traveling. The smart cane is equipped with a variety of sensors to detect obstacles, water-filled potholes, and accidents, offering both real-time assistance and emergency response capabilities.

## Features
- **Ultrasonic Sensor**: Detects obstacles in the path and alerts the user with a buzzer.
- **Water Sensor**: Identifies water-filled potholes or wet surfaces to prevent slips or falls.
- **Vibration Sensor**: Detects unusual vibrations caused by accidents or falls.
- **GSM Module**: Sends an alert call and message to a designated contact in case of an accident.
- **GPS Module**: Sends the location of the user during an emergency, helping responders reach them quickly.
- **SIM Card with Internet**: Enables real-time communication with the emergency contact.
- **Buzzer**: Provides auditory alerts when obstacles or water are detected.

## Components Used
- **Ultrasonic Sensor**: For obstacle detection
- **Water Sensor**: For detecting water on the path
- **Vibration Sensor**: For accident detection
- **GSM Module**: For sending alert calls and messages
- **GPS Module**: For location tracking
- **Arduino Uno (2)**: One for handling GSM, GPS, and vibration sensors; another for ultrasonic and water sensors
- **Buzzer**: For auditory alerts
- **Batteries**: Power source for the Arduino boards and modules
- **SIM Card with Internet**: For GSM and GPS communication

## System Design
The smart cane uses two **Arduino Uno** boards:
- **Arduino Uno 1**: Responsible for the GSM, GPS, and vibration sensors. In the event of an accident, the vibration sensor triggers the GSM module to alert the emergency contact with a phone call and SMS, including the user's GPS location.
- **Arduino Uno 2**: Manages the ultrasonic and water sensors, providing immediate feedback to the user about obstacles and water hazards on the road.

## Circuit Diagram
<img src="https://raw.githubusercontent.com/sangu-firedev/Smart-Cane/refs/heads/main/smart%20cane.jpg" alt="Smart Cane" width="500" />

## How It Works
1. **Obstacle Detection**: The ultrasonic sensor continuously scans for obstacles in the user's path. When an obstacle is detected, the buzzer alerts the user.
2. **Water Detection**: The water sensor detects the presence of water on the ground and triggers the buzzer to warn the user.
3. **Accident Detection**: If the vibration sensor detects a strong impact, the system assumes an accident has occurred. It triggers the GSM module to make an emergency call and send an SMS with the user’s GPS coordinates to a predefined contact.
4. **Emergency Response**: Using the GPS module, the location of the user is tracked and sent via SMS, helping family members or caregivers respond quickly to emergencies.

## Installation and Setup
1. Clone this repository:
   ```bash
   git clone https://github.com/sangu-firedev/Smart-Cane.git
   cd smart-cane

2. Upload the code to the two Arduino Uno boards. Ensure the correct sensors and modules are wired to their respective Arduino boards.
3. Insert a SIM card with internet access into the GSM module.
4. Power the system using the batteries and test each sensor for proper functionality.

## 🤖 Future Enhancements
- Add voice feedback for real-time obstacle detection alerts.
- Implement Bluetooth connectivity for indoor navigation.
- Include a camera module for object recognition and advanced obstacle avoidance.

## Contributing
Contributions are welcome! Please open an issue or submit a pull request if you'd like to improve the project.

## Acknowledgements
- Special thanks to the open-source community for providing amazing libraries and resources.
- Inspired by the need to make the world more accessible for the visually impaired.
