
# Minitalk

Minitalk is a small messaging program written in C, allowing communication between processes using UNIX signals. This project was created for educational purposes and demonstrates basic inter-process communication (IPC) techniques using signals.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Minitalk consists of two main components:
- **Server**: A process that listens for messages from clients and prints them.
- **Client**: A process that sends messages to the server.

The communication between the client and server is done using UNIX signals (`SIGUSR1` and `SIGUSR2`), encoding each character of the message bit by bit.

## Features

- Simple and lightweight implementation.
- Demonstrates the use of UNIX signals for IPC.
- Handles basic error conditions.

## Requirements

To build and run Minitalk, you need:
- A UNIX-like operating system (Linux, macOS, etc.)
- `make` utility
- `gcc` compiler

## Installation

Clone the repository to your local machine:

```sh
git clone https://github.com/ddcsoftdev/minitalk.git
cd minitalk
```

Build the project using `make`:

```sh
make
```

This will compile two executables: `server` and `client`.

## Usage

### Running the Server

To start the server, run the `server` executable. It will print its PID (Process ID), which is required by the client to send messages.

```sh
./server
```

### Sending Messages from the Client

To send a message to the server, run the `client` executable with the server's PID and the message as arguments.

```sh
./client <server_pid> "Your message here"
```

Example:

```sh
./client 12345 "Hello, World!"
```

### Example Session

1. Start the server:
    ```sh
    ./server
    ```
    Output:
    ```
    Server PID: 12345
    ```

2. In another terminal, send a message using the client:
    ```sh
    ./client 12345 "Hello, World!"
    ```
    The server will output:
    ```
    Received message: Hello, World!
    ```

## Contributing

Contributions are welcome! Please fork the repository and open a pull request to add new features, fix bugs, or improve documentation.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
