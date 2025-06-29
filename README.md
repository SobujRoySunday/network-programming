# Network Programming

This repository contains a collection of basic to intermediate-level network programming tasks written in **C**, designed for learning and practicing core concepts in computer networks and socket programming.

Each folder corresponds to a specific task or topic and includes code implementations structured with proper function usage and modularity.

---

## 📂 Directory Structure

| Folder                          | Description                                                                 |
|---------------------------------|-----------------------------------------------------------------------------|
| `01-ip-dec-to-bin`             | Convert an IP address from decimal to binary format                         |
| `02-ip-class-detection`        | Detect the class of a given IP address                                      |
| `03-ip-subnetting`            | Perform basic IP subnetting calculations                                    |
| `04-files-using-syscall`      | File operations using Linux system calls                                    |
| `05-simple-client-server`     | Basic TCP client-server communication                                       |
| `06-looped-client-server`     | TCP server that handles multiple clients in a loop                          |
| `07-udp-client-server`        | UDP-based client-server communication                                       |
| `08-concurrent-connections`   | Handle multiple clients concurrently using `fork()` or threading            |

---

## 🛠️ Technologies Used

- **Language**: C (100%)
- **Concepts Covered**:
  - IP addressing and classes
  - Subnetting
  - Socket programming
  - TCP & UDP communication
  - System calls for file handling
  - Concurrent server designs (multi-processing/threading)

---

## 🧑‍🎓 Who Should Use This?

This repository is ideal for:

- B.Tech/CS/IT students learning network programming
- Candidates preparing for system-level interviews
- Developers looking to brush up on low-level network fundamentals

---

## 🚀 How to Run

Make sure you have a Linux environment with GCC installed. Then:

```bash
# Navigate to a task directory
cd 05-simple-client-server

# Compile the server
gcc server.c -o server

# Compile the client
gcc client.c -o client

# Run the server in one terminal
./server

# Run the client in another terminal
./client
