# 🌟 **Cub3D**

## 🕹️ **My First RayCaster with miniLibX**

![cub3D Animation](https://media.giphy.com/media/3o6gDWzmAzrpi5DQU8/giphy.gif)

---

## 📜 **Project Description**

Inspired by the legendary **Wolfenstein 3D**, the first-ever FPS game created by the iconic duo **John Carmack** and **John Romero**, Cub3D is an exciting journey into the world of **Ray-Casting**.

### 🌌 **Objective**
Your mission is to develop a **3D dynamic view** inside a maze. Using the principles of **Ray-Casting**, you'll create a graphical representation of the maze from a **first-person perspective**, navigating and interacting with the environment.

---

## 🚀 **Features**

### 🛠️ **Mandatory Part**
- **Realistic 3D Representation**: Render a maze with walls and textures using **Ray-Casting**.
- **MiniLibX Integration**: Utilize the power of **MiniLibX** for graphics.
- **Dynamic Movements**:
  - `W`, `A`, `S`, `D`: Move the player in the maze.
  - Arrow keys: Rotate the player's view.
  - `ESC`: Exit the program cleanly.
  - Red Window Button: Close the program without crashes.
- **Textures and Colors**:
  - Different wall textures depending on direction (**North**, **South**, **East**, **West**).
  - Customizable **floor** and **ceiling** colors.
- **Scene Description File**: Parse a `.cub` file to load the maze configuration, including:
  - **Textures**
  - **Colors**
  - **Maze Map**

### 🎨 **Bonus Part**
- **Enhanced Graphics**: Add lighting effects, shadows, and animations for a more immersive experience.
- **Advanced Controls**: Diagonal movements, crouch, and sprint.
- **Multiplayer Mode**: Explore the maze with friends.
- **Minimap**: Implement a dynamic **2D minimap** to assist navigation.

---

## ⚙️ **Getting Started**

### 📦 **Prerequisites**
- **Linux/MacOS**
- **gcc** Compiler
- **Makefile**
- **MiniLibX** Library

### 💻 **Installation**
```bash
# Clone the repository
git clone https://github.com/Disaster-Loki/cub3D.git

# Navigate to the project directory
cd cub3D

# Build the project
make
```

### 🗺️ **Running the Project**
```bash
./cub3D path/to/your_map.cub
```

---

## 📄 **Scene Description File (.cub)**

### 🎮 **Example Configuration**
```txt
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,0
111111111111111111111
100000000011000000001
101100000111000000001
1100N1000000000000001
111111111011000001111
100000000011000001111
111101111111110111111
111101111111110111111
```

### ❗ **Error Handling**
- Invalid characters in the map.
- Unclosed walls.
- Missing textures or colors.

---

## 🎥 **Demo**

![Cub3D Demo](https://media.giphy.com/media/xT9IgzoKnwFNmISR8I/giphy.gif)

---

## 🧑‍💻 **Contributors**

- [**Disaster-Loki**](https://github.com/Disaster-Loki)  
- [**ptchipoc**](https://github.com/ptchipoc)

---

## 📜 **License**
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🌟 **Acknowledgments**

- **42 School** for their challenging and creative projects.
- **John Carmack** and **John Romero** for inspiring generations of developers with **Wolfenstein 3D**.
- The open-source community for their invaluable resources.

---

> **“Relive the history and create your own!”**

