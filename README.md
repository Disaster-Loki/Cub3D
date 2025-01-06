# 🌟 **Cub3D**

![Cub3D Animation](https://media.giphy.com/media/2t9mjApy1CYY24HTWo/giphy.gif)

---

## 🚀 **Project Overview**
**Cub3D** is my first experience building a RayCaster using **miniLibX**. This project takes inspiration from the legendary **Wolfenstein 3D**, the first-ever FPS game. 

### 🎯 **Goals**
- Explore ray-casting techniques.
- Develop a dynamic, first-person perspective inside a maze.
- Achieve smooth graphics rendering and player movement.

---

## 📽️ **Demo**

```c
#include "cub3d.h"

int main(void) {
    t_game game;

    if (!init_game(&game)) {
        printf("Error: Failed to initialize the game.\n");
        return (1);
    }
    while (1) {
        render_game(&game);
    }
    cleanup_game(&game);

    return (0);
}
```

> **Preview:** Navigate through a maze, observe realistic wall textures, and experience smooth gameplay.

---

## 📜 **Features**
- 🎮 **Keyboard controls:**
  - Arrow keys: Look left/right.
  - W, A, S, D: Move through the maze.
  - ESC: Exit the game.
- 🎨 **Customizable colors** for floor and ceiling.
- 🖼️ **Dynamic wall textures** based on the wall orientation (N/S/E/W).
- 🗺️ Parses `.cub` map files with customizable layouts.
- 🖥️ **MiniLibX Integration:** Lightweight graphics library for C programming.

---

## 🤝 **Collaborators**
- [Disaster-Loki](https://github.com/Disaster-Loki)
- [ptchipoc](https://github.com/ptchipoc)

---

## ⚙️ **How to Run**
1. Clone the repository:
   ```bash
   git clone https://github.com/Disaster-Loki/cub3D.git
   cd cub3D
   ```
2. Compile the project:
   ```bash
   make
   ```
3. Run the executable with a `.cub` map:
   ```bash
   ./cub3D path/to/map.cub
   ```

---

## 🌐 **Learn More**
Visit the [Wolfenstein 3D](http://users.atw.hu/wolf3d/) page to explore the game that inspired this project.

---

## ✨ **Acknowledgments**
Thanks to **42 Network** and the amazing open-source community for the resources and support!

---

## 📜 **License**
This project is licensed under the MIT License. See the LICENSE file for details.

