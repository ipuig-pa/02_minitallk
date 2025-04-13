# Minitalk

## Project Overview

---

This project consists on creating a communication program implementing a client-server architecture using UNIX signals. It demonstrates inter-process communication in a Unix environment by transmitting strings between two separate programs using only signals.

### Resources

- Custom libft and ft_printf library

## Compilation

---

- Use `make` to compile the project: This will compile both the client and server executables.

## Usage

---

### Server

Start the server first:

```bash
[ ]

bash
./server
```

The server will display its PID, which you'll need to communicate with it.

### Client

With the server running, use the client to send messages:

```bash
[ ]

bash
./client [server_pid] [message]
```

- `[server_pid]`: The PID displayed by the server
- `[message]`: The string you want to send to the server

Example:

```bash
[ ]

bash
./client 4321 "Hello, Minitalk!"
```

## Features

---

- Server prints its PID upon launch
- Client sends a string to the server using the server's PID
- Server displays the received string without delay
- Server can receive messages from multiple clients consecutively
- Communication occurs exclusively through UNIX signals (SIGUSR1 and SIGUSR2)

## Implementation Details

---

### Signal Transmission

The program uses two UNIX signals to transmit data:

- `SIGUSR1`: Represents binary 0
- `SIGUSR2`: Represents binary 1

Each character in the message is converted to its binary representation and transmitted bit by bit using these signals.

The program implements signal handlers to:

- Capture incoming signals
- Process binary data
- Reconstruct characters
- Handle transmission errors

## License

---

This project was developed as part of the curriculum at 42 School. Use of this code must comply with the school's academic integrity policies.
