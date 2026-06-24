# SpongeBob-Roboter

C++ CMake Projekt für Roboter-Steuerung und Simulation mit OpenGL.

## Übersicht

Roboteranwendung mit drahtloser Steuerung (nRF24L01), Motor-Control und OpenGL-Simulation.

**Status:** 50% fertig

## Komponenten

### Hardware
- Arduino mit nRF24L01 Transmitter (Button-Steuerung)
- Raspberry Pi mit nRF24L01 Receiver (C++)
- Motor Driver + DC-Motoren
- GPIO-basierte Motor-Ansteuerung

## Installation

### Abhängigkeiten

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install -y \
    build-essential \
    cmake \
    libglfw3-dev \
    libglew-dev \
    libglm-dev \
    pkg-config

# RF24 Library
cd /tmp
git clone https://github.com/nRF24/RF24.git
cd RF24
mkdir build && cd build
cmake ..
make
sudo make install
```

### Build

```bash
mkdir build
cd build
cmake ..
make
```

### Ausführung

```bash
# Simulator (OpenGL)
./robot_simulator

# Receiver auf Raspberry Pi
./receiver

# Motor-Test (Python)
python3 motor_control.py
```

## Klassen

- **Motor** — DC-Motor Steuerung & PWM
- **Sensor** — Sensor-Eingaben (Abstand, Temperatur, etc.)
- **Robot** — Hauptroboter-Logik
- **Controller** — Steuerlogik (nRF24L01 Input)
- **Simulator** — OpenGL 3D Visualisierung
