![Ton Digit Stream Animation](democast.gif)
# Ton-Digit-Stream
## 🎙️ Logic Walkthrough
> This video provides a narrated breakdown of the active logic changes to demonstrate the engineering intent behind the implementation.

https://github.com/user-attachments/assets/6240a8cf-d4e0-4f1a-b8ee-31998a9497fc


A minimalist C animation using `ncurses` and trigonometric functions to create a "floating whisp" effect in the terminal.

![Project Demo](path/to/your/demo.gif)

## 🛠 Tech Stack
- **Language:** C
- **Libraries:** `ncurses` (Terminal UI), `math.h` (Trigonometry)
- **Concepts:** Polar-to-Cartesian mapping, double buffering, real-time input handling.

## 🚀 How to Run
To run this on a Linux/Unix system, ensure you have the `ncurses` development library installed.

```bash
# Compile
gcc src/Tstoc.c -o Tstoc -lncurses -lm

# Run
./Tstoc

🧠 The Logic
The animation uses sine and cosine to calculate a circular path, combined with a horizontal drift. To maintain a "clean" visual field without ghosting, the program utilizes a hard-clear refresh cycle and tethered mathematical offsets for the trailing "whisp" digits.


---

### 4. The GitHub Commands
Once your files are ready in your local folder, run these in your terminal:

1.  **Initialize:** `git init`
2.  **Add Files:** `git add .`
3.  **Commit:** `git commit -m "Initial commit: Zen Digit Stream with tethered whisp effect"`
4.  **Connect:** `git remote add origin https://github.com/YOUR_USERNAME/Zen-Digit-Stream.git`
5.  **Push:** `git push -u origin main`



### Why this works for a portfolio:
It shows you aren't just writing "Hello World"—it proves you can handle **memory-safe UI updates**, **external library linking**, and **real-time loops**.

**Would you like me to help you write a more detailed "Technical Challenges" section for t
