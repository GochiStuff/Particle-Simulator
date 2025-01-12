# Balls

trying to make a simple particle simulator , with an approch to make realisic physical interactions efficiently. 

The project aims to provide a sandbox for simulating particle collisions, intra-particle forces, and more, with high performance and scalability.  

## COLLISION
### Master Branch - use Box bounding volumes 
### Circular Bound - use Circular Bounding volumes 


### Completed or Soon-to-be Completed
1. **Particle Collision**  
   - Realistic physical interactions using circular and AABB bounding volumes.  
2. **Gravity**  
   - Simulate gravitational forces between particles.  
3. **Velocity-Based Coloring**  
   - Particles are colored based on their velocity, providing a visually dynamic simulation.  
4. **Efficient Handling of Large Particle Counts**  
   - Simulate up to:
     - 50,000 particles at **120 FPS** without collision.
     - 500 - 1,000 particles at **120 FPS** with collision on mid-spec systems.  
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
