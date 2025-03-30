# Maze_Solver  

## 📝 Overview  
This project is an autonomous **maze-solving robot** that uses **ultrasonic sensors** and a **left wall-following algorithm** to navigate through a maze while avoiding obstacles.  

## 🔧 How It Works  
- The robot is equipped with **three ultrasonic sensors** (front, left, and right) to detect obstacles.  
- It follows the **left wall-following algorithm**, making decisions based on sensor data.  
- **Motor control** is implemented using PWM signals to control movement and turning.  

## 🔩 Components Used  
- 🎛 **Arduino Nano** (microcontroller)  
- 📡 **3x HC-SR04 Ultrasonic Sensors** (for distance measurement)  
- ⚙️ **L298N Motor Driver** (for motor control)  
- 🚗 **Two DC Motors** (for movement)  
- 🔋 **Battery Pack** (power source)  

## 🏁 Algorithm  
1. **Move forward** if no obstacle is detected.  
2. **If an obstacle is ahead**, check left and right distances:  
   - If **left is free**, turn **left**.  
   - If **right is free**, turn **right**.  
   - If **both are blocked**, **reverse slightly** and adjust direction.  

## 📥 Installation & Usage  
1. **Upload the Arduino code** to the Nano using the Arduino IDE.  
2. **Connect the components** as per the circuit diagram.  
3. **Power the robot** and let it navigate the maze autonomously.  

## 🎯 Applications  
- 🤖 Autonomous maze-solving robots  
- 🚧 Obstacle avoidance systems  
- 📡 Robotics and AI navigation projects  


---
🚀 **Developed for robotics and autonomous navigation experiments!**  
