# raybot
Autonomous Robot Control via Web Interface
Project Overview

The project involves controlling an autonomous robot through a web interface. Users can interact with the robot in real-time, view live video feeds, monitor environmental data, and send movement commands.
User-Facing Features

    Access the web portal at raybot.es to:
        View the latest images captured by the robot's webcams or watch a live video stream.
        Check the timestamp, temperature, and humidity readings for each captured image.
        Request a new photo with updated environmental data.
    Robot Control Options:
        Move two robotic arms (horizontal and vertical axes).
        Control two motors (forward/backward movement).
        Adjust a single motor (forward/backward).
        Steer left, right, or center.
    Additional Features:
        View a photo history log.
        Review a command history log.
        Watch live video streaming.
        Measure ground distance (for future enhancements).
    The web interface allows real-time robot control via command inputs.
    Live video streaming via Twitch.tv, embedded in the web interface using Node.js.

Development Notes
Hardware Setup

    Arduino Uno connected to:
        2x DHT11 temperature & humidity sensors.
        4x MG995 servo motors (for arm movement).
        1x DC motor (forward/backward motion).
        1x servo motor (steering left/right/center).
    Raspberry Pi 3 powered by dual 6V lead-acid batteries (7Ah).
    Ultrabook laptop with mobile internet (SIM card) for connectivity.
    2x USB webcams for live video feed.

Software & Automation

    Python scripts on the laptop handle:
        Serial communication with Arduino.
        HTTP GET/POST requests to a remote database via a PHP backend.
    Automated startup script (cron.sh) running on boot:
        fswebcam - Captures hourly images.
        Python scripts - Collect and log temperature/humidity data from Arduino.
        Secure API calls - Send/receive commands via HTTPS (user/password authentication).
    Live streaming via OBS → Twitch.tv, embedded in the web interface using an iframe.

Power & Electronics

    12V solar panel with charge controller.
    Dual 6V lead-acid batteries (7Ah).
    Voltage regulators:
        12V → 5V (for Raspberry Pi).
        12V → 6V (for servos/motors).
    12V DC to 200V AC inverter (for laptop power).
    Additional components:
        SIM808 module (GSM/GPRS connectivity).
        USB 4G router (SIM card-based internet).
        Arduino Sensor Shield V5.0.
        HC-SR04 ultrasonic sensor (distance measurement).
        Relays (motor control).

Software & System Architecture
Modules Developed

    Sensor & Camera Module
        Collects temperature/humidity data.
        Manages dual webcam feeds (latest image displayed by default).
    Robot Command Module
        Controls servo positions (horizontal/vertical movement).
        Handles motor commands (forward/backward, steering).
    Data Logging Module
        Stores images, timestamps, sensor data, commands, and distance measurements.

Operating Systems & Tools

    Raspberry Pi 3: Raspbian OS (Python, Arduino IDE).
    Raspberry Pi 4: Ubuntu 22.04 ARM64 (Python, Arduino IDE).
    Laptop: Ubuntu 22.04 (Python, Arduino IDE).
    Live Streaming: OBS → Twitch.tv.
    Web Backend:
        Node.js/Python WebSocket server for real-time control.
        Apache/PHP/MySQL for raybot.es web hosting.

Mechanical & Enclosure Design

    Stainless steel frame with transparent polycarbonate panels (sealed with silicone).
    Plastic casing for additional protection.
    Toy car chassis (modified for motor/steering integration).

Future Improvements

    AI integration for autonomous navigation.
    Process automation (scheduled tasks, auto-adjustments).
    IoT & Big Data for advanced analytics.
