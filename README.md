# Eye Gesture-Based Wheelchair & Device Control System

An assistive human-machine interaction (HMI) system designed for quadriplegic and severely paralyzed individuals. The system tracks eye gaze movements via a CMOS camera, processes real-time image data using a MATLAB computer vision application, and wirelessly transmits direction and appliance-control commands via Zigbee to a PIC microcontroller unit driving a motorized wheelchair and AC home appliances.

---

## 🛠 Project Architecture & Block Diagram

The system is split into two primary operational units: the **Processing Unit (PC/Laptop)** and the **Embedded Control Unit (Wheelchair & Appliances)**.

+-----------------------------------------------------------------------+
|                         PROCESSING UNIT (PC/Laptop)                  |
|                                                                       |
|   +-------------------+                     +---------------------+   |
|   |  Eye-Tracking     | === (USB Feed) ===> | MATLAB Application  |   |
|   |   CMOS Camera     |                     | (Gaze Detection)    |   |
|   +-------------------+                     +----------+----------+   |
|                                                        |              |
|                                                        v              |
|                                             +---------------------+   |
|                                             |  Zigbee Transceiver |   |
|                                             +----------+----------+   |
+--------------------------------------------------------|--------------+
| (Wireless)
v
+--------------------------------------------------------|--------------+
|                         EMBEDDED CONTROL UNIT          |              |
|                                                        v              |
|                                             +---------------------+   |
|                                             |  Zigbee Receiver    |   |
|                                             +----------+----------+   |
|                                                        |              |
|                                                        v              |
|                                             +---------------------+   |
|                                             | PIC16F877A / 873A   |   |
|                                             |   Microcontroller   |   |
|                                             +----+-----------+----+   |
|                                                  |           |        |
|                         +------------------------+           +-----+  |
|                         |                                          |  |
|                         v                                          v  |
|            +-------------------------+                 +-----------+  |
|            | Motor Drivers & Relays  |                 | AC Devices|  |
|            +------------+------------+                 | Control   |  |
|                         |                              | (Relays)  |  |
|             +-----------+-----------+                  +-----+-----+  |
|             |                       |                        |        |
|             v                       v                        v        |
|      [ Left Wheel ]          [ Right Wheel ]       [ Light / Fan / AC ]|
+-----------------------------------------------------------------------+

