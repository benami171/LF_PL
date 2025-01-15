# MST Graph Processing Server

A high-performance, multi-threaded server implementation for processing Minimum Spanning Tree (MST) algorithms and graph analytics. This project demonstrates advanced concurrent programming patterns and design principles in C++.

## 🌟 Features

### Graph Algorithms
- **MST Algorithms**
  - Prim's Algorithm
  - Kruskal's Algorithm
- **Graph Analytics**
  - Floyd-Warshall Algorithm for shortest paths
  - Total weight calculation
  - Average distance computation
  - Longest/shortest distance analysis

### Concurrent Design Patterns
- **Leader-Follower Pattern**
  - Dynamic thread pool management
  - Efficient task distribution
  - Leader election mechanism
  
- **Active Object Pattern**
  - Asynchronous operation processing
  - Message passing between stages
  - Thread-safe queue management

- **Pipeline Pattern**
  - Multi-stage graph processing
  - Parallel execution of analytics
  - Sequential data flow management

### Architecture
- **Client-Server Model**
  - TCP/IP communication
  - Multi-client support
  - Non-blocking I/O with poll

- **Design Patterns**
  - Singleton Pattern for resource management
  - Factory Pattern for algorithm creation
  - Strategy Pattern for algorithm selection

## 🚀 Getting Started

### Prerequisites
- CMake (version 3.22 or higher)
- C++ Compiler with C++17 support
- pthread library
- Linux/Unix environment

### Building the Project
```bash
mkdir build
cd build
cmake ..
make
```
### Running the server
```bash
./main
```
The server will start listening on port 9034 by default.

## 📝 Usage

### Client Commands
- `Newgraph` - Create a new graph
- `MST` - Calculate Minimum Spanning Tree
- `Newedge` - Add edge to graph
- `Removeedge` - Remove edge from graph
- `Exit` - Close connection

### Processing Modes
- `LF` - Leader-Follower thread pool processing
- `P` - Pipeline processing

### Algorithm Selection
- `Prim` - Use Prim's algorithm for MST
- `Kruskal` - Use Kruskal's algorithm for MST

## 🔧 Architecture Details

### Thread Management
- Thread-safe queue implementations
- Mutex-protected shared resources
- Condition variables for synchronization
- Graceful shutdown mechanisms

### Memory Management
- RAII principles
- Resource cleanup on shutdown

### Error Handling
- Exception safety
- Error reporting
- Graceful degradation

### Coverage Analysis
```bash
# Generate coverage report
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
./main
llvm-profdata merge -sparse default.profraw -o default.profdata
llvm-cov report ./main -instr-profile=default.profdata
```

Current coverage metrics:
- Lines: 88.76%
- Functions: 98.51%
- Branches: 78.68%

## 🛠️ Development

### Project Structure
```
.
├── ActiveObject.{cpp,hpp}   # Active Object pattern implementation
├── Algo.{cpp,hpp}          # Graph algorithms
├── ClientHandler.{cpp,hpp}  # Client connection handling
├── Graph.{cpp,hpp}         # Graph data structure
├── LeaderFollower.{cpp,hpp} # Thread pool implementation
├── Pipeline.{cpp,hpp}      # Pipeline pattern implementation
├── Proactor.{cpp,hpp}      # Proactor pattern implementation
├── Reactor.{cpp,hpp}       # Reactor pattern implementation
├── Server.cpp              # Main server implementation
└── Singletone.hpp         # Singleton pattern implementation
```

### Key Components

#### Graph Module
- Implements an undirected weighted graph
- Supports dynamic edge addition/removal
- Thread-safe operations with mutex protection

#### Algorithm Module
- MST algorithms (Prim, Kruskal)
- Graph analytics (Floyd-Warshall, distance calculations)
- Optimized implementations for performance

#### Concurrency Patterns
- Leader-Follower: Dynamic thread pool for task processing
- Active Object: Asynchronous operation handling
- Pipeline: Sequential processing stages

## 🔍 Implementation Details

### Thread Safety
- Mutex protection for shared resources
- Atomic operations where applicable
- Lock-free data structures when possible

### Memory Management
- RAII-compliant resource handling
- Proper cleanup in destructors
- Prevention of memory leaks

### Error Handling
- Exception-safe code
- Proper resource cleanup on errors
- Meaningful error messages

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Coding Standards
- Follow C++17 best practices
- Use consistent formatting
- Include appropriate comments
- Write unit tests for new features

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👥 Authors

- [Gal Ben Ami](https://github.com/benami171) 
- [Barak Rozenkvit](https://github.com/barakrozenkvit) 

Connect with us:
- Gal: [![GitHub](https://img.shields.io/github/followers/benami171?label=follow&style=social)](https://github.com/benami171)
- Barak: [![GitHub](https://img.shields.io/github/followers/barakrozenkvit?label=follow&style=social)](https://github.com/barakrozenkvit)

## 📚 References

1. "Design Patterns: Elements of Reusable Object-Oriented Software" by Gang of Four
2. "C++ Concurrency in Action" by Anthony Williams
3. "Modern C++ Programming with Test-Driven Development" by Jeff Langr

---

**Note**: This project is part of an Advanced Operating Systems course and demonstrates various concurrent programming patterns and design principles in C++.
