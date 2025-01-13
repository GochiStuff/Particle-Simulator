# Balls

trying to make a simple particle simulator , with an approch to make realisic physical interactions efficiently. 

The project aims to provide a sandbox for simulating particle collisions, intra-particle forces, and more, with high performance and scalability.  

## COLLISION
### Master Branch - use Box bounding volumes || IMAGEES :: 
### Circular Bound - use Circular Bounding volumes 
<div align="center">
   <div style="display: flex;">
      <img src="https://github.com/user-attachments/assets/9101152b-77e1-470b-a8bc-467bef3d192f" alt="Where did the image do ? " style="vertical-align: top; width:50%; height:auto;">
      <img src="https://github.com/user-attachments/assets/a8942558-c060-4c27-9483-0c449f77dce6f" alt="Where did the image do ? " style="width:50%; height:auto;">
      <img src="https://github.com/user-attachments/assets/919eec8d-0b07-4c41-9983-f459c8d05b32" alt="Where did the image do ? " style="width:50%; height:auto;">
      <img src="https://github.com/user-attachments/assets/54a9b995-9798-4c01-bfb5-ba596f06f080" alt="Where did the image do ? " style="width:50%; height:auto;">
      <img src="https://github.com/user-attachments/assets/d8e4d22e-7133-4acb-98e4-1729953682fc" alt="Where did the image do ? " style="width:50%; height:auto;">
      <img src="https://github.com/user-attachments/assets/8446b739-3b71-4315-b336-8a0d80edd2cf" alt="Where did the image do ? " style="width:50%; height:auto;">
      <img src="https://github.com/user-attachments/assets/3596ec2d-7363-4319-9127-0e8603773f48" alt="Where did the image do ? " style="width:50%; height:auto;">
   </div>
</div>


### Completed or Soon-to-be Completed

1. **Particle Collision**  
   - Realistic physical interactions using circular and AABB bounding volumes.  
2. **Gravity**  
   - Simulate gravitational forces between particles.  
3. **Velocity-Based Coloring**  
   - Particles are colored based on their velocity, providing a visually dynamic simulation.  
4. **Efficient Handling of Large Particle Counts**  
   - Simulate up to:
     - 200,000 particles at **120 FPS** without collision.
     - 1,000 - 3,000 particles at **120 FPS** with collision on mid-spec systems.  
5. **Support for Multiple Bounding Volume Types**  
   - Circular bounding volumes (basic implementation).  
   - AABB (rectangle/box bounding volumes).  
6. **Large-Scale Simulation**  
   - Capable of simulating a massive number of particles efficiently.  

### Planned Features  
- **Coefficient of Restitution**  
  - Simulate elasticity in collisions.  
- **Drag Effects**  
  - Model the impact of varying air densities.  
- **Intra-Particle Forces**  
  - Include advanced physical forces between particles.  

For collision , Source 
https://pbr-book.org/3ed-2018/Primitives_and_Intersection_Acceleration/Bounding_Volume_Hierarchies

## Getting Started  

### Prerequisites  
1. Install [SFML](https://www.sfml-dev.org/):  
   - Download the library.  
   - Include the headers and libraries in your project solution.  
   - Place the `bin` folder in your build directory.  

### Setup  
1. Clone the repository:  
   ```bash
   git clone https://github.com/gochi/balls-simulator.git
   cd balls-simulator
