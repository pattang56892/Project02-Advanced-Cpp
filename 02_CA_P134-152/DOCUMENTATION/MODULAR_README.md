# 🚀 Algorithm Learning Platform - Modular Architecture

## Overview
This is a complete refactoring of the monolithic QtMainWindow.cpp into a scalable, modular architecture that addresses all user requirements:

### ✅ Implemented Features

1. **📱 Responsive Sidebar Toggle**
   - Manual toggle button with hamburger icon
   - Auto-hide when viewport width < 800px
   - Smooth slide animations

2. **🌓 Dark/Light Theme System**
   - Toggle button in header
   - Complete theme management system
   - Consistent styling across all components

3. **📏 Optimized Header Layout**
   - Problem title reduced to 50% width
   - Button bar in remaining 50% space
   - Clean, professional design

4. **🧩 Modular Component Architecture**
   - Separated concerns into specialized classes
   - Easy to maintain and extend
   - Follows SOLID principles

## 📁 Project Structure

```
02_CA_P134-152/
├── main.cpp                     # Application entry point
├── AlgorithmLearningPlatform.h  # Main window class
├── AlgorithmLearningPlatform.cpp
├── ProblemData.h               # Data models and management
├── ProblemData.cpp
├── ThemeManager.h              # Theme system
├── ThemeManager.cpp
├── SidebarWidget.h             # Sidebar component
├── SidebarWidget.cpp
├── HeaderWidget.h              # Header with toggle buttons
├── HeaderWidget.cpp
├── ContentWidget.h             # Main content area
├── ContentWidget.cpp
├── CodeHighlighter.h           # Syntax highlighting
├── CodeHighlighter.h
├── AlgorithmSimulator.h        # Algorithm execution
├── AlgorithmSimulator.cpp
├── CMakeLists.txt              # Build configuration
└── QtMainWindow.cpp            # Original monolithic file (backup)
```

## 🎯 Component Responsibilities

### **AlgorithmLearningPlatform** (Main Window)
- Coordinates all components
- Handles window events and resizing
- Manages component communication

### **HeaderWidget**
- Problem title display (50% width)
- Sidebar toggle button
- Theme toggle button
- About button
- Responsive layout

### **SidebarWidget**
- Problem list with search
- Smooth slide animations
- Auto-hide on narrow screens
- Reset functionality

### **ContentWidget**
- Tabbed content display
- Interactive testing interface
- Syntax highlighted code
- Multi-language support

### **ThemeManager**
- Light/Dark theme switching
- Consistent styling system
- Theme-aware components

### **ProblemDataManager**
- Centralized data management
- Easy to add new problems
- Structured problem format

### **AlgorithmSimulator**
- Algorithm execution simulation
- Educational testing interface
- Input validation and feedback

## 🔧 How to Add New Problems

### 1. Add Problem Data
In `ProblemData.cpp`, add a new creation function:

```cpp
ProblemData ProblemDataManager::createProblem154()
{
    return ProblemData(
        154, "Your Problem Title",
        "Problem description here...",
        "Tutorial and approach...",
        "C++ solution code...",
        "Python solution code...",
        "JavaScript solution code...",
        "Example input/output..."
    );
}
```

### 2. Register the Problem
In `ProblemDataManager::loadAllProblems()`:

```cpp
problems.append(createProblem154());
```

### 3. Add Algorithm Simulation (Optional)
In `AlgorithmSimulator.cpp`, add simulation logic:

```cpp
case 154:
    return simulateYourNewAlgorithm(input);
```

## 🎨 Theme Customization

Themes are managed in `ThemeManager.cpp`:

- **Light Theme**: Clean, professional look
- **Dark Theme**: Easy on the eyes for long coding sessions
- **Extensible**: Easy to add new themes

## 📱 Responsive Design

The application automatically adapts to different screen sizes:

- **Wide screens (>800px)**: Full sidebar visible
- **Narrow screens (<800px)**: Sidebar auto-hides
- **Manual control**: Toggle button always available

## 🔧 Build Instructions

### Using CMake (Recommended)
```bash
mkdir build
cd build
cmake ..
make
```

### Using Qt Creator
1. Open `CMakeLists.txt` in Qt Creator
2. Configure project with Qt 6.x
3. Build and run

### Using Visual Studio (Windows)
1. Open the folder containing `CMakeLists.txt`
2. Configure CMake with Qt paths
3. Build and run

## 🚀 Benefits of Modular Architecture

### **Maintainability**
- Each component has a single responsibility
- Easy to locate and fix issues
- Clean separation of concerns

### **Scalability**
- Add new problems without touching UI code
- Extend functionality through new components
- Theme system supports unlimited themes

### **Testability**
- Components can be unit tested individually
- Clear interfaces between modules
- Easier debugging and validation

### **Reusability**
- Components can be reused in other projects
- Theme system is completely portable
- Algorithm simulator is independent

## 🎓 Educational Benefits

### **For Students**
- Clean, distraction-free interface
- Dark mode for comfortable learning
- Responsive design works on any device
- Interactive testing encourages experimentation

### **For Educators**
- Easy to add new curriculum content
- Structured problem format
- Multi-language code examples
- Professional presentation

### **For Developers**
- Demonstrates modern C++/Qt practices
- Shows proper software architecture
- Clean code examples to learn from
- Extensible design patterns

## 🔮 Future Enhancements

The modular architecture makes these additions straightforward:

1. **Database Integration**: Replace file-based data with database
2. **User Accounts**: Add login and progress tracking
3. **Code Execution**: Run actual code instead of simulation
4. **Collaborative Features**: Share solutions and discussions
5. **Mobile App**: Reuse components in mobile framework
6. **Plugin System**: Allow third-party algorithm additions

## 📝 License

Educational use - designed for learning algorithm concepts and modern software architecture.